#pragma once

#include <memory>

#include "decorator/Notifier.hpp"

namespace dp::decorator {

/// Concrete component
std::unique_ptr<Notifier> make_email_notifier();

/// Concrete decorators: each wraps another notifier and adds behavior
std::unique_ptr<Notifier> make_sms_decorator(std::unique_ptr<Notifier> wrapped);

std::unique_ptr<Notifier> make_slack_decorator(
    std::unique_ptr<Notifier> wrapped);

/// Changes the message itself
std::unique_ptr<Notifier> make_urgent_decorator(
    std::unique_ptr<Notifier> wrapped);

}  // namespace dp::decorator
