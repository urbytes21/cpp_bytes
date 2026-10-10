#include "observer/ListenerFactory.hpp"

#include <memory>

#include "AnalyticsListener.hpp"
#include "SoundListener.hpp"

namespace dp::observer {

std::unique_ptr<Listener> make_analytics_listener() {
  return std::make_unique<AnalyticsListener>();
}

std::unique_ptr<Listener> make_sound_listener() {
  return std::make_unique<SoundListener>();
}

}  // namespace dp::observer
