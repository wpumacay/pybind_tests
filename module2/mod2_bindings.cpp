
#include <pybind11/pybind11.h>

#include <resources.h>
#include <base.h>
#include <derived.h>

namespace py = pybind11;

PYBIND11_MODULE(module2, m)
{
    m.doc() = R"pbdoc(
        Bindings for sample module 2
    )pbdoc";

    // resources bindings
    MODULE2_RESOURCES_BINDINGS( m );

    // base-class bindings
    MODULE2_BASE_BINDINGS( m );

    // derived class bindings
    MODULE2_DERIVED_BINDINGS( m );

    m.attr( "__version__" ) = "dev";
}