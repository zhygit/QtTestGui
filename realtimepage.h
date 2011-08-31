#ifndef REALTIMEPAGE_H
#define REALTIMEPAGE_H
#include "realtimeinfoview.h"
#include "buttonwidget.h"
#include "curveview.h"

#include <QMap>
#include <QWidget>
#include <QAbstractButton>
QT_BEGIN_NAMESPACE
class QTimer;
class QStackedWidget;
class QLabel;
QT_END_NAMESPACE

class RealTimePage : public QWidget
{
    Q_OBJECT
public:
    explicit RealTimePage(QWidget *parent = 0);
     qreal sendValue();
     void addPanelItem(RealTimeInfoView* v,QString name, QString unit,QPointF p,qreal r);
     void addSummaryWidgetButton(ButtonWidget* buttonwidget,const QString &name);
     void ConncetButtonAndPage(ButtonWidget* buttonwidget,QStackedWidget* pagesstack);
signals:

public slots:
    void valueChanged();//RealTimeInfoView* v
    void changePageAccordingName(const QString &name);
private:
    RealTimeInfoView* CreatView(QString name, QString unit,QPointF p,qreal r);
    QWidget* CreateSummaryWidget();
    RealTimeInfoView* PanelViewWidget;
    RealTimeInfoView* PanelViewWidget2;

    qreal virtualspeed;
    QTimer* timer;

    ButtonWidget *viewbuttons;

    QStackedWidget* pageWidget;
    QStackedWidget* CreatePagesWidget();
    QLabel* CreateSamplePage(QString picPath);


    QMap<QString, int> ButtonIndex;
    int Num;     //用在add new button to Buttonlist时，为对应的int赋值

    RealTimeInfoView * page1_panelpage;//这个不确定是否要声明在这里，还是在CreatePagesWidget()的时候再声明？
                                       //如果是后者，本demo中该如何更新仪表盘的数据？

    //8.31 add curve view
    CurveView* CreateRealTimeCruveView(const QString &viewname,int viewtimerange,int maxspeed);
    CurveView* CurveViewPage;

};

#endif // REALTIMEPAGE_H
