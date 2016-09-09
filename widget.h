#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>

#include "sqlitedb.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

	void ShowSqliteMessage();
	void ConnectDB(const QString &path);
	void ConnectDB(const QString &path, const QString &passward);
	void DisconnectDB();
	void SetUserNamePassward(const QString &userName, const QString &passward);

	void CreateDB(const QString &path, const QString &name, const QString &passward);

public slots:
	void OnBtnConnectDBClicked();
	void OnBtnDisconnectDBClicked();
	void OnBtnSelectDBClicked();
	void OnBtnSetPasswardClicked();
	void OnBtnCreateDBClicked();
private:
    Ui::Widget *ui;

	SqliteDB *m_pDB;
};

#endif // WIDGET_H
