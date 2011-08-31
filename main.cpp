#include <QtGui/QApplication>
#include <QTranslator>
#include "mainwindow.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
        MainWindow w;
        QTranslator translator;
        translator.load("arrowpad_cn");
        app.installTranslator(&translator);
        w.show();

	return app.exec();
}
