#include "dashboarditem.h"
#include <QPainter>
#include <QStyleOption>
#include <math.h>
#include <QFont>
#include <QFontMetricsF>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;


DashboardItem::DashboardItem(QString& name, QString& unit,QPointF& p, qreal radius, QObject *parent)
    //QGraphicsItem(parent)
{
    setName(name);
    setUnit(unit);
    setRadius(radius);
    setPos(p);
    setSpeedHand(radius);
}

QRectF DashboardItem::boundingRect()const
{
    qreal adjust = 0.5;
    return QRectF(-300 - adjust, -300 - adjust,  //此处参数如何确定？
                  600 + adjust, 600 + adjust);
}

void DashboardItem::setRadius(qreal r)
{
    OutRadius=r;
    InRadius=r-50.0;
    GradientRadius=r+12;
}
void DashboardItem::setSpeedHand(qreal r)
{
    speedHand[0]=QPoint(10.0*r/150.0,10.0*r/150.0);
    speedHand[1]=QPoint(-10.0*r/150.0,10.0*r/150.0);
    speedHand[2]=QPoint(0.0,-(r-40.0));
}
void DashboardItem::setSpeed(qreal value)
{
    speed=value;
    update(this->boundingRect());
}

void DashboardItem::setName(const QString &name)
{
    MeterName=name;
}
void DashboardItem::setUnit(const QString &unit)
{
    Unit=unit;
}

void DashboardItem::drawcircle(QPainter *painter,QPointF center,qreal radius)
{
    painter->drawEllipse(center,radius,radius);
}
void DashboardItem::setItemPosF(QPointF &p)
{
    ItemPos=p;
}
void DashboardItem::setItemPosF(qreal x, qreal y)
{
    ItemPos.setX(x);
    ItemPos.setY(y);
}

void DashboardItem::drawname(QPainter *painter)
{
    QPen pen;
    QFont font("Arial",16);
    QFontMetricsF fm(font);
    QRectF TextRect=fm.boundingRect(MeterName);
    pen.setBrush(Qt::black);
    painter->setPen(pen);
    TextRect.moveCenter(QPoint(0,0.8*InRadius));
    painter->drawText(TextRect,Qt::AlignCenter,MeterName);

    TextRect=fm.boundingRect(Unit);
    TextRect.moveCenter(QPoint(0,0.8*InRadius-fm.height()));
    pen.setBrush(Qt::darkGreen);
    painter->setPen(pen);
    painter->drawText(TextRect,Qt::AlignCenter,Unit);
}

void DashboardItem::drawhand(QPainter *painter)
{
    QColor handColor(255,122,29);
    painter->setPen(Qt::NoPen);
    painter->setBrush(handColor);
    painter->save();
    //指针rotate
    painter->rotate((-220+speed)*220/360);     //test
    painter->drawConvexPolygon(speedHand, 3);
    painter->restore();
}
/*//void DashboardItem::drawscale(QPainter *painter, int max, qreal radius)
//{
//        QPen pen;
//        QFont font("Arial",12);
//        QFontMetricsF fm(font);
//        painter->setRenderHint(QPainter::Antialiasing);
//        painter->setFont(font);
//        int SpeedNum=0;
//        //int max=200;
//        QPointF TextP;
//        int rtext;
//        QString SpeedNumText;
//        QPointF LineStartP,LineEndP;
//        int r1,r2=OutRadius-20;       //刻度线从r1-->r2,
//        int every=20;
//        //int x=max/every;
//        for(int i=225,cnt=0;i>-46;i--,cnt++)
//        {
//            double a=TwoPi*i/360;
//            if(cnt%(int(floor(270*every/max)))==0)
//            {

//                QFont font("Arial",8);
//                QFontMetricsF fm(font);
//                r1=OutRadius-20;
//                SpeedNumText=QString("%1").arg(cnt);
//                QRectF TextRect=fm.boundingRect(SpeedNumText);
//                rtext=r1-15;
//                TextP.setX(rtext*cos(a));
//                TextP.setY(rtext*sin(-a));
//                TextRect.moveCenter(TextP);
//                painter->drawText(TextRect,Qt::AlignCenter,QString("%1").arg(SpeedNum));
//                pen.setBrush(Qt::gray);
//                pen.setWidth(1);
//                painter->setPen(pen);
//                painter->drawRect(TextRect);
//                pen.setBrush(Qt::red);
//                pen.setWidth(3);
//                painter->setPen(pen);
//            }
//            else
//            {
//                r1=OutRadius-10;
//                pen.setBrush(Qt::darkBlue);
//                pen.setWidth(1);
//                painter->setPen(pen);
//            }
//            LineStartP.setX(r1*cos(a));
//            LineStartP.setY(r1*sin(-a));
//            LineEndP.setX(r2*cos(a));
//            LineEndP.setY(r2*sin(-a));
//            painter->drawLine(LineStartP,LineEndP);
//        }
//}*/

void DashboardItem::drawscale(QPainter *painter, int max ,qreal radius)
{
    QPen pen;
    QFont font("Arial",12);
    QFontMetricsF fm(font);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setFont(font);
    int SpeedNum=0;
    //int max=200;
    QPointF TextP;
    int rtext;
    QString SpeedNumText;
    QPointF LineStartP,LineEndP;
    int r1,r2=OutRadius-20;       //刻度线从r1-->r2,
    for (int i=max;i>-(max-180+1);i=i-5,SpeedNum+=5)
    {
        double a=TwoPi*i/360;
        if (i%20==0)
        {
            QFont font("Arial",12);
            QFontMetricsF fm(font);
            r1=OutRadius-15;
            SpeedNumText=QString("%1").arg(SpeedNum);
            QRectF TextRect=fm.boundingRect(SpeedNumText);
            rtext=r1-20;
            TextP.setX(rtext*cos(a));
            TextP.setY(rtext*sin(-a));
            TextRect.moveCenter(TextP);

            painter->drawText(TextRect,Qt::AlignCenter,QString("%1").arg(SpeedNum));
//            pen.setBrush(Qt::gray);
//            pen.setWidth(1);
//            painter->setPen(pen);
//            painter->drawRect(TextRect);
            pen.setBrush(Qt::red);
            pen.setWidth(3);
            painter->setPen(pen);
        }
        else
        {
            r1=OutRadius-10;
            pen.setBrush(Qt::darkBlue);
            pen.setWidth(1);
            painter->setPen(pen);
        }
        LineStartP.setX(r1*cos(a));
        LineStartP.setY(r1*sin(-a));
        LineEndP.setX(r2*cos(a));
        LineEndP.setY(r2*sin(-a));
        painter->drawLine(LineStartP,LineEndP);
    }
}
void DashboardItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPen pen;

    //painter->translate(width() / 2, height() / 2);
    //外圆效果
    QColor color1(149,40,00);
    QRadialGradient Rgradient(0, 0, GradientRadius,0,0);
   // Rgradient.setColorAt(0.0, Qt::lightGray);
    Rgradient.setColorAt(0.77, Qt::black);
    Rgradient.setColorAt(0.8, color1);
    Rgradient.setColorAt(0.9, Qt::white);
    Rgradient.setColorAt(1, color1);
    pen.setBrush(Rgradient);
    pen.setWidth(20);
    pen.setStyle(Qt::SolidLine);
    //painter->setPen(Qt::NoPen);
    painter->setPen(pen);
    drawcircle(painter,QPointF(0.0,0.0),OutRadius);//画外圆
    //内圆效果
    pen.setStyle(Qt::DotLine);
    pen.setBrush(Qt::darkGreen);
    pen.setWidth(2);
    painter->setPen(pen);
    drawcircle(painter,QPointF(0.0,0.0),InRadius);//画内圆
    //刻度效果
    pen.setStyle(Qt::SolidLine);
    pen.setBrush(Qt::darkBlue);
    pen.setWidth(1);
    painter->setPen(pen);
    drawscale(painter,200,InRadius);
   //画名称和指针
    drawname(painter);
    drawhand(painter);

}

