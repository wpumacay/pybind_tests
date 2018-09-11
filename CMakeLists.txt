cmake_minimum_required( VERSION 3.0.0 )

project( pybind_tests )

add_subdirectory( pybind11 )
# add external libraries
add_subdirectory( ext/glfw )
add_subdirectory( ext/glad )
add_subdirectory( ext/glm )

set( EXT_INCLUDE_DIRECTORIES
	 "${CMAKE_SOURCE_DIR}/ext/glfw/include"
     "${CMAKE_BINARY_DIR}/ext/glad/include"
     "${CMAKE_SOURCE_DIR}/ext/glm"
     "${CMAKE_SOURCE_DIR}/ext/cat1/include" )

# add modules with byndings
add_subdirectory( module1 )
add_subdirectory( module2 )
# add_subdirectory( module3 )
