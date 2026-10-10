add_library(dp_memento
	${CMAKE_CURRENT_SOURCE_DIR}/Editor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/History.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/memento/Editor.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/memento/History.hpp
)

add_library(dp::memento ALIAS dp_memento)

target_link_libraries(dp_memento
	PRIVATE cppbytes::lab
)

target_include_directories(dp_memento
	PUBLIC include
)
