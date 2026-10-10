add_library(dp_flyweight
	${CMAKE_CURRENT_SOURCE_DIR}/ImageCache.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ImageData.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/flyweight/ImageCache.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/flyweight/ImageData.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/flyweight/Sprite.hpp
)

add_library(dp::flyweight ALIAS dp_flyweight)

target_link_libraries(dp_flyweight
	PRIVATE cppbytes::lab
)

target_include_directories(dp_flyweight
	PUBLIC include
)
