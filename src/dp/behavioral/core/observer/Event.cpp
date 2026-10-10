#include "observer/Event.hpp"

namespace dp::observer {

std::string to_string(Event event) {
  return event == Event::kPressed ? "pressed" : "released";
}

}  // namespace dp::observer
