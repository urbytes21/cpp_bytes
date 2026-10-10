#pragma once

#include <memory>

#include "facade/Subsystem.hpp"

namespace dp::facade {

/// A fake backend for tests: no network access
std::unique_ptr<Backend> make_fake_backend();

}  // namespace dp::facade
