
#include <container.h>
#include <pybind11/stl.h>

namespace py = pybind11;

namespace module3
{

    Container::Container( const std::string& name )
        : m_name( name )
    {
        std::cout << "Created Container named: " << m_name << std::endl;
    }

    Container::~Container()
    {
        std::cout << "Destroying (...) container named: " << m_name << std::endl;
        m_elements.clear();
        m_elementsRaw.clear();
        std::cout << "Destroyed Container named: " << m_name << std::endl;
    }

    void bindings_container( py::module& m )
    {
        py::class_< Container >( m, "Container" )
            .def( py::init< const std::string& >() )
            .def( "addElement", &Container::addElement )
            .def( "addElementRaw", &Container::addElementRaw, py::return_value_policy::take_ownership )
            //// .def( "addElement", []( Container* self, std::shared_ptr<Element> elm )
            ////     {
            ////         self->addElement( elm );
            ////     } )
            //// .def( "addElementRaw", []( Container* self, ElementRaw* elm )
            ////     {
            ////         self->addElementRaw( elm );
            ////     } )
            .def( "elements", &Container::elements )
            .def( "elementsRaw", &Container::elementsRaw, py::return_value_policy::reference_internal )
            .def_property_readonly( "name", &Container::name )
            .def( "__repr__", []( const Container& self )
                {
                    return "Container: " + self.name();
                }
            );
    }

}