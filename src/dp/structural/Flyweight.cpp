#include <cstddef>
#include <string>
#include <vector>

#include "flyweight/ImageCache.hpp"
#include "flyweight/Sprite.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

namespace {

constexpr int kWidth = 32;
constexpr int kHeight = 32;
constexpr std::size_t kSpriteCount = 2'000;

namespace problem {

/// Every sprite owns its own copy of the pixels (Rule of Zero: std::vector copies itself)
struct Sprite {
  std::string file;
  std::vector<int> pixels;  // intrinsic, duplicated in every object
  float x;
  float y;
  float scale;
};

void run() {
  LOG_SECTION("Problem: every object stores the same pixels");

  std::vector<Sprite> forest;
  forest.reserve(kSpriteCount);

  for (std::size_t i = 0; i < kSpriteCount; ++i) {
    forest.push_back({"tree.png", std::vector<int>(kWidth * kHeight),
                      static_cast<float>(i), 0.0F, 1.0F});
  }

  const std::size_t bytes =
      forest.size() * (sizeof(Sprite) + kWidth * kHeight * sizeof(int));

  LOG_S("  " << forest.size() << " sprites use about " << bytes / 1024
             << " KiB");
}

}  // namespace problem

void with_flyweight() {
  using namespace dp::flyweight;

  LOG_SECTION("Flyweight: share the pixels, keep only positions per object");

  ImageCache cache;
  std::vector<Sprite> forest;
  forest.reserve(kSpriteCount);

  for (std::size_t i = 0; i < kSpriteCount; ++i) {
    const char* file =
        (i % 3 == 0) ? "pine.png" : "oak.png";  // two distinct images
    forest.push_back(
        {cache.get(file, kWidth, kHeight), static_cast<float>(i), 0.0F, 1.0F});
  }

  const std::size_t bytes = forest.size() * sizeof(Sprite) + cache.bytes();

  LOG_S("  " << forest.size() << " sprites share " << cache.size()
             << " images, about " << bytes / 1024 << " KiB in total");
  LOG_S("  sprite 0 draws " << forest[0].image->file() << ", sprite 1 draws "
                            << forest[1].image->file() << " (use_count "
                            << forest[1].image.use_count() << ")");
}

}  // namespace

LAB_EXAMPLE("Flyweight",
            "share immutable intrinsic state between many small objects") {
  problem::run();
  with_flyweight();
}
