# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp/antlr-populate-gitclone-lastrun.txt" AND EXISTS "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp/antlr-populate-gitinfo.txt" AND
  "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp/antlr-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp/antlr-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp/antlr-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/sw/ubuntu-22.04/git/current/bin/git"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/antlr/antlr4" "antlr-src"
    WORKING_DIRECTORY "/u/jnt6mq/sipc-brandon_zhu/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/antlr/antlr4'")
endif()

execute_process(
  COMMAND "/sw/ubuntu-22.04/git/current/bin/git"
          checkout "4.13.1" --
  WORKING_DIRECTORY "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '4.13.1'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/sw/ubuntu-22.04/git/current/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp/antlr-populate-gitinfo.txt" "/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp/antlr-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/u/jnt6mq/sipc-brandon_zhu/_deps/antlr-subbuild/antlr-populate-prefix/src/antlr-populate-stamp/antlr-populate-gitclone-lastrun.txt'")
endif()
