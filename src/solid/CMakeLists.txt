add_library(cppbytes_solid
	${CMAKE_CURRENT_SOURCE_DIR}/DIP.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/ISP.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/LSP.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/OCP.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/SRP.cpp
)

add_library(cppbytes::solid ALIAS cppbytes_solid)

target_link_libraries(cppbytes_solid
	PRIVATE cppbytes::lab
)

target_compile_options(cppbytes_solid PRIVATE -Wall -Werror -Wextra)
