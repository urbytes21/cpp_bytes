# ----------------------------------------------------------------------------------------
# cppbytes::options - compile/link settings shared by every target of the project.
# Link it instead of using add_compile_options() so third-party code (GoogleTest) is not
# affected by our warnings, coverage or sanitizer flags.
# ----------------------------------------------------------------------------------------

add_library(cppbytes_options INTERFACE)
add_library(cppbytes::options ALIAS cppbytes_options)

target_compile_features(cppbytes_options INTERFACE cxx_std_20)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    # Compiler warnings (useful for learning/debugging)
    target_compile_options(cppbytes_options INTERFACE -Wall -Wextra -Wpedantic)

    if(CPPBYTES_WARNINGS_AS_ERRORS)
        target_compile_options(cppbytes_options INTERFACE -Werror)
    endif()

    # Code coverage configuration (see scripts/gen_coverage_*.sh)
    if(ENABLE_COVERAGE)
        message(STATUS "Enabling coverage flags")
        # -fprofile-update=atomic: the RaceCondition example increments a counter from
        # several threads on purpose, which would also corrupt gcov's own counters.
        target_compile_options(cppbytes_options INTERFACE --coverage -O0 -g -fprofile-update=atomic)
        target_link_options(cppbytes_options INTERFACE --coverage)
    endif()

    # Sanitizers catch memory errors and undefined behavior at run time:
    #   cmake -S . -B build-asan -DCPPBYTES_ENABLE_SANITIZERS=ON
    #   cmake --build build-asan && ./build-asan/bin/cpp_bytes --run-all
    if(CPPBYTES_ENABLE_SANITIZERS)
        message(STATUS "Enabling AddressSanitizer + UndefinedBehaviorSanitizer")
        target_compile_options(cppbytes_options INTERFACE
            -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover=undefined)
        target_link_options(cppbytes_options INTERFACE -fsanitize=address,undefined)
    endif()
endif()
