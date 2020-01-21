#pragma once

#include <common.h>
#include <element.h>

namespace py = pybind11;

namespace module3
{

    class Keeper
    {

    public :

        Keeper( const std::string& name );
        ~Keeper();

        void addElement( std::unique_ptr<Element> elm );
        std::vector< std::unique_ptr<Element> >& elements() { return m_elements; }

        std::string name() const { return m_name; }

    private :

        std::string m_name;
        std::vector< std::unique_ptr<Element> > m_elements;
    };

    void bindings_container( py::module& m );

}