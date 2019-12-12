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
    auto camObj = createGameObject();
    camObj->name = "Camera";
    camera = camObj->addComponent<CameraController>();
    camObj->setPosition(windowSize*0.5f);

    spriteAtlas = SpriteAtlas::create("bird.json","bird.png");
    spriteAtlasPokeman = SpriteAtlas::create("2DLandscape.json","2DLandscape.png");



    initLevel ();

    auto birdObj = createGameObject();
    birdObj->name = "Bird";
    camera->setFollowObject(birdObj, {+150, PokemanGame::windowSize.y / 2});
    auto so = birdObj->addComponent<SpriteComponent>();
    auto sprite = spriteAtlas->get("bird1.png");
    sprite.setScale({2,2});



    birdObj->setPosition({-100,300});
    so->setSprite(sprite);
    auto anim = birdObj->addComponent<SpriteAnimationComponent>();
    auto phys = birdObj->addComponent<PhysicsComponent>();
    phys->initCircle(b2_dynamicBody, 10/physicsScale, {birdObj->getPosition().x/physicsScale,birdObj->getPosition().y/physicsScale}, 1);
    auto birdC = birdObj->addComponent<TrainerController>();

    vector<Sprite> spriteAnim({spriteAtlas->get("bird1.png"),spriteAtlas->get("bird2.png"),spriteAtlas->get("bird3.png"),spriteAtlas->get("bird2.png")});
    for(auto & s : spriteAnim){
        s.setScale({2,2});
    }
    anim-> setSprites(spriteAnim);

    auto spriteBottom = spriteAtlas->get("column_bottom.png");
    spriteBottom.setScale({2,2});
    float curve = 250;
    int length = 50;
    float heighVariation = 80;
    float xVariation = 50;

    for (int i=0;i<length;i++) {
        auto obj = createGameObject();
        obj->name = "Wall bottom";

        auto so = obj->addComponent<SpriteComponent>();

        float xOffset = xVariation * cos(i*curve*0.2f);
        glm::vec2 pos{i*300+xOffset,spriteBottom.getSpriteSize().y/2 + sin(i*curve)*heighVariation};
        obj->setPosition(pos);
        so->setSprite(spriteBottom);

        std::shared_ptr<PhysicsComponent> wallPhys = obj->addComponent<PhysicsComponent>();
        wallPhys->initBox(b2_staticBody, vec2(26 / physicsScale, 160 / physicsScale), {obj->getPosition().x/physicsScale,obj->getPosition().y/physicsScale}, 2);

        glm::vec2 s { spriteBottom.getSpriteSize().x * spriteBottom.getScale().x/2, spriteBottom.getSpriteSize().y * spriteBottom.getScale().y/2};
    }
    auto spriteTop = spriteAtlas->get("column_top.png");
    spriteTop.setScale({2,2});
    for (int i=0;i<length;i++){
        auto obj = createGameObject();
        obj->name = "Wall top";
        auto so = obj->addComponent<SpriteComponent>();

        float xOffset = xVariation * cos(i*curve*0.2f);
        glm::vec2 pos{ i*300+xOffset, windowSize.y-spriteTop.getSpriteSize().y/2 + sin(i*curve)*heighVariation};
        obj->setPosition(pos);
        glm::vec2 s { spriteTop.getSpriteSize().x * spriteTop.getScale().x/2, spriteTop.getSpriteSize().y * spriteTop.getScale().y/2};
        so->setSprite(spriteTop);

        std::shared_ptr<PhysicsComponent> wallPhys = obj->addComponent<PhysicsComponent>();
        wallPhys->initBox(b2_staticBody, vec2(26 / physicsScale, 160 / physicsScale), {obj->getPosition().x/physicsScale,obj->getPosition().y/physicsScale}, 2);

    }

    // Coins:
    int coinAmount = 100;
    auto coinSprite = spriteAtlas->get("coin.png");
    float coinHeightVariation = 50;
    for (int i=0;i<coinAmount;i++) {
        auto obj = createGameObject();
        obj->name = "Coin";

        auto so = obj->addComponent<SpriteComponent>();

        float coinOffset = 150;
        glm::vec2 pos{i*300+coinOffset,300 + coinSprite.getSpriteSize().y/2 + sin(i*curve)*coinHeightVariation};
        obj->setPosition(pos);
        so->setSprite(coinSprite);

        auto coinPhys = obj->addComponent<PhysicsComponent>();
        coinPhys->initCircle(b2_staticBody, 10/physicsScale, {obj->getPosition().x/physicsScale,obj->getPosition().y/physicsScale}, 1);
        coinPhys->setSensor(true);
        glm::vec2 s { coinSprite.getSpriteSize().x * coinSprite.getScale().x/2, coinSprite.getSpriteSize().y * coinSprite.getScale().y/2};

    }

    background1Component.init("background.png");
    background2Component.init("background2.png");
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
        auto sprite = spriteAtlas->get("get-ready.png");
        sprite.setPosition(pos);
        spriteBatchBuilder.addSprite(sprite);
    } else if (gameState == GameState::GameOver){
        auto sprite = spriteAtlas->get("game-over.png");
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

    for (int i = 0; i < 4 ; ++i) {
        for (int j = 0; j < 4 ; ++j) {


            auto tile = spriteAtlasPokeman->get("brick_brown-vines1.png");
            tile.setScale({2,2});
            auto tileObj = createGameObject();
            tileObj->name = "tile";
            auto so1 = tileObj->addComponent<SpriteComponent>();
            so1->setSprite(tile);
            tileObj->setPosition({-200 + (64 * i),300 +(j*64)});

            std::shared_ptr<PhysicsComponent> TilePhys = tileObj->addComponent<PhysicsComponent>();
            TilePhys->initBox(b2_staticBody, vec2(32 / physicsScale, 32 / physicsScale), {tileObj->getPosition().x/physicsScale,tileObj->getPosition().y/physicsScale}, 2);

        }
    }

}
