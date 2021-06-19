cmake_minimum_required (VERSION 3.10.2)

project(messages CXX)

find_package(Protobuf REQUIRED)

#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS move.proto)

add_library(${PROJECT_NAME}
    move.proto
    ${PROTO_SRCS}
    ${PROTO_HDRS}
)

protobuf_generate(TARGET ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        CONAN_PKG::protobuf
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_BINARY_DIR}
)
