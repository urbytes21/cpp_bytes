# Templates only: nothing to compile, so this is a header-only INTERFACE library.
add_library(dp_iterator INTERFACE)

add_library(dp::iterator ALIAS dp_iterator)

target_include_directories(dp_iterator
	INTERFACE include
)
