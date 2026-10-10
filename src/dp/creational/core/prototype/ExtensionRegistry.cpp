#include "prototype/ExtensionRegistry.hpp"

#include <utility>

namespace dp::prototype {

void ExtensionRegistry::add(const std::string& name,
                            std::unique_ptr<Extension> prototype) {
  prototypes_[name] = std::move(prototype);
}

std::unique_ptr<Extension> ExtensionRegistry::create(
    const std::string& name) const {
  const auto it = prototypes_.find(name);
  return it == prototypes_.end() ? nullptr : it->second->clone();
}

}  // namespace dp::prototype
