add_library(dp_decorator
	${CMAKE_CURRENT_SOURCE_DIR}/EmailNotifier.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/EmailNotifier.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/NotifierDecorator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/NotifierDecorator.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/NotifierFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SlackDecorator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SlackDecorator.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/SmsDecorator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SmsDecorator.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/UrgentDecorator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/UrgentDecorator.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/decorator/Notifier.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/decorator/NotifierFactory.hpp
)

add_library(dp::decorator ALIAS dp_decorator)

target_link_libraries(dp_decorator
	PRIVATE cpplab::lab
)

target_include_directories(dp_decorator
	PUBLIC include
)
