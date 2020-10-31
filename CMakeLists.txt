cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

macro(proj PROJNAME PROJTYPE)
    project(${PROJNAME})
    file(GLOB_RECURSE SOURCES "src/${PROJECT_NAME}/*.cpp")
    file(GLOB_RECURSE HEADERS "src/${PROJECT_NAME}/*.hpp")
    if (${PROJTYPE} STREQUAL exe)
        add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
    else ()
        add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
    endif ()
    target_link_libraries(${PROJECT_NAME} PRIVATE ${ARGN})
endmacro()

find_package(SDL2 REQUIRED)

include_directories(vendor/microsoft/GSL/include)

proj(software_3d_engine lib SDL2)
proj(sandbox exe SDL2 software_3d_engine)
target_include_directories(sandbox PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/software_3d_engine)
