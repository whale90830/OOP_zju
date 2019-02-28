#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QMouseEvent>

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();


public slots:


private slots:
    void on_openImage_clicked();

    void on_train_clicked();

    void on_test_clicked();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
