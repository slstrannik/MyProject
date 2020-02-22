#include "DBHandler.h"

DBHandler::DBHandler(QObject *parent)
{
    this->parent = parent;
    QSqlDatabase::drivers();
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("JFuvxdhv45dd");
}

QSqlDatabase DBHandler::getInstance()
{
    if (!db.open()) qDebug() << db.lastError().text();
    return db;
}

DBHandler::~DBHandler(){
    db.close();
}

QSqlTableModel* DBHandler::getModelIndexDB()
{
    QSqlRelationalTableModel* sqltm = new QSqlRelationalTableModel(parent, getInstance());
    sqltm->tableName();
    sqltm->setTable("users");
    sqltm->setEditStrategy(QSqlTableModel::OnRowChange);
    if (!sqltm->select())qDebug() << sqltm->lastError().text();
    return sqltm;
}
