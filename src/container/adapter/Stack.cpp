// -----------------------------------------------------------------------------
// std::stack - last in, first out (LIFO)
//
//   - Access: top();
//   - Add: push() / emplace()
//   - Remove: pop()
//   - Size: size() / empty(); no iterators or indexing
//   - Check empty() before accessing or popping an element
//   - Traversal: create a temporary clone/copy of the stack and perform the pop-and-process
// Reference: https://en.cppreference.com/w/cpp/container/stack
// -----------------------------------------------------------------------------

#include <ios>
#include <stack>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("Stack", "std::stack: insert, access, pop, traverse") {
  std::stack<int> values;

  auto traversal = [](const std::stack<int>& stack) {
    auto copy = stack;
    while (!copy.empty()) {
      LOG_S(copy.top());
      copy.pop();
    }
  };

  LOG_SECTION("Push and emplace");
  values.push(1);
  values.push(2);
  values.emplace(3);
  LOG_S("size = " << values.size() << ", top = " << values.top());
  traversal(values);

  LOG_SECTION("Pop");
  values.pop();
  LOG_S("after pop: top = " << values.top());

  LOG_SECTION("Traverse a copy by popping");
  traversal(values);
  LOG_S("original size = " << values.size());

  LOG_SECTION("Drain the original");
  while (!values.empty()) {
    LOG_S(values.top());
    values.pop();
  }
  LOG_S("empty = " << std::boolalpha << values.empty());
}
