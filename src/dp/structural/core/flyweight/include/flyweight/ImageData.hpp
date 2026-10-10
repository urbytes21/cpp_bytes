#pragma once

#include <cstddef>
#include <string>
#include <vector>

namespace dp::flyweight {

/// Flyweight: intrinsic state, immutable and therefore safe to share
class ImageData {
 public:
  ImageData(std::string file, int width, int height);

  const std::string& file() const;
  std::size_t bytes() const;

 private:
  std::string file_;
  int width_;
  int height_;
  std::vector<int> pixels_;
};

}  // namespace dp::flyweight
