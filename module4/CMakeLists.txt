
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/include" )

pybind11_add_module( module4
                     src/base.cpp
                     src/derived.cpp
                     mod4_bindings.cpp )