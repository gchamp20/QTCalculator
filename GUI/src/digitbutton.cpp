#include "../include/digitbutton.h"

/*!
 *\file digitbutton.cpp
 * \Author Guillaume Champagne
 * \date 22 January 2015
 * \brief The DigitButton class implementation file
 */

DigitButton::DigitButton(QWidget *parent) : QPushButton(parent)
{
    value_ = 0;
    connect(this, SIGNAL(pressed()), this, SLOT(triggerPressed()));
}

DigitButton::DigitButton(const QString &text, QWidget *parent) : QPushButton(text, parent)
{
    value_= text.toInt();
    connect(this, SIGNAL(pressed()), this, SLOT(triggerPressed()));
}

DigitButton::~DigitButton()
{

}

void DigitButton::triggerPressed()
{
    emit pressed(value_);
}

void DigitButton::resizeEvent(QResizeEvent* e)
{
    QPushButton::resizeEvent(e);
}
