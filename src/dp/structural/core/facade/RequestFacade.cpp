#include "facade/RequestFacade.hpp"

#include <utility>

namespace dp::facade {

RequestFacade::RequestFacade(std::unique_ptr<Backend> backend)
    : backend_{std::move(backend)} {}

bool RequestFacade::send(const std::string& user,
                         const std::string& payload) const {
  if (!validator_.check(payload)) {
    return false;
  }

  if (!authenticator_.login(user)) {
    log_.write(user + " was rejected");
    return false;
  }

  log_.write(user + " sends a request");
  backend_->send(payload);

  return true;
}

}  // namespace dp::facade
