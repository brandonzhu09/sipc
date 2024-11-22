# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-src"
  "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-build"
  "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix"
  "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/tmp"
  "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp"
  "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src"
  "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
