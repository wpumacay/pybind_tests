
#include "../include/Window.h"


namespace module2
{

    Window::Window()
    {
        std::cout << "created new window" << std::endl;
    }

    Window::~Window()
    {

    }

    void Window::clear()
    {
        std::cout << "foo: clear window" << std::endl;
    }

}