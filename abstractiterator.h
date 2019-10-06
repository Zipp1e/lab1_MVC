#ifndef ABSTRACTITERATOR_H
#define ABSTRACTITERATOR_H

#include <QString>

class AbstractIterator
{
public:
    AbstractIterator() = default;
    virtual ~AbstractIterator() = default;
    virtual QString& GetNext() = 0;
    virtual QString& GetPrevious() = 0;
};

#endif // ABSTRACTITERATOR_H
