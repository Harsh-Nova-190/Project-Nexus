cmake_minimum_required(VERSION 3.8)

project("Project N (Nexus)")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Nexus
    src/main.cpp
    src/Lexer.cpp
    src/Token.cpp
)

target_include_directories(Nexus PRIVATE src)
