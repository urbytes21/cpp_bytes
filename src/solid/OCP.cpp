#include <optional>
#include "lab/Example.h"
#include "lab/Logger.h"

namespace {

namespace p {
enum class Kind { kLocal, kRemote };

float read_local_temp() {
  LOG("message");
  return 0.0F;
}

float read_remote_temp() {
  LOG("message");
  return 0.0F;
}

float read_temperature(Kind kind) {
  float value = 0.0F;
  switch (kind) {
    case Kind::kLocal:
      value = read_local_temp();
      break;
    case Kind::kRemote:
      value = read_remote_temp();
      break;
  }
  return value;
}
}  // namespace p

namespace s {
struct Celsius {
  float value;
};

/// @brief Closed for modification
///        Adding a source never requires editing this interface.
class TemperatureSource {
 public:
  virtual std::optional<Celsius> read() = 0;
  virtual ~TemperatureSource() = default;
};

/// @brief Open for extension
//         A new concrete class per source with no changes to TemperatureSource or its consumers
class LocalTemperature final : public TemperatureSource {
 public:
  std::optional<Celsius> read() override {
    LOG("message");
    return Celsius{0.0F};
  }
};

class RemoteTemperature final : public TemperatureSource {
 public:
  std::optional<Celsius> read() override {
    LOG("message");
    return Celsius{0.0F};
  }
};

class SimulatedTemperature final : public TemperatureSource {
 public:
  std::optional<Celsius> read() override { return Celsius{25.0F}; }
};

/// @brief Stable consumer
//         Never changes when a source is added
void sample_and_report(TemperatureSource& source) {
  auto reading = source.read();
  if (reading) {
    LOG_S("message: " << reading->value);
  }
}
}  // namespace s

}  // namespace

LAB_EXAMPLE("OCP", "") {
  {
    LOG("VIOLATE OCP");
    p::read_temperature(p::Kind::kLocal);
  }

  {
    s::SimulatedTemperature source;
    s::sample_and_report(source);
  }
}
