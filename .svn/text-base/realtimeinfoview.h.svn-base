#ifndef REALTIMEINFOVIEW_H
#define REALTIMEINFOVIEW_H

#include <QtGui/QGraphicsView>
#include "dashboarditem.h"
#include <QGraphicsScene>

class RealTimeInfoView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit RealTimeInfoView(QObject *parent = 0);
    void CreatInstrumentPanel(QString name, QString unit,QPointF p,qreal r);
    void CreateTextPanel();
    void UpdateInfo(QString name,qreal v);
    void UpdateInfos();
signals:

public slots:
    //void getValue();
private:
    QGraphicsScene *scene;//=new QGraphicsScene(this);
    QMap<QString,DashboardItem*> PanelMap;
    qreal speed;

};

#endif // REALTIMEINFOVIEW_H
