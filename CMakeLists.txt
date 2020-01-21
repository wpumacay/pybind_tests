cmake_minimum_required( VERSION 3.0.0 )

project( pybind_tests )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fPIC " )

if ( NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY )
    message( "Sending generated libs to OWN build directory" )
    set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/libs" )
else()
    message( "Sending generated libs to USER-DEFINED build directory" )
endif()

add_subdirectory( pybind11 )

# add modules with byndings
add_subdirectory( module1 )
add_subdirectory( module2 )
add_subdirectory( module3 )