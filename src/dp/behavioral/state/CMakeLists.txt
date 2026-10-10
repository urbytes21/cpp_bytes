add_library(dp_state
	${CMAKE_CURRENT_SOURCE_DIR}/Device.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/DeviceStateFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ErrorState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ErrorState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/IdleState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/IdleState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/ProcessingState.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ProcessingState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/state/Device.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/state/DeviceState.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/state/DeviceStateFactory.hpp
)

add_library(dp::state ALIAS dp_state)

target_link_libraries(dp_state
	PRIVATE cpplab::lab
)

target_include_directories(dp_state
	PUBLIC include
)
