#pragma once

#include <mutex>
#include <string>

namespace dp::singleton {

/// Meyers' singleton: one lazily created, thread-safe instance
class Config {
 public:
  static Config& instance();

  Config(const Config&) = delete;
  Config& operator=(const Config&) = delete;
  Config(Config&&) = delete;
  Config& operator=(Config&&) = delete;

  void set(const std::string& value);
  std::string get() const;

 private:
  Config();
  ~Config() = default;

  mutable std::mutex mutex_;
  std::string value_{"default"};
};

}  // namespace dp::singleton
