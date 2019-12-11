
#include <pybind11/pybind11.h>

#include <base.h>
#include <derived.h>

namespace py = pybind11;

PYBIND11_MODULE(module4, m)
{
    m.doc() = R"pbdoc(
        Bindings for sample module 4
    )pbdoc";

    // base-class bindings
    MODULE4_BASE_BINDINGS( m );

    // derived class bindings
    MODULE4_DERIVED_BINDINGS( m );

    m.attr( "__version__" ) = "dev";
}