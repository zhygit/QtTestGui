#ifndef REALTIMEPAGE_H
#define REALTIMEPAGE_H
#include "realtimeinfoview.h"
#include "buttonwidget.h"

#include <QMap>
#include <QWidget>
//#include <QStackedWidget>
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
     ~RealTimePage();
signals:
     void onClicked();

public slots:
    void valueChanged();//RealTimeInfoView* v
//    void changePage(int num);
    void changePage();
private:
    //QWidget* CreatInfomationPage();
    RealTimeInfoView* CreatView(QString name, QString unit,QPointF p,qreal r);
    QWidget* CreateSummaryWidget();
    //QWidget* PanelViewWidget;
    RealTimeInfoView* PanelViewWidget;
    RealTimeInfoView* PanelViewWidget2;

    qreal virtualspeed;
    QTimer* timer;

    ButtonWidget *viewbuttons;
    QButtonGroup *buttongroup;
    QStackedWidget* pageWidget;
    QStackedWidget* CreatePagesWidget();
    QLabel* CreateSamplePage(QString picPath);
    QMap<QPushButton*, int> maps;

    RealTimeInfoView * page1_panelpage;//�����ȷ���Ƿ�Ҫ���������������CreatePagesWidget()��ʱ����������
                                       //����Ǻ��ߣ���demo�и���θ����Ǳ��̵����ݣ�

};

#endif // REALTIMEPAGE_H
