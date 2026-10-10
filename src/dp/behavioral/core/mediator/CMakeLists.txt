add_library(dp_mediator
	${CMAKE_CURRENT_SOURCE_DIR}/Aircraft.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ControlTowerFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Tower.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Tower.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/mediator/Aircraft.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/mediator/ControlTower.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/mediator/ControlTowerFactory.hpp
)

add_library(dp::mediator ALIAS dp_mediator)

target_link_libraries(dp_mediator
	PRIVATE cpplab::lab
)

target_include_directories(dp_mediator
	PUBLIC include
)
