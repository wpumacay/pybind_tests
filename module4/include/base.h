#pragma once

#include <pybind11/pybind11.h>
#include <iostream>
#include <string>

namespace py = pybind11;

namespace module4
{

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

    protected :

        std::string m_name;
        size_t m_nlegs;

        float m_position;

    };

}

#define MODULE4_BASE_BINDINGS(m) \
    py::class_<module4::Animal>(m, "Animal") \
        .def_property( "position", &module4::Animal::getPosition, &module4::Animal::setPosition ) \
        .def_property_readonly( "name", &module4::Animal::name ) \
        .def( "nlegs", &module4::Animal::nlegs ) \
        .def( "toString", &module4::Animal::toString );
