#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include "abstractview.h"
#include "controller.h"

namespace Ui {
class View;
}

class View : public QMainWindow, public AbstractView {
    Q_OBJECT

public:
    explicit View(QWidget *parent = nullptr);
    ~View() override;
    void FallIntoPit(const QString& name) override;
    void TakeOutOfPit() override;
    void Compare(const bool& are_equal) override;
    void ScrollUp(const int& number) override;
    void ScrollDown(const int& number) override;
    void RewriteName(const int& number) override;

public slots:
    void stack_input_slot();
    void stack_pop_slot();
    void compare_slot();
    void scroll_up_slot();
    void scroll_down_slot();
    void change_name_slot();

private:
    Ui::View *_ui;
    Controller *_controller;
};

#endif // VIEW_H
