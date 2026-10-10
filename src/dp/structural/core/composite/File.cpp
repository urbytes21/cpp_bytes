#include "composite/File.hpp"

#include <utility>

#include "lab/Logger.h"

namespace dp::composite {

File::File(std::string name, std::size_t bytes)
    : Node{std::move(name)}, bytes_{bytes} {}

std::size_t File::size_bytes() const {
  return bytes_;
}

void File::print(int depth) const {
  LOG_S(indent(depth) << "- " << name() << " (" << bytes_ << " B)");
}

}  // namespace dp::composite
