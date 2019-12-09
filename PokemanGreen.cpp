//
// Created by Nikolay Schlüter and Sune Klem on 09/12/2019.
//
#include "PokemanGreen.h"
#include <iostream>

using namespace std;

PokemanGreen::PokemanGreen() {
    winSize = glm::vec2 (900,500);



    init();
}

void PokemanGreen::init() {
    renderer.setWindowSize(winSize);

    renderer.init().withSdlInitFlags(SDL_INIT_EVERYTHING)
            .withSdlWindowFlags(SDL_WINDOW_OPENGL)
            .withVSync(true);

    renderer.frameUpdate = [&](float deltaTime){
        cout << deltaTime << "\n";
    };


    mainCam.setOrthographicProjection(45,0.1f,1000);
    // mainCam.setProjectionTransform() <-- Jeg tror det er det vi skal bruge til at lave det isometric...

    renderer.startEventLoop();
    cout<< "Let the pokeman begin!";
}

