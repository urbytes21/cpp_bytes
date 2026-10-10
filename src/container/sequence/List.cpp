// -----------------------------------------------------------------------------
// std::list - doubly linked elements
//
//   - Access: front() / back(); no indexing or data()
//   - Insert: push_front() / push_back() / emplace() / insert() before an iterator
//   - Remove: pop_front() / pop_back() / erase() / remove() / remove_if()
//   - Reorder: sort() / unique() / reverse(); transfer nodes with splice() / merge()
//
// Reference: https://en.cppreference.com/w/cpp/container/list
// -----------------------------------------------------------------------------

#include <algorithm>
#include <iterator>
#include <list>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("List", "std::list: insert, traverse, erase, reorder, transfer") {
  std::list<int> values{1, 2, 3};

  LOG_SECTION("Insert and access");
  values.push_front(0);
  values.push_back(4);
  values.emplace_front(-1);
  values.emplace_back(5);
  auto inserted = values.insert(std::next(values.begin()), 9);
  values.emplace(inserted, 8);
  LOG_S("front = " << values.front() << ", back = " << values.back());
  LOG_S("size = " << values.size());

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
  values.erase(inserted);  // other iterators remain valid
  values.pop_front();
  values.pop_back();
  values.remove(2);  // removes all elements equal to 2
  values.remove_if([](int value) { return value == 8; });
  LOG_S("size = " << values.size());

  LOG_SECTION("Sort, unique, reverse");
  values.assign({3, 1, 2, 2});
  values.sort();  // list uses its member sort(), not std::sort
  values.unique();  // removes consecutive duplicates
  values.reverse();
  for (int value : values) {
    LOG_S(value);  // 3, 2, 1
  }

  LOG_SECTION("Transfer nodes");
  std::list<int> other{4, 5};
  values.splice(values.end(), other);  // moves all nodes from other
  LOG_S("after splice: size = " << values.size() << ", other.empty = " << other.empty());
  values.sort();
  other.assign({0, 6});
  values.merge(other);  // both lists must be sorted
  LOG_S("after merge: size = " << values.size() << ", other.empty = " << other.empty());
  values.clear();
  LOG_S("empty = " << values.empty());
}
