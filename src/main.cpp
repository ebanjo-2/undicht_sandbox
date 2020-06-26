#include <iostream>

#include <core/core.h>


#include <engine/engine.h>

#include <engine/file_loading/xml/xml_file.h>
#include <3D/master_renderer_3d.h>
#include <3D/file_loading/collada/collada_file.h>

#include <free_camera_3d.h>

#include <graphics/simple_geometry_generator.h>

using namespace undicht;

int main() {

    Engine::initialize("undicht_0.37_engine/default_config.und");

    {

        window::Window* window = Engine::s_main_window;
        window->setTitle("Hello World! powered by undicht 0.37");

        FreeCamera3D cam;
        cam.setRotation(glm::angleAxis(45.0f, glm::vec3(0,1,0)));

        MasterRenderer3D::setSceneCamera(cam);

        Model3D tux;
        ColladaFile model_file("res/sponza_collada/sponza.dae");
        model_file.loadModel(tux);

        model_file.open("res/SupertuxTex.dae");
        model_file.loadModel(tux);

        double start_time;

        while(!window->shouldClose()) {


            cam.update();

            MasterRenderer3D::newFrame();

            MasterRenderer3D::s_forward_renderer->prepare();
            MasterRenderer3D::s_forward_renderer->drawModel(tux);

            MasterRenderer3D::endFrame();


            window->update();

            std::cout << "fps: " << 1 / (core::Core::getTime() - start_time) << "\n";
            start_time = core::Core::getTime();

        }

    }

    Engine::terminate();

}
