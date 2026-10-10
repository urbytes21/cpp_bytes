#include <memory>

#include "bridge/RendererFactory.hpp"
#include "bridge/Widget.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

namespace {

namespace problem {

class Widget {
 public:
  virtual ~Widget() = default;
  virtual void draw() const = 0;
};

class Button : public Widget {};
class WindowsButton : public Button {
 public:
  void draw() const override { LOG("    WindowsButton::draw"); }
};
class LinuxButton : public Button {
 public:
  void draw() const override { LOG("    LinuxButton::draw"); }
};
class Label : public Widget {};
class WindowsLabel : public Label {
 public:
  void draw() const override { LOG("    WindowsLabel::draw"); }
};
class LinuxLabel : public Label {
 public:
  void draw() const override { LOG("    LinuxLabel::draw"); }
};
// Adding MacOs means MacOsButton, MacOsLabel, ...; adding a Slider means
// WindowsSlider, LinuxSlider, ... The hierarchy grows in two directions

void run() {
  LOG_SECTION("Problem: one subclass per widget AND platform");

  const std::unique_ptr<Widget> widgets[] = {std::make_unique<WindowsButton>(),
                                             std::make_unique<LinuxLabel>()};
  for (const auto& widget : widgets) {
    widget->draw();
  }
}

}  // namespace problem

void with_bridge() {
  using namespace dp::bridge;

  LOG_SECTION("Bridge: widgets and renderers vary independently");

  const auto windows = make_windows_renderer();
  const auto linux_renderer = make_linux_renderer();

  Button ok{windows, "OK"};
  const Label title{linux_renderer, "Settings"};
  ok.draw();
  title.draw();

  LOG("  switching the button's renderer at run time:");
  ok.set_renderer(linux_renderer);
  ok.draw();
}

}  // namespace

LAB_EXAMPLE(
    "Bridge",
    "separate abstraction from implementation to avoid M x N subclasses") {
  problem::run();
  with_bridge();
}
