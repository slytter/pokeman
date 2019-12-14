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

    tileType[0] = std::string("defaultWall.png");
    tileType[1] = std::string("dirt.png");
    tileType[2] = std::string("stone.png");
    tileType[3] = std::string("lava.png");

    monsterType.push_back(std::string("tile1.png"));
    monsterType.push_back(std::string("tile2.png"));
    monsterType.push_back(std::string("tile3.png"));
    monsterType.push_back(std::string("tile4.png"));
    monsterType.push_back(std::string("tile5.png"));

    pokemanMap.loadPokemanMap("levelData.json");

    spriteAtlasPokeman = SpriteAtlas::create("2DLandscape.json","2DLandscape.png");
    spriteAtlasMonsters = SpriteAtlas::create("monsters.json","monsters.png");
    defaultSprites = SpriteAtlas::create("screens.json","screens.png");
    spriteAtlas = SpriteAtlas::create("ash.json","ash.png");
    bulletSprite = SpriteAtlas::create("bullet.json","bullet.png");
    srand(10);

    init();

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
    auto birdC = Player->addComponent<TrainerController>();
    onGUIPLayer = birdC;
    onGUIPLayer -> setCamera(camera);

    vector<Sprite> spriteAnim({spriteAtlas->get("tile008.png"),spriteAtlas->get("tile009.png"),spriteAtlas->get("tile010.png"),spriteAtlas->get("tile011.png")});
    anim-> setSprites(spriteAnim);
    vector<Sprite> upDownSpriteAnim({
        spriteAtlas->get("tile012.png"),spriteAtlas->get("tile013.png"),spriteAtlas->get("tile014.png"),spriteAtlas->get("tile015.png"),
        spriteAtlas->get("tile000.png"),spriteAtlas->get("tile001.png"),spriteAtlas->get("tile002.png"),spriteAtlas->get("tile003.png")
    });
    anim-> setUpDownSprites(upDownSpriteAnim);
}


void PokemanGame::spawnProjectile(){
    auto projectile = createGameObject();
    projectile->name = "Projectile";
    std::shared_ptr<SpriteComponent> projectileSpriteCom = projectile->addComponent<SpriteComponent>();
    auto spriteImage = bulletSprite->get("bullet.png");
    spriteImage.setScale(vec2(1.2f, 1.2f));
    projectileSpriteCom->setSprite(spriteImage);
    std::shared_ptr<Projectile> projectileCompenent = projectile->addComponent<Projectile>();
    projectileCompenent->playerReference = Player;
    projectileCompenent->shoot();
}

void PokemanGame::enemySpawner() {
    auto enemy = createGameObject();
    enemy->name = "creature";
    auto so2 = enemy->addComponent<SpriteComponent>();
    auto sprite2 = spriteAtlasMonsters->get(monsterType[(rand() % 5)]);
    sprite2.setScale({2,2});

    int rno = (int)(rand() % 4);
    cout<< "dfs " << rno;
    enemy->setPosition(pokemanMap.enemySpawnPoints[rno]);
    so2->setSprite(sprite2);
    auto phys2 = enemy->addComponent<PhysicsComponent>();
    phys2->initCircle(b2_dynamicBody, 30/physicsScale, {enemy->getPosition().x/physicsScale,enemy->getPosition().y/physicsScale}, 1);
    auto creature = enemy->addComponent<Creature>();
    creature->getPlayer(Player);




}


void PokemanGame::update(float time) {
    timePast += time;
    if (countDown <= 0) {
        enemySpawner();
        countDown = enemySpawnerTime;
    }

    if (gameState == GameState::Running) {
        updatePhysics();

    }
    for (int i = 0; i < sceneObjects.size(); i++) {
        if(sceneObjects[i]->removeMe) {
            sceneObjects.erase(sceneObjects.begin() + i);
        }
        sceneObjects[i]->update(time);
    }

    countDown -= time;

    if(maySpawnProjectile && timePast > burstSpeed) {
        timePast = 0.0f;
        gunShotSound.play();
        spawnProjectile();
    }
}

void PokemanGame::render() {


    auto rp = RenderPass::create()
            .withCamera(camera->getCamera())
            .withClearColor(true, {0, 0, 0, 1})
            .build();


    onGUIPLayer->onGui();

    auto pos = camera->getGameObject()->getPosition();
    background1Component.renderBackground(rp, +pos.x*0.8f);

    auto spriteBatchBuilder = SpriteBatch::create();
    for (auto & go : sceneObjects){
        go->renderSprite(spriteBatchBuilder);
    }

    if (gameState == GameState::Ready){
        auto sprite = defaultSprites->get("cap-em-all.png");
        sprite.setScale(glm::vec2(0.5f, 0.5f));
        sprite.setPosition(pos);
        spriteBatchBuilder.addSprite(sprite);
    } else if (gameState == GameState::GameOver){
        auto sprite = defaultSprites->get("lost.png");
        sprite.setScale(glm::vec2(0.5f, 0.5f));
        sprite.setPosition(pos);
        spriteBatchBuilder.addSprite(sprite);
    }

    auto sb = spriteBatchBuilder.build();
    rp.draw(sb);

    background2Component.renderBackground(rp, -pos.x*0.2f);

    if (doDebugDraw){
        world->DrawDebugData();
        rp.drawLines(debugDraw.getLines());
        debugDraw.clear();
    }




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

    if (event.type == SDL_KEYDOWN){
        switch (event.key.keysym.sym){
            case SDLK_d:
                // press 'd' for physics debug
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
                    gameState = GameState::Running;
                }
                break;
        }
    }
    if (event.key.keysym.sym == SDLK_SPACE) {
        maySpawnProjectile = event.type == SDL_KEYDOWN;
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

void PokemanGame::initLevel() {
    sre::Sprite tile;
    for (int i = 0; i < pokemanMap.getWidth() ; ++i) {
        for (int j = 0; j < pokemanMap.getHeight() ; ++j) {
            for (auto type : tileType) {
                if (type.first == pokemanMap.getTile(i, j)) {
                    auto sprite = spriteAtlasPokeman->get(type.second);
                    sprite.setOrderInBatch(0);
                    tile = sprite;
                    tile.setScale({2,2});
                    auto tileObj = createGameObject();
                    tileObj->name = type.second.substr(0,type.second.find('.'));
                    auto so1 = tileObj->addComponent<SpriteComponent>();
                    so1->setSprite(tile);
                    tileObj->setPosition({(pokemanMap.getStartingPosition().x - pokemanMap.worldOffset.x) + (64 * i),(pokemanMap.getStartingPosition().y - pokemanMap.worldOffset.y) +(j*64)});
                    if (tileObj->name == "defaultWall" || tileObj->name == "lava") {
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
