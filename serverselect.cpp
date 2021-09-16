#include "serverselect.h"
#include "ui_serverselect.h"

serverSelect::serverSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::serverSelect)
{
    ui->setupUi(this);
}

serverSelect::~serverSelect()
{
    delete ui;
}
