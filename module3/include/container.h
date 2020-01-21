#pragma once

#include <common.h>
#include <element.h>

namespace py = pybind11;

namespace module3
{

    // just some test struct. We're trying to test const auto&, and auto& as returns of pybind11
    struct ContainerData
    {
        std::string version;
        size_t nElements;
    };

    class Container
    {

    public :

        Container( const std::string& name );
        ~Container();

        void addElement( std::shared_ptr<Element> elm ) { m_elements.push_back( elm ); }
        void addElementRaw( ElementRaw* elm ) { m_elementsRaw.push_back( elm ); }
        std::vector< std::shared_ptr<Element> >& elements() { return m_elements; }
        std::vector< ElementRaw* >& elementsRaw() { return m_elementsRaw; }

        std::string name() const { return m_name; }
        ContainerData& data() { return m_data; }
        const ContainerData& data() const { return m_data; }

    private :

        std::string m_name;
        ContainerData m_data;
        std::vector< std::shared_ptr<Element> > m_elements;
        std::vector< ElementRaw* > m_elementsRaw;
    };

    void bindings_container( py::module& m );

}