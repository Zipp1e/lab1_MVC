#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include "abstractiterator.h"

class Iterator : public AbstractIterator
{
public:
    Iterator(std::vector<QString>& collection);
    QString& GetNext() override;
    QString& GetPrevious() override;
    void RewriteCurrent(const QString& name);
    int GetCurrentIndex();

private:
    std::vector<QString>& collection_;
    int current_index_;
};

#endif // ITERATOR_H
