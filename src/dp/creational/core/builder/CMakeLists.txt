add_library(dp_builder
	${CMAKE_CURRENT_SOURCE_DIR}/Director.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/House.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/HouseBuilder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/HouseBuilderFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/HttpRequest.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/StoneHouseBuilder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/StoneHouseBuilder.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/WoodenHouseBuilder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/WoodenHouseBuilder.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/builder/Director.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/builder/House.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/builder/HouseBuilder.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/builder/HouseBuilderFactory.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/builder/HttpRequest.hpp
)

add_library(dp::builder ALIAS dp_builder)

target_link_libraries(dp_builder
	PRIVATE cppbytes::lab
)

target_include_directories(dp_builder
	PUBLIC include
)
