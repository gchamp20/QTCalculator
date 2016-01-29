#include "../include/characterButton.h"

CharacterButton::CharacterButton(QWidget *parent) : QPushButton(parent)
{
    realValue_ = text();
    connect(this, SIGNAL(pressed()), this, SLOT(triggerPressed()));
}

CharacterButton::CharacterButton(const QString& text, QWidget *parent) : QPushButton(text, parent), realValue_(text)
{
    connect(this, SIGNAL(pressed()), this, SLOT(triggerPressed()));
}

CharacterButton::~CharacterButton()
{

}

void CharacterButton::setText(const QString &text)
{
    QPushButton::setText(text);
    realValue_ = text;
}

void CharacterButton::setTextValue(const QString &text)
{
    realValue_ = text;
}

QString CharacterButton::getTextValue()
{
    return realValue_;
}

void CharacterButton::triggerPressed()
{
    emit pressed(text(), realValue_);
}

//Event override
void CharacterButton::resizeEvent(QResizeEvent *e)
{
    QPushButton::resizeEvent(e);
}
