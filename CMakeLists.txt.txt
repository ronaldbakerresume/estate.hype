cmake_minimum_required(VERSION 3.10)
project(EstateHype VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp
    src/api_integration.cpp
)

add_executable(EstateHype ${SOURCES})

find_package(Threads REQUIRED)
find_package(CURL REQUIRED)
find_package(pybind11 REQUIRED)

target_link_libraries(EstateHype PRIVATE Threads::Threads CURL::libcurl)

pybind11_add_module(estatehype bindings/estatehype_bindings.cpp ${SOURCES})
