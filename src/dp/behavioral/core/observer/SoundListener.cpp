#include "SoundListener.hpp"

#include "lab/Logger.h"

namespace dp::observer {

void SoundListener::on_event(const std::string& /*source*/, Event event) {
  if (event == Event::kPressed) {
    LOG("    [sound] click!");
  }
}

}  // namespace dp::observer
