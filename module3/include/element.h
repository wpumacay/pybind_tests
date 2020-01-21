#pragma once

#include <common.h>

namespace py = pybind11;

namespace module3
{

    class Element
    {

    public :

        Element( const std::string& name );
        ~Element();

        std::string name() const { return m_name; }

    private :

        std::string m_name;

    };

    class ElementRaw
    {

    public :

        ElementRaw( const std::string& name );
        ~ElementRaw();

        std::string name() const { return m_name; }

    private :

        std::string m_name;

    };

    void bindings_element( py::module& m );

}
