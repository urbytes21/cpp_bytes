#pragma once

#include <cstddef>

namespace dp::iterator {

/// A fixed ring of numbers that supports range-based for and std algorithms
class Ring {
 public:
  class iterator {  // NOLINT(readability-identifier-naming): standard naming
   public:
    using value_type = int;
    using difference_type = std::ptrdiff_t;

    iterator() = default;

    iterator(const Ring* ring, std::size_t index)
        : ring_{ring}, index_{index} {}

    int operator*() const {
      return ring_->values_[(ring_->start_ + index_) % kSize];
    }

    iterator& operator++() {
      ++index_;
      return *this;
    }

    iterator operator++(int) {
      iterator old = *this;
      ++index_;
      return old;
    }

    bool operator==(const iterator& other) const {
      return index_ == other.index_;
    }

   private:
    const Ring* ring_{nullptr};
    std::size_t index_{0};
  };

  explicit Ring(std::size_t start) : start_{start % kSize} {}
  iterator begin() const { return {this, 0}; }
  iterator end() const { return {this, kSize}; }

 private:
  static constexpr std::size_t kSize = 5;
  int values_[kSize]{10, 20, 30, 40, 50};
  std::size_t start_;
};

}  // namespace dp::iterator
