#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

	void ConnectDB(const QString &path);

public slots:
	void OnBtnConnectDBClicked();
	

private:
    Ui::Widget *ui;

	SqliteDB *m_pDB;
};

#endif // WIDGET_H
