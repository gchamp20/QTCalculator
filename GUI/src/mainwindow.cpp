#include "../include/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), errorState_(false)
{
    screen_ = new LCDScreen("", this);
    setGeometry(50,50,275,400);
    setWindowTitle("Calculatrice");
    setFixedSize(275,400);
    pad_ = new Numpad(width(), height() - 75, this);
    setChildsDimensions();
    connect(pad_, SIGNAL(characterPressed(QString)), this, SLOT(handleCharacterPressed(QString)));
    connect(pad_, SIGNAL(enterPressed()), this, SLOT(handleEnter()));
    connect(pad_, SIGNAL(clearPressed()), this, SLOT(handleClear()));
    connect(pad_, SIGNAL(erasePressed()), this, SLOT(handleErase()));
    connect(pad_, SIGNAL(updateEquation(QString)), this, SLOT(handleEquation(QString)));
}

MainWindow::~MainWindow()
{
    delete pad_;
    delete screen_;
}

void MainWindow::handleClear()
{
    screen_->clearText();
    equation_.clearAll();
    errorState_ = false;
}

void MainWindow::handleErase()
{
    if(isInErrorState()) {
        handleClear();
    }
    else {
    screen_->eraseText(1);
    equation_.removeCharacter(1);
    }
}

void MainWindow::handleCharacterPressed(QString character)
{
    if(isInErrorState()) {
        handleClear();
    }
    screen_->appendText(character);
}

void MainWindow::handleEnter()
{
    if(!isInErrorState()) {
        bool error = false;
        double result = solver_.evaluteExpression(equation_, error);
        equation_.clearAll();
        if(!error) {
            QString toAdd = QString::number(result);
            screen_->setText(toAdd);
            if(toAdd.contains("-")) {
                toAdd.replace(0,1,"#");
            }
            equation_.addCharacter(toAdd.toStdString());
        }
        else {
            if(solver_.getErrorCode() == Parser::ERR_OVERFLOW) {
                screen_->setText("Erreur (overflow)");
            }
            else if(solver_.getErrorCode() == Parser::ERR_SYNTAX) {
                screen_->setText("Erreur (syntaxe)");
            }
            else {
                screen_->setText("Erreur");
            }
            errorState_ = true;
        }
    }
}

void MainWindow::handleEquation(QString character)
{
    equation_.addCharacter(character.toStdString());
}

void MainWindow::setChildsDimensions()
{
    screen_->setGeometry(0,0,size().width(), 85);
    pad_->setGeometry(0, screen_->height(), width(), height() - 75);
}

bool MainWindow::isInErrorState()
{
    return errorState_;
}

//Event override
void MainWindow::resizeEvent(QResizeEvent* e)
{
    this->QMainWindow::resizeEvent(e);
    setChildsDimensions();
}
