#include "observer/Button.hpp"
#include "observer/CallbackButton.hpp"
#include "observer/Event.hpp"
#include "observer/ListenerFactory.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::observer;

namespace {

void classic() {
  LOG_SECTION("Classic Observer with an interface");

  Button btn{"Save button"};
  auto analytics = make_analytics_listener();
  auto sound = make_sound_listener();

  btn.attach(*analytics);
  btn.attach(*sound);
  btn.press();
  btn.release();

  LOG("  -- detaching the sound listener --");
  btn.detach(*sound);
  btn.press();
}

void callback() {
  LOG_SECTION("Observers as std::function callbacks");

  CallbackButton btn;
  int clicks = 0;

  const int counter = btn.subscribe([&clicks](Event) { ++clicks; });
  btn.subscribe([](Event event) {
    LOG_S("    lambda observer got " << to_string(event));
  });

  btn.press();
  btn.press();
  btn.unsubscribe(counter);
  btn.press();

  LOG_S("  counter observer saw "
        << clicks << " clicks (it unsubscribed before the third)");
}

}  // namespace

LAB_EXAMPLE(
    "Observer",
    "publish/subscribe with listener interfaces or std::function callbacks") {

  classic();
  callback();
}
