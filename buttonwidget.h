#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <QWidget>
#include <QGroupBox>
#include <QMap>
#include "flowlayout.h"
#include <QPushButton>
class QButtonGroup;


class ButtonWidget : public QGroupBox
{
    Q_OBJECT
public:
    explicit ButtonWidget(QWidget *parent = 0);
    ButtonWidget(QSize size);
    ButtonWidget(int buttonwidth,int buttonheight);
    void setButtonSize(int width,int height);
    void setButtonSize(QSize size);
    void CreateButton(const QString &buttonname);
    void CreateButton(const QString &buttonname,bool isFlat);
signals:
    void onClicked(const QString &name);
public slots:
    void DoClicked();
private:
    QSize buttonsize;
    FlowLayout *layout;
    int index;

};

#endif // BUTTONWIDGET_H
