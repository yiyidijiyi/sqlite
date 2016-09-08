/*
*  �������ڣ�
*  ����޸ģ�
*  ��       �ߣ�
*  �ļ�������
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
	SqliteDB(QObject *parent = 0);
	~SqliteDB();

	bool ConnectSqliteDB(const QString &path);
	bool ConnectSqliteDB(const QString &path, const QString &username, const QString &passward);
	bool DisConnectSqliteDB();
private:
	QSqlDatabase *m_pSqliteDB;
	QStringList m_messageList;
};

#endif // SQLITEDB_H
