#include "CardProcessor.hpp"

#include "lab/Logger.h"

namespace dp::adapter {

bool CardProcessor::pay(const std::string& customer, double amount_eur) {
  LOG_S("    [card] charged " << amount_eur << " EUR to the card of "
                              << customer);
  return true;
}

}  // namespace dp::adapter
