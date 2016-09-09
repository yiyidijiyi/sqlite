/*
*  �������ڣ�2016-09-08
*  ����޸ģ�2016-09-09
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
*             passward--����
*  ���أ���������ʱ��״̬��Ϣ
*  ���ܣ��������ݿ�
*/
bool SqliteDB::ConnectSqliteDB(const QString &path,  const QString &passward)
{
	bool state = false;
	m_messageList.clear();


	if (m_pSqliteDB)
	{
		m_pSqliteDB->setDatabaseName(path);

		if (!passward.isEmpty())
		{
			m_pSqliteDB->setPassword(passward);
		}		

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
*  ������path--���ݿ�·��
*             passward--����
*  ���أ�0-����ʧ�ܣ�1-�����ɹ�
*  ���ܣ��������ݿ������
*/
bool SqliteDB::CreateSqliteDB(const QString &path, const QString &passward)
{
	bool state = false;
	m_messageList.clear();

	if (m_pSqliteDB)
	{
		if (m_pSqliteDB->isOpen())
		{
			m_messageList.push_back(QStringLiteral("���ȹر������ӵ����ݿ⣡"));
		}
		else
		{
			m_pSqliteDB->setDatabaseName(path);

			if (!passward.isEmpty())
			{
				m_pSqliteDB->setPassword(passward);
			}

			if (m_pSqliteDB->open())
			{
				m_messageList.push_back(QStringLiteral("�������ݿ�ɹ���"));
			}
			else
			{
				m_messageList.push_back(QStringLiteral("�������ݿ�ʧ�ܣ�"));
			}

			m_pSqliteDB->close();
		}
	}
	else
	{
		m_messageList.push_back(QStringLiteral("��ʼ�����ݿ�����ʧ�ܣ�"));
	}

	return state;
}



/*
*  ������passward--����
*  ���أ�
*  ���ܣ��������ݿ������
*/
bool SqliteDB::SetPassward(const QString &passward)
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