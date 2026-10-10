// -----------------------------------------------------------------------------
// std::priority_queue - highest priority element first
//
//   - Access: top(); add with push() / emplace(); remove with pop().
//   - Default: largest first; std::greater<int> makes smallest first.
//   - Size: size() / empty(); no iterators or indexing.
//   - Check empty() before top() or pop(); traversal requires popping.
//
// Reference: https://en.cppreference.com/w/cpp/container/priority_queue
// -----------------------------------------------------------------------------

#include <functional>
#include <queue>
#include <vector>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("PriorityQueue", "std::priority_queue: push, top, pop, max-heap, min-heap") {
  std::priority_queue<int> values;

  LOG_SECTION("Push and emplace (max-heap)");
  values.push(3);
  values.push(1);
  values.emplace(5);
  LOG_S("size = " << values.size() << ", top = " << values.top());

  LOG_SECTION("Pop");
  values.pop();  // removes 5; returns no value
  LOG_S("after pop: top = " << values.top());

  LOG_SECTION("Traverse a copy by popping");
  auto copy = values;
  while (!copy.empty()) {
    LOG_S(copy.top());  // largest to smallest
    copy.pop();
  }
  LOG_S("original size = " << values.size());

  LOG_SECTION("Drain the original");
  while (!values.empty()) {
    LOG_S(values.top());
    values.pop();
  }
  LOG_S("empty = " << values.empty());

  LOG_SECTION("Min-heap");
  std::priority_queue<int, std::vector<int>, std::greater<int>> smallest_first;
  smallest_first.push(3);
  smallest_first.push(1);
  smallest_first.emplace(5);
  while (!smallest_first.empty()) {
    LOG_S(smallest_first.top());  // 1, 3, 5
    smallest_first.pop();
  }
}
