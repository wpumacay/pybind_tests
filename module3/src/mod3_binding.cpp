
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include <cstdlib>

#include <LApp.h>
#include <LMeshBuilder.h>

namespace py = pybind11;

class MeshWrapper
{
    private :

    engine::LMesh* m_meshRef;

    public :

    MeshWrapper()
    {
        m_meshRef = NULL;
    }

    ~MeshWrapper()
    {
        std::cout << "LOG> Deleting meshwrapper object" << std::endl;
        // TODO: Should set to awaiting delete ...
        // or something similar in order to be handled ...
        // by the engine itself. Right now it's leaky
        m_meshRef = NULL;
    }

    void setMeshReference( engine::LMesh* pMesh )
    {
        m_meshRef = pMesh;
    }

    void setX( float x ) 
    { 
        m_meshRef->pos.x = x;
    }
    float getX() 
    { 
        return m_meshRef->pos.x; 
    }
};

void init()
{
    auto _app = engine::LApp::GetInstance();
    auto _scene = _app->scene();

    // make a sample camera
    auto _camera = new engine::LFpsCamera( engine::LVec3( 1.0f, 2.0f, -1.0f ),
                                           engine::LVec3( 0.0f, 1.0f, 0.0f ) );
    // make a sample light source
    auto _light = new engine::LLightDirectional( engine::LVec3( 0.2, 0.2, 0.2 ), engine::LVec3( 0.8, 0.8, 0.8 ),
                                                 engine::LVec3( 0.05, 0.05, 0.05 ), 0, engine::LVec3( -1, -1, 0 ) );

    // add these components to the scene
    _scene->addCamera( _camera );
    _scene->addLight( _light );
}


void update()
{
    auto _app = engine::LApp::GetInstance();
    _app->update();
}

bool isActive()
{
    auto _app = engine::LApp::GetInstance();
    return _app->isActive();
}

MeshWrapper* addMesh()
{
    auto _app = engine::LApp::GetInstance();
    auto _scene = _app->scene();

    auto _mesh = engine::LMeshBuilder::createBox( 0.5f, 0.5f, 0.5f );
    _scene->addRenderable( _mesh );

    auto _meshWrapper = new MeshWrapper();
    _meshWrapper->setMeshReference( _mesh );

    return _meshWrapper;
}

void testNumpyArray1( py::array_t<float> pArray )
{
    py::buffer_info _buff = pArray.request();
    std::cout << "ndim: " << _buff.ndim << std::endl;
    std::cout << "size: " << _buff.size << std::endl;
    std::cout << "shape: " << _buff.shape.size() << std::endl;

    if ( _buff.ndim != 1 )
    {
        std::cout << "WARNING> should pass 1d array" << std::endl;
        return;
    }

    std::cout << "data ************" << std::endl;
    float* _ptr = ( float* ) _buff.ptr;
    std::cout << "[ ";
    for ( size_t i = 0; i < _buff.shape[0]; i++ )
    {
        std::cout << _ptr[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "****************" << std::endl;
}

#define TEST_SIZE 3

py::array_t<float> testNumpyArray2()
{
    auto _result = py::array_t<float>( TEST_SIZE );
    auto _buffer = _result.request();

    auto _ptr = ( float* ) _buffer.ptr;

    for ( size_t i = 0; i < _buffer.shape[0]; i++ )
    {
        _ptr[i] = ( ( (float) rand() ) / RAND_MAX );
    }

    return _result;
}

PYBIND11_MODULE( module3, m )
{
    // mesh wrapper
    py::class_<MeshWrapper>( m, "MeshWrapper" )
        .def( py::init<>() )
        .def( "setX", &MeshWrapper::setX )
        .def( "getX", &MeshWrapper::getX );

    m.def( "init", &init );
    m.def( "update", &update );
    m.def( "isActive", &isActive );
    m.def( "addMesh", &addMesh, py::return_value_policy::automatic );

    m.def( "testNumpyArray1", &testNumpyArray1 );
    m.def( "testNumpyArray2", &testNumpyArray2 );

    m.attr( "__version__" ) = "dev";
}