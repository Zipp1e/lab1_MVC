#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abstractcontroller.h"
#include "abstractview.h"
#include "stack.h"

class Controller : public AbstractController
{
public:
    explicit Controller(AbstractView *view);
    ~Controller() override;
    void PushToStack(const QString& name) override;
    void PopFromStack(const QString& name) override;
    void Compare() override;
private:
    AbstractView *_view;
    StringStack *_stack;
    StringStack *_out;
};

#endif // CONTROLLER_H
