add_library(dp_command
	${CMAKE_CURRENT_SOURCE_DIR}/ClearCommand.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ClearCommand.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/CommandFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Editor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InsertTextCommand.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InsertTextCommand.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/MacroCommand.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/MacroCommand.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/command/Command.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/command/CommandFactory.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/command/Editor.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/command/TextDocument.hpp
)

add_library(dp::command ALIAS dp_command)

target_link_libraries(dp_command
	PRIVATE cppbytes::lab
)

target_include_directories(dp_command
	PUBLIC include
)
