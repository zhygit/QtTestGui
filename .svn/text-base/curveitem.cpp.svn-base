#include "curveitem.h"
#include <QPainter>
#include <QLine>
#include <QStyleOption>
#include <QTime>
#include <QTimer>
 #include <QObject>
//#include <QWidget>

CurveItem::CurveItem(QObject *parent)
{
    setCordBoundingRect(600,300);
    setViewTimeRange(30);

    p_pre.setX(0.0);
    p_pre.setY(0.0);

}
void CurveItem::getTime()
{
    timeInterval=10*60;    //second is the base unit,here set 10minutes as the time interval;
    currentTime=QTime::currentTime();
    preTime=currentTime.addSecs(-timeInterval);
    afterTime=currentTime.addSecs(timeInterval);
    tCurrentTime=currentTime.toString("HH:mm:ss AP");
    tPreTime=preTime.toString("HH:mm:ss AP");
    tAfterTime=afterTime.toString("HH:mm:ss AP");


}
void CurveItem::timeDisplay(QPainter *painter)
{
    getTime();
    QFont font(painter->font());
    QFontMetricsF fm(font);
    QRectF textrect;
    QPointF CurrentTimePos=CordBoundingRect.center()+QPointF(0,CordBoundingRect.bottom()+10);
    textrect=fm.boundingRect(tCurrentTime);
    textrect.moveCenter(CurrentTimePos);
    painter->drawText(textrect,tCurrentTime);
}

QRectF CurveItem::boundingRect()const
{
    qreal adjust = 50;
    return QRectF(CordBoundingRect.left() - adjust, CordBoundingRect.top(),  //此处参数如何确定？
                  CordBoundingRect.width() + adjust, CordBoundingRect.height() + adjust);
}
void CurveItem::setCordBoundingRect(int w, int h)
{
    CordBoundingRect.setTopLeft(QPointF(-w/2,-h/2));
    CordBoundingRect.setWidth(w);
    CordBoundingRect.setHeight(h);
}
void CurveItem::setViewTimeRange(int range)
{
    viewTimeRange=range*60;
}

void CurveItem::drawCordinate(QPainter *painter)
{
    QPen pen;
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->drawRect(CordBoundingRect);
    pen.setColor(Qt::gray);
    painter->setPen(pen);
    QLineF verticalLine(CordBoundingRect.topLeft(),CordBoundingRect.bottomLeft());
    for(int i=0;i<4;i++)
    {
        verticalLine.translate(CordBoundingRect.width()/4,0);//move from left to right
        painter->drawLine(verticalLine);
    }
    QLineF horizonalLine(CordBoundingRect.bottomLeft(),CordBoundingRect.bottomRight());

    int maxspeed=220;
    int scale=20;
    QFont font(painter->font());
    QFontMetricsF fm(font);
    QString text;
    QRectF textrect;
    for(int i=0;i<(maxspeed/20);i++)
    {
        qreal yoffset=CordBoundingRect.height()*scale/maxspeed;
        horizonalLine.translate(0,-yoffset);  //move from top to buttom
        painter->drawLine(horizonalLine);
        text=QString("%1").arg(i*scale);
        textrect=fm.boundingRect(text);
        textrect.moveBottomRight(QPointF(CordBoundingRect.left()-10,CordBoundingRect.bottom()-yoffset*i));
        painter->drawText(textrect,text);
    }
    text=QString("km/h");
    textrect=fm.boundingRect(text);
    textrect.moveBottomRight(CordBoundingRect.topLeft()-QPointF(5,0));
    painter->drawText(textrect,text);
}

void CurveItem::drawCurve(QPainter *painter)
{
    QPen pen;
    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->translate(CordBoundingRect.bottomLeft());
//    updateSpeed();
    qreal x_inc=20*CordBoundingRect.width()/viewTimeRange;
    newp.setX(newp.x()+ x_inc);
    newp.setY( -speed );
    if(newp.x()<CordBoundingRect.width())
    {
        path.lineTo(newp);
        painter->drawPath(path);
        p_pre=newp;
    }
    else{
        path.closeSubpath();
        newp.setX(0);
        path = QPainterPath();
//        path = newpath;
//        path =QPainterPath( newpath);
//        path.translate(-newp.x(),0);
        path.moveTo(newp);
        path.lineTo(newp);
        painter->drawPath(path);
        p_pre=newp;
    }




}


void CurveItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    qWarning( "repaint" );
    drawCordinate(painter);
    timeDisplay(painter);
    drawCurve(painter);
//    CordTest(painter);
}
void CurveItem::CordTest(QPainter *painter)
{
    QPen pen;
    pen.setColor(Qt::green);
    painter->setPen(pen);
    painter->drawLine(0,0,100,-100);
}
void CurveItem::updateAll()
{
//    currentTime=QTime::currentTime();
//    getTime();
    updateSpeed();
    update();
}


void CurveItem::updateSpeed()
{
    if(speed<160)
        speed=speed+10+((-50 + qrand() % 100) / 10.0);
    else  speed += (-50 + qrand() % 100) / 10.0;

}
