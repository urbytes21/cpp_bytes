add_library(dp_composite
	${CMAKE_CURRENT_SOURCE_DIR}/File.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Folder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Node.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Shortcut.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/composite/File.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/composite/Folder.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/composite/Node.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/composite/Shortcut.hpp
)

add_library(dp::composite ALIAS dp_composite)

target_link_libraries(dp_composite
	PRIVATE cpplab::lab
)

target_include_directories(dp_composite
	PUBLIC include
)
