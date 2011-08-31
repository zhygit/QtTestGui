#include "realtimeinfoview.h"
#include "dashboarditem.h"
#include <QGraphicsScene>

RealTimeInfoView::RealTimeInfoView(QObject *parent)//:
    //QGrapicsView(parent)
{
    scene = new QGraphicsScene;
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    //scene->setSceneRect(-200,-200, 400, 400);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
//    CreatInstrumentPanel(QString("SpeedWatch"),QString("Km/h"),QPoint(0.0,0.0),150.0);
//    CreatInstrumentPanel(QString("Watch1"),QString("rpm"),QPoint(350.0,0.0),100.0);
//    CreatInstrumentPanel(QString("Watch2"),QString("C"),QPoint(0.0,320.0),150.0);
}

void RealTimeInfoView::CreatInstrumentPanel(QString name,QString unit,QPointF p,qreal r)
{
//此处注释为Qt编译器问题，一个更普遍的写法如下行注释，但要继续添加以下三行，然后代入形参
    //DashboardItem::DashboardItem(QString &name, QPoint &P, qreal Radius, QObject *parent)/
//    QString name("SpeedWatch");
//    QPointF p(0.0,0.0);
//    qreal r=150.0;
    DashboardItem *newwatch= new DashboardItem(name,unit,p,r );
    scene->addItem(newwatch);
    PanelMap.insert(name,newwatch);
}

void RealTimeInfoView::CreateTextPanel()
{

}
void RealTimeInfoView::UpdateInfo(QString name,qreal v)
{
    speed=v;
   if(PanelMap.contains(name))
    {
        PanelMap.value(name)->setSpeed(v);
    }
}
void RealTimeInfoView::UpdateInfos()
{

}
//void RealTimeInfoView::getValue(qreal v);
//{
//    speed=v;
//}
