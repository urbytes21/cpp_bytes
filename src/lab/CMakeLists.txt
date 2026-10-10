add_library(cppbytes_lab STATIC
    src/CommandLine.cpp
    src/Logger.cpp
    src/Menu.cpp
    src/Registry.cpp
    src/Runner.cpp
)

add_library(cppbytes::lab ALIAS cppbytes_lab)

target_include_directories(cppbytes_lab
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)