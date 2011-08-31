#include "mappredefinedpage.h"
#include <QtGui>


MapPredefinedPage::MapPredefinedPage(QWidget *parent) :
    QWidget(parent)
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
	left->addWidget( CreateQueryWidget() );
	left->addWidget( mapToolBar );
	left->addWidget( map );
	left->addStretch( 1 );

	QGridLayout* right = new QGridLayout();
	right->addWidget( CreateRegionWidget(), 0, 0 );
	right->addWidget( CreateRouteWidget(), 1, 0 );

	QHBoxLayout* layout = new QHBoxLayout();
	layout->addLayout( left );
	layout->addLayout( right );
	setLayout( layout );

}

QWidget*  MapPredefinedPage::CreateQueryWidget()
{
	QTabWidget* query = new QTabWidget();

	QWidget* searchMaps = new QWidget();
	QHBoxLayout* layout1 = new QHBoxLayout();
	layout1->addWidget(  new QLineEdit() );
	layout1->addWidget( new QPushButton( tr("Search" ) ) );
	searchMaps->setLayout( layout1 );

	QWidget* getDirections = new QWidget();
	QHBoxLayout* layout2 = new QHBoxLayout();
	layout2->addWidget( new QLabel( tr( "From:" )) );
	layout2->addWidget(  new QLineEdit() );
	layout2->addWidget( new QLabel( tr( "To:" )) );
	layout2->addWidget(  new QLineEdit() );
	layout2->addWidget( new QPushButton( tr( "Search" ) ) );
	getDirections->setLayout( layout2 );

	query->addTab( searchMaps, tr( "Search Maps") );
	query->addTab( getDirections, tr( "Get Directions" ));
	return query;
}

QWidget* MapPredefinedPage::CreateRegionWidget()
{
	QGroupBox* region = new QGroupBox( tr( "Region") );

	QGridLayout* grid = new QGridLayout();
	grid->setSizeConstraint(QLayout::SetFixedSize);
	QToolButton* add = new QToolButton();
	add->setText("+");
	QToolButton* remove = new QToolButton();
	remove->setText( "-" );
	QLineEdit* queryText = new QLineEdit();
	QToolButton* doQuery = new QToolButton();
	doQuery->setText( "?" );
	grid->addWidget( add, 0, 0 );
	grid->addWidget( remove, 0, 1 );
	grid->addWidget( queryText, 0, 2, 1, 4  );
	grid->addWidget( doQuery, 0, 6 );

	QVBoxLayout* vBox = new QVBoxLayout();
	QListWidget* contents = new QListWidget();
	vBox->addLayout( grid );
	vBox->addWidget( contents );

	region->setLayout( vBox );
	return region;
}

QWidget* MapPredefinedPage::CreateRouteWidget()
{
	QGroupBox* route = new QGroupBox( tr( "Route" ) );

	QGridLayout* grid = new QGridLayout();
	grid->setSizeConstraint(QLayout::SetFixedSize);
	QToolButton* add = new QToolButton();
	add->setText("+");
	QToolButton* remove = new QToolButton();
	remove->setText( "-" );
	QLineEdit* queryText = new QLineEdit();
	QToolButton* doQuery = new QToolButton();
	doQuery->setText( "?" );
	grid->addWidget( add, 0, 0 );
	grid->addWidget( remove, 0, 1 );
	grid->addWidget( queryText, 0, 2, 1, 4  );
	grid->addWidget( doQuery, 0, 6 );

	QVBoxLayout* vBox = new QVBoxLayout();
	QListWidget* contents = new QListWidget();
	vBox->addLayout( grid );
	vBox->addWidget( contents );

	route->setLayout( vBox );
	return route;
}
