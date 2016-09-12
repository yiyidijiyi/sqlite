/*
*  �������ڣ�
*  ����޸ģ�
*  ��       �ߣ�
*  �ļ�������
*/
#include "widget.h"
#include "ui_widget.h"


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
Widget::Widget(QWidget *parent) 
	:QWidget(parent)
    ,ui(new Ui::Widget)
	,m_pDB(NULL)
	, m_pRelationTableModel(NULL)
{
    ui->setupUi(this);

	m_pDB = new SqliteDB();

	m_pRelationTableModel = new QSqlRelationalTableModel(ui->tableView);

	connect(ui->pushButton_clearMessage, &QPushButton::clicked, ui->textEdit_message, &QTextEdit::clear);
	connect(ui->pushButton_detectDriver, &QPushButton::clicked, this, &Widget::OnBtnShowSqlDriverClicked);
	connect(ui->pushButton_connectDB, &QPushButton::clicked, this, &Widget::OnBtnConnectDBClicked);
	connect(ui->pushButton_selDB, &QPushButton::clicked, this, &Widget::OnBtnSelectDBClicked);
	connect(ui->pushButton_disconnectDB, &QPushButton::clicked, this, &Widget::OnBtnDisconnectDBClicked);
	connect(ui->pushButton_setPassward, &QPushButton::clicked, this, &Widget::OnBtnSetPasswardClicked);
	connect(ui->pushButton_createDB, &QPushButton::clicked, this, &Widget::OnBtnCreateDBClicked);
	connect(ui->pushButton_createAccount, &QPushButton::clicked, this, &Widget::OnBtnCreateAccountClicked);
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
Widget::~Widget()
{
	if (m_pRelationTableModel)
	{
		delete m_pRelationTableModel;
	}

	if (m_pDB)
	{
		delete m_pDB;
	}

    delete ui;
}

/*
*  ������
*  ���أ�
*  ���ܣ�
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
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::ConnectDB(const QString &path)
{
	m_pDB->ConnectSqliteDB(path);
	
	ShowSqliteMessage();
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::ConnectDB(const QString &path, const QString &passward)
{
	m_pDB->ConnectSqliteDB(path, passward);
	
	ShowSqliteMessage();
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::DisconnectDB()
{
	m_pDB->DisconnectSqliteDB();

	ShowSqliteMessage();
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::SetUserNamePassward(const QString &userName, const QString &passward)
{
	if (userName.isEmpty())
	{
		ui->textEdit_message->append(QStringLiteral("�û�������Ϊ�գ�"));
	}
	else if (passward.isEmpty())
	{
		ui->textEdit_message->append(QStringLiteral("���õ����벻��Ϊ�գ�"));
	}
	else
	{
		m_pDB->SetPassward(passward);

		ShowSqliteMessage();
	}
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::CreateDB(const QString &path, const QString &name, const QString &passward)
{
	QString pathName;

	if (path.isEmpty())
	{
		ui->textEdit_message->append(QStringLiteral("·��Ϊ�գ�����Ĭ��·�� ./data��"));
		pathName = QString("./data/");
	}
	else
	{
		int index = path.lastIndexOf(QString("/"));
		pathName = path.left(index + 1);
	}

	if (name.isEmpty())
	{
		ui->textEdit_message->append(QStringLiteral("���ݿ�����Ϊ�գ���������data.db��"));
		pathName += QString("data.db");
	}
	else
	{
		pathName += name;
	}

	m_pDB->CreateSqliteDB(pathName, passward);

	ShowSqliteMessage();
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::CreateAccountTable()
{
	QString str = "create table Account(id integar primary key autoincrement, name varchar, passward varchar, type integar, \
				  date timestamp not null defaut(datetime('now'), 'localtime'))";
	//QString str = "create table student (id int primary key, name varchar(30), age int)";

	m_pDB->CreateTable(str);

	ShowSqliteMessage();
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::OnBtnShowSqlDriverClicked()
{
	if (m_pDB)
	{
		m_pDB->GetSqlDriver();

		ShowSqliteMessage();
	}
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::OnBtnConnectDBClicked()
{
	QString path = ui->lineEdit_DBPath->text();
	QString passward = ui->lineEdit_passward->text();

	if (!path.isEmpty())
	{
		ConnectDB(path,  passward);
	}
	else
	{
		ui->textEdit_message->append(QStringLiteral("���ݿ�·������Ϊ�գ�"));
	}
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::OnBtnSelectDBClicked()
{
	QString path = QFileDialog::getOpenFileName(this, QStringLiteral("��ѡ�����ݿ�"), "./", "DataBase(*.db)");

	ui->lineEdit_DBPath->setText(path);
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::OnBtnDisconnectDBClicked()
{
	DisconnectDB();
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::OnBtnSetPasswardClicked()
{
	QString userName = ui->lineEdit_setUserName->text();
	QString passward = ui->lineEdit_setPassward->text();
	
	SetUserNamePassward(userName, passward);
}

/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::OnBtnCreateDBClicked()
{
	QString path = ui->lineEdit_DBPath->text();
	QString name = ui->lineEdit_DBName->text();
	QString passward = ui->lineEdit_passward->text();

	CreateDB(path, name, passward);
}


/*
*  ������
*  ���أ�
*  ���ܣ�
*/
void Widget::OnBtnCreateAccountClicked()
{
	CreateAccountTable();
}



/*
*  ������
*  ���أ�
*  ���ܣ�
*/