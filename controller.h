#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "abstractcontroller.h"
#include "abstractview.h"

class Controller : public AbstractController
{
public:
    explicit Controller(AbstractView *view);
    ~Controller() override = default;
    void PushToStack(const QString& name) override;
    void PopFromStack() override;
    void Compare() override;
private:
    AbstractView *_view;
    //Stack *stack;
};

#endif // CONTROLLER_H
