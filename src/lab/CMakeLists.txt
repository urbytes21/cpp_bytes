add_library(cpplab_lab STATIC
    src/CommandLine.cpp
    src/Logger.cpp
    src/Menu.cpp
    src/Registry.cpp
    src/Runner.cpp
)

add_library(cpplab::lab ALIAS cpplab_lab)

target_include_directories(cpplab_lab
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)