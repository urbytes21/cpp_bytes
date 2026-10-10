#pragma once

#include <string>

#include "adapter/PaymentProcessor.hpp"

namespace dp::adapter {

class CardProcessor : public PaymentProcessor {
 public:
  bool pay(const std::string& customer, double amount_eur) override;
};

}  // namespace dp::adapter
