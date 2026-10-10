# Containers

Each example focuses on its own container: initialization, access, insertion,
traversal, and removal. Operations and output stay together in one function.

| Example | Focus |
|---|---|
| `sequence/Array` | Fixed-size elements, checked access, traversal, fill and swap |
| `sequence/Vector` | Contiguous elements, size vs capacity, insertion and erasure |
| `sequence/Deque` | Indexed access and insertion/removal at both ends |
| `sequence/List` | Insert/erase by iterator, sort, unique, reverse, splice and merge |
| `sequence/ForwardList` | Insert/erase after an iterator, before_begin, node transfer |
| `associative/Map` | Sorted unique keys, insert vs update, lookup and key ranges |
| `associative/MultiMap` | Sorted duplicate keys, equal_range, erasing one or all matches |
| `associative/Set` | Sorted unique keys, insertion result, lookup and key ranges |
| `unordered/UnorderedMap` | Hashed key/value pairs, insert vs update, lookup and buckets |
| `unordered/UnorderedSet` | Hashed unique keys, lookup, reserve, rehash and buckets |
| `adapter/Stack` | Last in, first out: push, top and pop |
| `adapter/Queue` | First in, first out: push, front, back and pop |
| `adapter/PriorityQueue` | Highest priority first, max-heap and min-heap |
| `adapter/FlatMap` | Sorted key/value pairs; requires C++23 and library support |

## Traversal

- Sequences: range-based loops, iterators, const iterators and `std::for_each`.
  Array, vector and deque also support index loops. All except forward_list
  support reverse iterators.
- Ordered maps and sets: sorted traversal, reverse traversal and key ranges.
- Unordered maps and sets: unspecified order, including traversal within buckets;
  no reverse iterators.
- Stack, queue and priority_queue: no iterators. Pop a copy to traverse while
  preserving the original, or pop the original to drain it.

## Build and run

From the repository root:

```bash
cmake -S . -B build/debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build/debug --target cpp_lab
./build/debug/bin/cpp_lab --plain --run container/sequence/Vector
./build/debug/bin/cpp_lab --plain --run-all container
```

All files are included in the container library. In the default C++20 build,
`FlatMap` is marked unavailable and only prints its requirements when run directly.
Its actual example is enabled when the standard library exposes `std::flat_map`.
