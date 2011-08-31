#include "alarmpage.h"
#include <QtGui>
#include "flowlayout.h"
#include "buttonwidget.h"
AlarmPage::AlarmPage( QWidget* parent ) :
		QWidget( parent )
{
	QLabel* map = new QLabel();
	QPixmap* pic = new QPixmap();
	pic->load( "alarmPage.bmp" );
	map->setPixmap( *pic );
	QLabel* mapToolBar = new QLabel();
	QPixmap* picMapToolBar = new QPixmap();
	picMapToolBar->load( "toolbar.bmp" );
	mapToolBar->setPixmap( *picMapToolBar );

	QVBoxLayout* left = new QVBoxLayout();
	left->addWidget( CreateSummaryWidget() );
	left->addWidget( mapToolBar );
	left->addWidget( map );
	left->addStretch( 1 );

	QVBoxLayout* right = new QVBoxLayout();
	right->addWidget( CreateAlarmInfoWidget() );
	right->addWidget( CreateAlarmProcessWidget() );
	right->addStretch( 1 );

	QHBoxLayout* layout = new QHBoxLayout();
	layout->addLayout( left );
	layout->addLayout( right );
	setLayout( layout );
        int Num=0;
}

void AlarmPage::ChangeColor(QLCDNumber *lcdnum)
{
	lcdnum->setNumDigits(8);
	lcdnum->setSegmentStyle( QLCDNumber::Filled );
	QPalette lcdp = lcdnum->palette();
	lcdp.setColor(QPalette::Normal,QPalette::WindowText,Qt::green);
	lcdnum->setPalette(lcdp);
}

//QWidget* AlarmPage::CreateSummaryWidget()
//{
//	QGroupBox* box = new QGroupBox();
//	QGridLayout* layout = new QGridLayout();
//	QLabel* totalLabel = new QLabel( "Total:" );
//	QLCDNumber* totalNum = new QLCDNumber();
//	ChangeColor( totalNum );
//	totalNum->display( 10 );
//	QLabel* regionLabel = new QLabel( "Region:" );
//	QLCDNumber* regionNum = new QLCDNumber();
//	ChangeColor( regionNum );
//	regionNum->display( 5 );
//	QLabel* speedLabel = new QLabel( "OverSpeed:" );
//	QLCDNumber* speedNum = new QLCDNumber();
//	ChangeColor( speedNum );
//	speedNum->display( 2 );
//	QLabel* oilLabel = new QLabel( "Oil:" );
//	QLCDNumber* oilNum = new QLCDNumber();
//	ChangeColor( oilNum );
//	oilNum->display( 3 );
//	layout->addWidget( totalLabel, 0, 0 );
//	layout->addWidget( totalNum, 0, 1 );
//	layout->addWidget( regionLabel, 0, 2 );
//	layout->addWidget( regionNum, 0, 3 );
//	layout->addWidget( oilLabel, 1, 0 );
//	layout->addWidget( oilNum, 1, 1 );
//	layout->addWidget( speedLabel, 1, 2 );
//	layout->addWidget( speedNum, 1, 3 );
//	box->setLayout( layout );
//	return box;
//}
void AlarmPage::addSummaryWidgetButton(ButtonWidget *buttonwidget, const QString &name)
{
    buttonwidget->CreateButton(name);
    ButtonIndex[name]=Num++;
}
QWidget* AlarmPage::CreateSummaryWidget()
{

        QSize buttonsize(150,30);
        ButtonWidget *viewbuttons = new ButtonWidget(buttonsize);
        addSummaryWidgetButton(viewbuttons,(tr("Total Alarm")));
        addSummaryWidgetButton(viewbuttons,(tr("Region Alarm")));
        addSummaryWidgetButton(viewbuttons,(tr("Path Alarm")));
        addSummaryWidgetButton(viewbuttons,(tr("Overspeed")));
        addSummaryWidgetButton(viewbuttons,(tr("Oil Alarm")));
        addSummaryWidgetButton(viewbuttons,(tr("Destination Alarm")));
        //connect(viewbuttons,SIGNAL(onClicked(QString)),this,SLOT(changePageAccordingName(QString)));
        return viewbuttons;
}

QWidget* AlarmPage::CreateAlarmInfoWidget()
{
	QGroupBox* alarmInfo = new QGroupBox( tr("alarm info") );
	QLabel* carID = new QLabel( tr("Car No:  12345677") );
	QLabel* alarmType = new QLabel( tr("Alarm Type:  Leave Region alarm") );
	QLabel* alarmText = new QLabel( tr("Alarm Text:  \n     Run Outof Beijing"));

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget( carID );
	layout->addWidget( alarmType );
	layout->addWidget( alarmText );
	alarmInfo->setLayout( layout );
	return alarmInfo;
}

QWidget* AlarmPage::CreateAlarmProcessWidget()
{
	QGroupBox* process = new QGroupBox( tr("alarm process") );
	QPushButton* startListen = new QPushButton( tr("Start listening") );
	startListen->setFlat( true );
	QPushButton* takePhoto = new QPushButton( tr( "Take photo" ) );
	takePhoto->setFlat( true );
	QPushButton* startMonitor = new QPushButton( tr( "Start Monitor" ) );
	startMonitor->setFlat( true );
	QTextEdit* notes  = new QTextEdit();
	QPushButton* done = new QPushButton( tr( "Done!" ) );

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget( startListen );
	layout->addWidget( takePhoto );
	layout->addWidget( startMonitor );
	layout->addWidget( notes );
	layout->addWidget( done );
	process->setLayout( layout );
	return process;
}


