// -----------------------------------------------------------------------------
// std::unordered_map - hash table of unique keys to values
//
//              [k] - inserts a default if missing
//
//   +) Look up:
//              find(k) / contains(k) - check without inserting
//              at(k)
//
//  +) Insert:
//              insert() / emplace() / try_emplace() - keep an existing value
//              insert_or_assign() / map[key] = value - insert or update
//
// Reference: https://en.cppreference.com/w/cpp/container/unordered_map
// -----------------------------------------------------------------------------

#include <algorithm>
#include <ios>
#include <string>
#include <unordered_map>

#include "lab/Example.h"
#include "lab/Logger.h"

LAB_EXAMPLE("UnorderedMap",
            "std::unordered_map: insert, update, lookup, iterate, erase") {

  /// @brief Init
  std::unordered_map<std::string, int> inventory{{"apple", 5}, {"banana", 2}};

  /// @brief Insert
  LOG_SECTION("Insert");

  inventory.insert({"cherry", 7});
  inventory.emplace("date", 1);
  inventory.try_emplace("apple", 100);

  LOG_S("apple = " << inventory.at("apple"));

  /// @brief Insert or update
  LOG_SECTION("Insert or update");
  inventory.insert_or_assign("apple", 10);
  inventory["banana"] = 4;
  inventory["kiwi"] = 3;

  LOG_S("apple = " << inventory.at("apple"));
  LOG_S("banana = " << inventory.at("banana"));
  LOG_S("kiwi = " << inventory.at("kiwi"));

  /// @brief Read
  LOG_SECTION("Look up");
  if (const auto it = inventory.find("apple"); it != inventory.end()) {
    LOG_S("found apple: " << it->second);
  }

  LOG_S("contains mango: " << inventory.contains("mango"));
  LOG_S("at cherry: " << inventory.at("cherry"));
  LOG_S("operator[] mango: " << inventory["mango"]);

  /// @brief Traversal order is unspecified. unordered_map has no reverse iterators
  LOG_SECTION("Range-based loop: entries");
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
    // it->second can be updated; it->first (the key) is const.
  }

  LOG_SECTION("std::for_each");
  std::for_each(inventory.cbegin(), inventory.cend(), [](const auto& entry) {
    LOG_S(entry.first << ": " << entry.second);
  });

  LOG_SECTION("Buckets: local iterators");
  for (std::size_t bucket = 0; bucket < inventory.bucket_count(); ++bucket) {
    for (auto it = inventory.begin(bucket); it != inventory.end(bucket); ++it) {
      LOG_S("bucket " << bucket << ": " << it->first << " = " << it->second);
    }
  }

  /// @brief Erase
  LOG_SECTION("Erase");

  inventory.erase("banana");
  LOG_S("contains banana: " << inventory.contains("banana"));

  LOG_S("size: " << inventory.size());
  inventory.clear();
  LOG_S("empty: " << std::boolalpha << inventory.empty());
}
