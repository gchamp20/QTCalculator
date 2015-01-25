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

void Expression::addCharacter(const std::string character)
{
	expression_.append(character);
}

void Expression::removeCharacter(const int& number)
{
    if(expression_.length() != 0) {
    expression_.erase(expression_.length() - number, number);
    }
}

void Expression::clearAll()
{
    expression_.clear();
    value_ = 0;
}

void Expression::setValue(double value)
{
    value_ = value;
}
