#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registarse.h"
#include "inicio.h"
#include "QDebug"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString nombre;
    nombre="DataBase.sqlite";
    daba = QSqlDatabase::addDatabase("QSQLITE");
    daba.setDatabaseName(nombre);
    if(daba.open())
        qDebug()<<"Base de datos creada";
    else
        qDebug()<<"Error";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Btn_Regis_clicked(){
    Registarse *res = new Registarse(0);
    res->show();
}


void MainWindow::on_Btn_login_clicked(){
    QString name=ui->txt_name->text();
    QString passw=ui->txt_password->text();
    QString user=ui->txt_user->text();
    QSqlQuery share;
    QString pass;
    QString neim;
    QString consult;

    consult.append("SELECT * FROM usuario where usuar='"+user+"'");
    share.prepare(consult);
    if(share.exec()){
        qDebug()<<"Consulta Realizada";
        while(share.next()){
            neim=share.value(0).toByteArray().constData();
            pass=share.value(3).toByteArray().constData();
        }
    } else
    QMessageBox::critical(this, tr("ERROR"), tr("Usuario no existe"));


    if(pass==passw && neim==name){
        Inicio *ini= new Inicio(0);
        ini->show();
    }
    else
      QMessageBox::critical(this, tr("Error"), tr("Contraseña o  Nombre Incorrectos."));

}
