#ifndef CURVEVIEW_H
#define CURVEVIEW_H

#include <QtGui/QGraphicsView>
#include <QGraphicsScene>
#include "curveitem.h"

class CurveView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit CurveView(QObject *parent = 0);
    void CreateCurveView(const QString &viewname,int viewtimerange,int maxspeed);
    void updateSpeed(qreal v);
// QGraphicsScene *scene;
signals:

public slots:

private:
    QGraphicsScene *scene;
    CurveItem *curve;
    qreal speed;
};

#endif // CURVEVIEW_H
