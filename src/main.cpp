#include <iostream>

#include <core/core.h>


#include <engine/engine.h>

#include <engine/file_loading/xml/xml_file.h>
#include <3D/master_renderer_3d.h>

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

        SimpleGeometryGenerator mesh_generator;
        std::vector<float> cube_vertices;
        mesh_generator.genCylinder(cube_vertices, 32, true);

        Model3D cube;
        cube.getMesh().setLayout(core::BufferLayout({core::UND_VEC3F}));
        cube.getMesh().setData(cube_vertices);

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
