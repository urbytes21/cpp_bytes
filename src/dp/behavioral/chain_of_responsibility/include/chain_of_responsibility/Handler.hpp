#pragma once

#include <functional>
#include <optional>
#include "chain_of_responsibility/Request.hpp"

namespace dp::chain_of_responsibility {

/// Handler: stores the next link and forwards by default.
class Handler {
 public:
  virtual ~Handler() = default;

  /// Returns `next` so a chain can be written as a.setNext(b).setNext(c).
  Handler& set_next(Handler& next);

  virtual void handle(const Request& request) const;

 private:
  // non-owning: the client owns all handlers
  std::optional<std::reference_wrapper<Handler>> next_;
};

}  // namespace dp::chain_of_responsibility
