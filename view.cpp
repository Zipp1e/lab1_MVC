#include "view.h"
#include "ui_view.h"
#include <iostream>

View::View(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::View)
{
    _ui->setupUi(this);
    _controller = new Controller(this);
    for (QString& item : _controller->crowd_->people_) {
        _ui->crowd_view_->addItem(item);
    }


    QObject::connect(_ui->stack_input_button_, &QPushButton::clicked, this, &View::stack_input_slot);
    QObject::connect(_ui->stack_pop_button_, &QPushButton::clicked, this, &View::stack_pop_slot);
    QObject::connect(_ui->compare_button_, &QPushButton::clicked, this, &View::compare_slot);
    QObject::connect(_ui->iterate_up_button_, &QPushButton::clicked, this, &View::scroll_up_slot);
    QObject::connect(_ui->iterate_down_button_, &QPushButton::clicked, this, &View::scroll_down_slot);
    QObject::connect(_ui->change_button_, &QPushButton::clicked, this, &View::change_name_slot);
    QObject::connect(_ui->save_button_, &QPushButton::clicked, this, &View::crowd_erase_slot);
}


View::~View()
{
    delete _ui;
    delete _controller;
}



void View::stack_input_slot() {
    _ui->label->setText("ok");
    _controller->PushToStack(_ui->stack_input_name_->text());
}
void View::stack_pop_slot() {
    _controller->PopFromStack();
}
void View::compare_slot() {
    _controller->Compare();
}

void View::scroll_up_slot() {
    _controller->IterateUp();
}

void View::scroll_down_slot() {
    _controller->IterateDown();
}

void View::change_name_slot() {
    _controller->ChangeName(_ui->change_name_->text());
}

void View::crowd_erase_slot() {
    _controller->EraseFromCrowd();
}


void View::FallIntoPit(const QString &name){
    _ui->stack_widget_1_->addItem(name);
    _ui->stack_input_name_->setText("");
}

void View::TakeOutOfPit(){
    QString name = _ui->stack_widget_1_->item(_ui->stack_widget_1_->count()-1)->text();
    _ui->stack_widget_1_->takeItem(_ui->stack_widget_1_->count()-1);
    _ui->stack_widget_2_->addItem(name);
}

void View::Compare(const bool& are_equal){
    if(are_equal){
        _ui->equality_label->setText("Равно!");
    } else {
        _ui->equality_label->setText("Не равно!");
    }
}

void View::ScrollUp(const int &number) {
    _ui->stack_widget_2_->item(number)->setForeground(Qt::blue);
    if (number > 0) {
        _ui->stack_widget_2_->item(number-1)->setForeground(Qt::white);
    }
    _ui->change_name_->setText(_ui->stack_widget_2_->item(number)->text());
}

void View::ScrollDown(const int &number) {
    _ui->stack_widget_2_->item(number)->setForeground(Qt::blue);
    if (number < _ui->stack_widget_2_->count()) {
        _ui->stack_widget_2_->item(number+1)->setForeground(Qt::black);
    }
    _ui->change_name_->setText(_ui->stack_widget_2_->item(number)->text());
}

void View::RewriteName(const int &number) {
    _ui->stack_widget_2_->item(number)->setText(_ui->change_name_->text());
}

void View::SaveFromCrowd() {
    _ui->crowd_view_->takeItem(0);
}
