#pragma once

#include <pybind11/pybind11.h>
#include <iostream>
#include <string>

#include <memory>
#include <resources.h>

namespace py = pybind11;

namespace module2
{

    class Heart;

    class Animal
    {

    public :

        Animal( const std::string& name );

        virtual ~Animal();

        void setPosition( float position ) { m_position = position; }
        float getPosition() const { return m_position; }

        std::string name() const { return m_name; }
        size_t nlegs() const { return m_nlegs; }

        virtual std::string toString() const;

        Heart* heart() const { return m_heart.get(); }

    protected :

        std::string m_name;
        size_t m_nlegs;
        float m_position;

        std::unique_ptr< Heart> m_heart;

    };

}

#define MODULE2_BASE_BINDINGS(m) \
    py::class_<module2::Animal>(m, "Animal") \
        .def_property( "position", &module2::Animal::getPosition, &module2::Animal::setPosition ) \
        .def_property_readonly( "name", &module2::Animal::name ) \
        .def( "nlegs", &module2::Animal::nlegs ) \
        .def( "toString", &module2::Animal::toString )\
        .def( "heart", &module2::Animal::heart, py::return_value_policy::reference );
