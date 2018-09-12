
#include <pybind11/pybind11.h>

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

    m.attr( "__version__" ) = "dev";
}