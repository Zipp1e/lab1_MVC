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
    void PopFromStack() override;
    void Compare() override;
    void IterateUp();
    void IterateDown();
    void ChangeName(const QString& name);
private:
    AbstractView *_view;
    StringStack *_stack;
    StringStack *_out;
    Iterator iterator_;
};

#endif // CONTROLLER_H
