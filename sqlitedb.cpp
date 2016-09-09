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
	m_pSqliteDB = new QSqlDatabase(QSqlDatabase::addDatabase("SQLITECIPHER"));
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
*  ������
*  ���أ�
*  ���ܣ�
*/
QStringList& SqliteDB::GetMessage()
{
	return m_messageList;
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

	if (m_pSqliteDB)
	{
		m_pSqliteDB->setDatabaseName(path);

		if (m_pSqliteDB->isOpen())
		{
			m_messageList.push_back(QStringLiteral("������һ�����ݿ⣬��Ͽ���ǰ���ݿ���������µ����ݿ⣡"));
		}
		else
		{
			if (m_pSqliteDB->open())
			{
				state = true;
				m_messageList.push_back(QStringLiteral("�������ݿ�ɹ���"));
			}
			else
			{
				m_pSqliteDB->close();
				m_messageList.push_back(QStringLiteral("�������ݿ�ʧ�ܣ�"));
				m_messageList.push_back(m_pSqliteDB->lastError().text());
			}
		}
	}
	else
	{
		m_messageList.push_back(QStringLiteral("��ʼ��QSqlDatabase����"));
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
bool SqliteDB::ConnectSqliteDB(const QString &path, const QString &userName, const QString &passward)
{
	bool state = false;
	m_messageList.clear();


	if (m_pSqliteDB)
	{
		m_pSqliteDB->setDatabaseName(path);
		m_pSqliteDB->setUserName(userName);
		m_pSqliteDB->setPassword(passward);

		if (m_pSqliteDB->isOpen())
		{
			m_messageList.push_back(QStringLiteral("������һ�����ݿ⣬��Ͽ���ǰ���ݿ���������µ����ݿ⣡"));
		}
		else
		{
			if (m_pSqliteDB->open())
			{
				state = true;
				m_messageList.push_back(QStringLiteral("�������ݿ�ɹ���"));
			}
			else
			{
				m_messageList.push_back(QStringLiteral("�������ݿ�ʧ�ܣ�"));
				m_messageList.push_back(m_pSqliteDB->lastError().text());
			}
		}
	}
	else
	{
		m_messageList.push_back(QStringLiteral("��ʼ��QSqlDatabase����"));
	}

	return state;
}


/*
*  ������
*  ���أ����ݿ�ر���Ϣ
*  ���ܣ��رմ򿪵����ݿ�
*/
bool SqliteDB::DisconnectSqliteDB()
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
*  ������passward--����
*  ���أ�
*  ���ܣ��������ݿ������
*/
bool SqliteDB::SetUserNamePassward(const QString &userName, const QString &passward)
{
	bool state = false;
	m_messageList.clear();

	if (!m_pSqliteDB)
	{
		m_messageList.push_back(QStringLiteral("��ʼ��QSqlDatabase����"));
	}
	else
	{
		if (m_pSqliteDB->isOpen())
		{
			m_pSqliteDB->close();
		}
		
		m_pSqliteDB->setPassword(passward);
		m_pSqliteDB->setConnectOptions("QSQLITE_CREATE_KEY");

		if (m_pSqliteDB->open())
		{
			m_messageList.push_back(QStringLiteral("���ݿ��������óɹ���"));
		}
		else
		{
			m_messageList.push_back(QStringLiteral("���ݿ���������ʧ�ܣ�"));
		}
	}

	return state;
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/