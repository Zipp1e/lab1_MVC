#include "controller.h"
#include "stack.h"
#include <iostream>

Controller::Controller(AbstractView *view) :
    _view(view), _stack(new StringStack(10)), _out(new StringStack(10)), iterator_(_out->CreateIterator()) {
}

Controller::~Controller(){
    delete _stack;
    delete _out;
}
void Controller::PushToStack(const QString &name){
    _stack->Push(name);
    _view->FallIntoPit(name);
}

void Controller::PopFromStack(){
    _out->Push(_stack->Top());
    _stack->Pop();
    _view->TakeOutOfPit();
}

void Controller::Compare(){
    bool are_equal = (*_stack == *_out);
    _view->Compare(are_equal);
}

void Controller::IterateUp() {
    iterator_.GetNext();
    _view->ScrollUp(iterator_.GetCurrentIndex());
}

void Controller::IterateDown() {
    iterator_.GetPrevious();
    _view->ScrollDown(iterator_.GetCurrentIndex());
}

void Controller::ChangeName(const QString& name) {
    iterator_.RewriteCurrent(name);
    _view->RewriteName(iterator_.GetCurrentIndex());
}
