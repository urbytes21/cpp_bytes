#include "singleton/Config.hpp"

#include "lab/Logger.h"

namespace dp::singleton {

Config& Config::instance() {
  static Config config;  // created once, on the first call, thread-safe
  return config;
}

Config::Config() {
  LOG("  Config constructed (happens exactly once)");
}

void Config::set(const std::string& value) {
  const std::lock_guard<std::mutex> lock(mutex_);  // the instance is shared
  value_ = value;
}

std::string Config::get() const {
  const std::lock_guard<std::mutex> lock(mutex_);
  return value_;
}

}  // namespace dp::singleton
