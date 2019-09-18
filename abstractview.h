#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include <QString>

class AbstractView
{
public:
    AbstractView() = default;
    virtual ~AbstractView() = default;
    virtual void PushToStack(const QString& name);
    virtual void PopFromStackToOut(const QString& name);
    virtual void Compare();
};

#endif // ABSTRACTVIEW_H
