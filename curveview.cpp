#include "curveview.h"
#include "curveitem.h"
#include <QGraphicsScene>
#include <QList>

CurveView::CurveView(QObject *parent) /*:
    QGraphicsView(parent)*/
{
    scene = new QGraphicsScene;
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
}

void CurveView::CreateCurveView(const QString &viewname,int viewtimerange,int maxspeed)
{
    curve = new CurveItem();
    curve->setTitle(viewname);
    curve->setViewTimeRange(viewtimerange);
    curve->setMaxSpeed(maxspeed);
    scene->addItem(curve);
}
void CurveView::updateSpeed(qreal v)
{
//    QList<QGraphicsItem*> list = scene->items() ;
//    for(int i;i<list.size();i++)
//        ((CurveItem*)(list.at(i)))->updateSpeed(v);
    curve->updateSpeed_item(v);

}
