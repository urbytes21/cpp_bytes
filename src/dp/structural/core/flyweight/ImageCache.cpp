#include "flyweight/ImageCache.hpp"

namespace dp::flyweight {

std::shared_ptr<const ImageData> ImageCache::get(const std::string& file,
                                                 int width, int height) {
  const auto key =
      std::make_tuple(file, width, height);  // all intrinsic fields

  auto& slot = cache_[key];
  if (!slot) {
    slot = std::make_shared<const ImageData>(file, width, height);
  }

  return slot;
}

std::size_t ImageCache::size() const {
  return cache_.size();
}

std::size_t ImageCache::bytes() const {
  std::size_t total = 0;
  for (const auto& [key, image] : cache_) {
    total += image->bytes();
  }

  return total;
}

}  // namespace dp::flyweight
