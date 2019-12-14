#include "sre/SDLRenderer.hpp"
#include "sre/SpriteAtlas.hpp"
#include <vector>
#include "Box2D/Dynamics/b2World.h"
#include "GameObject.hpp"
#include "CameraController.hpp"
#include "BackgroundComponent.hpp"
#include "Box2DDebugDraw.hpp"
#include "WorldGenerator.h"
#include "TrainerController.hpp"
#include "GameState.h"
#include "SoundSource.h"

class PhysicsComponent;

enum class GameState {
    Ready,
    Running,
    GameOver
};

class PokemanGame : public b2ContactListener {
public:
    PokemanGame();
    std::shared_ptr<GameObject> Player;
    std::shared_ptr<GameObject> createGameObject();
    static const glm::vec2 windowSize;

    SoundSource gunShotSound = SoundSource((char*)"sounds/gun-sound.wav", false, 0, 0.6f);
    SoundSource damageSound = SoundSource((char*)"sounds/damage.wav", false, 1);
    SoundSource soundTrackSound = SoundSource((char*)"sounds/sound-track.mp3", true, 2, 0.6f);
    SoundSource pukeSound = SoundSource((char*)"sounds/puke.wav", false, 3);
    SoundSource ahShitSound = SoundSource((char*)"sounds/ah-shit.wav", false, 4, 0.6f);
    SoundSource hellNoSound = SoundSource((char*)"sounds/hell-no.wav", false, 5);

    std::shared_ptr<WorldGenerator> pokemanWorld;


    void BeginContact(b2Contact *contact) override;

    void EndContact(b2Contact *contact) override;

    static PokemanGame* instance;

    WorldGenerator pokemanMap;
    void setGameState(GameState newState);
    GameState getGameState();


    std::shared_ptr<GameObject> addGameObject(std::shared_ptr<GameObject> gameObject);

    void spawnProjectile();

private:
    bool runOnceWhenGameOver = true;
    GameState gameState = GameState::Ready;
    float timePast = 0.0f;
    bool maySpawnProjectile = false;
    float burstSpeed = 0.2f;
    int enemyCount;
    sre::SDLRenderer r;
    void init();
    void initPhysics();

    void enemySpawner ();

    void update(float time);

    void render();

    void onKey(SDL_Event &event);

    void handleContact(b2Contact *contact, bool begin);

    void initLevel ();

    std::shared_ptr<CameraController> camera;
    std::shared_ptr<sre::SpriteAtlas> spriteAtlas;
    std::shared_ptr<sre::SpriteAtlas> spriteAtlasPokeman;
    std::shared_ptr<sre::SpriteAtlas> spriteAtlasMonsters;
    std::shared_ptr<sre::SpriteAtlas> defaultSprites;
    std::shared_ptr<sre::SpriteAtlas> bulletSprite;

    std::shared_ptr<TrainerController> onGUIPLayer;

    std::map<int,std::string> tileType;
    std::vector<std::string> monsterType;

    float enemySpawnerTime = 2;
    float countDown = enemySpawnerTime;

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
    friend class PhysicsComponent;
};



