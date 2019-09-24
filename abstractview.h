#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include <QString>

class AbstractView
{
public:
    AbstractView() = default;
    virtual ~AbstractView() = default;
    virtual void PushToStack(const QString& name) = 0;
    virtual void PopFromStackToOut(const QString& name) = 0;
    virtual void Compare(const bool& are_equal) = 0;
};

#endif // ABSTRACTVIEW_H
