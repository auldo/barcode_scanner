cmake_minimum_required(VERSION 3.14)
project(auldo_bs)

#CPP Version
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Include Dirs
include_directories(include ${ROOT_INCLUDE_DIRS})

#Compile Files
set(COMPILE_MAIN src/util/get_version.cpp)
set(COMPILE_PLAYGROUND tests/playground.cpp)
set(COMPILE_TESTS tests/tests.cpp)

#Main Library
add_library(auldo_bs_lib STATIC ${COMPILE_MAIN})

# Fetch Testing Framework
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

#Enable Tests
enable_testing()
add_executable(auldo_bs_tests ${COMPILE_TESTS})
target_link_libraries(auldo_bs_tests auldo_bs_lib)
target_link_libraries(auldo_bs_tests GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(auldo_bs_tests)

#Enable Playground
add_executable(auldo_bs_playground ${COMPILE_PLAYGROUND})
target_link_libraries(auldo_bs_playground auldo_bs_lib)