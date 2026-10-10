string(TIMESTAMP PROJECT_BUILD_TIME "%Y-%m-%d %H:%M:%S")
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/version.h.in
    ${PROJECT_BINARY_DIR}/generated/version.hpp
    @ONLY
)

add_subdirectory(lab)
# add_subdirectory(core)        # C++ language and standard library
add_subdirectory(dp)          # design patterns
# add_subdirectory(socket)      # POSIX TCP sockets
add_subdirectory(solid)
add_subdirectory(algo)
add_subdirectory(container)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(scratch_debug EXCLUDE_FROM_ALL debug.cpp)

# NOTE: forces the .o into the executable by using <WHOLE_ARCHIVE>
# to let its static initialization executes
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        cppbytes::lab
        # cppbytes::core
        "$<LINK_LIBRARY:WHOLE_ARCHIVE,cppbytes::dp>"
        "$<LINK_LIBRARY:WHOLE_ARCHIVE,cppbytes::solid>"
        "$<LINK_LIBRARY:WHOLE_ARCHIVE,cppbytes::algo>"
        "$<LINK_LIBRARY:WHOLE_ARCHIVE,cppbytes::container>"
        # cppbytes::socket
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_BINARY_DIR}/generated
)

# if(CPPBYTES_BUILD_TESTS)
#     cppbytes_discover_example_tests(${PROJECT_NAME})
# endif()

# if(CPPBYTES_GUI_ENABLED)
#     add_subdirectory(ap)     # MVC / MVVM with GTK4 (separate executables)
# endif()

# if(CPPBYTES_BUILD_DEMOS)
#     add_subdirectory(demo)   # dlopen plugin demo
# endif()

# src/embedded is a bare-metal ARM example built with its own script (see its README).
