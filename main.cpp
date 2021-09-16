#include "client.h"
#include "loginwindow.h"

#include <QScreen>
#include <QApplication>

#include <iostream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    loginWindow w;
    w.setClient(new customClient());
    w.move(QGuiApplication::primaryScreen()->geometry().center() - w.rect().center());

    w.show();
    return a.exec();

}
