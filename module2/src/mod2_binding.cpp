
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

class Wrapper
{

    private :

    void* m_ref;

    public :

    Wrapper()
    {
        m_ref = new float;
    }

    ~Wrapper()
    {
        m_ref = NULL;
    }

    void setValue( float x )
    {
        *( reinterpret_cast<float*>( m_ref ) ) = x;
    }

    float getValue()
    {
        return *( reinterpret_cast<float*>( m_ref ) );
    }
};

PYBIND11_MODULE(module2, m)
{
    m.def( "createWindow", &createWindow );
    m.def( "test", &test );
    m.def( "render", &render );

    m.attr( "__version__" ) = "dev";

    py::class_<Wrapper>( m, "Wrapper" )
        .def( py::init<>() )
        .def( "setValue", &Wrapper::setValue )
        .def( "getValue", &Wrapper::getValue );
}