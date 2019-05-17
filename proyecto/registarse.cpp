#include "registarse.h"
#include "ui_registarse.h"
#include "QDebug"
#include "QMessageBox"

Registarse::Registarse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registarse)
{
    ui->setupUi(this);
    CrearTabla();
}

Registarse::~Registarse()
{
    delete ui;
}

void Registarse::CrearTabla(){
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS usuario("
                    "nombre TEXT NOT NULL,"
                    "apellido TEXT NOT NULL,"
                    "usuar TEXT PRIMARY KEY,"
                    "contra TEXT NOT NULL,"
                    "documento REAL NOT NULL,"
                    "fecha INTEGER NOT NULL"
                    ");");
    QSqlQuery crear;
    crear.prepare(consulta);
    if(crear.exec())
        qDebug()<<"Tabla Creada";

}

void Registarse::on_btn_regristro_clicked(){
    QString name=ui->txt_name->text();
    QString apellido=ui->txt_apellido->text();
    QString usua=ui->txt_user->text();
    QString passw=ui->txt_password->text();
    QString document=ui->txt_document->text();
    QString fecha=ui->txt_date->text();
    qDebug()<<name;
    qDebug()<<apellido;
    qDebug()<<usua;
    qDebug()<<passw;
    qDebug()<<document;
    qDebug()<<fecha;

    QSqlQuery insert;
    insert.prepare("INSERT INTO usuario(nombre, apellido, usuar, contra, documento, fecha)"
                   "VALUES (:nombre, :apellido, :usuar, :contra, :documento, :fecha)"
                );
    insert.bindValue(":nombre", name);
    insert.bindValue(":apellido", apellido);
    insert.bindValue(":usuar", usua);
    insert.bindValue(":contra", passw);
    insert.bindValue(":documento", document);
    insert.bindValue(":fecha", fecha);
    if(insert.exec()){
        qDebug()<<"datos ingresados a la tabla";
        QMessageBox::information(this, tr("REALIZADO"), tr("Se ha registrado correctamente"));
    }
    else
        QMessageBox::critical(this, tr("ERROR"), tr("El usuario ya está en uso"));
}
