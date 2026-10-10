#include "builder/House.hpp"

#include <utility>

namespace dp::builder {

void House::add_part(std::string part) {
  parts_.push_back(std::move(part));
}

std::string House::describe() const {
  std::string text;
  for (const std::string& part : parts_) {
    text += (text.empty() ? "" : ", ") + part;
  }
  return text.empty() ? "(empty)" : text;
}

}  // namespace dp::builder
