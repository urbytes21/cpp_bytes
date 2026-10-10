// -----------------------------------------------------------------------------
// std::deque - indexed elements with insertion at both ends
//
//   - Access: operator[] / at() / front() / back(); no data().
//   - Insert: push_front() / push_back() / emplace_front() / emplace_back() / insert().
//   - Remove: pop_front() / pop_back() / erase() / clear().
//   - Pushing at either end keeps references valid, but invalidates iterators.
//
// Reference: https://en.cppreference.com/w/cpp/container/deque
// -----------------------------------------------------------------------------

#include <algorithm>
#include <deque>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("Deque", "std::deque: access, both ends, traverse, erase") {
  std::deque<int> values{1, 2, 3};

  LOG_SECTION("Insert at both ends and in the middle");
  values.push_front(0);
  values.push_back(4);
  values.emplace_front(-1);
  values.emplace_back(5);
  values.insert(values.begin() + 2, 9);

  LOG_SECTION("Access and update");
  values[2] = 10;
  values.at(3) = 20;
  LOG_S("front = " << values.front() << ", back = " << values.back());
  LOG_S("size = " << values.size());

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
  values.pop_front();
  values.pop_back();
  values.erase(values.begin() + 1);
  LOG_S("front = " << values.front() << ", back = " << values.back());
  values.clear();
  LOG_S("empty = " << values.empty());
}
