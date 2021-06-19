cmake_minimum_required (VERSION 3.10.2)
project(Server CXX)

find_package(Threads REQUIRED)

add_executable(server
    main.cpp
)

target_link_libraries(server
    PRIVATE
        Threads::Threads
        CONAN_PKG::boost
        messages
)
