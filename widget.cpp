/*
*  创建日期：
*  最后修改：
*  作       者：
*  文件描述：
*/
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
	m_pDB(NULL)
{
    ui->setupUi(this);

	m_pDB = new SqliteDB();

	connect(ui->pushButton_clearMessage, &QPushButton::clicked, ui->textEdit_message, &QTextEdit::clear);
	connect(ui->pushButton_connectDB, &QPushButton::clicked, this, &Widget::OnBtnConnectDBClicked);
}

Widget::~Widget()
{
	if (m_pDB)
	{
		delete m_pDB;
	}

    delete ui;
}

void Widget::ConnectDB(const QString &path)
{
	bool  state = m_pDB->ConnectSqliteDB(path);

	if (state)
	{
		ui->textEdit_message->append(QStringLiteral("数据库连接成功！"));
	}
	else
	{
		ui->textEdit_message->append(QStringLiteral("数据库连接成功！"));
	}
	//size_t n = message.size();
	//while(n > 0)
	//{
	//	ui->textEdit_message->append(message[--n]);
	//}
}

void Widget::OnBtnConnectDBClicked()
{
	QString path = "./data/test1.db";

	ConnectDB(path);
}
