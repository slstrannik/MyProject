#pragma once

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQueryModel>
#include <QSqlRelationalTableModel>
#include <QDebug>

class DBHandler
{
private:
    QObject *parent = nullptr;
    QSqlDatabase db;
public:
    DBHandler(QObject*);
    ~DBHandler();
    QSqlDatabase getInstance();
    QSqlTableModel *getModelIndexDB();
};

