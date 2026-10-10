add_library(dp_observer
	${CMAKE_CURRENT_SOURCE_DIR}/AnalyticsListener.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/AnalyticsListener.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Button.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/CallbackButton.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Event.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ListenerFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SoundListener.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SoundListener.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/observer/Button.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/observer/CallbackButton.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/observer/Event.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/observer/Listener.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/observer/ListenerFactory.hpp
)

add_library(dp::observer ALIAS dp_observer)

target_link_libraries(dp_observer
	PRIVATE cpplab::lab
)

target_include_directories(dp_observer
	PUBLIC include
)
