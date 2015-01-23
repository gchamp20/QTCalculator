#include "../include/Expression.h"


/*!
    \file Expression.cpp
    \Author Guillaume Champagne
    \date 12 January 2015
    \brief Expression class implementation file
*/

Expression::Expression() : value_(0), expression_("")
{
    isValid_ = checkValidity();
}

Expression::Expression(const std::string &input) : value_(0), expression_(input)
{
    isValid_ = checkValidity();
}

Expression::~Expression()
{

}

bool Expression::checkValidity() const
{
    return true;
}

double Expression::getValue() const
{
    return value_;
}

std::string Expression::getString() const
{
    return expression_;
}

void Expression::setValue(double value)
{
    value_ = value;
}
