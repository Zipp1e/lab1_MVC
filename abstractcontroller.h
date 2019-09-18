#ifndef ABSTRACTCONTROLLER_H
#define ABSTRACTCONTROLLER_H

#endif // ABSTRACTCONTROLLER_H

#include <QString>

class AbstractController
{
public:
    virtual ~AbstractController() = default;
    virtual void PushToStack(const QString& name);
    virtual void PopFromStack();
    virtual void Compare();
};
