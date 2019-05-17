#ifndef REGISTARSE_H
#define REGISTARSE_H

#include "QtSql/QSqlDatabase"
#include "QtSql/qsqlquery.h"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include <QWidget>

namespace Ui {
class Registarse;
}

class Registarse : public QWidget
{
    Q_OBJECT

public:
    explicit Registarse(QWidget *parent = 0);
    ~Registarse();
    void CrearTabla();
private slots:
    void on_btn_regristro_clicked();

private:
    Ui::Registarse *ui;
};

#endif // REGISTARSE_H
