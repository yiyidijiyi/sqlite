/*
*  创建日期：
*  最后修改：
*  作       者：
*  文件描述：
*/
#ifndef SQLITEDB_H
#define SQLITEDB_H

#include <QObject>
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QtSql>
#include <Qtsql/QSqlQuery>

class SqliteDB : public QObject
{
	Q_OBJECT

public:
	SqliteDB(QObject *parent);
	~SqliteDB();

private:
	
};

#endif // SQLITEDB_H
