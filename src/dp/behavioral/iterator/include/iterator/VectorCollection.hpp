#pragma once

#include <cstddef>
#include <memory>
#include <vector>

#include "iterator/Iterator.hpp"

namespace dp::iterator {

template <typename T>
class VectorIterator : public Iterator<T> {
 public:
  explicit VectorIterator(const std::vector<T>& data) : data_{data} {}

  bool has_next() const override { return index_ < data_.size(); }

  const T& next() override { return data_[index_++]; }

 private:
  const std::vector<T>& data_;
  std::size_t index_{0};
};

template <typename T>
class VectorCollection : public Aggregate<T> {
 public:
  void add(const T& value) { data_.push_back(value); }

  std::unique_ptr<Iterator<T>> create_iterator() const override {
    return std::make_unique<VectorIterator<T>>(data_);
  }

 private:
  std::vector<T> data_;
};

}  // namespace dp::iterator
