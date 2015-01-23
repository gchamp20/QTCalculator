#include "../include/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    buttonContainer_ = new QWidget(this);
    buttonLayout_ = new QGridLayout;
    screen_ = new LCDScreen("", this);
    createDigitButtons();
    setChildsDimensions();
    setButtonContainerLayout();
}

MainWindow::~MainWindow()
{
    delete buttonContainer_;
    delete screen_;
    for(int i = 0 ; i < digitButtons_.size(); ++i) {
        delete digitButtons_[i];
    }
}

void MainWindow::createDigitButtons()
{
    for(int i = 0; i < 10; ++i) {
        digitButtons_.append(new DigitButton(QString::number(i)));
        connect(digitButtons_[i], SIGNAL(pressed(int)), screen_, SLOT(addText(int)));
    }
}

void MainWindow::setButtonContainerLayout()
{
    const int ROW = 5;
    const int COLUMN = 4;
    int currentRow = ROW - 1;
    int thatsizethought = digitButtons_.size();
    buttonLayout_->addWidget(digitButtons_[0], currentRow, 0);
    --currentRow;
    for(int i = 0; i < digitButtons_.size() - 1; ++i) {
        buttonLayout_->addWidget(digitButtons_[i+1], currentRow, i % (COLUMN - 1));
        if(i != 0 && (i % COLUMN - 1) == 0) {
            --currentRow;
        }
    }
    buttonContainer_->setLayout(buttonLayout_);
}

void MainWindow::setChildsDimensions()
{
    screen_->setGeometry(0,0,size().width(), 75);
    buttonContainer_->setGeometry(0, screen_->height() + 20, width(), height() - 75);
}

void MainWindow::resizeEvent(QResizeEvent* e)
{
    this->QMainWindow::resizeEvent(e);
    setChildsDimensions();
}
