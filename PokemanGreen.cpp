//
// Created by Nikolay Schlüter and Sune Klem on 09/12/2019.
//
#include "PokemanGreen.h"
#include <iostream>
#include <glm/gtc/constants.hpp>
#include "GameObject.hpp"
#include "Player.h"
#include <vector>
#include <glm/gtc/matrix_transform.hpp>

using namespace std;
using namespace sre;

PokemanGreen::PokemanGreen() {
    winSize = glm::vec2 (900,500);
    renderer.init().withSdlInitFlags(SDL_INIT_EVERYTHING)
            .withSdlWindowFlags(SDL_WINDOW_OPENGL)
            .withVSync(true);

    camRotation = glm::vec2(0.6108652382f,0.75049157836f);

    init();
}

void PokemanGreen::init() {
    atlas = SpriteAtlas::create("asteroids.json", "asteroids.png");
    auto spaceshipSprite = atlas->get("playerShip2_red.png");
    player = std::make_shared<Player>(spaceshipSprite, &isDead);
    gameObjects.push_back(player);

    renderer.setWindowSize(winSize);

    // setup callback functions
    renderer.keyEvent = [&](SDL_Event& e){
        keyEvent(e, player);
    };
    renderer.frameUpdate = [&](float deltaTime){
        // update(deltaTime);
    };
    renderer.frameRender = [&](){
       render();
    };

    mainCam.setWindowCoordinates();
    mainCam.setOrthographicProjection(200, -1000, 1000);

    // We still need look at!! //

    player->position = glm::vec3(0,0,0);

    glm::mat4 IsometricView = glm::rotate(mainCam.getViewTransform(), camRotation.x, glm::vec3(0.0f, 1.0f, 0.0f));
    IsometricView = glm::rotate(IsometricView, camRotation.y, glm::vec3(-1.0f, 0.0f, 0.0f));

    mainCam.setViewTransform(IsometricView); // <-- Jeg tror det er det vi skal bruge til at lave det isometric...

    renderer.startEventLoop();
    cout<< "Let the pokeman begin!";
    startGame();
}


void PokemanGreen::startGame() {

}



void PokemanGreen::render() {
    auto renderPass = RenderPass::create()
            .withCamera(mainCam)
            .withClearColor(true, {.30, .90, .40, 1})
            .build();
    auto spriteBatchBuilder = SpriteBatch::create();
    //mainCam.lookAt({player->position,0},{player->position,-1},{0,1,0});

    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->render(spriteBatchBuilder);
        //cout << gameObjects[i]->position.x << endl;
    }
    auto spriteBatch = spriteBatchBuilder.build();
    renderPass.draw(spriteBatch);


    ImGui::SetNextWindowPos(ImVec2(Renderer::instance->getWindowSize().x / 2 - 100, .0f), ImGuiSetCond_Always);
    ImGui::SetNextWindowSize(ImVec2(200, 70), ImGuiSetCond_Always);
    ImGui::Begin("", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    ImGui::LabelText("GOs", "%i", (int) gameObjects.size());
    ImGui::LabelText("Score", "%s", "score");
    ImGui::End();
}

void PokemanGreen::keyEvent(SDL_Event &event, std::shared_ptr<Player> player) {
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->onKey(event);
    }

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE) {
        if(isDead){
            // restartGame();
        }else{
            auto laserSprite = atlas->get("laserRed16.png");
            std::cout << player->position.x << ", " << player->position.y;
        }
    }

    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_d) {
        debugCollisionCircles = !debugCollisionCircles;
    }
}

//void drawCircle(std::vector<glm::vec3> &lines, glm::vec2 position, float radius) {
//
//}
