add_library(cppbytes_algo
	${CMAKE_CURRENT_SOURCE_DIR}/iteration.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/recursion.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/linkedlist.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/hash_algorithm.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/tree.cpp
)

add_library(cppbytes::algo ALIAS cppbytes_algo)

target_link_libraries(cppbytes_algo
	PRIVATE cppbytes::lab
)

target_compile_options(cppbytes_algo PRIVATE -Wall -Werror -Wextra)
