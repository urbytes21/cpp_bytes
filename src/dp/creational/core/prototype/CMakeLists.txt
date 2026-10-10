add_library(dp_prototype
	${CMAKE_CURRENT_SOURCE_DIR}/AnalyticsExtension.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ExtensionRegistry.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/LoggerExtension.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/prototype/AnalyticsExtension.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/prototype/Extension.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/prototype/ExtensionRegistry.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/prototype/LoggerExtension.hpp
)

add_library(dp::prototype ALIAS dp_prototype)

target_link_libraries(dp_prototype
	PRIVATE cppbytes::lab
)

target_include_directories(dp_prototype
	PUBLIC include
)
