add_library(dp_factory_method
	${CMAKE_CURRENT_SOURCE_DIR}/DebuggerInstaller.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/InstallerFactory.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Linux.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Linux.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/MacOs.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/MacOs.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/Windows.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/Windows.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/factory_method/Debugger.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/factory_method/DebuggerInstaller.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/factory_method/InstallerFactory.hpp
)

add_library(dp::factory_method ALIAS dp_factory_method)

target_link_libraries(dp_factory_method
	PRIVATE cpplab::lab
)

target_include_directories(dp_factory_method
	PUBLIC include
)
