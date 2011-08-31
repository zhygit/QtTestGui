#ifndef CURVEITEM_H
#define CURVEITEM_H

#include <QGraphicsItem>
#include <QPainterPath>
#include <QTime>
//#include <QWidget>

class CurveItem : public QObject,public QGraphicsItem
{
    Q_OBJECT;
public:
    explicit CurveItem(QObject *parent = 0);
    QRectF boundingRect() const;
    void setCordBoundingRect(int w,int h);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void drawCordinate(QPainter *painter);
    void drawCurve(QPainter *painter);
    void updateSpeed();
    void getTime();
    void timeDisplay(QPainter *painter);
    void setViewTimeRange(int range); //range以分钟为单位，函数处理以秒为单位

    void CordTest(QPainter *painter);


signals:

public slots:
    void updateAll();



private:
    QPoint Orgin;
    QRectF CordBoundingRect;
    QTime currentTime,preTime,afterTime;
    int timeInterval;
    QString tCurrentTime,tPreTime,tAfterTime;
    qreal speed;
    int viewTimeRange;
    QPointF p_pre,newp;
    QPainterPath path;

};

#endif // CURVEITEM_H
