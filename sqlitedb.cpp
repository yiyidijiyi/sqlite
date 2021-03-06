/*
*  创建日期：2016-09-08
*  最后修改：2016-09-11
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
	, m_pQuery(NULL)
	, m_messageList("")
{
	m_pSqliteDB = new QSqlDatabase(QSqlDatabase::addDatabase("SQLITECIPHER"), "myDB");
	//m_pSqliteDB = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"));
	m_pQuery = new QSqlQuery(*m_pSqliteDB);
}


/*
*  参数：
*  返回：
*  功能：析构函数
*/
SqliteDB::~SqliteDB()
{
	if (m_pQuery)
	{
		delete m_pQuery;
	}

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
*  参数：
*  返回：
*  功能：
*/
QStringList& SqliteDB::GetMessage()
{
	return m_messageList;
}


/*
*  参数：
*  返回：
*  功能：
*/
void SqliteDB::GetSqlDriver()
{
	m_messageList.clear();

	m_messageList = QSqlDatabase::drivers();

	m_messageList.push_front(QStringLiteral("可用的Sql驱动有："));
}


/*
*  参数：path--数据库路径
*             passward--密码
*  返回：链接数据时的状态信息
*  功能：连接数据库
*/
bool SqliteDB::ConnectSqliteDB(const QString &path,  const QString &passward)
{
	bool state = false;
	m_messageList.clear();

	if (m_pSqliteDB->isOpen())
	{
		m_pSqliteDB->close();
	}


	if (m_pSqliteDB)
	{
		m_pSqliteDB->setDatabaseName(path);

		if (!passward.isEmpty())
		{
			m_pSqliteDB->setPassword(passward);
		}		

		if (m_pSqliteDB->isOpen())
		{
			m_messageList.push_back(QStringLiteral("已连接一个数据库，请断开当前数据库后再连接新的数据库！"));
		}
		else
		{
			if (m_pSqliteDB->open())
			{
				state = true;
				m_messageList.push_back(QStringLiteral("连接数据库成功！"));
			}
			else
			{
				m_pSqliteDB->close();
				m_messageList.push_back(QStringLiteral("连接数据库失败！"));
				m_messageList.push_back(m_pSqliteDB->lastError().text());
			}
		}
	}
	else
	{
		m_messageList.push_back(QStringLiteral("初始化QSqlDatabase错误！"));
	}

	return state;
}


/*
*  参数：
*  返回：数据库关闭信息
*  功能：关闭打开的数据库
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
*  参数：path--数据库路径
*             passward--密码
*  返回：0-创建失败，1-创建成功
*  功能：设置数据库的密码
*/
bool SqliteDB::CreateSqliteDB(const QString &path, const QString &passward)
{
	bool state = false;
	m_messageList.clear();

	if (m_pSqliteDB)
	{
		if (m_pSqliteDB->isOpen())
		{
			m_messageList.push_back(QStringLiteral("请先关闭已连接的数据库！"));
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
				m_messageList.push_back(QStringLiteral("创建数据库成功！"));
			}
			else
			{
				m_messageList.push_back(QStringLiteral("创建数据库失败！"));
			}

			m_pSqliteDB->close();
		}
	}
	else
	{
		m_messageList.push_back(QStringLiteral("初始化数据库驱动失败！"));
	}

	return state;
}


/*
*  参数：passward--密码
*  返回：
*  功能：设置数据库的密码
*/
bool SqliteDB::SetPassward(const QString &passward)
{
	bool state = false;
	m_messageList.clear();

	if (!m_pSqliteDB)
	{
		m_messageList.push_back(QStringLiteral("初始化QSqlDatabase错误！"));
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
			m_messageList.push_back(QStringLiteral("数据库密码设置成功！"));
		}
		else
		{
			m_messageList.push_back(QStringLiteral("数据库密码设置失败！"));
		}
	}

	return state;
}


/*
*  参数：str--创建表的sql语句
*  返回：
*  功能：在打开的数据库中创建一个表
*/
bool SqliteDB::CreateTable(const QString &str)
{
	bool state = false;
	m_messageList.clear();

	if (m_pSqliteDB)
	{
		if (m_pSqliteDB->isOpen())
		{
			//m_pQuery->prepare(str);
			m_pQuery->prepare("create table student (id int primary key, name varchar(30), age int)");

			if (m_pQuery->exec())
			{
				state = true;
				m_messageList.push_back(QStringLiteral("在数据库中建表成功！"));
			}
			else
			{
				m_messageList.push_back(QStringLiteral("在数据库中建表失败！"));
				m_messageList.push_back(m_pQuery->lastError().text());
			}
		}
		else
		{
			m_messageList.push_back(QStringLiteral("未连接到数据库！"));
		}
	}
	else
	{
		m_messageList.push_back(QStringLiteral("sqlite驱动加载错误！"));
	}
	

	return state;
}


/*
*  参数：
*  返回：
*  功能：
*/