
#include <pybind11/pybind11.h>

#include "../include/mod1.h"


namespace py = pybind11;

PYBIND11_MODULE(module1, m)
{

    m.doc() = R"pbdoc(
        Bindings for sample module 1
    )pbdoc";

    m.def( "msin", &module1::msin );
    m.def( "mpow", &module1::mpow );

    m.attr( "__version__" ) = "dev";

}