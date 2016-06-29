#ifndef CVWIDGET_H
#define CVWIDGET_H

#include <QWidget>
#include "ui_cvwidget.h"

class CVWidget : public QWidget
{
	Q_OBJECT

public:
	CVWidget(QWidget *parent = 0);
	~CVWidget();

private:
	Ui::CVWidget ui;
};

#endif // CVWIDGET_H
