#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "SWR_Base/SWEP1R.h"

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow, public SW
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

    void setClient(customClient* c, QString n);

    void startSWLoop();
    virtual void userUpdate() override;

private slots:
    void on_toolButton_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::mainWindow *ui;
    customClient* client;

    QString userName;
};

#endif // MAINWINDOW_H
