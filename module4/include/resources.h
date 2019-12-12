#pragma once

#include <iostream>

#include <base.h>

namespace module4
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

#define MODULE4_RESOURCES_BINDINGS(m) \
    py::class_<module4::Heart>(m, "Heart") \
        .def( "size", &module4::Heart::size ) \
        .def( "owner", &module4::Heart::owner );
