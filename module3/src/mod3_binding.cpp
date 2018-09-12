
#include <pybind11/pybind11.h>

#include <LApp.h>

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
}


void update()
{
    auto _app = engine::LApp::GetInstance();
    _app->update();
}


MeshWrapper* addMesh()
{
    auto _app = engine::LApp::GetInstance();
    auto _scene = _app->getCurrentScene();

    auto _mesh = engine::LMeshBuilder::createBox( 0.5f, 0.5f, 0.5f );
    _scene->addRenderable( _mesh );

    auto _meshWrapper = new MeshWrapper();
    _meshWrapper->setMeshReference( _mesh );

    return _meshWrapper;
}

PYBIND11_MODULE( module3, m )
{
    // mesh wrapper
    py::class_<MeshWrapper>( m, "MeshWrapper" )
        .def( py::init<>() )
        .def( "setX", &MeshWrapper::setX )
        .def( "getX", &MeshWrapper::getX );

    m.def( "init", &init );
    m.def( "render", &render );
    m.def( "addMesh", &addMesh, return_value_policy::automatic );

    m.attr( "__version__" ) = "dev";
}