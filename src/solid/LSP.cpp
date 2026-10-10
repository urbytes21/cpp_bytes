#include <cassert>

#include "lab/Example.h"
#include "lab/Logger.h"

namespace {
namespace p {

class Rectangle {
 public:
  virtual ~Rectangle() = default;

  virtual void set_width(int w) = 0;
  virtual void set_height(int h) = 0;
  virtual int area() const = 0;
};

class RectangleImpl final : public Rectangle {
 public:
  void set_width(int w) override { width_ = w; }
  void set_height(int h) override { height_ = h; }
  int area() const override { return width_ * height_; }

 private:
  int width_ = 0;
  int height_ = 0;
};

class Square final : public Rectangle {
 public:
  void set_width(int w) override {
    width_ = w;
    height_ = w;  // must keep width == height
  }

  void set_height(int h) override {
    width_ = h;
    height_ = h;
  }

  int area() const override { return width_ * height_; }

 private:
  int width_ = 0;
  int height_ = 0;
};

}  // namespace p

namespace s {

/// @brief Narrow contract: only promises what every shape can honor
class Shape {
 public:
  virtual ~Shape() = default;

  virtual int area() const = 0;
};

class Rectangle final : public Shape {
 public:
  void set_width(int w) { width_ = w; }
  void set_height(int h) { height_ = h; }

  int area() const override { return width_ * height_; }

 private:
  int width_ = 0;
  int height_ = 0;
};

class Square final : public Shape {
 public:
  void setSide(int s) { side_ = s; }

  int area() const override { return side_ * side_; }

 private:
  int side_ = 0;
};

}  // namespace s
}  // namespace

LAB_EXAMPLE("LSP", "") {
  {
    LOG("VIOLATE LSP");
    auto set_and_verify = [](p::Rectangle& r) {
      r.set_width(5);
      r.set_height(4);
      if (r.area() != 20) {
        LOG("r.area() != 20");
      }
    };

    p::RectangleImpl rect;
    set_and_verify(rect);
    p::Square square;
    set_and_verify(square);
  }

  {
    s::Rectangle rect;
    rect.set_width(5);
    rect.set_height(4);
    assert(rect.area() == 20);

    s::Square square;
    square.setSide(5);
    assert(square.area() == 25);
  }
}