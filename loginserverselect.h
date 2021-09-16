#ifndef LOGINSERVERSELECT_H
#define LOGINSERVERSELECT_H

#include <QDialog>


namespace Ui { class loginServerSelect; }


class loginServerSelect : public QDialog
{
    Q_OBJECT
public:
    loginServerSelect(QWidget* parent = nullptr);
    ~loginServerSelect();

private:
    Ui::loginServerSelect *ui;
};

#endif // LOGINSERVERSELECT_H
