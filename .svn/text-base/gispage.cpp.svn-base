#include "gispage.h"
#include <QtGui>

GisPage::GisPage(QWidget *parent) :
    QWidget(parent)
{

}

QWidget* GisPage::CreateStructureWidget()
{
	QLabel* structure = new QLabel();
	QPixmap* structurePic = new QPixmap();
	structurePic->load( "gis_structure.bmp" );
	structure->setPixmap( *structurePic );
	return structure;
}

QWidget* GisPage::CreateOptionsWidget()
{
	QGroupBox* groupBox = new QGroupBox();
	QFormLayout* layout = new QFormLayout();

}

QWidget* GisPage::CreateGisMapWidget()
{
	QLabel* map = new QLabel();
	QPixmap* mapPic = new QPixmap();
	mapPic->load( "gis_map.bmp" );
	map->setPixmap( *mapPic );
	return mapPic;
}
