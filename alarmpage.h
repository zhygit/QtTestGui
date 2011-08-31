#ifndef ALARMPAGE_H
#define ALARMPAGE_H

#include <QWidget>
#include "buttonwidget.h"

QT_BEGIN_NAMESPACE
class QLCDNumber;
QT_END_NAMESPACE

class AlarmPage : public QWidget
{
	Q_OBJECT

public:
	explicit AlarmPage( QWidget* parent = 0 );
        void addSummaryWidgetButton(ButtonWidget* buttonwidget,const QString &name);
signals:

public slots:

private:
	QWidget* CreateSummaryWidget();
	QWidget* CreateAlarmInfoWidget();
	QWidget* CreateAlarmProcessWidget();
	void ChangeColor( QLCDNumber* lcdnum );
        QMap <QString,int> ButtonIndex;
        int Num;// for the "int" in "ButtonIndex " above
};

#endif // ALARMPAGE_H
