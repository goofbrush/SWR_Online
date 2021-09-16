#include "ui_loginwindow.h"
#include "loginwindow.h"

#include "mainwindow.h"
#include "serverselect.h"

#include <QMessageBox>
#include <QScreen>
#include <iostream>


loginWindow::loginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_toolButton_clicked()
{
    serverSelect popup;
    popup.setModal(true);
    popup.exec();
}


void loginWindow::on_pushButton_2_clicked()
{
    if(client->isConnected()) {
        mainWindow* mainW = new mainWindow();
        mainW->setClient(client, ui->lineEdit_userName->text());
        mainW->move(QGuiApplication::primaryScreen()->geometry().center() - mainW->rect().center());
        mainW->show(); this->close();
    }
    else {
        customClient* client = new customClient();
        client->Connect("127.0.0.1", 60000);
        client->start();
        if(!client->blockUntilConnect(1)) {
            client->stopThread = true;
            while(!client->threadStopped) { }
            std::cout<<"couldntconnect"<<std::endl;
            client->Disconnect();
            client->stopThread = false; client->threadStopped = false;

            QMessageBox::warning(
                this,
                tr("Server Timeout"),
                tr("The server appears to be down") );
        }
        else {
            mainWindow* mainW = new mainWindow();
            mainW->setClient(client, ui->lineEdit_userName->text());
            mainW->move(QGuiApplication::primaryScreen()->geometry().center() - mainW->rect().center());
            mainW->show(); this->close();
        }

    }

}

