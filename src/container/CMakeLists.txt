add_library(cppbytes_container
    sequence/Array.cpp
    # sequence/Deque.cpp
    sequence/ForwardList.cpp
    sequence/List.cpp
    sequence/Vector.cpp

    # associative/Map.cpp
    # associative/MultiMap.cpp
    # associative/Set.cpp

    unordered/UnorderedMap.cpp
    # unordered/UnorderedSet.cpp

    # adapter/FlatMap.cpp
    adapter/PriorityQueue.cpp
    adapter/Queue.cpp
    adapter/Stack.cpp
)

add_library(cppbytes::container ALIAS cppbytes_container)

target_compile_options(cppbytes_container PRIVATE -Wall -Wextra -Werror)
target_link_libraries(cppbytes_container PRIVATE cppbytes::lab)
