#include "facade/BackendFactory.hpp"

#include <memory>

#include "FakeBackend.hpp"

namespace dp::facade {

std::unique_ptr<Backend> make_fake_backend() {
  return std::make_unique<FakeBackend>();
}

}  // namespace dp::facade
