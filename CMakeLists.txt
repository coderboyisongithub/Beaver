cmake_minimum_required(VERSION 3.13)
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
   

endif()

# Add the executable
add_executable(Beaver
    Beaver/Source.cpp
)
target_include_directories(Beaver PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Beaver
)


# Apply compile options based on build type
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(Beaver PRIVATE -O3)
    message("SELECTING RELEASE MODE BUILD/COMPILE")
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(Beaver PRIVATE -DDEBUG)
    message("SELECTING DEBUG MODE BUILD/COMPILE")
endif()



# Google test
enable_testing()
FetchContent_MakeAvailable(googletest)
add_executable(DAG_ValidpathTest DAG-validPathtest/test.cpp
    )
target_link_libraries(
  DAG_ValidpathTest
  GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(DAG_ValidpathTest)

