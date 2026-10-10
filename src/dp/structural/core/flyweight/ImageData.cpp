#include "flyweight/ImageData.hpp"

#include <utility>

#include "lab/Logger.h"

namespace dp::flyweight {

ImageData::ImageData(std::string file, int width, int height)
    : file_{std::move(file)},
      width_{width},
      height_{height},
      pixels_(width * height) {
  LOG_S("    loading " << file_ << " (" << width_ << "x" << height_ << ")");
}

const std::string& ImageData::file() const {
  return file_;
}

std::size_t ImageData::bytes() const {
  return sizeof(*this) + pixels_.size() * sizeof(int);
}

}  // namespace dp::flyweight
