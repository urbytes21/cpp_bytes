add_library(cpplab_algo
	${CMAKE_CURRENT_SOURCE_DIR}/iteration.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/recursion.cpp
)

add_library(cpplab::algo ALIAS cpplab_algo)

target_link_libraries(cpplab_algo
	PRIVATE cpplab::lab
)

target_compile_options(cpplab_algo PRIVATE -Wall -Werror -Wextra)
