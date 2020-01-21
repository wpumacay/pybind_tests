#!/usr/bin/env python

import os
import sys
import subprocess

from setuptools import find_packages, setup, Extension
from setuptools.command.build_ext import build_ext

def buildBindings( sourceDir, buildDir, cmakeArgs, buildArgs, env ):
    if not os.path.exists( buildDir ) :
        os.makedirs( buildDir )

    subprocess.call( ['cmake', sourceDir] + cmakeArgs, cwd=buildDir, env=env )
    subprocess.call( ['cmake', '--build', '.'] + buildArgs, cwd=buildDir )

class CMakeExtension( Extension ) :

    def __init__( self, name, sourceDir ) :
        super( CMakeExtension, self ).__init__( name, sources=[] )
        self.sourceDir = os.path.abspath( sourceDir )

class BuildCommand( build_ext ) :

    def run( self ) :
        try:
            _ = subprocess.check_output( ['cmake', '--version'] )
        except OSError:
            raise RuntimeError( 'CMake must be installed to build the following extensions: ' +
                                ', '.join( e.name for e in self.extensions ) )

        for _extension in self.extensions :
            self.build_extension( _extension )

    def build_extension( self, extension ) :
        _extensionFullPath = self.get_ext_fullpath( extension.name )
        _extensionDirName = os.path.dirname( _extensionFullPath )
        _extensionDirPath = os.path.abspath( _extensionDirName )

        _cfg = 'Debug' if self.debug else 'Release'
        _buildArgs = ['--config', _cfg, '--', '-j4']
        _cmakeArgs = ['-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=' + _extensionDirPath,
                      '-DPYTHON_EXECUTABLE=' + sys.executable,
                      '-DCMAKE_BUILD_TYPE=' + _cfg]

        _env = os.environ.copy()
        _env['CXXFLAGS'] = '{} -DVERSION_INFO=\\"{}\\"'.format( _env.get( 'CXXFLAGS', '' ),
                                                                self.distribution.get_version() )

        _sourceDir = extension.sourceDir
        _buildDir = self.build_temp

        buildBindings( _sourceDir, _buildDir, _cmakeArgs, _buildArgs, _env )

setup(
    name                    = 'pybind_tests',
    version                 = '0.0.1',
    description             = 'Sample modules that use pybind11',
    author                  = 'Wilbert Santos Pumacay Huallpa',
    license                 = 'MIT License',
    author_email            = 'wpumacay@gmail.com',
    url                     = 'https://github.com/wpumacay/pybind_tests',
    keywords                = 'pybind11',
    packages                = find_packages(),
    zip_safe                = False,
    install_requires        = [
                                'setuptools'
                              ],
    package_data            = {},
    ext_modules             = [
                                CMakeExtension( 'modules', '.' )
                              ],
    cmdclass                = {
                                'build_ext': BuildCommand
                              }
)