cmake_minimum_required( VERSION 3.0.0 )

project( pybind_tests )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC " )

set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/libs" )

add_subdirectory( pybind11 )
# add external libraries
set( EXT_INCLUDE_DIRECTORIES
	 "${CMAKE_SOURCE_DIR}/ext/glfw/include"
     "${CMAKE_BINARY_DIR}/ext/glad/include"
     "${CMAKE_SOURCE_DIR}/ext/glm" )

# Avoid building the examples in the libraries
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs" )
set( GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs" )
set( GLM_TEST_ENABLE OFF CACHE BOOL "Build unit tests" )

add_subdirectory( ext/glfw )
add_subdirectory( ext/glad )
add_subdirectory( ext/glm )

# add modules with byndings
# add_subdirectory( module1 )
# add_subdirectory( module2 )
add_subdirectory( module4 )
# add_subdirectory( moduleEngineWrapper )
