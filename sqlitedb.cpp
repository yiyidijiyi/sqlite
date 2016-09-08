/*
*  创建日期：
*  最后修改：
*  作       者：
*  文件描述：
*/
#include "sqlitedb.h"

/*
*  参数：
*  返回：
*  功能：构造函数
*/
SqliteDB::SqliteDB(QObject *parent)
	: QObject(parent)
	, m_pSqliteDB(NULL)
	, m_messageList("")
{
	m_pSqliteDB = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
}


/*
*  参数：
*  返回：
*  功能：析构函数
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
*  参数：path--数据库路径
*  返回：链接数据时的状态信息
*  功能：连接数据库
*/
bool SqliteDB::ConnectSqliteDB(const QString &path)
{
	bool state = false;
	m_messageList.clear();

	m_pSqliteDB->setDatabaseName(path);

	if (m_pSqliteDB->open())
	{
		state = true;
		m_messageList.push_back(QStringLiteral("连接数据库成功！"));
	}
	else
	{
		m_messageList.push_back(QStringLiteral("连接数据库失败！"));
	}

	return state;
}


/*
*  参数：path--数据库路径
*             username--用户名
*             passward--密码
*  返回：链接数据时的状态信息
*  功能：连接数据库
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
		m_messageList.push_back(QStringLiteral("连接数据库成功！"));
	}
	else
	{
		m_messageList.push_back(QStringLiteral("连接数据库失败！"));
	}

	return state;
}


/*
*  参数：
*  返回：数据库关闭信息
*  功能：关闭打开的数据库
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
			m_messageList.push_back(QStringLiteral("关闭数据库成功！"));
		}
		else
		{
			m_messageList.push_back(QStringLiteral("数据库未连接！"));
		}	
	}
	else
	{
		m_messageList.push_back(QStringLiteral("数据库未连接！"));
	}

	return state;
}


/*
*  参数：
*  返回：
*  功能：
*/