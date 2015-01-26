#include <stack>
#include <queue>
#include <sstream>
#include <iostream>
#include <limits>
#include <cmath>
#include <cerrno>
#include "../include/Parser.h"

/*!
    \file Parser.cpp
    \Author Guillaume Champagne
    \date 12 January 2015
    \brief Parser class implementation file
*/

Parser::Parser() : isDecimal_(true)
{

}

Parser::~Parser()
{

}

double Parser::evaluteExpression(const Expression &input, bool& failed)
{
    return evaluatePostFix(input.getString(), failed);
}

double Parser::evaluatePostFix(const std::string &input, bool& failed)
{
    std::queue<std::string> postFix = createPostFix(input);
    std::stack<double> numbers;
    std::string debug;
    std::string mainQuery = input;
    double result = 0;
    double firstNumber = 0;
    double secondNumber = 0;
    bool overflow = false;
    while(!postFix.empty() && !overflow)
    {
        debug = postFix.front();
        if(isdigit(postFix.front()[0]) || postFix.front()[0] == '#')
        {
            numbers.push(convertStringToNumber(postFix.front()));
            postFix.pop();
        }
        else //is an operator
        {
            secondNumber = numbers.top();
            numbers.pop();
            firstNumber = numbers.top();
            numbers.pop();
            result = doOperation(firstNumber, secondNumber, postFix.front().c_str()[0], overflow); //all operators are 1 charater
          //  std::cout << firstNumber << " " << postFix.front() << " " << secondNumber << " = " << result << std::endl;
            postFix.pop();
            numbers.push(result);
        }
    }
    failed = overflow;
    return numbers.top();
}

double Parser::doOperation(double firstNb, double secondNb, char operators, bool& isOverflow)
{
    double result = 0;

    if(operators == '+' && !testAdditionOverflow(firstNb, secondNb)) {
        result = firstNb + secondNb;
    }
    else if(operators == '-' && !testSubstractionOverflow(firstNb, secondNb)) {
        result = firstNb - secondNb;
    }
    else if(operators == '*' && !testMultiplicationOverflow(firstNb, secondNb)) {
        result = firstNb * secondNb;
    }
    else if(operators == '/') {
        if(secondNb == -1) {
            result = -firstNb;
        }
        else if(!testDivisionOverflow(firstNb, secondNb)) {
            result = firstNb / secondNb;
        }
        else {
            isOverflow = true;
        }
    }
    else if(operators == '^' && !testExponentOverflow(firstNb,secondNb)) {
        result = pow(firstNb,secondNb);
    }
    else {
        isOverflow = true;
    }

    return result;
}

std::queue<std::string> Parser::createPostFix(const std::string &input)
{
    std::queue<std::string> output;
    std::stack<std::string> operators;
    std::vector<std::string> tokens = parseStringToToken(input);
    std::string debug;
    std::string toPush;
    for(unsigned int i = 0; i < tokens.size(); i++)
    {
        debug = tokens[i];
        if(isdigit(tokens[i][0]) || tokens[i][0] == '#')
        {
            output.push(tokens[i]);
        }
        //TO DO
        //If functions (sin,cos,log...)
        else if(tokens[i] != "(" && tokens[i] != ")") //assume token is an operator (Functions not implemented)
        {
            if(!operators.empty())
            {
                int tokensPrecedence = getOperatorPrecedence(tokens[i]);
                int topTokenPrecedence = getOperatorPrecedence(operators.top());
                bool isLeftAssociative = testLeftAssociativity(tokens[i]);
                bool isOperator = (operators.top() != "(" && operators.top() != ")");
                bool isEmpty = false;
                while(isOperator && !isEmpty && ((isLeftAssociative  && tokensPrecedence >= topTokenPrecedence) ||
                        (!isLeftAssociative && tokensPrecedence > topTokenPrecedence)))
                {
                    output.push(operators.top());
                    //std::cout << "Popped : " << operators.top() << std::endl;
                    operators.pop();
                    isEmpty = operators.empty();
                    if(!isEmpty)
                    {
                        isOperator = (operators.top() != "(" && operators.top() != ")");
                        topTokenPrecedence = getOperatorPrecedence(operators.top());
                    }
                }
            }
            operators.push(tokens[i]);
            //std::cout << "Pushed : " << tokens[i] << std::endl;
        }
        else if(tokens[i] == "(")
        {
            operators.push(tokens[i]);
           // std::cout << "Pushed : " << tokens[i] << std::endl;
        }
        else if(tokens[i] == ")")
        {
            while(operators.top() != "(")
            {
                toPush = operators.top();
                output.push(operators.top());
                operators.pop();
                toPush = operators.top();
            }
            operators.pop();
        }
    }
    while(!operators.empty())
    {
        output.push(operators.top());
        operators.pop();
    }
    return output;
}

std::vector<std::string> Parser::parseStringToToken(const std::string &input)
{
    std::vector<std::string> output;
    std::string buffer;
    buffer.clear();
    for(unsigned int i = 0; i < input.length(); i++)
    {
        if(isdigit(input[i]) || input[i] == '#' || input[i] == '.')
        {
            buffer += input[i];
        }
        else if(input[i] == 'e') { //scientific notation
            if(i < input.length() - 1) { //make sure we're not going over bounds
                buffer += input[i];
                ++i;
                buffer += input[i];
            }
        }
        else
        {
            if(!buffer.empty())
            {
                output.push_back(buffer);
                buffer.clear();
            }
            buffer += input[i];
            output.push_back(buffer);
            buffer.clear();
        }
    }
    if(!buffer.empty())
    {
        output.push_back(buffer);
    }
    return output;
}

double Parser::convertStringToNumber(const std::string &input)
{
    std::stringstream converter;
    double result;
    bool isNegative = false;
    if(input[0] == '#')
    {
        std::string positiveVersion = input.substr(1, input.length());
        isNegative = true;
        converter << positiveVersion;
    }
    else
    {
        converter << input;
    }
    converter >> result;
    if(isNegative)
        return -result;
    else
        return result;
}

int Parser::getOperatorPrecedence(const std::string &operators)
{
    int precedence = 0;

    if(operators == "(" || operators == ")")
        precedence = 1;
    else if(operators == "!")
        precedence = 2;
    else if(operators == "^")
        precedence = 3;
    else if(operators == "*" || operators == "/" || operators == "%")
        precedence = 4;
    else if(operators == "+" || operators == "-")
        precedence = 5;
    return precedence;
}

bool Parser::testLeftAssociativity(const std::string &operators)
{
    if(operators == "+" || operators == "-" || operators == "*" || operators == "/" || operators == "^")
        return true;
    else
        return false;
}

bool Parser::testAdditionOverflow(double a, double b)
{
    if((b > 0 && a > std::numeric_limits<double>::max() - b) ||
       (b < 0 && a < (-std::numeric_limits<double>::max()) - b)) {
        return true;
    }
    else {
        return false;
    }
    return true;
}

bool Parser::testSubstractionOverflow(double a, double b)
{
    if((b >= 0 && a < (-std::numeric_limits<double>::max()) + b) ||
       (b < 0 && a > std::numeric_limits<double>::max() + b)) {
        return true;
    }
    else {
        return false;
    }
    return true;
}
bool Parser::testMultiplicationOverflow(double a, double b)
{
    if(a > 0) {
        if(b > 0) {
            if(a > std::numeric_limits<double>::max()/b)
                return true;
            else
                return false;
        }
        else {
            if(b < (-std::numeric_limits<double>::max())/a)
                return true;
            else
                return false;
        }
    }
    else {
        if(b > 0) {
            if(a < (-std::numeric_limits<double>::max())/b)
                return true;
            else
                return false;
        }
        else {
            if(a != 0 && b < std::numeric_limits<double>::max() / a)
                return true;
            else
                return false;
        }
    }
    return true;
}

bool Parser::testDivisionOverflow(double a, double b)
{
    if(b == 0 || b == (-std::numeric_limits<double>::max()) || b == -1)
        return true;
    else
        return false;
}

bool Parser::testExponentOverflow(double a, double b)
{
    double result = std::pow(a,b);
    if(errno == EDOM || errno == ERANGE)
        return true;
    else
        return false;
}











