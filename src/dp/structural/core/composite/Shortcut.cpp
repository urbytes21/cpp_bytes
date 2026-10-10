#include "composite/Shortcut.hpp"

#include <utility>

#include "lab/Logger.h"

namespace dp::composite {

Shortcut::Shortcut(std::string name, std::string target)
    : Node{std::move(name)}, target_{std::move(target)} {}

std::size_t Shortcut::size_bytes() const {
  return 1;
}

void Shortcut::print(int depth) const {
  LOG_S(indent(depth) << "~ " << name() << " -> " << target_);
}

}  // namespace dp::composite
