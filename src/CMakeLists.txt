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

add_executable(${PROJECT_NAME} main.cpp)

# NOTE: forces the .o into the executable by using <WHOLE_ARCHIVE>
# to let its static initialization executes
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        cpplab::lab
        # cpplab::core
        "$<LINK_LIBRARY:WHOLE_ARCHIVE,cpplab::dp>"
        "$<LINK_LIBRARY:WHOLE_ARCHIVE,cpplab::solid>"
        # cpplab::socket
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${PROJECT_BINARY_DIR}/generated
)

# if(CPPLAB_BUILD_TESTS)
#     cpplab_discover_example_tests(${PROJECT_NAME})
# endif()

# if(CPPLAB_GUI_ENABLED)
#     add_subdirectory(ap)     # MVC / MVVM with GTK4 (separate executables)
# endif()

# if(CPPLAB_BUILD_DEMOS)
#     add_subdirectory(demo)   # dlopen plugin demo
# endif()

# src/embedded is a bare-metal ARM example built with its own script (see its README).
