#include "view.h"
#include "ui_view.h"

View::View(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::View)
{
    _ui->setupUi(this);
    _controller = new Controller(this);
}

View::~View()
{
    delete _ui;
    delete _controller;
}

void View::PushToStack(const QString &name){
    _ui->stack_element_1_->text() = name;
}

void View::PopFromStackToOut(const QString &name){
    _ui->stack_element_1_->text() = "";
    _ui->out_element_1_->text() = name;
}
