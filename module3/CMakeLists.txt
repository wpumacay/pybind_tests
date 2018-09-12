
find_package( OpenGL REQUIRED )

include_directories( ${EXT_INCLUDE_DIRECTORIES} )

pybind11_add_module( module3
                     src/mod3_binding.cpp )
target_link_libraries( module2 PRIVATE 
                       gengine )