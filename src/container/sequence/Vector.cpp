// -----------------------------------------------------------------------------
// std::vector - dynamic contiguous elements
//
//   - Access: operator[] / at() / front() / back() / data().
//   - Insert: push_back() / emplace_back() / insert() / emplace().
//   - Remove: pop_back() / erase() / std::erase() / clear().
//   - Capacity: reserve() allocates room; resize() changes the number of elements.
//   - Reallocation invalidates all iterators, pointers and references.
//
// Reference: https://en.cppreference.com/w/cpp/container/vector
// -----------------------------------------------------------------------------

#include <algorithm>
#include <vector>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("Vector", "std::vector: access, capacity, insert, traverse, erase") {
  std::vector<int> values{1, 2, 3};

  LOG_SECTION("Size and capacity");
  values.reserve(10);  // does not change size
  LOG_S("size = " << values.size() << ", capacity = " << values.capacity());
  values.resize(5, 0);  // appends two zeros
  LOG_S("after resize(5): size = " << values.size() << ", back = " << values.back());

  LOG_SECTION("Access and update");
  values[0] = 10;
  values.at(1) = 20;  // throws if the index is out of range
  LOG_S("front = " << values.front() << ", back = " << values.back());
  LOG_S("data()[1] = " << values.data()[1]);

  LOG_SECTION("Insert");
  values.push_back(4);
  values.emplace_back(5);
  values.insert(values.begin(), 0);  // inserts before the iterator
  values.emplace(values.begin() + 1, 9);

  LOG_SECTION("Index loop");
  for (std::size_t i = 0; i < values.size(); ++i) {
    LOG_S("[" << i << "] = " << values[i]);
  }

  LOG_SECTION("Range-based loop");
  for (const auto& value : values) {
    LOG_S(value);
  }

  LOG_SECTION("Iterators: begin / end");
  for (auto it = values.begin(); it != values.end(); ++it) {
    LOG_S(*it);
  }

  LOG_SECTION("Const iterators: cbegin / cend");
  for (auto it = values.cbegin(); it != values.cend(); ++it) {
    LOG_S(*it);
  }

  LOG_SECTION("Reverse iterators: rbegin / rend");
  for (auto it = values.rbegin(); it != values.rend(); ++it) {
    LOG_S(*it);
  }

  LOG_SECTION("std::for_each");
  std::for_each(values.cbegin(), values.cend(), [](const auto& entry) {
    LOG_S(entry);
  });

  LOG_SECTION("Remove");
  values.pop_back();
  values.erase(values.begin());  // erase by position
  std::erase(values, 0);  // C++20: erase all zeros
  LOG_S("size = " << values.size() << ", front = " << values.front());
  values.clear();
  LOG_S("empty = " << values.empty() << ", capacity = " << values.capacity());
}
