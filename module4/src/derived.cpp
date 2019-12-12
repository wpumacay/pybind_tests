
#include <derived.h>

namespace module4
{

    Duck::Duck( const std::string& name,
                size_t numOfFeathers )
        : Animal( name )
    {
        m_nlegs = 2;
        m_nfeathers = numOfFeathers;
    }

    Duck::~Duck()
    {
        std::cout << "Duck> destroying object" << std::endl;
    }

    std::string Duck::toString() const
    {
        std::string _strrep = Animal::toString();

        _strrep += std::string( "nfeathers  : " ) + std::to_string( m_nfeathers ) + "\n\r";

        return _strrep;
    }

    Dog::Dog( const std::string& name,
              size_t numOfFleas )
        : Animal( name )
    {
        m_nlegs = 4;
        m_nfleas = numOfFleas;
    }

    Dog::~Dog()
    {
        std::cout << "Dog> destroying object" << std::endl;
    }

    std::string Dog::toString() const
    {
        std::string _strrep = Animal::toString();

        _strrep += std::string( "nfleas     : " ) + std::to_string( m_nfleas ) + "\n\r";

        return _strrep;
    }

}