#include <QtGui/QApplication>
#include <QTranslator>
#include "mainwindow.h"
#include <QMessageBox>
#include <QTime>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        MainWindow w;
        QTranslator translator;
        translator.load("arrowpad_cn");
        app.installTranslator(&translator);
        w.show();

	return app.exec();
}
