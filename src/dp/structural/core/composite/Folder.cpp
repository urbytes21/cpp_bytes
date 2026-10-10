#include "composite/Folder.hpp"

#include "lab/Logger.h"

namespace dp::composite {

bool Folder::remove(const std::string& child_name) {
  return std::erase_if(children_, [&child_name](const auto& child) {
           return child->name() == child_name;
         }) > 0;
}

std::size_t Folder::size_bytes() const {
  std::size_t total = 0;
  for (const auto& child : children_) {
    total += child->size_bytes();  // leaf or folder - no need to know
  }

  return total;
}

void Folder::print(int depth) const {
  LOG_S(indent(depth) << "+ " << name() << "/ (" << size_bytes() << " B)");
  for (const auto& child : children_) {
    child->print(depth + 1);
  }
}

}  // namespace dp::composite
