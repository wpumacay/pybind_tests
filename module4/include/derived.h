#pragma once

#include <base.h>

namespace py = pybind11;

namespace module4
{

    class Duck : public Animal
    {

    public :

        Duck( const std::string& name,
              size_t numOfFeathers );

        ~Duck();

        void quack() const { std::cout << "Quack!!!, I'm " << m_name << std::endl; }

        size_t nfeathers() const { return m_nfeathers; }

        std::string toString() const override;

    private :

        size_t m_nfeathers;

    };

    class Dog : public Animal
    {

    public :

        Dog( const std::string& name,
             size_t numOfFleas );

        ~Dog();

        void bark() const { std::cout << "Wooff!!!, I'm " << m_name << std::endl; }

        size_t nfleas() const { return m_nfleas; }

        std::string toString() const override;

    private :

        size_t m_nfleas;

    };

}

#define MODULE4_DERIVED_BINDINGS(m) \
    py::class_<module4::Duck, module4::Animal>(m, "Duck") \
        .def( py::init<const std::string&, size_t>() ) \
        .def( "quack", &module4::Duck::quack ) \
        .def( "nfeathers", &module4::Duck::nfeathers );\
    py::class_<module4::Dog, module4::Animal>(m, "Dog") \
        .def( py::init<const std::string&, size_t>() ) \
        .def( "bark", &module4::Dog::bark ) \
        .def( "nfleas", &module4::Dog::nfleas );
