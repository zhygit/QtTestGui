#include "carmanagepage.h"
#include <QTGui>

CarManagePage::CarManagePage(QWidget *parent) :
	QWidget(parent)
{
	QTabWidget* tabWidget = new QTabWidget();
	QWidget* summaryWidget = CreateSummaryWidget();
	QWidget* unitsWidget = CreateUnitsWidget();
	QWidget* settingsWidget = CreateSettingsWidget();
	tabWidget->addTab( summaryWidget, tr( "Summary" ) );
	tabWidget->addTab( unitsWidget, tr( "Units" ) );
	tabWidget->addTab( settingsWidget, tr( "Settings" ) );

	QHBoxLayout* layout = new QHBoxLayout();
	layout->addWidget( CreateStructureWidget() );
	layout->addWidget( tabWidget );

	setLayout( layout );
}

QWidget* CarManagePage::CreateStructureWidget()
{
	QGroupBox* structureWidget = new QGroupBox();

	QHBoxLayout* hBox = new QHBoxLayout();
	QToolButton* add = new QToolButton();
	add->setText("+");
	QToolButton* remove = new QToolButton();
	remove->setText( "-" );
	hBox->addWidget( add );
	hBox->addWidget( remove );
	hBox->addStretch( 1 );

	QTreeWidget* tree = new QTreeWidget();
	tree->setColumnCount( 1 );
	QTreeWidgetItem* root = new QTreeWidgetItem( QStringList( tr( "DaQing GPS Center") ) );
	QTreeWidgetItem* child1 = new QTreeWidgetItem( QStringList( tr( "test1" ) ) );
	QTreeWidgetItem* child2 = new QTreeWidgetItem( QStringList( tr( "test2" ) ) );
	root->addChild( child1 );
	root->addChild( child2 );
	root->setCheckState( 0, Qt::Unchecked );
	child1->setCheckState( 0, Qt::Unchecked );
	child2->setCheckState( 0, Qt::Unchecked );

	tree->addTopLevelItem( root );
	tree->expandAll();
	QVBoxLayout* vBox = new QVBoxLayout();
	vBox->addLayout( hBox );
	vBox->addWidget( tree );

	structureWidget->setLayout( vBox );
	return structureWidget;
}

QWidget* CarManagePage::CreateUnitsWidget()
{
	return new QWidget();
}

QWidget* CarManagePage::CreateSettingsWidget()
{
	QWidget* settings = new QWidget();
	QGridLayout* layout = new QGridLayout();
	layout->setSizeConstraint( QLayout::SetFixedSize );

	QGroupBox* safeRegions = new QGroupBox( tr("Safe Regions") );
	QGridLayout* layout1 = new QGridLayout();
	layout1->addWidget( new QListWidget() );
	safeRegions->setLayout( layout1 );

	QGroupBox* safePathes = new QGroupBox( tr("Safe Pathes") );
	QGridLayout* layout2 = new QGridLayout();
	layout2->addWidget( new QListWidget() );
	safePathes->setLayout( layout2 );

	QGroupBox* overspeed = new QGroupBox( tr("Over speed") );

	QGroupBox* oilSettings = new QGroupBox( tr( "Oil Settings") );

	layout->addWidget( safeRegions, 0, 0 );
	layout->addWidget( safePathes, 0, 1 );
	layout->addWidget( overspeed, 1, 0 );
	layout->addWidget( oilSettings, 1, 1 );
	settings->setLayout( layout );
	return settings;
}

QWidget* CarManagePage::CreateSummaryWidget()
{
	return new QWidget();
}
