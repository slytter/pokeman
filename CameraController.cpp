
#include "CameraController.hpp"
#include "PokemanGame.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>
#include <iostream>

using namespace std;
using namespace glm;

CameraController::CameraController(GameObject *gameObject) : Component(gameObject) {
    camera.setWindowCoordinates();
    camera.setOrthographicProjection(250, -2000, 2000);  // Sets the projection of the camera to orthographic.
    camRotation = glm::vec3(-0.94,-0.66, 0.44); // Initialize the vector that contains the rotation values (in radians) which are used to obtain the isometric view.
    cameraOriMat4 = camera.getViewTransform(); // Get the initial view transform of the camera.
}

sre::Camera &CameraController::getCamera() {
    return camera;
}

void CameraController::update(float deltaTime) {
    lerpTime += deltaTime / 2.0f * lerpSpeed;
    float easeTime = 0.5 - cos(-glm::max(glm::min(lerpTime, 1.0f), 0.0f) * M_PI) * 0.5; // our ease-in-out easing function.
    // We are lerping the camera view from a 0,0,0 vector to the isometric view, with the above easing function (and vice versa), which animates the camera.
    vec3 lerpedCameraRotation = glm::mix(vec3(0,0,0), camRotation, easeTime);
    auto position = followObject->getPosition();
    gameObject->setPosition(position);
    // The following 3 lines of code, calculates the isometric view, in respect to the orthographic camera perspective.
    // The paired vectors represent the weight of the transformation in respect to given axis.
    // (these 3 lines could be transformed into a single transformation matrix)
    IsometricView = rotate(cameraOriMat4, lerpedCameraRotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    IsometricView = rotate(IsometricView, lerpedCameraRotation.y, glm::vec3(0.0f, 1.0f, 0.00f));
    IsometricView = rotate(IsometricView, lerpedCameraRotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    camera.setViewTransform(IsometricView); // Apply the newly calculated values.
    camera.setPositionAndRotation(vec3(position.x,position.y,0), camera.getRotationEuler()); // Insures that camera is correctly oriented and follows the player.
}

void CameraController::setFollowObject(std::shared_ptr<GameObject> followObject, glm::vec2 offset) {
    this->followObject = followObject; // Gets a reference to the player.
    this->offset = offset;
}

bool CameraController::onKey(SDL_Event &event) {
    // We implemented a basic camera rotation controller in order to test the isometric view.
    // When in-game, use keys: T, G to control x. Y, H to control y. U, J to control z.
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

    return false;
}

// This function enables each component (which has a reference to camera) to map a GUI element onto a give gameobject.
// The function converts the input so it is correctly mapped in isometric view.
glm::vec2 CameraController::getCameraPos (glm::vec3 _ObjectPos) {
    vec4 objectToTrack = vec4(_ObjectPos, 1.0f);
    auto r = sre::Renderer::instance; // Gets the instance of the renderer.
    auto viewport = static_cast<glm::vec2>(r->getDrawableSize());
    // The line bellow, converts the position of the object into the clipping space, by applying the viewport transform, the projection transform and the object position.
    // The following lines then maps the output in a central view in respect to the given window size.
    vec4 cSpace = camera.getProjectionTransform(viewport) * camera.getViewTransform()*objectToTrack;
    vec4 ndc = cSpace/cSpace.w;
    ndc.y *= -1;
    vec4 wCoords = ndc * 0.5f + 0.5f;
    return vec2(wCoords) * vec2(r->getWindowSize());
}