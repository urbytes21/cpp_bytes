#pragma once

#include <memory>

#include "observer/Listener.hpp"

namespace dp::observer {
std::unique_ptr<Listener> make_analytics_listener();
std::unique_ptr<Listener> make_sound_listener();
}  // namespace dp::observer
