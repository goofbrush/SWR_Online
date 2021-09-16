#ifndef SERVERSELECT_H
#define SERVERSELECT_H

#include <QDialog>

namespace Ui {
class serverSelect;
}

class serverSelect : public QDialog
{
    Q_OBJECT

public:
    explicit serverSelect(QWidget *parent = nullptr);
    ~serverSelect();

private:
    Ui::serverSelect *ui;
};

#endif // SERVERSELECT_H
