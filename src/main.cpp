#include <iostream>
#include <engine/engine.h>

int main() {

    undicht::Engine::initialize();

    undicht::window::Window* window = undicht::Engine::s_main_window;

    while(!window->shouldClose()) {

        window->update();

    }

    undicht::Engine::terminate();

}
