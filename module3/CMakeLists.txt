
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/include" )

pybind11_add_module( module3
                     src/container.cpp
                     src/element.cpp
                     mod3_bindings.cpp )