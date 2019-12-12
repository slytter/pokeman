#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include <vector>
#include "Box2D/Dynamics/b2World.h"
#include "GameObject.hpp"
#include "CameraController.hpp"
#include "BackgroundComponent.hpp"
#include "Box2DDebugDraw.hpp"
#include "WorldGenerator.h"

class PhysicsComponent;

enum class GameState{
    Ready,
    Running,
    GameOver
};

class PokemanGame : public b2ContactListener {
public:
    PokemanGame();

    std::shared_ptr<GameObject> createGameObject();
    static const glm::vec2 windowSize;

    std::shared_ptr<WorldGenerator> pokemanWorld;


    void BeginContact(b2Contact *contact) override;

    void EndContact(b2Contact *contact) override;

    static PokemanGame* instance;

    WorldGenerator pokemanMap;
    void setGameState(GameState newState);

    std::shared_ptr<GameObject> addGameObject(std::shared_ptr<GameObject> gameObject);

    void spawnProjectile(glm::vec2 pos, float rotation);

private:
    sre::SDLRenderer r;

    void init();
    void initPhysics();



    void update(float time);

    void render();

    void onKey(SDL_Event &event);

    void handleContact(b2Contact *contact, bool begin);

    void initLevel ();

    std::shared_ptr<CameraController> camera;
    std::shared_ptr<sre::SpriteAtlas> spriteAtlas;
    std::shared_ptr<sre::SpriteAtlas> spriteAtlasPokeman;
    std::shared_ptr<sre::SpriteAtlas> defaultSprites;

    std::map<int,std::string> tileType;

    std::vector<std::shared_ptr<GameObject>> sceneObjects;
    BackgroundComponent background1Component;
    BackgroundComponent background2Component;

    void updatePhysics();
    b2World * world = nullptr;
    const float physicsScale = 100;
    void registerPhysicsComponent(PhysicsComponent *r);
    void deregisterPhysicsComponent(PhysicsComponent *r);
    std::map<b2Fixture*,PhysicsComponent *> physicsComponentLookup;
    Box2DDebugDraw debugDraw;
    bool doDebugDraw = false;
    GameState gameState = GameState::Ready;
    friend class PhysicsComponent;
};



