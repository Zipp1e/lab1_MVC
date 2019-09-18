#include "controller.h"

Controller::Controller(AbstractView *view) : _view(view){
}

void Controller::PushToStack(const QString &name){
    _view->PushToStack(name);
}

void Controller::PopFromStack(){
    _view->PopFromStack();
}
