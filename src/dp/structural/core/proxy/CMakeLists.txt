add_library(dp_proxy
	${CMAKE_CURRENT_SOURCE_DIR}/Server.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Server.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/ServerProxy.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ServerProxy.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/ServiceFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/proxy/Service.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/proxy/ServiceFactory.hpp
)

add_library(dp::proxy ALIAS dp_proxy)

target_link_libraries(dp_proxy
	PRIVATE cppbytes::lab
)

target_include_directories(dp_proxy
	PUBLIC include
)
