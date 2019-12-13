    //
// Created by Morten Nobel-Jørgensen on 10/10/2017.
//

#include "CameraController.hpp"
#include "PokemanGame.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>
#include <iostream>

using namespace std;
using namespace glm;

CameraController::CameraController(GameObject *gameObject) : Component(gameObject) {
    camera.setOrthographicProjection(PokemanGame::windowSize.y * 3, -1000, 1000);

    camera.setWindowCoordinates();
    camera.setOrthographicProjection(200, -2000, 2000);
    camRotation = glm::vec3(-0.94,-0.66, 0.44);
    //-0.94, y: -0.66, z: 0.44
    cameraOriMat4 = camera.getViewTransform();
    camera.setViewTransform(IsometricView);
}

sre::Camera &CameraController::getCamera() {
    return camera;
}

void CameraController::update(float deltaTime) {
    lerpTime += deltaTime / 2.0f * lerpSpeed;
    float easeTime = 0.5 - cos(-glm::min(lerpTime, 1.0f) * M_PI) * 0.5;
    vec3 lerpedCameraRotation = glm::mix(vec3(0,0,0), camRotation, easeTime);
    auto position = followObject->getPosition();
    gameObject->setPosition(position);
    IsometricView = rotate(cameraOriMat4, lerpedCameraRotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    IsometricView = rotate(IsometricView, lerpedCameraRotation.y, glm::vec3(0.0f, 1.0f, 0.00f));
    IsometricView = rotate(IsometricView, lerpedCameraRotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    camera.setViewTransform(IsometricView);
    camera.setPositionAndRotation(vec3(position.x,position.y,0), camera.getRotationEuler());
}

void CameraController::setFollowObject(std::shared_ptr<GameObject> followObject, glm::vec2 offset) {
    this->followObject = followObject;
    this->offset = offset;
}

bool CameraController::onKey(SDL_Event &event) {
    if (event.key.keysym.sym == SDLK_t && event.type == SDL_KEYDOWN) {
        camRotation.x += 0.02f;
    }
    if  (event.key.keysym.sym == SDLK_g && event.type == SDL_KEYDOWN) {
        camRotation.x -= 0.02f;
    }
    if  (event.key.keysym.sym == SDLK_y && event.type == SDL_KEYDOWN) {
        camRotation.y += 0.02f;
    }
    if  (event.key.keysym.sym == SDLK_h && event.type == SDL_KEYDOWN) {
        camRotation.y -= 0.02f;
    }
    if  (event.key.keysym.sym == SDLK_u && event.type == SDL_KEYDOWN) {
        camRotation.z += 0.02f;
    }
    if  (event.key.keysym.sym == SDLK_j && event.type == SDL_KEYDOWN) {
        camRotation.z -= 0.02f;
    }

    std::cout << "x: " << camRotation.x << ", y: " << camRotation.y << ", z: " << camRotation.z << std::endl;

    return false;
}