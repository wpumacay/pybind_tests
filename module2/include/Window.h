
#pragma once

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace module2
{

    class Window
    {

        private :

        GLFWwindow* m_glfwWindowHandle;
        int m_width;
        int m_height;
        bool m_initialized;

        public :

        static Window* INSTANCE;

        Window();
        ~Window();

        void clear();

    };


}