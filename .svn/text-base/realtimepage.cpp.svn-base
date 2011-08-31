#include "realtimepage.h"
#include "realtimeinfoview.h"
//#include <QTimer>
#include <QtGui>
#include "curveview.h"


RealTimePage::RealTimePage(QWidget *parent) :
    QWidget(parent)
{
    Num=0;
    pageWidget = CreatePagesWidget();

    //测试速度变化用
    virtualspeed=0;
    timer = new QTimer(this);
    connect (timer,SIGNAL(timeout()),this,SLOT(valueChanged()));
    timer->start(1000);
//    connect (timer,);//

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(CreateSummaryWidget());
    layout->addWidget(pageWidget);
    setLayout(layout);

}



RealTimeInfoView* RealTimePage::CreatView(QString name, QString unit, QPointF p, qreal r)
{
    RealTimeInfoView *view =new RealTimeInfoView;//()
    view->CreatInstrumentPanel(name,unit,p,r);

    return view;
}
void RealTimePage::addPanelItem(RealTimeInfoView *v, QString name, QString unit, QPointF p, qreal r)
{
    v->CreatInstrumentPanel(name,unit,p,r);
}


CurveView* RealTimePage::CreateRealTimeCruveView(const QString &viewname,int viewtimerange,int maxspeed)
{
    CurveView *view = new CurveView();
    view->CreateCurveView(viewname,viewtimerange,maxspeed);
    return view;
}

void RealTimePage::valueChanged()
{
    if(virtualspeed<160)
        virtualspeed=virtualspeed+10+((-50 + qrand() % 100) / 10.0);
    else if (virtualspeed >190)
    {
        virtualspeed += (-80 + qrand() % 100) / 10.0;
    }
    else
    {
        virtualspeed += (-50 + qrand() % 100) / 10.0;
    }

//    if(virtualspeed>200)
//    {
//        virtualspeed=0;
//    }
//    else
//    {
//        virtualspeed++;
//    }
    page1_panelpage->UpdateInfo(QString("SpeedWatch"),sendValue());
    page1_panelpage->UpdateInfo(QString("Watch"),sendValue());
//    CurveViewPage->updateSpeed(sendValue);
    CurveViewPage->updateSpeed(sendValue());
}
qreal RealTimePage::sendValue()
{
    return virtualspeed;
}

QLabel* RealTimePage::CreateSamplePage(QString picPath)
{
        QLabel* page = new QLabel();
        page->setAlignment( Qt::AlignLeft | Qt::AlignTop );
        QPixmap* pic = new QPixmap();
        pic->load( picPath );
        page->setPixmap( *pic );
        return page;
}

void RealTimePage::addSummaryWidgetButton(ButtonWidget *buttonwidget, const QString &name)
{
    buttonwidget->CreateButton(name);
    ButtonIndex[name]=Num++;
}

QWidget* RealTimePage::CreateSummaryWidget()
{
        QSize buttonsize(120,30);
        viewbuttons = new ButtonWidget(buttonsize);
        addSummaryWidgetButton(viewbuttons,(tr("PanelView")));
        addSummaryWidgetButton(viewbuttons,(tr("CurveView")));
        addSummaryWidgetButton(viewbuttons,(tr("FaultDiagnosis")));
        addSummaryWidgetButton(viewbuttons,tr("Test"));
        connect(viewbuttons,SIGNAL(onClicked(QString)),this,SLOT(changePageAccordingName(QString)));

        return viewbuttons;
}
QStackedWidget* RealTimePage::CreatePagesWidget()
{
    QStackedWidget* viewpages = new QStackedWidget();
    page1_panelpage = CreatView(QString("SpeedWatch"),QString("Km/h"),QPoint(0.0,0.0),150.0);
    addPanelItem(page1_panelpage,QString("Watch"),QString("rpm"),QPoint(300.0,0.0),120.0);

    CurveViewPage= CreateRealTimeCruveView(tr("RealTimeSpeedCurve"),30,220);
//    QLabel* page2_curvepage = CreateSamplePage("curve.jpg");
    QLabel* page3_faultpage = CreateSamplePage("diagnos.jpg");
//    page2_curvepage->setAlignment(Qt::AlignCenter);
    page3_faultpage->setAlignment(Qt::AlignCenter);
    viewpages->addWidget(page1_panelpage);
    viewpages->addWidget(CurveViewPage);
    viewpages->addWidget(page3_faultpage);

    return viewpages;
}

void RealTimePage::ConncetButtonAndPage(ButtonWidget *buttonwidget, QStackedWidget *pagesstack)
{
}

void RealTimePage::changePageAccordingName(const QString &name)
{
    pageWidget->setCurrentIndex(ButtonIndex[name]);
}
