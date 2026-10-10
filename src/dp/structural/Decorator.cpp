#include <memory>
#include <string>
#include <utility>

#include "decorator/Notifier.hpp"
#include "decorator/NotifierFactory.hpp"

#include "lab/Example.h"
#include "lab/Logger.h"

using namespace dp::decorator;

namespace {

namespace problem {

class EmailNotifier : public Notifier {
 public:
  void send(const std::string& message) const override {
    LOG_S("    email: " << message);
  }
};

class EmailAndSmsNotifier : public EmailNotifier {
 public:
  void send(const std::string& message) const override {
    EmailNotifier::send(message);
    LOG_S("    sms  : " << message);
  }
};

class EmailAndSlackNotifier : public EmailNotifier {
 public:
  void send(const std::string& message) const override {
    EmailNotifier::send(message);
    LOG_S("    slack: " << message);
  }
};

class EmailAndSmsAndSlackNotifier : public EmailAndSmsNotifier {
 public:
  void send(const std::string& message) const override {
    EmailAndSmsNotifier::send(message);
    LOG_S("    slack: " << message);
  }
};
// ...plus SmsOnly, SlackOnly, SmsAndSlack... one class per combination

void run() {
  LOG_SECTION("Problem: one subclass per combination");
  const EmailAndSmsAndSlackNotifier notifier;
  notifier.send("server is down");
}

}  // namespace problem

void with_decorator() {
  LOG_SECTION("Decorator: combine features by wrapping");

  std::unique_ptr<Notifier> notifier = make_email_notifier();
  LOG("  email only:");
  notifier->send("build finished");

  notifier = make_sms_decorator(std::move(notifier));
  notifier = make_slack_decorator(std::move(notifier));
  LOG("  email + sms + slack:");
  notifier->send("deploy started");

  notifier = make_urgent_decorator(std::move(notifier));
  LOG("  wrapped once more with UrgentDecorator:");
  notifier->send("server is down");
}

}  // namespace

LAB_EXAMPLE(
    "Decorator",
    "stack wrappers at run time instead of subclassing every combination") {
  problem::run();
  with_decorator();
}
