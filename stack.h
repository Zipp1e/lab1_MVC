#pragma once
#ifndef STACK_H
#define STACK_H

#include <QString>
#include <vector>
#include "iterable.h"
#include "peoplegroup.h"

class StringStack : public Iterable, public PeopleGroup {
  friend class Iterator;
 public:

  explicit StringStack(const int& max_size) : max_size_(max_size){
    std::vector<QString> data_(max_size);
    size_ = 0;
  }

  bool operator== (const StringStack &b)
  {
    return (this->data_ == b.data_);
  }

  bool Push(const QString& value) {
    if (size_ < max_size_) {
      data_.push_back(value);
      size_++;
      return true;
    } else {
      return false;
    }
  }

  QString Top(const QString& default_value = "") const {
    return data_[size_ - 1];
  }

  bool Pop() {
    if (size_ != 0) {
      size_--;
      return true;
    } else {
      return false;
    }
  }

  int Size() const {
    return size_;
  }

  int MaxSize() const {
    return max_size_;
  }

  bool IsEmpty() const {
    return (size_ == 0);
  }

  bool IsFull() const {
    return (size_ == max_size_);
  }

  Iterator CreateIterator() override {
      return Iterator(data_);
  }
  void Accept(Visitor& v) override {
      v.VisitStack(this);
  }

 private:
  std::vector<QString> data_;
  int max_size_;
  int size_;
};

#endif // STACK_H
