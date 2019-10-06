#ifndef ITERABLE_H
#define ITERABLE_H

#include "iterator.h"
#include <vector>
#include <QString>

class Iterable {
    virtual Iterator CreateIterator() = 0;
};

#endif // ITERABLE_H
