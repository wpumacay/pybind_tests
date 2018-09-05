cmake_minimum_required( VERSION 3.0.0 )

project( pybind_tests )

add_subdirectory( pybind11 )
# add external libraries
add_subdirectory( ext/glfw )
# add modules with byndings
add_subdirectory( module1 )
add_subdirectory( module2 )