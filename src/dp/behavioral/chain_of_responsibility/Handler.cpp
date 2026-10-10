#include "chain_of_responsibility/Handler.hpp"

#include "lab/Logger.h"

namespace dp::chain_of_responsibility {

Handler& Handler::set_next(Handler& next) {
  next_ = next;
  return next_.value();
}

void Handler::handle(const Request& request) const {
  if (next_.has_value()) {
    next_->get().handle(request);
  } else {
    LOG_S("  [end of chain] nobody handled " << request.method << ' '
                                             << request.path);
  }
}

}  // namespace dp::chain_of_responsibility
