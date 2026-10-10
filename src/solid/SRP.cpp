#include "lab/Example.h"
#include "lab/Logger.h"

namespace {
namespace p {

/// @brief This class has at least 3 reasons to change
class SensorManager {
 public:
  int read_adc();
  void log_csv(float value);

  void step();  // workflow
};

int SensorManager::read_adc() {
  LOG("message");
  return 0;
}

void SensorManager::log_csv(float value) {
  (void)value;
  LOG("message");
}

void SensorManager::step() {
  read_adc();
  log_csv(0);
}

}  // namespace p

namespace s {
/// @brief Changes only if the ADC chip or bus protocol changes
class ADC {
 public:
  int read() {
    LOG("message");
    return 0;
  }
};

/// @brief Changes only if the log format or destination changes
class Logger {
 public:
  void log(float value) {
    (void)value;
    LOG("message");
  }
};

/// @brief Changes only if the step sequence itself changes
class SensorManager {
 public:
  SensorManager(ADC& adc, Logger& logger) : adc_(adc), logger_(logger) {}

  void step() {
    int raw = adc_.read();
    logger_.log(static_cast<float>(raw));
  }

 private:
  ADC& adc_;
  Logger& logger_;
};
}  // namespace s

}  // namespace

LAB_EXAMPLE("SRP", "") {
  {
    LOG("VIOLATE SRP");
    p::SensorManager mng;
    mng.step();
  }

  {
    s::ADC adc;
    s::Logger logger;
    s::SensorManager sensor(adc, logger);

    sensor.step();
  }
}
