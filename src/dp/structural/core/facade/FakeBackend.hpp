#pragma once

#include <string>

#include "facade/Subsystem.hpp"

namespace dp::facade {

/// A fake backend for tests: no network access
class FakeBackend : public Backend {
 public:
  void send(const std::string& payload) const override;
};

}  // namespace dp::facade
