#pragma once

#include <string>

namespace dp::observer {

enum class Event { kPressed, kReleased };

std::string to_string(Event event);

}  // namespace dp::observer
