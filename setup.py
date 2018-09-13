import os
import re
import sys
import platform
import subprocess

from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
from distutils.version import LooseVersion


class CMakeExtension( Extension ) :

    def __init__( self, name, sourcedir = '' ) :
        super( CMakeExtension, self ).__init__( name, sources = [] )
        self.sourcedir = os.path.abspath( sourcedir )

class CMakeBuild( build_ext ) :

    def run( self ) :
        try :
            _out = subprocess.check_output( [ 'cmake', '--version' ] )
        except OSError:
            raise RuntimeError( 'CMake is not install, and it is used to build these extensions' )

        for _ext in self.extensions :
            self._buildExtension( _ext )

    def _buildExtension( self, ext ) :
        _extDir = os.path.abspath( os.path.dirname( self.get_ext_fullpath( ext.name ) ) )
        _cmakeArgs = [ '-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=' + _extDir,
                       '-DPYTHON_EXECUTABLE=' + sys.executable ]

        _cfg = 'Debug' if self.debug else 'Release'
        _buildArgs = [ '--config', _cfg ]

        _cmakeArgs += [ '-DCMAKE_BUILD_TYPE=' + _cfg ]

        _env = os.environ.copy()
        _env[ 'CXXFLAGS' ] = '{} -DVERSION_INFO\\"{}\\"'.format( _env.get( 'CXXFLAGS', '' ),
                                                                 self.distribution.get_version() )

        if not os.path.exists( self.build_temp ) :
            os.makedirs( self.build_temp )
        
        subprocess.check_call( [ 'cmake', ext.sourcedir ] + _cmakeArgs, cwd = self.build_temp, env = _env )
        subprocess.check_call( [ 'cmake', '--build', '.' ] + _buildArgs, cwd = self.build_temp )

setup(
    name = 'module3',
    version = '0.0.1',
    author = 'Wilbert Pumacay',
    author_email = 'wpumacay@gmail.com',
    description = 'A testing wrapper for an opengl rendering engine',
    long_description = '',
    ext_modules = [ CMakeExtension( 'module3' ) ],
    cmdclass = dict( build_ext = CMakeBuild ),
    zip_safe = False
)
