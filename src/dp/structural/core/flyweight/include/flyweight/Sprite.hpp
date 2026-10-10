#pragma once

#include <memory>

#include "flyweight/ImageData.hpp"

namespace dp::flyweight {

/// Context: extrinsic state + shared flyweight
struct Sprite {
  std::shared_ptr<const ImageData> image;
  float x;
  float y;
  float scale;
};

}  // namespace dp::flyweight
