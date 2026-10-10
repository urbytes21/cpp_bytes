add_library(dp_facade
	${CMAKE_CURRENT_SOURCE_DIR}/BackendFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/FakeBackend.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/FakeBackend.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/RequestFacade.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Subsystem.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/facade/BackendFactory.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/facade/RequestFacade.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/facade/Subsystem.hpp
)

add_library(dp::facade ALIAS dp_facade)

target_link_libraries(dp_facade
	PRIVATE cpplab::lab
)

target_include_directories(dp_facade
	PUBLIC include
)
