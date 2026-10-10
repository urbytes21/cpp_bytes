// -----------------------------------------------------------------------------
// std::unordered_set - hashed unique keys
//
//   - Insert: insert() / emplace() keep unique keys; elements cannot be changed in place.
//   - Look up: find() / contains() / count(); no indexing.
//   - Traverse: order is unspecified; no reverse iterators.
//   - Hash storage: reserve() / rehash() / bucket_count() / load_factor().
//   - Rehashing invalidates iterators, but keeps references and pointers valid.
//
// Reference: https://en.cppreference.com/w/cpp/container/unordered_set
// -----------------------------------------------------------------------------

#include <algorithm>
#include <unordered_set>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("UnorderedSet", "std::unordered_set: insert, lookup, traverse, buckets, erase") {
  std::unordered_set<int> values{3, 1, 2, 2};

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

  LOG_SECTION("Hash storage");
  values.reserve(10);  // room for at least 10 elements at the current max load factor
  LOG_S("buckets = " << values.bucket_count() << ", load factor = " << values.load_factor());
  values.rehash(20);  // request at least 20 buckets
  LOG_S("after rehash: buckets = " << values.bucket_count());

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

  LOG_SECTION("Buckets: local iterators");
  for (std::size_t bucket = 0; bucket < values.bucket_count(); ++bucket) {
    for (auto it = values.begin(bucket); it != values.end(bucket); ++it) {
      LOG_S("bucket " << bucket << ": " << *it);
    }
  }

  LOG_SECTION("Erase");
  values.erase(2);
  values.erase(values.begin());
  LOG_S("size = " << values.size());
  values.clear();
  LOG_S("empty = " << values.empty());
}
