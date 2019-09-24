#include "controller.h"
#include "stack.h"
#include <iostream>

Controller::Controller(AbstractView *view) :
    _view(view), _stack(new StringStack(10)), _out(new StringStack(10)){
}

Controller::~Controller(){
    delete _stack;
    delete _out;
}
void Controller::PushToStack(const QString &name){
    _view->PushToStack(name);
    _stack->Push(name);
}

void Controller::PopFromStack(const QString& name){
    //std::cout << "name";
    _out->Push(_stack->Top());
    _stack->Pop();
    _view->PopFromStackToOut(name);
}

void Controller::Compare(){
    bool are_equal = (*_stack == *_out);
    _view->Compare(are_equal);
}
