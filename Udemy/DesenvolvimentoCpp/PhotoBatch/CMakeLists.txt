cmake_minimum_required(VERSION 3.12)

project(PhotoBatch)

option(_BUILD_TESTS "build the tests" OFF)

# verificar debug vs release mode
if(GENERATOR_IS_MULTI_CONFIG)
    message("Using a multi configuration generator")
else()
    message("Using a single configuration generator")
endif()

file(GLOB photobatch_sources
    "${PROJECT_SOURCE_DIR}/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(PhotoBatch ${photobatch_sources} )
include_directories("${PROJECT_SOURCE_DIR}/include")

set_target_properties(PhotoBatch PROPERTIES CXX_STANDARD 17)

set(FETCHCONTENT_QUIET OFF CACHE BOOL "Desabilita o modo quiet do FetchContent" FORCE)
include(FetchContent)

add_subdirectory(external)
target_link_libraries(PhotoBatch PRIVATE stb)

if(_BUILD_TESTS)
    add_subdirectory(tests)
endif()
