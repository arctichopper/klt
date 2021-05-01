# Prevent re-execution
include_guard( GLOBAL )

# CMakeLists test
cmake_minimum_required( VERSION 3.5 )

# Set debug option (comment for release builds)
set(CMAKE_BUILD_TYPE Debug)

# Create a project
project( klt_alg VERSION 1.0.0 LANGUAGES CXX )

# Use debug symbols (search for a fancier way to do it)
# Or can also set it while running cmake command, passing arguments -DCMAKE_BUILD_TYPE=RelWithDebInfo
# (release version) or -DCMAKE_BUILD_TYPE=Debug (no optimized version)
#! set( CMAKE_BUILD_TYPE Debug )

# Search for all sources in "src" dir and stores in TEST_SRCS variable
file( GLOB PROJ_SRCS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp" )

# Create a library using sources and add include directories
# add_library( teststudy STATIC ${TEST_SRCS} )

# For more info: https://pabloariasal.github.io/2018/02/19/its-time-to-do-cmake-right/ (also see official docs)
#     Build Interface are used for build purposes using an external main function (like in this example)
#     Install Interface uses relative paths and are interpreted relative to the installation prefix like:
#        <prefix>/include/mylib
# target_include_directories( teststudy
#    PUBLIC
#       $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/inc>
#       $<INSTALL_INTERFACE:inc>
# )

# Conan packages integration
include( ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake )
conan_basic_setup( TARGETS )

# Create executable of name "TestProg" for the main function source file
add_executable( klt_alg main.cpp ${PROJ_SRCS} )

# Include directory to executable
target_include_directories( klt_alg
   PUBLIC
      $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/inc>
      $<INSTALL_INTERFACE:inc>
)

# Add compile options
target_compile_options( klt_alg PRIVATE -Werror )

# Modern way to set the standard version
target_compile_features( klt_alg PRIVATE cxx_std_17 )

# Link lib targets to the executable target
target_link_libraries( klt_alg CONAN_PKG::libpng CONAN_PKG::libjpeg CONAN_PKG::boost CONAN_PKG::eigen )

# Extra: add tests
enable_testing()
include( ${CMAKE_CURRENT_LIST_DIR}/test/CMakeLists.txt )
