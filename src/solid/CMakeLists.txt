add_library(cpplab_solid
	${CMAKE_CURRENT_SOURCE_DIR}/DIP.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ISP.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/LSP.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OCP.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SRP.cpp
)

add_library(cpplab::solid ALIAS cpplab_solid)

target_link_libraries(cpplab_solid
	PRIVATE cpplab::lab
)

target_compile_options(cpplab_solid PRIVATE -Wall -Werror -Wextra)
