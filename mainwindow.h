#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QDialog>
#include <QMap>

QT_BEGIN_NAMESPACE
class QStackedWidget;
class QGroupBox;
class QLabel;
class QPushButton;
QT_END_NAMESPACE

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
	void changePage();

private:
	QWidget* CreateContentsWidget();
	QStackedWidget* CreatePagesWidget();
	QGroupBox* CreateRealTimeViewGroupBox();
	QGroupBox* CreateHistoryViewGroupBox();
	QGroupBox* CreateConfigGroupBox();
	QGroupBox* CreateManagementGroupBox();

	QPushButton* CreateMenuButton( QString title );
	QLabel *CreateSamplePage( QString picPath );

	QWidget *contentsWidget;
	QStackedWidget *pagesWidget;
	QMap<QWidget*, int> maps;
};

#endif // MAINWINDOW_H
