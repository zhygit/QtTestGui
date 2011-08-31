#include "mainwindow.h"
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QPicture>
#include <QMessageBox>
#include "alarmpage.h"
#include "mappredefinedpage.h"
#include "carmanagepage.h"
#include "realtimepage.h"

MainWindow::MainWindow(QWidget *parent)
	: QDialog(parent)
{
	contentsWidget = CreateContentsWidget();
	pagesWidget = CreatePagesWidget();

	QHBoxLayout *horizontalLayout = new QHBoxLayout();
	horizontalLayout->addWidget(contentsWidget);
	horizontalLayout->addWidget(pagesWidget, 1);

	QLabel* logoLabel = new QLabel();
	logoLabel->setAlignment( Qt::AlignRight );
	logoLabel->setBackgroundRole( QPalette::Link );
	logoLabel->setText( "Superbee.com\n demo version \n 2011 7" );

	QVBoxLayout *verticalLayout = new QVBoxLayout();
	verticalLayout->addWidget( logoLabel );
	verticalLayout->addLayout( horizontalLayout );
	setLayout( verticalLayout );
}

MainWindow::~MainWindow()
{

}

QWidget* MainWindow::CreateContentsWidget()
{
	QGroupBox* contents = new QGroupBox();

	QVBoxLayout *layout = new QVBoxLayout();
	layout->addWidget( CreateRealTimeViewGroupBox() );
	layout->addWidget( CreateHistoryViewGroupBox() );
        layout->addWidget( CreateManagementGroupBox() );
	layout->addWidget( CreateConfigGroupBox() );
	layout->addStretch( 1 );
	contents->setLayout( layout );

	return contents;
}

QPushButton* MainWindow::CreateMenuButton(QString title )
{
	static int index = 0;
	QPushButton* button = new QPushButton( title );
	button->setFlat( true );
	index++;
	maps[ button ] = index;
	connect(button, SIGNAL(clicked()), this, SLOT( changePage()));
	return button;
}

QGroupBox* MainWindow::CreateRealTimeViewGroupBox()
{
	QGroupBox* groupBox = new QGroupBox(tr("&Real Time Monitor"));
	QPushButton *button1 = CreateMenuButton(tr("&GIS View"));
	QPushButton *button2 = CreateMenuButton(tr("&Video View"));
	QPushButton *button3 = CreateMenuButton(tr("&Information View"));
	QPushButton *button4 = CreateMenuButton(tr("&Alarm View"));

	QVBoxLayout *vbox = new QVBoxLayout;
	vbox->addWidget(button1);
	vbox->addWidget(button2);
	vbox->addWidget(button3);
	vbox->addWidget(button4);
	vbox->addStretch(1);
	groupBox->setLayout(vbox);
	return groupBox;
}

QGroupBox* MainWindow::CreateHistoryViewGroupBox()
{
	QGroupBox *groupBox = new QGroupBox(tr("&History Data"));
	QPushButton *button1 = CreateMenuButton(tr("&Trajectory Playback"));
	QPushButton *button2 = CreateMenuButton(tr("&Location Playback"));
	QPushButton *button3 = CreateMenuButton(tr("&Information Playback"));
	QPushButton *button4 = CreateMenuButton(tr("&Alarm Playback"));

	QVBoxLayout *vbox = new QVBoxLayout;
	vbox->addWidget(button1);
	vbox->addWidget(button2);
	vbox->addWidget(button3);
	vbox->addWidget(button4);
	vbox->addStretch(1);
	groupBox->setLayout(vbox);
	return groupBox;
}

QGroupBox* MainWindow::CreateManagementGroupBox()
{
	QGroupBox *groupBox = new QGroupBox(tr("&System Administration"));
	QPushButton *button1 = CreateMenuButton(tr("&Cars"));
	QPushButton *button2 = CreateMenuButton(tr("&Users"));
	QPushButton *button3 = CreateMenuButton(tr("&Map"));

	QVBoxLayout *vbox = new QVBoxLayout;
	vbox->addWidget(button1);
	vbox->addWidget(button2);
	vbox->addWidget(button3);
	vbox->addStretch(1);
	groupBox->setLayout(vbox);
	return groupBox;
}

QGroupBox* MainWindow::CreateConfigGroupBox()
{
	QGroupBox* groupBox = new QGroupBox(tr("&Config"));
	QPushButton *button1 = CreateMenuButton(tr("&Client Config"));
	QPushButton *button2 = CreateMenuButton(tr("&Server Status"));

	QVBoxLayout *vbox = new QVBoxLayout;
	vbox->addWidget(button1);
	vbox->addWidget(button2);	
	vbox->addStretch(1);
	groupBox->setLayout(vbox);
	return groupBox;
}

QLabel* MainWindow::CreateSamplePage(QString picPath)
{
	QLabel* page = new QLabel();
	page->setAlignment( Qt::AlignLeft | Qt::AlignTop );
	QPixmap* pic = new QPixmap();
	pic->load( picPath );
	page->setPixmap( *pic );
	return page;
}

QStackedWidget* MainWindow::CreatePagesWidget()
{
	QStackedWidget* pages = new QStackedWidget();
	QLabel* page1 = CreateSamplePage( "gisview.bmp" );

	QLabel* page2 = new QLabel();

        //QLabel* page3 = CreateSamplePage( "3.bmp" );
        RealTimePage* page3 =new RealTimePage();

	AlarmPage* page4 = new AlarmPage();

	QLabel* page5 = CreateSamplePage( "5.bmp" );

	QLabel* page6 = new QLabel();

        QLabel* page7 = CreateSamplePage( "7.bmp" );//7.bmp

	QLabel* page8 = new QLabel();

	CarManagePage* page9 = new CarManagePage();

	QLabel* page10 = new QLabel();


	MapPredefinedPage* page11 = new MapPredefinedPage();

	QLabel* page12 = new QLabel();

	QLabel* page13 = new QLabel();


	pages->addWidget( page1 );
	pages->addWidget( page2 );
	pages->addWidget( page3 );
	pages->addWidget( page4 );
	pages->addWidget( page5 );
	pages->addWidget( page6 );
	pages->addWidget( page7 );
	pages->addWidget( page8 );
	pages->addWidget( page9 );
	pages->addWidget( page10 );
	pages->addWidget( page11 );
	pages->addWidget( page12 );
	pages->addWidget( page13 );

	return pages;
}

void MainWindow::changePage()
{
	QWidget* widget = this->focusWidget();
	//QMessageBox::warning( this, "Hello", widget->windowTitle() );

	if ( maps.find( widget ) != maps.end() )
	{
		int index = maps[ widget ];

		if (  pagesWidget->count() >= index )
			pagesWidget->setCurrentIndex( index-1 );
	}
}
