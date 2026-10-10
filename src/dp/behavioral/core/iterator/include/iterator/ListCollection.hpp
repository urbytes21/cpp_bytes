#pragma once

#include <list>
#include <memory>

#include "iterator/Iterator.hpp"

namespace dp::iterator {

template <typename T>
class ListIterator : public Iterator<T> {
 public:
  explicit ListIterator(const std::list<T>& data)
      : data_{data}, position_{data.begin()} {}

  bool has_next() const override { return position_ != data_.end(); }
  const T& next() override { return *position_++; }

 private:
  const std::list<T>& data_;
  typename std::list<T>::const_iterator position_;
};

template <typename T>
class ListCollection : public Aggregate<T> {
 public:
  void add(const T& value) { data_.push_back(value); }

  std::unique_ptr<Iterator<T>> create_iterator() const override {
    return std::make_unique<ListIterator<T>>(data_);
  }

 private:
  std::list<T> data_;
};

}  // namespace dp::iterator
