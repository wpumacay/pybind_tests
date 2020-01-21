#pragma once

#include <base.h>

namespace py = pybind11;

namespace module2
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

#define MODULE2_DERIVED_BINDINGS(m) \
    py::class_<module2::Duck, module2::Animal>(m, "Duck") \
        .def( py::init<const std::string&, size_t>() ) \
        .def( "quack", &module2::Duck::quack ) \
        .def( "nfeathers", &module2::Duck::nfeathers );\
    py::class_<module2::Dog, module2::Animal>(m, "Dog") \
        .def( py::init<const std::string&, size_t>() ) \
        .def( "bark", &module2::Dog::bark ) \
        .def( "nfleas", &module2::Dog::nfleas );
