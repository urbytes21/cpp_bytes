add_library(dp_chain_of_responsibility
	${CMAKE_CURRENT_SOURCE_DIR}/AuthenticationHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/AuthenticationHandler.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Handler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/HandlerFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/LoggingHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/LoggingHandler.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/MethodHandler.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/MethodHandler.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/chain_of_responsibility/Handler.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/chain_of_responsibility/HandlerFactory.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/chain_of_responsibility/Request.hpp
)

add_library(dp::chain_of_responsibility ALIAS dp_chain_of_responsibility)

target_link_libraries(dp_chain_of_responsibility
	PRIVATE cppbytes::lab
)

target_include_directories(dp_chain_of_responsibility
	PUBLIC include
)
