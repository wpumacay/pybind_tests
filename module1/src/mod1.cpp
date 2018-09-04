
#include "../include/mod1.h"


namespace module1
{

    float msin( float x )
    {
        std::cout << "wtf?? sin" << std::endl;
        return sin(x);
    }

    float mpow( float a, float b )
    {
        std::cout << "wtf?? pow" << std::endl;
        return pow( a, b );
    }

}