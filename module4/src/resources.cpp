
#include <resources.h>

namespace module4
{

    Heart::Heart( Animal* owner, float size )
        : m_owner( owner ), m_size( size )
    {
        // nothing extra to do here
    }

    Heart::~Heart()
    {
        //// m_owner = nullptr; // must not set nullptr, it seems under the hood they're shared ptrs
        std::cout << "Heart> destroyed (" << m_owner->name() << ")'s heart :(" << std::endl;
    }

}