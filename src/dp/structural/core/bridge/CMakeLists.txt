add_library(dp_bridge
	${CMAKE_CURRENT_SOURCE_DIR}/LinuxRenderer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/LinuxRenderer.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/RendererFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Widget.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/WindowsRenderer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/WindowsRenderer.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/bridge/Renderer.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/bridge/RendererFactory.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/bridge/Widget.hpp
)

add_library(dp::bridge ALIAS dp_bridge)

target_link_libraries(dp_bridge
	PRIVATE cpplab::lab
)

target_include_directories(dp_bridge
	PUBLIC include
)
