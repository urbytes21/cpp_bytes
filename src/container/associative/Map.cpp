// -----------------------------------------------------------------------------
// std::map - sorted unique keys with mapped values
//
//   - Look up: find() / contains() / at(); operator[] inserts a default if missing.
//   - Insert: insert() / emplace() / try_emplace() keep an existing value.
//   - Insert or update: insert_or_assign() / map[key] = value.
//   - Ranges: lower_bound() (>= key) / upper_bound() (> key) / equal_range().
//
// Reference: https://en.cppreference.com/w/cpp/container/map
// -----------------------------------------------------------------------------

#include <algorithm>
#include <map>
#include <string>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("Map", "std::map: insert, update, lookup, sorted traversal, erase") {
  std::map<std::string, int> inventory{{"banana", 2}, {"apple", 5}};

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
  LOG_S("at cherry = " << inventory.at("cherry"));  // throws if missing
  LOG_S("operator[] mango = " << inventory["mango"]);  // inserts 0

  LOG_SECTION("Range-based loop: entries (sorted by key)");
  for (const auto& entry : inventory) {
    LOG_S(entry.first << ": " << entry.second);
  }

  LOG_SECTION("Range-based loop: structured bindings");
  for (const auto& [key, value] : inventory) {
    LOG_S(key << ": " << value);
  }

  LOG_SECTION("Iterators: begin / end");
  for (auto it = inventory.begin(); it != inventory.end(); ++it) {
    LOG_S(it->first << ": " << it->second);
  }

  LOG_SECTION("Const iterators: cbegin / cend");
  for (auto it = inventory.cbegin(); it != inventory.cend(); ++it) {
    LOG_S(it->first << ": " << it->second);
  }

  LOG_SECTION("Reverse iterators: rbegin / rend");
  for (auto it = inventory.rbegin(); it != inventory.rend(); ++it) {
    LOG_S(it->first << ": " << it->second);
  }

  LOG_SECTION("std::for_each");
  std::for_each(inventory.cbegin(), inventory.cend(), [](const auto& entry) {
    LOG_S(entry.first << ": " << entry.second);
  });

  LOG_SECTION("Key range: banana through date");
  const auto last = inventory.upper_bound("date");
  for (auto it = inventory.lower_bound("banana"); it != last; ++it) {
    LOG_S(it->first << ": " << it->second);
  }
  const auto [first, end] = inventory.equal_range("apple");
  for (auto it = first; it != end; ++it) {
    LOG_S("equal_range apple: " << it->second);
  }

  LOG_SECTION("Erase");
  inventory.erase("banana");
  LOG_S("contains banana = " << inventory.contains("banana"));
  LOG_S("size = " << inventory.size());
  inventory.clear();
  LOG_S("empty = " << inventory.empty());
}
