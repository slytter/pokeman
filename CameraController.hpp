#pragma once

#include "sre/Camera.hpp"
#include "glm/glm.hpp"
#include "Component.hpp"

class CameraController : public Component {
public:
    explicit CameraController(GameObject *gameObject);
    glm::vec3 camRotation;
    void update(float deltaTime) override;
    void setFollowObject(std::shared_ptr<GameObject> followObject, glm::vec2 offset);
    sre::Camera& getCamera();
    glm::mat4 cameraOriMat4;
    bool onKey(SDL_Event &event) override;
    glm::vec2 getCameraPos (glm::vec3 _ObjectPos);
    float lerpTime = 0.0f;
    float lerpSpeed = 0.0f;
private:
    glm::mat4 IsometricView;
    sre::Camera camera;
    std::shared_ptr<GameObject> followObject;
    glm::vec2 offset;
};

