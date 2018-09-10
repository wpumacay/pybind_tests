
#include "../include/Window.h"


namespace module2
{

    Window* Window::INSTANCE = NULL;

    Window::Window()
    {
        if ( Window::INSTANCE != NULL )
        {
            delete Window::INSTANCE;
        }

        Window::INSTANCE = this;

        glfwInit();
        glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
        glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
        glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
        glfwWindowHint( GLFW_RESIZABLE, 0 );

        m_glfwWindowHandle = glfwCreateWindow( 800, 600, "Window", NULL, NULL );

        if ( m_glfwWindowHandle == NULL )
        {
            std::cout << "ERROR: Could not initialize glfw" << std::endl;
            m_initialized = false;
            glfwTerminate();
            return;
        }

        glfwMakeContextCurrent( m_glfwWindowHandle );

        if ( !gladLoadGLLoader( (GLADloadproc) glfwGetProcAddress ) )
        {
            std::cout << "ERROR: Could not initialize glad" << std::endl;
            m_initialized = false;
            glfwTerminate();
            return;
        }

        glfwGetFramebufferSize( m_glfwWindowHandle, &m_width, &m_height );
        glViewport( 0, 0, m_width, m_height );

        glEnable( GL_DEPTH_TEST );
        glClearColor( 0.6f, 0.659f, 0.690f, 1.0f );

        m_initialized = true;
        std::cout << "LOG: finished initializing glfw window" << std::endl;
    }

    Window::~Window()
    {
        m_glfwWindowHandle = NULL;
        Window::INSTANCE = NULL;
        glfwTerminate();
    }

    void Window::clear()
    {
        std::cout << "foo: clear window" << std::endl;
    }

}