#include "ui_mainwindow.h"
#include "mainwindow.h"

#include "loginwindow.h"

#include <QScreen>

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    startSWLoop();

    QPalette p = this->style()->standardPalette();
    p.setColor(QPalette::Highlight, QColor(17,164,166));
    ui->progressBar_P1Progress->setPalette(p);
    ui->progressBar_P2Progress->setPalette(p);

    p.setColor(QPalette::Highlight, QColor(194,38,30));
    ui->progressBar_P1Heat->setPalette(p);
    ui->progressBar_P2Heat->setPalette(p);
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::setClient(customClient* c, QString n)
{
    client = c;
    userName = n;
    ui->label_gameP1Name->setText(userName);
}

void mainWindow::on_toolButton_clicked()
{
    loginWindow* loginW = new loginWindow();
    loginW->setClient(client);
    loginW->move(QGuiApplication::primaryScreen()->geometry().center() - loginW->rect().center());
    loginW->show(); this->close();
}


void mainWindow::on_toolButton_2_clicked()
{

}


void mainWindow::startSWLoop()
{
    std::thread( [this] { this->start(); } ).detach();
}
void mainWindow::userUpdate()
{
//    std::cout << PodHeat << std::endl;
//    ui->label_p1Pod->setText(QString::fromStdString(Values.RacerNames[PodRacer]));
    ui->label_p1Track->setText(QString::fromStdString(Values.TrackNames[CurrentTrack]));
    ui->label_P1Timer->setText(QString::number(TotalTimer));
    ui->progressBar_P1Progress->setValue(MaxProgress*100000); ui->progressBar_P1Progress->update();
//    ui->progressBar_P1Heat->setValue(PodHeat); ui->progressBar_P1Heat->update();
}
