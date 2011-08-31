#ifndef DASHBOARDITEM_H
#define DASHBOARDITEM_H

#include <QGraphicsItem>

class DashboardItem : public QObject,public QGraphicsItem
{
   // Q_OBJECT
public:
   // explicit DashboardItem( QString& name, QPointF& P,qreal Radius, QObject *parent = 0);
    explicit DashboardItem( QString &name, QString &unit, QPointF &P,qreal radius, QObject *parent = 0);
    QRectF boundingRect() const;
    void drawcircle(QPainter *painter,QPointF center,qreal radius);
    void drawscale(QPainter *painter,int max,qreal radius);
    void drawhand(QPainter *painter);
    void drawname(QPainter *painter);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void setRadius(qreal r);
    void setName(const QString &name);
    void setUnit(const QString &unit);
    void setItemPosF(QPointF &p);
    void setItemPosF(qreal x,qreal y);
    void setSpeedHand(qreal r);
    void setSpeed(qreal value);
protected:

signals:

public slots:

private:
    QString MeterName;
    QString Unit;
    qreal OutRadius;
    qreal InRadius;
    int GradientRadius;
    QPointF ItemPos;
    QPointF speedHand[3];
    qreal speed; //use for QTimer test;
};

#endif // DASHBOARDITEM_H
