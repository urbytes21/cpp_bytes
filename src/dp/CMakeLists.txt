add_library(cpplab_dp
	${CMAKE_CURRENT_SOURCE_DIR}/behavioral/ChainOfResponsibility.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/behavioral/Command.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/behavioral/Interpreter.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/behavioral/Iterator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/behavioral/Mediator.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/behavioral/Memento.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/behavioral/Observer.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/behavioral/State.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/behavioral/Strategy.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/behavioral/TemplateMethod.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/behavioral/Visitor.cpp
)

add_library(cpplab::dp ALIAS cpplab_dp)

add_subdirectory(behavioral/state)
add_subdirectory(behavioral/strategy)

target_link_libraries(cpplab_dp
	PRIVATE
		cpplab::lab
		dp::state
		dp::strategy
)
