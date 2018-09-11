
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

        static Window* INSTANCE;
        Window();

        public :

        static Window* getInstance();
        ~Window();

        void clear() { glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); }
        void pollEvents() { glfwPollEvents(); }
        void swapBuffers() { glfwSwapBuffers( m_glfwWindowHandle ); }
        bool isActive() { return glfwWindowShouldClose( m_glfwWindowHandle ) == 0; }
        bool isInitialized() { return m_initialized; }

        int width() { return m_width; }
        int height() { return m_height; }

        void render();

        static void onKeyCallback( GLFWwindow* pWindow, int key,
                                   int scancode, int action, int mode );
        static void onMouseCallback( GLFWwindow* pWindow, int button,
                                     int action, int mode );

    };


}