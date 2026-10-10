add_library(dp_strategy
	${CMAKE_CURRENT_SOURCE_DIR}/include/strategy/ExportStrategy.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/strategy/Document.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/ExportStrategyFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/JsonExport.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/MarkdownExport.hpp
)

add_library(dp::strategy ALIAS dp_strategy)

target_link_libraries(dp_strategy
	PRIVATE cppbytes::lab
)

target_include_directories(dp_strategy
	PUBLIC include
)
