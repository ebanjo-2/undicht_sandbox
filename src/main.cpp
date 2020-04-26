#include <iostream>
#include <engine/engine.h>

#include <engine/file_loading/xml/xml_file.h>

using namespace undicht;

int main() {

    Engine::initialize("undicht_0.37_engine/default_config.und");

    {

        window::Window* window = Engine::s_main_window;


        while(!window->shouldClose()) {

            window->update();

        }

    }

    Engine::terminate();

}
