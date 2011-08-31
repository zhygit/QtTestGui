#ifndef ALARMMANAGE_H
#define ALARMMANAGE_H

#include <QWidget>

class AlarmManage : public QWidget
{
    Q_OBJECT
public:
    explicit AlarmManage(QWidget *parent = 0);

signals:

public slots:

private:
	QWidget* CreateGroupInfoWidget();
	QWidget* CreateGroupManageWidget();
	QWidget* CreateRegionAlarmWidget();
	QWidget* CreateOilAlarmWidget();

};

#endif // ALARMMANAGE_H
