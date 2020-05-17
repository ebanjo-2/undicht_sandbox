#include <iostream>

#include <core/core.h>


#include <engine/engine.h>

#include <engine/file_loading/xml/xml_file.h>
#include <3D/master_renderer_3d.h>

using namespace undicht;

int main() {

    Engine::initialize("undicht_0.37_engine/default_config.und");

    {

        window::Window* window = Engine::s_main_window;
        window->setTitle("Hello World! powered by undicht 0.37");
        window->setWindowMode(true, false);

        while(!window->shouldClose()) {

            MasterRenderer3D::newFrame();

            MasterRenderer3D::endFrame();

            window->update();

        }

    }

    Engine::terminate();

}
