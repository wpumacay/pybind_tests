
include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/include" )

pybind11_add_module( module2
                     src/resources.cpp
                     src/base.cpp
                     src/derived.cpp
                     mod2_bindings.cpp )