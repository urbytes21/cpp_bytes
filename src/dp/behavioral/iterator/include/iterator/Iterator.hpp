#pragma once

#include <memory>

namespace dp::iterator {

/// @brief Iterator interface
template <typename T>
class Iterator {
 public:
  virtual ~Iterator() = default;

  virtual bool has_next() const = 0;
  virtual const T& next() = 0;
};

/// Aggregate interface
template <typename T>
class Aggregate {
 public:
  virtual ~Aggregate() = default;

  virtual std::unique_ptr<Iterator<T>> create_iterator() const = 0;
};

}  // namespace dp::iterator
