
#include <base.h>

namespace module4
{

    Animal::Animal( const std::string& name )
        : m_name( name )
    {
        m_position = 0.0f;
        m_nlegs = 0;
    }

    Animal::~Animal()
    {
        // nothing for now
    }

    std::string Animal::toString() const
    {
        std::string _strrep;

        _strrep += std::string( "name       : " ) + m_name + "\n\r";
        _strrep += std::string( "position   : " ) + std::to_string( m_position ) + "\n\r";
        _strrep += std::string( "nlegs      : " ) + std::to_string( m_nlegs ) + "\n\r";

        return _strrep;
    }

}