/*
*  创建日期：
*  最后修改：
*  作       者：
*  文件描述：
*/
#include "widget.h"
#include "ui_widget.h"


/*
*  参数：
*  返回：
*  功能：
*/
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
	m_pDB(NULL)
{
    ui->setupUi(this);

	m_pDB = new SqliteDB();

	connect(ui->pushButton_clearMessage, &QPushButton::clicked, ui->textEdit_message, &QTextEdit::clear);
	connect(ui->pushButton_connectDB, &QPushButton::clicked, this, &Widget::OnBtnConnectDBClicked);
	connect(ui->pushButton_selDB, &QPushButton::clicked, this, &Widget::OnBtnSelectDBClicked);
	connect(ui->pushButton_disconnectDB, &QPushButton::clicked, this, &Widget::OnBtnDisconnectDBClicked);
	connect(ui->pushButton_setPassward, &QPushButton::clicked, this, &Widget::OnBtnSetPasswardClicked);
}


/*
*  参数：
*  返回：
*  功能：
*/
Widget::~Widget()
{
	if (m_pDB)
	{
		delete m_pDB;
	}

    delete ui;
}

/*
*  参数：
*  返回：
*  功能：
*/
void Widget::ShowSqliteMessage()
{
	QStringList message = m_pDB->GetMessage();

	size_t n = message.size();
	for (size_t i = 0; i < n; i++)
	{
		ui->textEdit_message->append(message[i]);
	}
}


/*
*  参数：
*  返回：
*  功能：
*/
void Widget::ConnectDB(const QString &path)
{
	m_pDB->ConnectSqliteDB(path);
	
	ShowSqliteMessage();
}


/*
*  参数：
*  返回：
*  功能：
*/
void Widget::ConnectDB(const QString &path, const QString &userName, const QString &passward)
{
	m_pDB->ConnectSqliteDB(path, userName, passward);
	
	ShowSqliteMessage();
}


/*
*  参数：
*  返回：
*  功能：
*/
void Widget::DisconnectDB()
{
	m_pDB->DisconnectSqliteDB();

	ShowSqliteMessage();
}


/*
*  参数：
*  返回：
*  功能：
*/
void Widget::SetUserNamePassward(const QString &userName, const QString &passward)
{
	if (userName.isEmpty())
	{
		ui->textEdit_message->append(QStringLiteral("用户名不能为空！"));
	}
	else if (passward.isEmpty())
	{
		ui->textEdit_message->append(QStringLiteral("设置的密码不能为空！"));
	}
	else
	{
		m_pDB->SetUserNamePassward(userName,  passward);

		ShowSqliteMessage();
	}
}


/*
*  参数：
*  返回：
*  功能：
*/
void Widget::OnBtnConnectDBClicked()
{
	QString path = ui->lineEdit_DBPath->text();
	QString userName = ui->lineEdit_userName->text();
	QString passward = ui->lineEdit_passward->text();

	if (!path.isEmpty())
	{
		if (userName.isEmpty())
		{
			ConnectDB(path);
		}
		else
		{
			ConnectDB(path, userName, passward);
		}
	}
	else
	{
		ui->textEdit_message->append(QStringLiteral("数据库路径不能为空！"));
	}
}


/*
*  参数：
*  返回：
*  功能：
*/
void Widget::OnBtnSelectDBClicked()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("请选择数据库"), "./", "DataBase(*.db)");

	ui->lineEdit_DBPath->setText(path);
}


/*
*  参数：
*  返回：
*  功能：
*/
void Widget::OnBtnDisconnectDBClicked()
{
	DisconnectDB();
}


/*
*  参数：
*  返回：
*  功能：
*/
void Widget::OnBtnSetPasswardClicked()
{
	QString userName = ui->lineEdit_setUserName->text();
	QString passward = ui->lineEdit_setPassward->text();
	
	SetUserNamePassward(userName, passward);
}




/*
*  参数：
*  返回：
*  功能：
*/