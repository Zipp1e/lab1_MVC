#include "iterator.h"

Iterator::Iterator(std::vector<QString>& collection) :
    collection_(collection), current_index_(0)
{
}

QString& Iterator::GetNext() {
    if (current_index_ < collection_.size() - 1) {
        current_index_++;
    }
    return collection_[current_index_];
}

QString& Iterator::GetPrevious() {
    if (current_index_ > 0) {
        current_index_--;
    }
    return collection_[current_index_];
}

void Iterator::RewriteCurrent(const QString &name) {
    collection_[current_index_] = name;
}

int Iterator::GetCurrentIndex() {
    return current_index_;
}
