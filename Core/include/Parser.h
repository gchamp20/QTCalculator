#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDE

#include "Expression.h"


/*!
    \file Parser.h
    \Author Guillaume Champagne
    \date 12 January 2015
    \brief Parser class
*/


//! Parser class
/*!
    Object used to evaluate an Expression and apply operation priority
*/
class Parser {

    public:

    //! Default Constructor
    /*!
        Init the parser to decimal mode
    */
    Parser();

    //! Destructor
    /*!
        Nothing done here
    */
    ~Parser();

    double evaluteExpression(const Expression &input);

    /*!
        \brief Implementation of Dijkstra's shunting yard algo to create postfix notation
        \return string. The postfix notation to evalute
    */
    std::queue<std::string> createPostFix(const std::string &input);

    private:

    /*!
        Mode of the parser
    */
    bool isDecimal_;


    /*!
        \brief Evaluate a postfix notation expression
        \return double. Value of the evalutated output
    */
    double evaluatePostFix(const std::string &input);

    /*!
        \brief Takes two numbers and evalutes them according to the operator
        \return double
    */
    double doOperation(double firstNb, double secondNb, char operators);

    /*!
        \brief Find operator precedence
        \return int. Value of the precedence. 1 being the highest
    */
    int getOperatorPrecedence(const std::string &operators);

    /*!
        \brief Determine if operator is left associative
        \return bool
    */
    bool testLeftAssociativity(const std::string &operators);

    /*!
        \brief Split the initial string in tokens (Each number, operators separated)
        \return std::vector<std::string> containing each token
    */
    std::vector<std::string> parseStringToToken(const std::string &input);

    double convertStringToNumber(const std::string &input);

};

#endif // PARSER_H_INCLUDED
