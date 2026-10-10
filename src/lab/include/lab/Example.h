#pragma once

// -----------------------------------------------------------------------------
// LAB_EXAMPLE: define and register a runnable lab example.
//
// Example:
//
//   LAB_EXAMPLE("Hello", "Prints a greeting") {
//     LOG("Hello from the lab");
//   }
//
// The example's group is determined by its file path. For example:
//   src/core/smart_pointer/Weak.cpp -> core/smart_pointer
//
// Names must be unique within the same group and cannot contain spaces or '/'.
//
// Optional flags:
//
//   lab::kInteractive
//     For examples that wait for input, network activity, or never return.
//     These are skipped by --run-all and smoke tests.
//
//   lab::kDraft
//     For unfinished examples. The menu marks them as [draft].
//
// Examples are automatically registered before main().
// See docs/adding-examples.md for more details.
// -----------------------------------------------------------------------------

#include "Registry.h"

namespace lab::detail {
constexpr unsigned flags() noexcept {
  return kNone;
}
constexpr unsigned flags(unsigned value) noexcept {
  return value;
}
}  // namespace lab::detail

#define LAB_DETAIL_CONCAT_IMPL(a, b) a##b
#define LAB_DETAIL_CONCAT(a, b) LAB_DETAIL_CONCAT_IMPL(a, b)

#define LAB_EXAMPLE(name, description, ...)                              \
  LAB_DETAIL_EXAMPLE(LAB_DETAIL_CONCAT(lab_example_, __COUNTER__), name, \
                     description, ::lab::detail::flags(__VA_ARGS__))

#define LAB_DETAIL_EXAMPLE(function, name, description, flags)         \
  static void function();                                              \
  [[maybe_unused]] static const bool LAB_DETAIL_CONCAT(function,       \
                                                       _registered) =  \
      ::lab::Registry::instance().add(__FILE__, (name), (description), \
                                      &(function), (flags));           \
  static void function()
