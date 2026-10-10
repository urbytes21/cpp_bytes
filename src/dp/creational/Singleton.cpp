#include <cstddef>
#include <thread>
#include <vector>

#include "singleton/Config.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::singleton;

LAB_EXAMPLE("Singleton",
            "Meyers' singleton: one lazily created, thread-safe instance") {

  LOG_SECTION("One instance, global access");
  LOG("  first call to Config::instance():");
  Config& config = Config::instance();
  config.set("0x001");

  LOG_SECTION("Every thread gets the same object");
  std::vector<const Config*> seen(4, nullptr);
  std::vector<std::thread> threads;
  for (std::size_t i = 0; i < seen.size(); ++i) {
    threads.emplace_back([&seen, i] { seen[i] = &Config::instance(); });
  }

  for (std::thread& thread : threads) {
    thread.join();
  }

  bool all_same = true;
  for (const Config* address : seen) {
    all_same = all_same && address == &config;
  }

  LOG_S("  4 threads saw the same address: " << std::boolalpha << all_same);
}
