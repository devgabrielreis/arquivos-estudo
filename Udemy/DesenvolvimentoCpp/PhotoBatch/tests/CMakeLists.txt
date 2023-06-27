set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

add_executable(TestArgumentParser
    "TestArgumentParser.cpp"
    "${CMAKE_SOURCE_DIR}/src/ArgumentParser.cpp"
    "${CMAKE_SOURCE_DIR}/src/utils.cpp"
)

target_include_directories(TestArgumentParser PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(TestArgumentParser PRIVATE gtest_main)
