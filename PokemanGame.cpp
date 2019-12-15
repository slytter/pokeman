#include <sre/Inspector.hpp>
#include <iostream>
#include "PokemanGame.hpp"
#include "GameObject.hpp"
#include "sre/RenderPass.hpp"
#include "SpriteComponent.hpp"
#include "SpriteAnimationComponent.hpp"
#include "Box2D/Dynamics/Contacts/b2Contact.h"
#include "PhysicsComponent.hpp"
#include "TrainerController.hpp"
#include "Projectile.h"
#include "Creature.h"
#include "SoundSource.h"


using namespace std;
using namespace glm;
using namespace sre;

const glm::vec2 PokemanGame::windowSize(800, 600);


PokemanGame* PokemanGame::instance = nullptr;

PokemanGame::PokemanGame() :debugDraw(physicsScale) {
    instance = this;
    r.setWindowSize(windowSize);
    r.init()
      .withSdlInitFlags(SDL_INIT_EVERYTHING)
      .withSdlWindowFlags(SDL_WINDOW_OPENGL);

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) {
        cout << "Cannot initialize audio output"<< endl;
        return;
    }

    tileType[0] = std::string("defaultWall.png");
    tileType[1] = std::string("dirt.png");
    tileType[2] = std::string("stone.png");
    tileType[3] = std::string("lava.png");

    // Loading monsters:
    monsterType.push_back(std::string("tile1.png"));
    monsterType.push_back(std::string("tile2.png"));
    monsterType.push_back(std::string("tile3.png"));
    monsterType.push_back(std::string("tile4.png"));
    monsterType.push_back(std::string("tile5.png"));

    // Loading map
    pokemanMap.loadPokemanMap("assets/levelData.json");

    // Loading spritemaps
    spriteAtlasPokeman = SpriteAtlas::create("sprites/2DLandscape.json","sprites/2DLandscape.png");
    spriteAtlasMonsters = SpriteAtlas::create("sprites/monsters.json","sprites/monsters.png");
    defaultSprites = SpriteAtlas::create("sprites/screens.json","sprites/screens.png");
    spriteAtlas = SpriteAtlas::create("sprites/ash.json","sprites/ash.png");
    bulletSprite = SpriteAtlas::create("sprites/bullet.json","sprites/bullet.png");
    srand(10);

    ImGui::GetStyle().FrameBorderSize = 0.0f;
    ImGui::GetStyle().WindowBorderSize = 0.0f;
    init();

    // Loading GUI fonts:
    auto fonts = ImGui::GetIO().Fonts;
    fonts->AddFontDefault();
    auto fontName = "assets/Lazer84.ttf";
    int fontSize = 45;
    chosenFont = fonts->AddFontFromFileTTF(fontName, fontSize);

    // setup callback functions
    r.keyEvent = [&](SDL_Event& e){
        onKey(e);
    };
    r.frameUpdate = [&](float deltaTime){
        update(deltaTime);
    };
    r.frameRender = [&](){
        render();
    };
    // start game loop
    r.startEventLoop();
}

void PokemanGame::init() {
    if (world != nullptr){ // deregister call backlistener to avoid getting callbacks when recreating the world
        world->SetContactListener(nullptr);
    }
    soundTrackSound.play();
    Player = nullptr;
    onGUIPLayer = nullptr;

    createGameObject();
    sceneObjects.clear();

    camera.reset();
    physicsComponentLookup.clear();
    initPhysics();
    initLevel ();

    auto camObj = createGameObject();
    camObj->name = "Camera";
    camera = camObj->addComponent<CameraController>();
    camObj->setPosition(windowSize*0.5f);

    Player = createGameObject();
    Player->name = "Player";

    camera->setFollowObject(Player, {+150, PokemanGame::windowSize.y / 2});
    auto so = Player->addComponent<SpriteComponent>();
    auto sprite = spriteAtlas->get("tile008.png");
    sprite.setOrderInBatch(10);
    sprite.setScale({2,2});

    Player->setPosition({(int)pokemanMap.getStartingPosition().x, pokemanMap.getStartingPosition().y});
    so->setSprite(sprite);

    auto anim = Player->addComponent<SpriteAnimationComponent>();
    auto phys = Player->addComponent<PhysicsComponent>();
    phys->initCircle(b2_dynamicBody, 10/physicsScale, {Player->getPosition().x / physicsScale, Player->getPosition().y / physicsScale}, 1);
    auto trainer = Player->addComponent<TrainerController>();
    onGUIPLayer = trainer;
    onGUIPLayer -> setCamera(camera);

    vector<Sprite> spriteAnim({spriteAtlas->get("tile008.png"),spriteAtlas->get("tile009.png"),spriteAtlas->get("tile010.png"),spriteAtlas->get("tile011.png")});
    anim-> setSprites(spriteAnim);
    vector<Sprite> upDownSpriteAnim({
        spriteAtlas->get("tile012.png"),spriteAtlas->get("tile013.png"),spriteAtlas->get("tile014.png"),spriteAtlas->get("tile015.png"),
        spriteAtlas->get("tile000.png"),spriteAtlas->get("tile001.png"),spriteAtlas->get("tile002.png"),spriteAtlas->get("tile003.png")
    });
    anim-> setUpDownSprites(upDownSpriteAnim);
    wave = 1;
    allEnemiesSpawnedInWave = false;
}

void PokemanGame::spawnProjectile(){
    auto projectile = createGameObject();
    projectile->name = "Projectile";
    std::shared_ptr<SpriteComponent> projectileSpriteCom = projectile->addComponent<SpriteComponent>();
    auto spriteImage = bulletSprite->get("bullet.png");
    spriteImage.setScale(vec2(1.2f, 1.2f));
    std::shared_ptr<Projectile> projectileCompenent = projectile->addComponent<Projectile>();
    projectileCompenent->playerReference = Player;
    projectileCompenent->shoot();
    projectileSpriteCom->setSprite(spriteImage);
}

void PokemanGame::enemySpawner() { // This is a very simple function which is responsible for spawning enemies.
    enemyCount++;
    auto enemy = createGameObject();
    enemy->name = "creature";
    auto so2 = enemy->addComponent<SpriteComponent>();
    auto sprite2 = spriteAtlasMonsters->get(monsterType[(rand() % 5)]);
    sprite2.setScale({1.5f,2});
    int rno = (int)(rand() % 4);
    enemy->setPosition(pokemanMap.enemySpawnPoints[rno]);
    so2->setSprite(sprite2);
    auto phys2 = enemy->addComponent<PhysicsComponent>();
    phys2->initCircle(b2_dynamicBody, 30/physicsScale, {enemy->getPosition().x/physicsScale,enemy->getPosition().y/physicsScale}, 1);
    auto creature = enemy->addComponent<Creature>();
    creature->getEnemyCount(enemyCount);
    creature->getPlayer(Player);
    creature->setCamera(camera);
}


void PokemanGame::update(float time) {
    bool gameIsRunning = gameState == GameState::Running;
    int waveSize = waveIncreaseBy * wave;

    // A wave incrementation is allowed when all enemies are killed, and all enemies has been spawned.
    if(currentEnemyCount == 0 && allEnemiesSpawnedInWave && gameIsRunning) {
        wave++;
        allEnemiesSpawnedInWave = false;
    }

    // We spawn an enemy when all enemies has not been spawned and the timer is 0,.
    if (countDown <= 0 && gameIsRunning && !allEnemiesSpawnedInWave) {
        enemySpawner();
        if(currentEnemyCount == waveSize - 1) { // if the current enemies is equal to the wavesize:
            allEnemiesSpawnedInWave = true; // we block for more enemies to be spawned for now.
        }
        countDown = enemySpawnerTime;
    }
    countDown -= time;

    currentEnemyCount = 0;
    for (int i = 0; i < sceneObjects.size(); i++) {
        if(sceneObjects[i]->name == "creature") { // Here we count to current amount of enemies.
            currentEnemyCount ++;
        }
        if(sceneObjects[i]->removeMe) { // here we remove components that the removeMe boolean set to true.
            sceneObjects.erase(sceneObjects.begin() + i); // using erase with an index, makes sure that no pointers are removed wrongly
        }
        sceneObjects[i]->update(time);
    }

    timePast += time;
    if(maySpawnProjectile && timePast > burstSpeed) { // here we allow for a projectile to be spawned
        timePast = 0.0f;
        gunShotSound.play();
        spawnProjectile();
    }
    if (gameIsRunning) {
        updatePhysics();
    }
}

void PokemanGame::render() {
    auto rp = RenderPass::create()
            .withCamera(camera->getCamera())
            .withClearColor(true, {0, 0, 0, 1})
            .build();

    for (int i = 0; i <sceneObjects.size() ; ++i) {
        sceneObjects[i]->renderGUI(); // This function handles every GUI element attached to a game object.
    }

    auto pos = camera->getGameObject()->getPosition();

    auto spriteBatchBuilder = SpriteBatch::create();
    for (auto & go : sceneObjects){
        if(go->name != "Player" || gameState == GameState::Running){ // making sure that we only render the player when gameState is running.
            go->renderSprite(spriteBatchBuilder); //rendering sprites from gameopjects
        }
    }

    if (gameState == GameState::Ready) { // When the game is in its initial ready state
        runOnceWhenGameOver = true;
        auto sprite = defaultSprites->get("cap-em-all.png"); // we show the main screen sprite:
        sprite.setScale(glm::vec2(0.4f, 0.4f));
        sprite.setPosition(pos);
        spriteBatchBuilder.addSprite(sprite);
    } else if (gameState == GameState::GameOver) { // When game is over:
        if(runOnceWhenGameOver) { // run once:
            camera->lerpTime = 1;
            camera->lerpSpeed = -1;

            runOnceWhenGameOver = false;
            pukeSound.play();
            hellNoSound.play();
        }
        auto sprite = defaultSprites->get("lost.png");
        sprite.setScale(glm::vec2(0.4f, 0.4f));
        sprite.setPosition(pos);
        spriteBatchBuilder.addSprite(sprite);
    }

    auto sb = spriteBatchBuilder.build();
    rp.draw(sb);

    if (doDebugDraw){
        world->DrawDebugData();
        rp.drawLines(debugDraw.getLines());
        debugDraw.clear();
    }

    ImGui::SetNextWindowPos(ImVec2(Renderer::instance->getWindowSize().x/2-100, .0f), ImGuiSetCond_Always);
    ImGui::SetNextWindowBgAlpha(0.0f);
    ImGui::SetNextWindowSize(ImVec2(300, 100), ImGuiSetCond_Always);
    ImGui::Begin("WAVE", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    ImGui::PushFont(chosenFont);
    ImGui::Text("WAVE: %d", wave); // Drawing wave GUI
    ImGui::PopFont();
    ImGui::End();
}

void PokemanGame::onKey(SDL_Event &event) {
    for (auto & gameObject: sceneObjects) {
        for (auto & c : gameObject->getComponents()){
            bool consumed = c->onKey(event);
            if (consumed){
                return;
            }
        }
    }
    if (event.key.keysym.sym == SDLK_SPACE && gameState == GameState::Running) { // Press space will allow shooting
        maySpawnProjectile = event.type == SDL_KEYDOWN;
    }
    if (event.type == SDL_KEYDOWN){
        switch (event.key.keysym.sym){
            case SDLK_d:
                doDebugDraw = !doDebugDraw;
                if (doDebugDraw){
                    world->SetDebugDraw(&debugDraw);
                } else {
                    world->SetDebugDraw(nullptr);
                }
                break;
            case SDLK_r:
                init();
                break;
            case SDLK_SPACE:
                if (gameState == GameState::GameOver){
                    camera->lerpTime = 0.0f;
                    init();
                    gameState = GameState::Ready;
                } else if (gameState == GameState::Ready){
                    camera->lerpSpeed = 1.0f;
                    ahShitSound.play();
                    gameState = GameState::Running;
                }
                break;
        }
    }

}

std::shared_ptr<GameObject> PokemanGame::createGameObject() {
    auto obj = shared_ptr<GameObject>(new GameObject());
    sceneObjects.push_back(obj);
    return obj;
}


void PokemanGame::updatePhysics() {
    const float32 timeStep = 1.0f / 60.0f;
    const int positionIterations = 2;
    const int velocityIterations = 6;
    world->Step(timeStep, velocityIterations, positionIterations);

    for (auto phys : physicsComponentLookup){
        if (phys.second->rbType == b2_staticBody) continue;
        auto position = phys.second->body->GetPosition();
        float angle = phys.second->body->GetAngle();
        auto gameObject = phys.second->getGameObject();
        gameObject->setPosition(glm::vec2(position.x*physicsScale, position.y*physicsScale));
        gameObject->setRotation(angle);
    }
}

void PokemanGame::initPhysics() {
    delete world;
    world = new b2World(b2Vec2(0,0));
    world->SetContactListener(this);

    if (doDebugDraw){
        world->SetDebugDraw(&debugDraw);
    }
}

void PokemanGame::BeginContact(b2Contact *contact) {
    b2ContactListener::BeginContact(contact);
    handleContact(contact, true);
}

void PokemanGame::EndContact(b2Contact *contact) {
    b2ContactListener::EndContact(contact);
    handleContact(contact, false);
}

void PokemanGame::deregisterPhysicsComponent(PhysicsComponent *r) {
    auto iter = physicsComponentLookup.find(r->fixture);
    if (iter != physicsComponentLookup.end()){
        physicsComponentLookup.erase(iter);
    } else {
        assert(false); // cannot find physics object
    }
}

void PokemanGame::registerPhysicsComponent(PhysicsComponent *r) {
    physicsComponentLookup[r->fixture] = r;
}

void PokemanGame::handleContact(b2Contact *contact, bool begin) {
    auto fixA = contact->GetFixtureA();
    auto fixB = contact->GetFixtureB();
    auto physA = physicsComponentLookup.find(fixA);
    auto physB = physicsComponentLookup.find(fixB);
    if (physA !=physicsComponentLookup.end() && physB != physicsComponentLookup.end()){
        auto & aComponents = physA->second->getGameObject()->getComponents();
        auto & bComponents = physB->second->getGameObject()->getComponents();
        for (auto & c : aComponents){
            if (begin){
                c->onCollisionStart(physB->second);
            } else {
                c->onCollisionEnd(physB->second);
            }
        }
        for (auto & c : bComponents){
            if (begin){
                c->onCollisionStart(physA->second);
            } else {
                c->onCollisionEnd(physA->second);
            }
        }
    }
}

void PokemanGame::setGameState(GameState newState) {
    this->gameState = newState;
}

GameState PokemanGame::getGameState() {
    return gameState;
}

void PokemanGame::initLevel() { // This function initializes the map
    sre::Sprite tile;
    // The PokemanMap object, contains a 2D vector that represents the gameworld (specified in assets/levelData.json).
    // The every entry in the 2D vector, has a tile-type (either: 0 = defaultWall,1 = dirt,2 = stone, 3 = lava) which defines its "properties".
    for (int i = 0; i < pokemanMap.getWidth() ; ++i) {
        for (int j = 0; j < pokemanMap.getHeight() ; ++j) {
            for (auto type : tileType) { // This loops through each tile-type, in order to test for match.
                if (type.first == pokemanMap.getTile(i, j)) { // The map variable, matches the given entry of the 2D grid, to the corresponding image path.
                    auto sprite = spriteAtlasPokeman->get(type.second);
                    sprite.setOrderInBatch(0);
                    tile = sprite;
                    tile.setScale({2,2});
                    auto tileObj = createGameObject();
                    tileObj->name = type.second.substr(0,type.second.find('.')); // This tags the newly created gameobject.
                    auto so1 = tileObj->addComponent<SpriteComponent>();
                    so1->setSprite(tile);
                    tileObj->setPosition({(pokemanMap.getStartingPosition().x - pokemanMap.worldOffset.x) + (64 * i),(pokemanMap.getStartingPosition().y - pokemanMap.worldOffset.y) +(j*64)}); // The tile is positioned in the gameworld
                    if (tileObj->name == "defaultWall") { // Here the tag of the gameobjec is checked, in order to see if a collider needs to be attached.
                        std::shared_ptr<PhysicsComponent> TilePhys = tileObj->addComponent<PhysicsComponent>();
                        TilePhys->initBox(b2_staticBody, vec2(32 / physicsScale, 32 / physicsScale), {tileObj->getPosition().x/physicsScale,tileObj->getPosition().y/physicsScale}, 2);
                    }
                }
            }
        }
    }
}

std::shared_ptr<GameObject> PokemanGame::addGameObject(std::shared_ptr<GameObject> gameObject) {
    sceneObjects.push_back(gameObject);
    return gameObject;
}
