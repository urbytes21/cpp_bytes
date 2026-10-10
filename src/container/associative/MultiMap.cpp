// -----------------------------------------------------------------------------
// std::multimap - sorted keys allowing duplicates
//
//   - Insert: insert() / emplace() keep every entry, including duplicate keys.
//   - Look up: find() returns one match; equal_range() returns all matches.
//   - Remove: erase(iterator) removes one entry; erase(key) removes every match.
//   - There is no operator[], at(), try_emplace() or insert_or_assign().
//
// Reference: https://en.cppreference.com/w/cpp/container/multimap
// -----------------------------------------------------------------------------

#include <algorithm>
#include <map>
#include <string>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("MultiMap", "std::multimap: duplicate keys, lookup, traverse, erase") {
  std::multimap<std::string, int> inventory{{"apple", 5}, {"banana", 2}};

  LOG_SECTION("Insert duplicate keys");
  inventory.insert({"apple", 10});
  inventory.emplace("apple", 20);
  LOG_S("count apple = " << inventory.count("apple"));  // 3

  LOG_SECTION("Look up");
  if (const auto it = inventory.find("apple"); it != inventory.end()) {
    LOG_S("one apple entry = " << it->second);
  }
  LOG_S("contains banana = " << inventory.contains("banana"));
  const auto [first, last] = inventory.equal_range("apple");
  for (auto it = first; it != last; ++it) {
    LOG_S("apple: " << it->second);
  }

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

  LOG_SECTION("Erase one or all matches");
  if (const auto it = inventory.find("apple"); it != inventory.end()) {
    inventory.erase(it);  // removes one apple entry
  }
  LOG_S("remaining apple entries = " << inventory.count("apple"));
  LOG_S("erase apple: removed = " << inventory.erase("apple"));
  LOG_S("size = " << inventory.size());
  inventory.clear();
  LOG_S("empty = " << inventory.empty());
}
