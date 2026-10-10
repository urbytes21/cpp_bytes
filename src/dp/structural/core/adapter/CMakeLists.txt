add_library(dp_adapter
	${CMAKE_CURRENT_SOURCE_DIR}/Adaptee.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Adaptee.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/AdapterFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CardProcessor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CardProcessor.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/ClassAdapter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ClassAdapter.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/ObjectAdapter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ObjectAdapter.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/PayPalAdapter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/PayPalAdapter.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/PayPalSdk.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/PayPalSdk.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/adapter/AdapterFactory.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/adapter/PaymentProcessor.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/adapter/Target.hpp
)

add_library(dp::adapter ALIAS dp_adapter)

target_link_libraries(dp_adapter
	PRIVATE cpplab::lab
)

target_include_directories(dp_adapter
	PUBLIC include
)
