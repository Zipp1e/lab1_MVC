#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include <QString>

class AbstractView
{
public:
    AbstractView() = default;
    virtual ~AbstractView() = default;
    virtual void FallIntoPit(const QString& name) = 0;
    virtual void TakeOutOfPit() = 0;
    virtual void Compare(const bool& are_equal) = 0;
    virtual void ScrollUp(const int& number) = 0;
    virtual void ScrollDown(const int& number) = 0;
    virtual void RewriteName(const int& number) = 0;
};

#endif // ABSTRACTVIEW_H
