#include <iostream>

#include <core/core.h>


#include <engine/engine.h>

#include <engine/file_loading/xml/xml_file.h>
#include <3D/master_renderer_3d.h>

#include <free_camera_3d.h>

using namespace undicht;

    // vertex positions of a cube (source: https://learnopengl.com/code_viewer_gh.php?code=src/1.getting_started/7.4.camera_class/camera_class.cpp)
    const float vertices[] = {
        -0.5f, -0.5f, -1.5f,
         0.5f, -0.5f, -1.5f,
         0.5f,  0.5f, -1.5f,
         0.5f,  0.5f, -1.5f,
        -0.5f,  0.5f, -1.5f,
        -0.5f, -0.5f, -1.5f,

        -0.5f, -0.5f,  1.5f,
         0.5f, -0.5f,  1.5f,
         0.5f,  0.5f,  1.5f,
         0.5f,  0.5f,  1.5f,
        -0.5f,  0.5f,  1.5f,
        -0.5f, -0.5f,  1.5f,

        -0.5f,  0.5f,  1.5f,
        -0.5f,  0.5f, -1.5f,
        -0.5f, -0.5f, -1.5f,
        -0.5f, -0.5f, -1.5f,
        -0.5f, -0.5f,  1.5f,
        -0.5f,  0.5f,  1.5f,

         0.5f,  0.5f,  1.5f,
         0.5f,  0.5f, -1.5f,
         0.5f, -0.5f, -1.5f,
         0.5f, -0.5f, -1.5f,
         0.5f, -0.5f,  1.5f,
         0.5f,  0.5f,  1.5f,

        -0.5f, -0.5f, -1.5f,
         0.5f, -0.5f, -1.5f,
         0.5f, -0.5f,  1.5f,
         0.5f, -0.5f,  1.5f,
        -0.5f, -0.5f,  1.5f,
        -0.5f, -0.5f, -1.5f,

        -0.5f,  0.5f, -1.5f,
         0.5f,  0.5f, -1.5f,
         0.5f,  0.5f,  1.5f,
         0.5f,  0.5f,  1.5f,
        -0.5f,  0.5f,  1.5f,
        -0.5f,  0.5f, -1.5f
    };

    const core::BufferLayout vertex_layout({core::UND_VEC3F});

int main() {

    Engine::initialize("undicht_0.37_engine/default_config.und");

    {

        window::Window* window = Engine::s_main_window;
        window->setTitle("Hello World! powered by undicht 0.37");

        FreeCamera3D cam;
        cam.setRotation(glm::angleAxis(45.0f, glm::vec3(0,1,0)));

        MasterRenderer3D::setSceneCamera(cam);

        Model3D cube;
        cube.getMesh().setLayout(vertex_layout);
        cube.getMesh().setData(vertices, sizeof(vertices));

        cube.addTranslation(glm::vec3(0,-10,0));


        while(!window->shouldClose()) {

            cam.update();

            MasterRenderer3D::newFrame();

            MasterRenderer3D::s_forward_renderer->prepare();
            MasterRenderer3D::s_forward_renderer->drawModel(cube);

            MasterRenderer3D::endFrame();

            window->update();

        }

    }

    Engine::terminate();

}
