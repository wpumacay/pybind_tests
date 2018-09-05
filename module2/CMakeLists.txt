
find_package( OpenGL REQUIRED )


pybind11_add_module( module2
                     src/Window.cpp
                     src/mod2_binding.cpp )
target_link_libraries( module2 PRIVATE
                       ${OPENGL_LIBRARIES}
                       glfw )