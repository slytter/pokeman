#pragma once

#include "sre/Camera.hpp"
#include "glm/glm.hpp"
#include "Component.hpp"

class SideScrollingCamera : public Component {
public:
    explicit SideScrollingCamera(GameObject *gameObject);
    glm::vec2 camRotation;
    void update(float deltaTime) override;
    void setFollowObject(std::shared_ptr<GameObject> followObject, glm::vec2 offset);
    sre::Camera& getCamera();
    glm::mat4 cameraOriMat4;
private:
    glm::mat4 IsometricView;
    sre::Camera camera;
    std::shared_ptr<GameObject> followObject;
    glm::vec2 offset;
};

