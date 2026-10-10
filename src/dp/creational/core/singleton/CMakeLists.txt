add_library(dp_singleton
	${CMAKE_CURRENT_SOURCE_DIR}/Config.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/singleton/Config.hpp
)

add_library(dp::singleton ALIAS dp_singleton)

target_link_libraries(dp_singleton
	PRIVATE cpplab::lab
)

target_include_directories(dp_singleton
	PUBLIC include
)
