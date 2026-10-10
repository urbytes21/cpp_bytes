// -----------------------------------------------------------------------------
// std::forward_list - singly linked elements
//
//   - Access: front(); no indexing, back(), size() or reverse iterators
//   - Insert: push_front() / emplace_front() / insert_after() / emplace_after()
//   - Remove: pop_front() / erase_after() / remove() / remove_if() / clear()
//   - before_begin() is the position before the first element; do not dereference it
//   - Reorder: sort() / unique() / reverse(); transfer with splice_after() / merge()
//
// Reference: https://en.cppreference.com/w/cpp/container/forward_list
// -----------------------------------------------------------------------------

#include <algorithm>
#include <forward_list>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("ForwardList", "std::forward_list: insert_after, traverse, erase_after, transfer") {
  std::forward_list<int> values{1, 2, 3};

  LOG_SECTION("Insert and access");
  values.push_front(0);
  values.emplace_front(-1);
  auto inserted = values.insert_after(values.before_begin(), 9);
  values.emplace_after(inserted, 8);
  LOG_S("front = " << values.front());

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

  LOG_SECTION("std::for_each");
  std::for_each(values.cbegin(), values.cend(), [](const auto& entry) {
    LOG_S(entry);
  });

  LOG_SECTION("Remove");
  values.erase_after(inserted);  // removes 8, which follows 9
  values.pop_front();  // removes 9
  values.remove(2);
  values.remove_if([](int value) { return value < 0; });
  LOG_S("front = " << values.front());

  LOG_SECTION("Sort, unique, reverse");
  values.assign({3, 1, 2, 2});
  values.sort();
  values.unique();  // removes consecutive duplicates
  values.reverse();
  for (int value : values) {
    LOG_S(value);  // 3, 2, 1
  }

  LOG_SECTION("Transfer nodes");
  std::forward_list<int> other{4, 5};
  values.splice_after(values.before_begin(), other);
  LOG_S("after splice_after: front = " << values.front() << ", other.empty = " << other.empty());
  values.sort();
  other.assign({0, 6});
  values.merge(other);  // both lists must be sorted
  LOG_S("after merge: front = " << values.front() << ", other.empty = " << other.empty());
  values.clear();
  LOG_S("empty = " << values.empty());
}
