#ifndef FREE_CAMERA_3D_H
#define FREE_CAMERA_3D_H


#include <3D/entities/perspective_camera_3d.h>
#include <engine/engine.h>
#include <window/key_input_watcher.h>
#include <window/mouse_input_watcher.h>


class FreeCamera3D : public undicht::PerspectiveCamera3D {
    /** a camera that can be controlled by mouse and keyboard */
    public:

        float m_movement_speed = 0.001f;
        float m_mouse_speed = 100.0f;

        undicht::window::KeyInputWatcher m_key_input;
        undicht::window::MouseInputWatcher m_mouse_input;


        void update();

        FreeCamera3D();
        virtual ~FreeCamera3D();


};

#endif // FREE_CAMERA_3D_H
