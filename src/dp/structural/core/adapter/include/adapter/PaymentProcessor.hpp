#pragma once

#include <string>

namespace dp::adapter {

/// Target: what the shop checkout already uses
class PaymentProcessor {
 public:
  virtual ~PaymentProcessor() = default;

  virtual bool pay(const std::string& customer, double amount_eur) = 0;
};

}  // namespace dp::adapter
