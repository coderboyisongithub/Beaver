cmake_minimum_required(VERSION 4.0)
project(Beaver)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Set C++ Standard
if(LINUX)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
elseif(APPLE)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
else()
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

endif()


# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
    set(CMAKE_CXX_FLAGS_RELEASE O2)
endif()

# Add the executable
add_executable(Beaver
    Beaver/Source.cpp
)

target_compile_options(Beaver PRIVATE -w)

target_include_directories(Beaver PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Beaver
)



# Google test
enable_testing()
add_executable(DAG_ValidpathTest DAG-validPathtest/test.cpp
    )
target_link_libraries(
  DAG_ValidpathTest
  GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(DAG_ValidpathTest)

