#include "AnalyticsListener.hpp"
#include "observer/Event.hpp"

#include "lab/Logger.h"

namespace dp::observer {

void AnalyticsListener::on_event(const std::string& source, Event event) {
  ++events_;
  LOG_S("    [analytics] recorded " << source << " " << to_string(event)
                                    << " (total " << events_ << ")");
}

}  // namespace dp::observer
