#pragma once

#include <QString>
#include <vector>

class StringDeque {
 public:

  explicit StringDeque(int n) : data_(n), head_(0), tail_(0), size_(0) {
  }

  int Size() const {
    return size_;
  }

  int MaxSize() const {
    return data_.size();
  }

  bool IsEmpty() const {
    return size_ == 0;
  }

  bool IsFull() const {
    return (size_ == data_.size());
  }

  bool PushBack(QString new_value) {
    if (size_ < data_.size()) {
      if (size_ != 0) {
        tail_++;
        tail_ = tail_ % data_.size();
        data_[tail_] = new_value;
      } else {
        data_[tail_] = new_value;
      }
      size_++;
      return true;
    } else {
      return false;
    }
  }

  QString Back(QString default_value = "") const {
    if (!IsEmpty()) {
      return data_[tail_];
    } else {
      return default_value;
    }
  }

  bool PopBack() {
    if (size_ != 0) {
      size_--;
      data_[tail_] = "";
      if (size_ != 0) {
        tail_--;
        if (tail_ < 0) {
          tail_ = tail_ + data_.size();
        }
      }
      return true;
    } else {
      return false;
    }
  }

  bool PushFront(QString new_value) {
    if (size_ < data_.size()) {
      if (size_ != 0) {
        head_--;
        if (head_ < 0) {
          head_ = head_ + data_.size();
        }
        data_[head_] = new_value;
      } else {
        data_[head_] = new_value;
      }
      size_++;
      return true;
    } else {
      return false;
    }
  }

  QString Front(QString default_value = "") const {
    if (size_ != 0) {
      return data_[head_];
    } else {
      return default_value;
    }
  }

  bool PopFront() {
    if (size_ != 0) {
      size_--;
      if (size_ != 0) {
        head_++;
        head_ = head_ % data_.size();
      }
      return true;
    } else {
      return false;
    }
  }

 private:
  std::vector<QString> data_;
  int size_;
  int head_;
  int tail_;
};

class StringStack {
 public:

  explicit StringStack(int max_size) : deque_(max_size) {}

  bool Push(QString value) {
    return deque_.PushBack(value);
  }

  QString Top(QString default_value = "") const {
    return deque_.Back(default_value);
  }

  bool Pop() {
    return deque_.PopBack();
  }

  int Size() const {
    return deque_.Size();
  }

  int MaxSize() const {
    return deque_.MaxSize();
  }

  bool IsEmpty() const {
    return deque_.IsEmpty();
  }

  bool IsFull() const {
    return deque_.IsFull();
  }

 private:
  StringDeque deque_;
};
