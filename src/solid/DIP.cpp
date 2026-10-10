#include "lab/Example.h"
#include "lab/Logger.h"

namespace {
namespace p {

class Bulb {
 public:
  void turn_on() {}
  void turn_off() {}
};

class Switch {
  Bulb bulb_;  // depends on a concrete, low-level class
 public:
  void toggle(bool on) { on ? bulb_.turn_on() : bulb_.turn_off(); }
};

}  // namespace p

namespace s {
// Switch
// v
// ISwitchable
// ^
// Bulb

class ISwitchable;

class Switch {
  ISwitchable& device_;  // depends on an abstraction
 public:
  explicit Switch(ISwitchable& device) : device_(device) {}
  void toggle(bool on);
};

class ISwitchable {
 public:
  virtual ~ISwitchable() = default;

  virtual void turn_on() = 0;
  virtual void turn_off() = 0;
};

class Bulb : public ISwitchable {
 public:
  void turn_on() override {}
  void turn_off() override {}
};

void Switch::toggle(bool on) {
  on ? device_.turn_on() : device_.turn_off();
}
}  // namespace s

}  // namespace

LAB_EXAMPLE("DIP", "") {
  {
    LOG("VIOLATE DIP");
    p::Switch bad_switch;
    bad_switch.toggle(true);
  }

  {
    s::Bulb bulb;
    s::Switch good_switch(bulb);
    good_switch.toggle(true);
  }
}