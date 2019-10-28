#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abstractcontroller.h"
#include "abstractview.h"


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
    void EraseFromCrowd();
    Crowd* crowd_;
private:
    AbstractView *_view;
    StringStack *_stack;
    StringStack *_out;
    Iterator iterator_;
    Savior* savior_;
};

#endif // CONTROLLER_H
