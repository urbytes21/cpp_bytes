#pragma once

#include <cstddef>
#include <map>
#include <memory>
#include <string>
#include <tuple>

#include "flyweight/ImageData.hpp"

namespace dp::flyweight {

/// Flyweight factory: one ImageData per distinct (file, width, height)
class ImageCache {
 public:
  std::shared_ptr<const ImageData> get(const std::string& file, int width,
                                       int height);

  std::size_t size() const;
  std::size_t bytes() const;

 private:
  std::map<std::tuple<std::string, int, int>, std::shared_ptr<const ImageData>>
      cache_;
};

}  // namespace dp::flyweight
