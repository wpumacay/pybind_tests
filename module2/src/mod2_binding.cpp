
#include <pybind11/pybind11.h>

#include "../include/Window.h"

namespace py = pybind11;

void createWindow()
{
    auto _window = module2::Window::getInstance();
}

float test( float x )
{
    std::cout << "jojojojojo" << std::endl;
}

void render()
{
    auto _window = module2::Window::getInstance();

    _window->clear();
    _window->pollEvents();

    _window->render();

    _window->swapBuffers();
}

PYBIND11_MODULE(module2, m)
{
    m.def( "createWindow", &createWindow );
    m.def( "test", &test );
    m.def( "render", &render );

    m.attr( "__version__" ) = "dev";
}