// -----------------------------------------------------------------------------
// std::flat_map - sorted unique keys with mapped values (C++23)
//
//   - Look up: find() / contains() / at(); operator[] inserts a default if missing.
//   - Insert: insert() / emplace() / try_emplace() keep an existing value.
//   - Insert or update: insert_or_assign() / map[key] = value.
//   - Traverse: sorted by key; insertion and erasure can invalidate iterators.
//   - Requires C++23 and standard-library support for std::flat_map.
//
// Reference: https://en.cppreference.com/w/cpp/container/flat_map
// -----------------------------------------------------------------------------

#include <algorithm>
#include <string>
#include <version>

#include "lab/Example.h"
#include "lab/Logger.h"

#if defined(__cpp_lib_flat_map) && __cpp_lib_flat_map >= 202207L
#include <flat_map>

LAB_EXAMPLE("FlatMap", "std::flat_map: insert, update, lookup, sorted traversal, erase") {
  std::flat_map<std::string, int> inventory{{"banana", 2}, {"apple", 5}};

  LOG_SECTION("Insert");
  inventory.insert({"cherry", 7});
  inventory.emplace("date", 1);
  inventory.try_emplace("apple", 100);  // keeps the existing 5
  LOG_S("apple = " << inventory.at("apple"));

  LOG_SECTION("Insert or update");
  inventory.insert_or_assign("apple", 10);
  inventory["banana"] = 4;
  inventory["kiwi"] = 3;

  LOG_SECTION("Look up");
  if (const auto it = inventory.find("apple"); it != inventory.end()) {
    LOG_S("found apple: " << it->second);
  }
  LOG_S("contains mango = " << inventory.contains("mango"));
  LOG_S("at cherry = " << inventory.at("cherry"));

  LOG_SECTION("Range-based loop (sorted by key)");
  // flat_map iterators return pairs of references; use const auto& or auto&&.
  for (const auto& [key, value] : inventory) {
    LOG_S(key << ": " << value);
  }

  LOG_SECTION("Iterators: begin / end");
  for (auto it = inventory.begin(); it != inventory.end(); ++it) {
    const auto [key, value] = *it;
    LOG_S(key << ": " << value);
  }

  LOG_SECTION("Const iterators: cbegin / cend");
  for (auto it = inventory.cbegin(); it != inventory.cend(); ++it) {
    const auto [key, value] = *it;
    LOG_S(key << ": " << value);
  }

  LOG_SECTION("Reverse iterators: rbegin / rend");
  for (auto it = inventory.rbegin(); it != inventory.rend(); ++it) {
    const auto [key, value] = *it;
    LOG_S(key << ": " << value);
  }

  LOG_SECTION("std::for_each");
  std::for_each(inventory.cbegin(), inventory.cend(), [](const auto& entry) {
    LOG_S(entry.first << ": " << entry.second);
  });

  LOG_SECTION("Erase");
  inventory.erase("banana");
  LOG_S("contains banana = " << inventory.contains("banana"));
  LOG_S("size = " << inventory.size());
  inventory.clear();
  LOG_S("empty = " << inventory.empty());
}
#else
LAB_EXAMPLE("FlatMap", "std::flat_map: requires C++23 and library support", lab::kDraft) {
  LOG("std::flat_map is unavailable in this build. Requires C++23 and library support.");
}
#endif
