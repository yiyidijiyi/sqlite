/*
*  �������ڣ�2016-09-08
*  ����޸ģ�2016-09-09
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

	QStringList& GetMessage();

	bool ConnectSqliteDB(const QString &path,  const QString &passward = QString(""));
	bool DisconnectSqliteDB();
	bool CreateSqliteDB(const QString &path, const QString &passward = QString(""));

	bool SetPassward(const QString &passward);
private:
	QSqlDatabase *m_pSqliteDB;
	QStringList m_messageList;
};

#endif // SQLITEDB_H
