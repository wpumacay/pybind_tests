#pragma once

#include <iostream>

#include <base.h>

namespace module2
{

    class Animal;

    class Heart
    {

    public :

        Heart( Animal* owner, float size );
        ~Heart();

        Animal* owner() const { return m_owner; }
        float size() const { return m_size; }

    private :

        Animal* m_owner;
        float m_size;
    };

}

#define MODULE2_RESOURCES_BINDINGS(m) \
    py::class_<module2::Heart>(m, "Heart") \
        .def( "size", &module2::Heart::size ) \
        .def( "owner", &module2::Heart::owner );
