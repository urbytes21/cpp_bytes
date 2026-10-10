#pragma once

#include <atomic>
#include <mutex>
#include <source_location>
#include <string_view>
#include <sstream>  // IWYU pragma: keep

namespace lab {
class Logger {
 public:
  static Logger& instance();

  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;

  void log(std::string_view message,
           const std::source_location& loc = std::source_location::current());

  void logFunction(
      const std::source_location& loc = std::source_location::current());

  void section(std::string_view title);

  void setShowLocation(bool show) { show_location_ = show; }
  void setUseColor(bool use) { use_color_ = use; }
  bool showLocation() const { return show_location_; }

 private:
  Logger();
  void write(std::string_view message, const std::source_location& loc,
             bool with_function);

  std::mutex mutex_;
  std::atomic<bool> show_location_;
  std::atomic<bool> use_color_;
};

}  // namespace lab

/// @brief Log a string
#define LOG(message) ::lab::Logger::instance().log(message)

/// @brief Log anything that can be streamed into std::ostream.
#define LOG_S(...)                                        \
  do {                                                    \
    std::ostringstream lab_log_stream_;                   \
    lab_log_stream_ << __VA_ARGS__;                       \
    ::lab::Logger::instance().log(lab_log_stream_.str()); \
  } while (false)

/// @brief Log the signature of the current function
#define LOG_FUNC() ::lab::Logger::instance().logFunction()

/// @brief Print a separator to structure the output
#define LOG_SECTION(title) ::lab::Logger::instance().section(title)
