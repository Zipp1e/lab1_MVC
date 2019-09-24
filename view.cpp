#include "view.h"
#include "ui_view.h"
#include <iostream>

View::View(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::View)
{
    _ui->setupUi(this);
    _controller = new Controller(this);

    auto stack_input_slot = [&](){
        _controller->PushToStack(_ui->stack_input_name_->text());
        _ui->stack_input_name_->setText("");
    };
    auto stack_pop_slot = [&](){
        const QString& smth = _ui->stack_widget_1_->item(_ui->stack_widget_1_->count())->text();
        _controller->PopFromStack(smth);
    };
    auto compare_slot = [&](){
        _controller->Compare();
    };


    connect(_ui->stack_input_button_, &QPushButton::clicked, stack_input_slot);
    connect(_ui->stack_pop_button_, &QPushButton::clicked, stack_pop_slot);
    connect(_ui->compare_button_, &QPushButton::clicked, compare_slot); 
}

View::~View()
{
    delete _ui;
    delete _controller;
}

void View::PushToStack(const QString &name){
    _ui->stack_widget_1_->addItem(name);
}

void View::PopFromStackToOut(const QString &name){
    _ui->stack_widget_1_->takeItem(_ui->stack_widget_1_->count());
    _ui->stack_widget_2_->addItem(name);
}

void View::Compare(const bool& are_equal){
    if(are_equal){
        _ui->equality_label->setText("Равно!");
    } else {
        _ui->equality_label->setText("Не равно!");
    }
}
