#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <QWidget>
#include "flowlayout.h"

class ButtonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ButtonWidget(QWidget *parent = 0);
    ButtonWidget(QSize size);
    ButtonWidget(int buttonwidth,int buttonheight);
    void setButtonSize(int width,int height);
    void setButtonSize(QSize size);
    void addNewButton(const QString &buttonname);
    void addNewButton(const QString &buttonname,bool isFlat);
    FlowLayout* getLayout();
signals:

public slots:
private:
    QSize buttonsize;
    FlowLayout *layout;


};

#endif // BUTTONWIDGET_H
