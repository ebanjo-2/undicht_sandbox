#include "free_camera_3d.h"
#include <glm/glm/glm.hpp>

using namespace undicht;
using namespace undicht::window;

FreeCamera3D::FreeCamera3D() {
    //ctor

    m_key_input.setWindow(Engine::s_main_window);
    m_mouse_input.setWindow(Engine::s_main_window);
}

FreeCamera3D::~FreeCamera3D() {
    //dtor
}


void FreeCamera3D::update() {

    //std::cout << getViewDirection().x << " " << getViewDirection().y << " " << getViewDirection().z << "\n";

    m_mouse_input.updateCursorOffset();

    // hiding / showing the cursor
    if(m_key_input.getKeyState(UND_KEY_E)) {

        Engine::s_main_window->setCursorVisible(true);

    } else {

        Engine::s_main_window->setCursorVisible(false);

        // moving
        if(m_key_input.getKeyState(UND_KEY_LSHIFT)) {

            m_movement_speed = 0.01;
        } else {
            m_movement_speed = 0.001f;
        }

        if(m_key_input.getKeyState(UND_KEY_S)) {

            addTranslation(-1.0f * getViewDirection() * m_movement_speed);
        }

        if(m_key_input.getKeyState(UND_KEY_W)) {

            addTranslation(getViewDirection() * m_movement_speed);
        }

        if(m_key_input.getKeyState(UND_KEY_A)) {

            addTranslation(-1.0f * glm::normalize(glm::cross(getViewDirection(), glm::vec3(0,1,0))) * m_movement_speed);
        }

        if(m_key_input.getKeyState(UND_KEY_D)) {

            addTranslation(glm::normalize(glm::cross(getViewDirection(), glm::vec3(0,1,0))) * m_movement_speed);
        }

        // changing view direction
        float offset_x, offset_y;
        m_mouse_input.getCursorOffset(offset_x, offset_y);

        // trying to avoid gimbal lock
        glm::vec3 view_dir = getViewDirection();
        if(((offset_y > 0) && (view_dir.y > 0.99)) || ((offset_y < 0) && (view_dir.y < -0.99))) {
            // no rotating any further
            offset_y = 0;
        }

        // adding pitch
        glm::vec3 pitch_axis = glm::normalize(glm::cross(getViewDirection(), glm::vec3(0,1,0)));
        glm::quat rotation = glm::angleAxis(offset_y * m_mouse_speed, pitch_axis) * getRotation();

        // adding yaw
        rotation = glm::angleAxis(offset_x * m_mouse_speed * -1.0f, glm::vec3(0,1,0)) * rotation;

        // saving the new rotation
        setRotation(rotation);


    }


}

