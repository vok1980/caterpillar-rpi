cmake_minimum_required (VERSION 3.10.2)
project (RemoteControl CXX)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file (
        DOWNLOAD
            "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
        TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)


conan_cmake_run (
    REQUIRES
        boost/1.75.0
    OPTIONS
        boost:header_only=True
    BASIC_SETUP
    BUILD missing)

add_subdirectory (client)
add_subdirectory (server)
