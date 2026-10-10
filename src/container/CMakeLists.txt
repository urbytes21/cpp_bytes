add_library(cpplab_container
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
    # adapter/PriorityQueue.cpp
    adapter/Queue.cpp
    adapter/Stack.cpp
)

add_library(cpplab::container ALIAS cpplab_container)

target_compile_options(cpplab_container PRIVATE -Wall -Wextra -Werror)
target_link_libraries(cpplab_container PRIVATE cpplab::lab)
