//
// Created by Morten Nobel-Jørgensen on 10/10/2017.
//

#include "SideScrollingCamera.hpp"
#include "PokemanGame.hpp"
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

SideScrollingCamera::SideScrollingCamera(GameObject *gameObject) : Component(gameObject) {
    camera.setOrthographicProjection(PokemanGame::windowSize.y * 3, -1000, 1000);

    camera.setWindowCoordinates();
    camera.setOrthographicProjection(300, -2000, 2000);
    camRotation = glm::vec2(1,1);
    IsometricView = rotate(camera.getViewTransform(), camRotation.x, glm::vec3(0.0f, 1.0f, 0.0f));
    IsometricView = glm::rotate(IsometricView, camRotation.y, glm::vec3(-1.0f, 0.0f, 0.0f));

    camera.setViewTransform(IsometricView); // <-- Jeg tror det er det vi skal bruge til at lave det isometric...



}

sre::Camera &SideScrollingCamera::getCamera() {
    return camera;
}

void SideScrollingCamera::update(float deltaTime) {
    auto position = followObject->getPosition(); // getting position
    gameObject->setPosition(position);

    camera.setPositionAndRotation(vec3(position.x, position.y, 0), vec3(0,0,0));
    IsometricView = rotate(camera.getViewTransform(), camRotation.x, glm::vec3(0.0f, 1.0f, 0.0f));
    IsometricView = glm::rotate(IsometricView, camRotation.y, glm::vec3(-1.0f, 0.0f, 0.0f));
    camera.setViewTransform(IsometricView); // <-- Jeg tror det er det vi skal bruge til at lave det isometric...
    vec3 eye (camera.getPosition());
    vec3 at (position, -1);
    vec3 up (0, 1, 0);
    camera.lookAt(eye, at, up);

}

void SideScrollingCamera::setFollowObject(std::shared_ptr<GameObject> followObject, glm::vec2 offset) {
    this->followObject = followObject;
    this->offset = offset;
}
