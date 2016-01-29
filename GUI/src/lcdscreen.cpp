#include "../include/lcdscreen.h"

LCDScreen::LCDScreen(QWidget *parent) : QWidget(parent)
{
    textContainer = new QLabel;
    initiliazeDesign();
}

LCDScreen::LCDScreen(const QString &text, QWidget *parent) : QWidget(parent), text_(text)
{
    textContainer = new QLabel;
    textContainer->setText(text_);
    initiliazeDesign();
}

LCDScreen::~LCDScreen()
{
    delete textContainer;
}

void LCDScreen::clearText()
{
    text_.clear();
    updateTextContainer();
}

void LCDScreen::eraseText(const int &numberCharacter)
{
    if(text_.size() != 0) {
        text_.remove(text_.length() - numberCharacter, numberCharacter);
        updateTextContainer();
    }
}

void LCDScreen::setText(const QString &text)
{
    text_ = text;
    updateTextContainer();
}

void LCDScreen::setText(const int &toConvert)
{
    setText(QString::number(toConvert));
}

void LCDScreen::appendText(const QString &text)
{
    text_.insert(text_.length(), text);
    updateTextContainer();
}

void LCDScreen::appendText(const int &toConvert)
{
    appendText(QString::number(toConvert));
}

void LCDScreen::updateTextContainer()
{
    textContainer->setText(text_);
}

void LCDScreen::initiliazeDesign()
{
    textContainer->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    textContainer->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    textContainer->setFont(QFont("Lucida", 20, 3));
    textContainer->setStyleSheet("background-color:white");
    textContainer->setAutoFillBackground(true);
    textContainer->setParent(this);
}

//Events overriding
void LCDScreen::resizeEvent(QResizeEvent *e)
{
    this->QWidget::resizeEvent(e);
    textContainer->setGeometry(5,5,size().width() - 10, size().height() - 10);
}
