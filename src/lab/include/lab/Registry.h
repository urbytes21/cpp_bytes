#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace lab {

/// @brief Optional flags for an example
enum ExampleFlags : unsigned {
  kNone = 0U,
  kInteractive = 1U << 0U,
  kDraft = 1U << 1U,
};

using ExampleFunction = void (*)();

/// @brief A registered runnable example
struct Example {
  std::string id;           ///< Unique "<group>/<name>" identifier
  std::string group;        ///< Source directory below src/
  std::string name;         ///< Name shown in the menu
  std::string description;  ///< Short description
  std::string source;       ///< Source path relative to the repository root
  ExampleFunction run{nullptr};
  unsigned flags{kNone};

  bool isInteractive() const { return (flags & kInteractive) != 0U; }
  bool isDraft() const { return (flags & kDraft) != 0U; }

  /// @brief Returns labels for the example flags
  std::string labels() const;
};

/// @brief Stores and provides access to registered examples
class Registry {
 public:
  /// @brief Returns the global registry
  static Registry& instance();

  /// @brief Registers an example
  bool add(std::string_view file, std::string_view name,
           std::string_view description, ExampleFunction run,
           unsigned flags = kNone);

  /// @brief Returns all registered examples
  const std::vector<Example>& examples() const { return examples_; }

  /// @brief Finds an example by id
  const Example* find(std::string_view id) const;

  /// @brief Finds examples matching an id or description
  std::vector<const Example*> match(std::string_view filter) const;

  /// @brief Returns registration errors
  const std::vector<std::string>& errors() const { return errors_; }

 private:
  std::vector<Example> examples_;
  std::vector<std::string> errors_;
};

namespace detail {

/// @brief Makes a source path relative to the source root
std::string relativeSourcePath(std::string_view file,
                               std::string_view source_root);

/// @brief Gets the example group from its source path
std::string groupFromSourcePath(std::string_view relative_path);

}  // namespace detail
}  // namespace lab