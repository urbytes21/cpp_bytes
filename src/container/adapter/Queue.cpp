// -----------------------------------------------------------------------------
// std::queue - first in, first out (FIFO)
//
//   - Access: front() / back(); add with push() / emplace(); remove with pop().
//   - Size: size() / empty(); no iterators or indexing.
//   - Check empty() before accessing or popping an element.
//
// Reference: https://en.cppreference.com/w/cpp/container/queue
// -----------------------------------------------------------------------------

#include <ios>
#include <queue>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("Queue", "std::queue: insert, access, pop, traverse") {
  std::queue<int> values;

  auto traversal = [](const std::queue<int>& queue) {
    auto copy = queue;
    while (!copy.empty()) {
      LOG_S(copy.front());
      copy.pop();
    }
  };

  LOG_SECTION("Push and emplace");
  values.push(1);
  values.push(2);
  values.emplace(3);
  LOG_S("size = " << values.size() << ", front = " << values.front());
  LOG_S("back = " << values.back());
  traversal(values);

  LOG_SECTION("Pop");
  values.pop();
  LOG_S("after pop: front = " << values.front());
  traversal(values);

  LOG_SECTION("Traverse a copy by popping");
  traversal(values);
  LOG_S("original size = " << values.size());

  LOG_SECTION("Drain the original");
  while (!values.empty()) {
    auto val = values.front();
    values.pop();
    LOG_S(val);
  }
  LOG_S("empty = " << std::boolalpha << values.empty());
}
