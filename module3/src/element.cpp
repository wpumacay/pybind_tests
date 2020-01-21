
#include <element.h>

namespace py = pybind11;

namespace module3
{

    Element::Element( const std::string& name )
        : m_name( name )
    {
        std::cout << "Created Element named: " << m_name << std::endl;
    }

    Element::~Element()
    {
        std::cout << "Destroyed Element named: " << m_name << std::endl;
    }


    ElementRaw::ElementRaw( const std::string& name )
        : m_name( name )
    {
        std::cout << "Created ElementRaw named: " << m_name << std::endl;
    }

    ElementRaw::~ElementRaw()
    {
        std::cout << "Destroyed ElementRaw named: " << m_name << std::endl;
    }

    void bindings_element( py::module& m )
    {
        py::class_< Element, std::shared_ptr<Element> >( m, "Element" )
            .def( py::init<const std::string&>() )
            .def_property_readonly( "name", &Element::name )
            .def( "__repr__", []( const Element& self )
                {
                    return "Element: " + self.name();
                }
            );

        py::class_< ElementRaw >( m, "ElementRaw" )
            .def( py::init<const std::string&>() )
            .def_property_readonly( "name", &ElementRaw::name )
            .def( "__repr__", []( const ElementRaw& self )
                {
                    return "ElementRaw: " + self.name();
                }
            );
    }

}