// -----------------------------------------------------------------------------
// std::set - sorted unique keys
//
//   - Insert: insert() / emplace() return an iterator and whether insertion succeeded.
//   - Look up: find() / contains() / count(); elements cannot be changed in place.
//   - Ranges: lower_bound() (>= key) / upper_bound() (> key) / equal_range().
//   - Remove: erase(key) / erase(iterator) / clear().
//
// Reference: https://en.cppreference.com/w/cpp/container/set
// -----------------------------------------------------------------------------

#include <algorithm>
#include <set>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("Set", "std::set: unique keys, insert, lookup, sorted traversal, erase") {
  std::set<int> values{3, 1, 2, 2};  // duplicate 2 is ignored

  LOG_SECTION("Insert");
  const auto [position, inserted] = values.insert(4);
  LOG_S("insert 4: value = " << *position << ", inserted = " << inserted);
  LOG_S("insert 4 again: inserted = " << values.insert(4).second);
  values.emplace(5);

  LOG_SECTION("Look up");
  if (const auto it = values.find(3); it != values.end()) {
    LOG_S("found = " << *it);
  }
  LOG_S("contains 9 = " << values.contains(9));
  LOG_S("count 2 = " << values.count(2));  // 0 or 1

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

  LOG_SECTION("Range: 2 through 4");
  const auto last = values.upper_bound(4);
  for (auto it = values.lower_bound(2); it != last; ++it) {
    LOG_S(*it);
  }
  const auto [first, end] = values.equal_range(3);
  for (auto it = first; it != end; ++it) {
    LOG_S("equal_range 3: " << *it);
  }

  LOG_SECTION("Erase");
  values.erase(2);
  values.erase(values.begin());
  LOG_S("size = " << values.size());
  values.clear();
  LOG_S("empty = " << values.empty());
}
