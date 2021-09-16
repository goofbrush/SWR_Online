#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class loginWindow; }
QT_END_NAMESPACE

class loginWindow : public QMainWindow
{
    Q_OBJECT

public:
    loginWindow(QWidget *parent = nullptr);
    ~loginWindow();

    void setClient(customClient* c) { client = c; }

private slots:
    void on_toolButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::loginWindow *ui;
    customClient* client;
};
#endif // LOGINWINDOW_H
