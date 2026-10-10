add_library(cpplab_container
	${CMAKE_CURRENT_SOURCE_DIR}/sequence/Array.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sequence/Deque.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sequence/ForwardList.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sequence/List.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/sequence/Vector.cpp
)

add_library(cpplab::container ALIAS cpplab_container)

target_compile_options(cpplab_container
	PRIVATE
		-Wall
		-Wextra
		-Werror
)

target_link_libraries(cpplab_container PRIVATE cpplab::lab)