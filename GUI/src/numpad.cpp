#include "../include/numpad.h"

Numpad::Numpad(QWidget* parent) : QWidget(parent)
{
    createButtons();
    initializeButtons();
    createLayout();
    connectSignals();
}

Numpad::Numpad(const int &width, const int &height, QWidget *parent) : QWidget(parent)
{
    setGeometry(0,0,width,height);
    createButtons();
    initializeButtons();
    createLayout();
    connectSignals();
}

Numpad::~Numpad()
{
    for(int i = 0; i < digits_.size(); ++i) {
        delete digits_[i];
    }

    for(int i = 0; i < operators_.size(); ++i) {
        delete operators_[i];
    }

    for(int i = 0; i < controls_.size(); ++i) {
        delete controls_[i];
    }
}

void Numpad::triggerDigits(int value)
{
    emit digitPressed(value);
}

void Numpad::triggerOperator()
{
    //TO IMPLEMENT
}

void Numpad::triggerEnter()
{
    emit enterPressed();
}

void Numpad::triggerClear()
{
    emit clearPressed();
}

void Numpad::createButtons()
{
    for(unsigned int i = 0; i < 10; ++i) {
        digits_.push_back(new DigitButton(QString::number(i), this));
    }

    for(int i = static_cast<int>(Operation::ADDITION); i < static_cast<int>(Operation::END_ENUM); ++i) {
        operators_.push_back(new QPushButton(this));
    }

    for(int i = static_cast<int>(Control::ENTER); i < static_cast<int>(Control::END_ENUM); ++i) {
        controls_.push_back(new QPushButton(this));
    }
}

void Numpad::initializeButtons()
{
    operators_[static_cast<int>(Operation::ADDITION)]->setText("+");
    operators_[static_cast<int>(Operation::SUBSTRACION)]->setText("-");
    operators_[static_cast<int>(Operation::MULTIPLICATION)]->setText("x");
    operators_[static_cast<int>(Operation::DIVISION)]->setText("/");
    operators_[static_cast<int>(Operation::LPARENTHESIS)]->setText("(");
    operators_[static_cast<int>(Operation::RPARENTHESIS)]->setText(")");
    operators_[static_cast<int>(Operation::MINUS)]->setText("( - )");
}

void Numpad::connectSignals()
{
    for(int i = 0; i < digits_.size(); ++i) {
        connect(digits_[i], SIGNAL(pressed(int)), this, SLOT(triggerDigits(int)));
    }

    for(int i = 0; i < operators_.size(); ++i) {
        //TO DO
    }
    connect(controls_[static_cast<int>(Control::ENTER)], SIGNAL(pressed()), this, SLOT(triggerEnter()));
    connect(controls_[static_cast<int>(Control::CLEAR)], SIGNAL(pressed()), this, SLOT(triggerClear()));
}

void Numpad::createLayout()
{
    const int ROW = 5;
    const int COLUMN = 4;
    const int ROW_SPACE = 5;
    const int COLUMN_SPACE = 5;
    buttonSize_ = QSize(width()/COLUMN, static_cast<int>(0.80*(height()/ROW)));
    int currentColumn = 0;
    int currentRow = ROW - 1;
    digits_[0]->setGeometry(calculatePosition(currentRow,currentColumn, ROW_SPACE, COLUMN_SPACE));
    --currentRow;
    for(int i = 0; i < digits_.size() - 1; ++i) {
        currentColumn = i % (COLUMN - 1);
        if(i % (COLUMN - 1) == 0 && i != 0) {
            --currentRow;
        }
        digits_[i + 1]->setGeometry(calculatePosition(currentRow,currentColumn, ROW_SPACE, COLUMN_SPACE));
    }
    operators_[static_cast<int>(Operation::ADDITION)]->setGeometry(calculatePosition(1, COLUMN - 1,
                                                                                     ROW_SPACE, COLUMN_SPACE));
    operators_[static_cast<int>(Operation::SUBSTRACION)]->setGeometry(calculatePosition(2, COLUMN - 1,
                                                                                     ROW_SPACE, COLUMN_SPACE));
    operators_[static_cast<int>(Operation::MULTIPLICATION)]->setGeometry(calculatePosition(3, COLUMN - 1,
                                                                                     ROW_SPACE, COLUMN_SPACE));
    operators_[static_cast<int>(Operation::DIVISION)]->setGeometry(calculatePosition(4, COLUMN - 1,
                                                                                     ROW_SPACE, COLUMN_SPACE));
    operators_[static_cast<int>(Operation::LPARENTHESIS)]->setGeometry(calculatePosition(4, 1,
                                                                                     ROW_SPACE, COLUMN_SPACE));
    operators_[static_cast<int>(Operation::RPARENTHESIS)]->setGeometry(calculatePosition(4, 2,
                                                                                     ROW_SPACE, COLUMN_SPACE));
    operators_[static_cast<int>(Operation::MINUS)]->setGeometry(calculatePosition(0, COLUMN - 1,
                                                                                     ROW_SPACE, COLUMN_SPACE));
}

QRect Numpad::calculatePosition(int row, int column, int rowSpacing, int columnSpacing)
{
    return QRect(column*(buttonSize_.width()), row * ( buttonSize_.height()),
                 buttonSize_.width(), buttonSize_.height());
}


