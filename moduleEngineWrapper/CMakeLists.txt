
find_package( OpenGL REQUIRED )

include_directories( ${EXT_INCLUDE_DIRECTORIES} )

pybind11_add_module( moduleEngineWrapper
                     src/engine_bindings.cpp )
target_link_libraries( moduleEngineWrapper PRIVATE 
                       gengine )