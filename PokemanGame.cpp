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


    pokemanMap.loadPokemanMap("levelData.json");

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


    sceneObjects.clear();
    camera.reset();
    physicsComponentLookup.clear();
    initPhysics();

    spriteAtlasPokeman = SpriteAtlas::create("2DLandscape.json","2DLandscape.png");
    initLevel ();
    auto camObj = createGameObject();
    camObj->name = "Camera";
    camera = camObj->addComponent<CameraController>();
    camObj->setPosition(windowSize*0.5f);

    spriteAtlas = SpriteAtlas::create("ash.json","ash.png");
    defaultSprites = SpriteAtlas::create("bird.json","bird.png");

    auto birdObj = createGameObject();
    birdObj->name = "Bird";
    camera->setFollowObject(birdObj, {+150, PokemanGame::windowSize.y / 2});
    auto so = birdObj->addComponent<SpriteComponent>();
    auto sprite = spriteAtlas->get("tile008.png");
    sprite.setScale({2,2});
    std:: cout << (int)pokemanMap.getStartingPosition().x;

    birdObj->setPosition({(int)pokemanMap.getStartingPosition().x,pokemanMap.getStartingPosition().y});
    so->setSprite(sprite);
    auto anim = birdObj->addComponent<SpriteAnimationComponent>();
    auto phys = birdObj->addComponent<PhysicsComponent>();
    phys->initCircle(b2_dynamicBody, 10/physicsScale, {birdObj->getPosition().x/physicsScale,birdObj->getPosition().y/physicsScale}, 1);
    auto birdC = birdObj->addComponent<TrainerController>();

    vector<Sprite> spriteAnim({spriteAtlas->get("tile008.png"),spriteAtlas->get("tile009.png"),spriteAtlas->get("tile010.png"),spriteAtlas->get("tile011.png")});
    anim-> setSprites(spriteAnim);
    vector<Sprite> upDownSpriteAnim({
        spriteAtlas->get("tile012.png"),spriteAtlas->get("tile013.png"),spriteAtlas->get("tile014.png"),spriteAtlas->get("tile015.png"),
        spriteAtlas->get("tile000.png"),spriteAtlas->get("tile001.png"),spriteAtlas->get("tile002.png"),spriteAtlas->get("tile003.png")
    });
    anim-> setUpDownSprites(upDownSpriteAnim);

}

void PokemanGame::update(float time) {
    if (gameState == GameState::Running){
        updatePhysics();
    }
    for (int i=0;i<sceneObjects.size();i++){
        if(sceneObjects[i]->removeMe){
            sceneObjects.erase(sceneObjects.begin() + i);
        }
        sceneObjects[i]->update(time);
    }
}

void PokemanGame::render() {
    auto rp = RenderPass::create()
            .withCamera(camera->getCamera())
            .build();

    auto pos = camera->getGameObject()->getPosition();
    background1Component.renderBackground(rp, +pos.x*0.8f);

    auto spriteBatchBuilder = SpriteBatch::create();
    for (auto & go : sceneObjects){
        go->renderSprite(spriteBatchBuilder);
    }

    if (gameState == GameState::Ready){
        auto sprite = defaultSprites->get("get-ready.png");
        sprite.setPosition(pos);
        spriteBatchBuilder.addSprite(sprite);
    } else if (gameState == GameState::GameOver){
        auto sprite = defaultSprites->get("game-over.png");
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
                    init();
                    gameState = GameState::Ready;
                } else if (gameState == GameState::Ready){
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

void PokemanGame::initLevel() {
    sre::Sprite tile;
    bool colOn = false;

    for (int i = 0; i < pokemanMap.getWidth() ; ++i) {
        for (int j = 0; j < pokemanMap.getHeight() ; ++j) {
            for (auto type : tileType) {
                if (type.first == pokemanMap.getTile(i, j)) {
                    tile = spriteAtlasPokeman->get(type.second);
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
