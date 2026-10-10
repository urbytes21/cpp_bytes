#pragma once

#include <map>
#include <memory>
#include <string>

#include "prototype/Extension.hpp"

namespace dp::prototype {

/// Registry of named presets
class ExtensionRegistry {
 public:
  void add(const std::string& name, std::unique_ptr<Extension> prototype);

  /// Returns a fresh copy of the preset, or nullptr for unknown names
  std::unique_ptr<Extension> create(const std::string& name) const;

 private:
  std::map<std::string, std::unique_ptr<Extension>> prototypes_;
};

}  // namespace dp::prototype
