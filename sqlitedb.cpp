/*
*  �������ڣ�
*  ����޸ģ�
*  ��       �ߣ�
*  �ļ�������
*/
#include "sqlitedb.h"

/*
*  ������
*  ���أ�
*  ���ܣ����캯��
*/
SqliteDB::SqliteDB(QObject *parent)
	: QObject(parent)
	, m_pSqliteDB(NULL)
	, m_messageList("")
{
	m_pSqliteDB = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
}


/*
*  ������
*  ���أ�
*  ���ܣ���������
*/
SqliteDB::~SqliteDB()
{
	if (m_pSqliteDB)
	{
		if (m_pSqliteDB->isOpen())
		{
			m_pSqliteDB->close();
		}

		delete m_pSqliteDB;
	}
}


/*
*  ������path--���ݿ�·��
*  ���أ���������ʱ��״̬��Ϣ
*  ���ܣ��������ݿ�
*/
bool SqliteDB::ConnectSqliteDB(const QString &path)
{
	bool state = false;
	m_messageList.clear();

	m_pSqliteDB->setDatabaseName(path);

	if (m_pSqliteDB->open())
	{
		state = true;
		m_messageList.push_back(QStringLiteral("�������ݿ�ɹ���"));
	}
	else
	{
		m_messageList.push_back(QStringLiteral("�������ݿ�ʧ�ܣ�"));
	}

	return state;
}


/*
*  ������path--���ݿ�·��
*             username--�û���
*             passward--����
*  ���أ���������ʱ��״̬��Ϣ
*  ���ܣ��������ݿ�
*/
bool SqliteDB::ConnectSqliteDB(const QString &path, const QString &username, const QString &passward)
{
	bool state = false;
	m_messageList.clear();

	m_pSqliteDB->setDatabaseName(path);
	m_pSqliteDB->setUserName(username);
	m_pSqliteDB->setPassword(passward);

	if (m_pSqliteDB->open())
	{
		state = true;
		m_messageList.push_back(QStringLiteral("�������ݿ�ɹ���"));
	}
	else
	{
		m_messageList.push_back(QStringLiteral("�������ݿ�ʧ�ܣ�"));
	}

	return state;
}


/*
*  ������
*  ���أ����ݿ�ر���Ϣ
*  ���ܣ��رմ򿪵����ݿ�
*/
bool SqliteDB::DisConnectSqliteDB()
{
	bool state = false;
	m_messageList.clear();

	if (m_pSqliteDB)
	{
		if (m_pSqliteDB->isOpen())
		{
			m_pSqliteDB->close();

			state = true;
			m_messageList.push_back(QStringLiteral("�ر����ݿ�ɹ���"));
		}
		else
		{
			m_messageList.push_back(QStringLiteral("���ݿ�δ���ӣ�"));
		}	
	}
	else
	{
		m_messageList.push_back(QStringLiteral("���ݿ�δ���ӣ�"));
	}

	return state;
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/