#pragma once

#include <string>
#include <variant>

/// Modern alternative for a closed set of types: std::variant + std::visit
namespace dp::visitor::with_variant {

struct Paragraph {
  std::string text;
};

struct Image {
  std::string path;
};

using Element = std::variant<Paragraph, Image>;

/// Helper that merges several lambdas into one overloaded function object.
template <typename... Lambdas>
struct Overloaded : Lambdas... {
  using Lambdas::operator()...;
};

}  // namespace dp::visitor::with_variant
