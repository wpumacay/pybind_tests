
#include <pybind11/pybind11.h>

#include "../include/Window.h"

namespace py = pybind11;

void createWindow()
{
    module2::Window* _window = new module2::Window();
    _window->clear();
    // delete _window;
}

float test( float x )
{
    module2::Window* _window = new module2::Window();
    _window->clear();
    delete _window;

    return x * x;
}

PYBIND11_MODULE(module2, m)
{
    m.def( "createWindow", &createWindow );
    m.def( "test", &test );

    m.attr( "__version__" ) = "dev";
}