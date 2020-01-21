
#include <common.h>
#include <element.h>
#include <container.h>

namespace py = pybind11;

PYBIND11_MODULE( module3, m )
{
    m.doc() = R"pbdoc(
        Bindings for sample module 3
    )pbdoc";

    // element bindings
    module3::bindings_element( m );
    // container bindings
    module3::bindings_container( m );
}