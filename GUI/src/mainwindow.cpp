#include "../include/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    buttonContainer_ = new QWidget(this);
    screen_ = new LCDScreen("", this);
    enter_ = new QPushButton("Entré", buttonContainer_);
    clear_ = new QPushButton("Effacé", buttonContainer_);
    createDigitButtons();
    setGeometry(0,0,400,500);
    setChildsDimensions();
    setButtonContainerLayout();
}

MainWindow::~MainWindow()
{
    delete buttonContainer_;
    delete screen_;
    delete clear_;
    delete enter_;
    for(int i = 0 ; i < digitButtons_.size(); ++i) {
        delete digitButtons_[i];
    }
}

void MainWindow::createDigitButtons()
{
    for(int i = 0; i < 10; ++i) {
        digitButtons_.append(new DigitButton(QString::number(i),buttonContainer_));
        connect(digitButtons_[i], SIGNAL(pressed(int)), screen_, SLOT(addText(int)));
    }
}

void MainWindow::setButtonContainerLayout()
{
    const int ROW = 5;
    const int COLUMN = 4;
    int currentRow = ROW - 1;
    int currentColumn = 0;
    int height = (buttonContainer_->height() - (ROW * 5 + 10)) / ROW;
    int width = (buttonContainer_->width() - (COLUMN * 5 + 10)) / COLUMN;
    clear_->setGeometry(5,height * currentRow + ROW, width * 2, height);
    enter_->setGeometry(10 + width * 2, height * currentRow + ROW, width * 2, height);
    --currentRow;
    digitButtons_[0]->setGeometry(5,height * currentRow + ROW, width, height);
    --currentRow;
    for(int i = 0; i < digitButtons_.size() - 1; ++i) {
        currentColumn = i % (COLUMN - 1);
        if(i != 0 && currentColumn == 0) {
            --currentRow;
        }
        digitButtons_[i+1]->setGeometry(5 + width * currentColumn, height * currentRow + ROW, width, height);
    }
}

void MainWindow::setChildsDimensions()
{
    screen_->setGeometry(0,0,size().width(), 85);
    buttonContainer_->setGeometry(0, screen_->height(), width(), height() - 75);
}

void MainWindow::resizeEvent(QResizeEvent* e)
{
    this->QMainWindow::resizeEvent(e);
    setChildsDimensions();
}
