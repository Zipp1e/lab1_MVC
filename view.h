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
    void PushToStack(const QString& name) override;
    void PopFromStackToOut(const QString& name) override;
    void Compare(const bool& are_equal) override;

private:
    Ui::View *_ui;
    Controller *_controller;
};

#endif // VIEW_H
