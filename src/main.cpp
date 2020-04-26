#include <iostream>
#include <engine/engine.h>

#include <engine/file_loading/xml/xml_file.h>

using namespace undicht;

int main() {

    Engine::initialize();

    {

        window::Window* window = Engine::s_main_window;

        // testing xml file loading
        XmlFile file("res/SupertuxTex.dae");


        std::vector<const XmlElement*> elements = file.getAllElements({"COLLADA", "library_effects", "effect", "profile_COMMON", "newparam sid=\"Tux_jpg-surface\""});

        for(const XmlElement* elem : elements) {

            elem->printRecursive();
        }

        while(!window->shouldClose()) {

            window->update();

        }

    }

    Engine::terminate();

}
