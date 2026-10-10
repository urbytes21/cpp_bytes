#include "decorator/NotifierFactory.hpp"

#include <memory>
#include <utility>

#include "EmailNotifier.hpp"
#include "SlackDecorator.hpp"
#include "SmsDecorator.hpp"
#include "UrgentDecorator.hpp"

namespace dp::decorator {

std::unique_ptr<Notifier> make_email_notifier() {
  return std::make_unique<EmailNotifier>();
}

std::unique_ptr<Notifier> make_sms_decorator(
    std::unique_ptr<Notifier> wrapped) {
  return std::make_unique<SmsDecorator>(std::move(wrapped));
}

std::unique_ptr<Notifier> make_slack_decorator(
    std::unique_ptr<Notifier> wrapped) {
  return std::make_unique<SlackDecorator>(std::move(wrapped));
}

std::unique_ptr<Notifier> make_urgent_decorator(
    std::unique_ptr<Notifier> wrapped) {
  return std::make_unique<UrgentDecorator>(std::move(wrapped));
}

}  // namespace dp::decorator
