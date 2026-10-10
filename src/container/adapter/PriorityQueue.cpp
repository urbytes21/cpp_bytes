// -----------------------------------------------------------------------------
// std::priority_queue - highest priority element first
//
//   - Access: top(); add with push() / emplace()
//   - Remove with pop()
//   - Default: largest first; std::greater<int> makes smallest first
//   - Size: size() / empty(); no iterators or indexing
//   - Check empty() before top() or pop(); traversal requires popping
//
// Reference: https://en.cppreference.com/w/cpp/container/priority_queue
// -----------------------------------------------------------------------------

#include <functional>
#include <ios>
#include <queue>
#include <vector>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("PriorityQueue",
            "std::priority_queue: push, top, pop, max-heap, min-heap") {

  std::priority_queue<int> max_heap;

  auto traversal = [](auto& heap) {
    LOG_SECTION("Traverse a copy by popping");
    auto copy = heap;
    while (!copy.empty()) {
      LOG_S(copy.top());  // largest to smallest
      copy.pop();
    }
  };

  LOG_SECTION("Push and emplace (max-heap)");
  max_heap.push(3);
  max_heap.push(1);
  max_heap.emplace(5);
  LOG_S("size = " << max_heap.size() << ", top = " << max_heap.top());
  traversal(max_heap);

  LOG_SECTION("Pop");
  max_heap.pop();  // removes 5; returns no value
  LOG_S("after pop: top = " << max_heap.top());

  LOG_SECTION("Drain the original");
  while (!max_heap.empty()) {
    LOG_S(max_heap.top());
    max_heap.pop();
  }
  LOG_S("empty = " << std::boolalpha << max_heap.empty());

  LOG_SECTION("Min-heap");
  std::priority_queue<int, std::vector<int>, std::greater<>> min_heap;
  min_heap.push(3);
  min_heap.push(1);
  min_heap.emplace(5);
  traversal(min_heap);
}
