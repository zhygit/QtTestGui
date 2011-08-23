#include "realtimepage.h"
#include "realtimeinfoview.h"
//#include <QTimer>
#include <QtGui>

RealTimePage::RealTimePage(QWidget *parent) :
    QWidget(parent)
{

    //PanelViewWidget = CreatView(QString("SpeedWatch"),QString("Km/h"),QPoint(0.0,0.0),150.0);//建立一个仪表盘的veiw
    //addPanelItem(PanelViewWidget,QString("Watch"),QString("rpm"),QPoint(300.0,0.0),120.0);//在已有的仪表盘view中添加一个新的仪表盘Item
    pageWidget = CreatePagesWidget();

    //测试速度变化用
    virtualspeed=0;
    timer = new QTimer(this);
    connect (timer,SIGNAL(timeout()),this,SLOT(valueChanged()));
    timer->start(100);

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(CreateSummaryWidget());
   // layout->addWidget(PanelViewWidget);
    layout->addWidget(pageWidget);
    setLayout(layout);

}

RealTimePage::~RealTimePage()
{
   //timer->stop();
}
RealTimeInfoView* RealTimePage::CreatView(QString name, QString unit, QPointF p, qreal r)
{
    RealTimeInfoView *view =new RealTimeInfoView;
    view->CreatInstrumentPanel(name,unit,p,r);

    return view;
}
void RealTimePage::addPanelItem(RealTimeInfoView *v, QString name, QString unit, QPointF p, qreal r)
{
    v->CreatInstrumentPanel(name,unit,p,r);
}

void RealTimePage::valueChanged()
{
    //cout<<"value changed"<<endl;
    if(virtualspeed>200)
    {
        virtualspeed=0;
    }
    else
    {
        virtualspeed++;
    }
    //end();
//    v->UpdateInfo(QString("SpeedWatch"),sendValue());
//    v->UpdateInfo(QString("Watch"),sendValue());
//    PanelViewWidget->UpdateInfo(QString("SpeedWatch"),sendValue());
    //    PanelViewWidget->UpdateInfo(QString("Watch"),sendValue());
    page1_panelpage->UpdateInfo(QString("SpeedWatch"),sendValue());
    page1_panelpage->UpdateInfo(QString("Watch"),sendValue());
}
qreal RealTimePage::sendValue()
{
    return virtualspeed;
}

QWidget* RealTimePage::CreateSummaryWidget()
{
        QGroupBox* box = new QGroupBox();
        QSize buttonsize(120,30);
        viewbuttons = new ButtonWidget(buttonsize);
        buttongroup = viewbuttons->getButtonGroup(); //没用好~
        viewbuttons->addNewButton(tr("PanelView"));
        viewbuttons->addNewButton(tr("CurveView"));
        viewbuttons->addNewButton(tr("FaultDiagnosis"));
        box->setLayout(viewbuttons->getLayout());
        connect(buttongroup->button(0),SIGNAL(clicked()),this,SLOT(changePage()));
        connect(buttongroup->button(1),SIGNAL(clicked()),this,SLOT(changePage()));
        connect(buttongroup->button(2),SIGNAL(clicked()),this,SLOT(changePage()));
//        static int index =0;
//        index++;
//        maps [buttongroup->button(0)]=index;
        maps=*(viewbuttons->getButtonMap());
        return box;
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

QStackedWidget* RealTimePage::CreatePagesWidget()
{
    QStackedWidget* viewpages = new QStackedWidget();
    page1_panelpage = CreatView(QString("SpeedWatch"),QString("Km/h"),QPoint(0.0,0.0),150.0);
    addPanelItem(page1_panelpage,QString("Watch"),QString("rpm"),QPoint(300.0,0.0),120.0);

    QLabel* page2_curvepage = CreateSamplePage("curve.jpg");
    QLabel* page3_faultpage = CreateSamplePage("diagnos.jpg");
    viewpages->addWidget(page1_panelpage);
    viewpages->addWidget(page2_curvepage);
    viewpages->addWidget(page3_faultpage);

    return viewpages;
}
void onClicked()
{
//    QWidget* widget = viewbuttons->focusWidget();
//    QString buttonName =widget->accessibleName();
}

void RealTimePage::changePage()
{
    QWidget* widget = viewbuttons->focusWidget();
//    QString name =widget->accessibleName();
    QPushButton *b =(QPushButton*)widget;
    if ( maps.find( b ) != maps.end() )
          {
                int index = maps[ b ];
                if (  pageWidget->count() >= index )
                         pageWidget->setCurrentIndex( index-1 );
          }

}
//void RealTimePage::changePage(int num)
//{
//   pageWidget->setCurrentIndex(num);
//}
