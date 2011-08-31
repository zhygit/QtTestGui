#ifndef MAPPREDEFINEDPAGE_H
#define MAPPREDEFINEDPAGE_H

#include <QWidget>

class MapPredefinedPage : public QWidget
{
    Q_OBJECT
public:
    explicit MapPredefinedPage(QWidget *parent = 0);

signals:

public slots:

private:
	QWidget* CreateQueryWidget();
	QWidget* CreateRegionWidget();
	QWidget* CreateRouteWidget();

};

#endif // MAPPREDEFINEDPAGE_H
