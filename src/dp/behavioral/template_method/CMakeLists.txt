add_library(dp_template_method
	${CMAKE_CURRENT_SOURCE_DIR}/Beverage.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/BeverageFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/BlackCoffee.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Coffee.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Coffee.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Tea.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Tea.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/template_method/Beverage.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/template_method/BeverageFactory.hpp
)

add_library(dp::template_method ALIAS dp_template_method)

target_link_libraries(dp_template_method
	PRIVATE cpplab::lab
)

target_include_directories(dp_template_method
	PUBLIC include
)
