#include "buttonwidget.h"
#include "flowlayout.h"
#include <QtGui>

ButtonWidget::ButtonWidget(QWidget *parent) :
    QWidget(parent)
{
    layout = new FlowLayout();
}
ButtonWidget::ButtonWidget(QSize size)
{
    layout = new FlowLayout();
    setButtonSize(size);
}
ButtonWidget::ButtonWidget(int buttonwidth, int buttonheight)
{
    layout = new FlowLayout();
    setButtonSize(buttonwidth,buttonheight);
}

void ButtonWidget::setButtonSize(int width, int height)
{
    buttonsize.setWidth(width);
    buttonsize.setHeight(height);
}
void ButtonWidget::setButtonSize(QSize size)
{
    buttonsize.setWidth(size.width());
    buttonsize.setHeight(size.height());
}
FlowLayout* ButtonWidget::getLayout()
{
    return layout;
}

void ButtonWidget::addNewButton(const QString &buttonname)
{
    QPushButton *newButton = new QPushButton(buttonname);
    newButton->setFixedSize(buttonsize);
    newButton->setAutoFillBackground(true);
    layout->addWidget(newButton);
}

void ButtonWidget::addNewButton(const QString &buttonname, bool isFlat)
{
    QPushButton *newButton = new QPushButton(buttonname);
    newButton->setFixedSize(buttonsize);
    newButton->setAutoFillBackground(true);//为什么这句要在setFlat前才生效？
    newButton->setFlat(isFlat);
    layout->addWidget(newButton);
}
