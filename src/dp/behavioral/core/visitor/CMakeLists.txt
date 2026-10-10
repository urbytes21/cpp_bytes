add_library(dp_visitor
	${CMAKE_CURRENT_SOURCE_DIR}/Element.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/HtmlExporter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/HtmlExporter.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/JsonExporter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/JsonExporter.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/VisitorFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/WordCounter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/WordCounter.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/visitor/Counter.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/visitor/Element.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/visitor/VariantElement.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/visitor/Visitor.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/visitor/VisitorFactory.hpp
)

add_library(dp::visitor ALIAS dp_visitor)

target_link_libraries(dp_visitor
	PRIVATE cpplab::lab
)

target_include_directories(dp_visitor
	PUBLIC include
)
