// -----------------------------------------------------------------------------
// std::array - fixed-size contiguous elements
//
//   - Access: operator[] / at() / front() / back() / data()
//   - Update: assign an element / fill() / swap(); no insert or erase
//   - Size: size() / empty(); the size is part of the type
//
// Reference: https://en.cppreference.com/w/cpp/container/array
// -----------------------------------------------------------------------------

#include <algorithm>
#include <array>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("Array", "std::array: initialize, access, update, traverse") {
  LOG_SECTION("Initialize");

  // generic lamba
  auto traversal = [](const auto& array) {
    for (const auto& value : array) {
      LOG_S(value);
    }
  };

  std::array<int, 4> values{1, 2, 3, 4};
  const std::array<int, 3> zeros{};  // all elements are 0
  LOG_S("size = " << values.size() << ", empty = " << values.empty());
  LOG_S("zeros[0] = " << zeros[0]);
  traversal(values);

  LOG_SECTION("Access and update");
  values[1] = 20;     // unchecked access
  values.at(2) = 30;  // checked access; throws if the index is out of range
  LOG_S("front = " << values.front() << ", back = " << values.back());
  LOG_S("data()[1] = " << values.data()[1]);

  LOG_SECTION("Index loop");
  for (std::size_t i = 0; i < values.size(); ++i) {
    LOG_S("[" << i << "] = " << values[i]);
  }

  LOG_SECTION("Range-based loop");
  for (const auto& value : values) {
    LOG_S(value);
  }

  LOG_SECTION("Iterators: begin / end");
  for (auto* it = values.begin(); it != values.end(); ++it) {
    LOG_S(*it);
  }

  LOG_SECTION("Const iterators: cbegin / cend");
  for (const auto* it = values.cbegin(); it != values.cend(); ++it) {
    LOG_S(*it);
  }

  LOG_SECTION("Reverse iterators: rbegin / rend");
  for (auto it = values.rbegin(); it != values.rend(); ++it) {
    LOG_S(*it);
  }

  LOG_SECTION("std::for_each");
  std::for_each(values.cbegin(), values.cend(),
                [](const auto& entry) { LOG_S(entry); });

  LOG_SECTION("Fill and swap");
  values.fill(0);
  std::array<int, 4> other{5, 6, 7, 8};
  values.swap(other);
  LOG_S("values.front = " << values.front()
                          << ", other.front = " << other.front());
}
