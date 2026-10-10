add_library(dp_abstract_factory
	${CMAKE_CURRENT_SOURCE_DIR}/Linux.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Linux.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/MacOs.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/MacOs.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/ToolchainFactoryProvider.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Windows.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Windows.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/abstract_factory/Products.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/abstract_factory/ToolchainFactory.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/abstract_factory/ToolchainFactoryProvider.hpp
)

add_library(dp::abstract_factory ALIAS dp_abstract_factory)

target_link_libraries(dp_abstract_factory
	PRIVATE cppbytes::lab
)

target_include_directories(dp_abstract_factory
	PUBLIC include
)
