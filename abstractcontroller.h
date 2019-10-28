#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#endif // ABSTRACTCONTROLLER_H

#include <QString>
#include "savior.h"
#include "stack.h"

class AbstractController
{
public:
    virtual ~AbstractController() = default;
    virtual void PushToStack(const QString& name) = 0;
    virtual void PopFromStack() = 0;
    virtual void Compare() = 0;
};
