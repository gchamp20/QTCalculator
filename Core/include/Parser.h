#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDE

#include <queue>
#include <vector>
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
        \brief Init the parser to decimal mode
    */
    Parser();

    //! Destructor
    /*!
        \brief Nothing done here
    */
    ~Parser();

    double evaluteExpression(const Expression &input, bool& failed);

    /*!
     * \brief getErrorCode
     * \return Error code (or errorCodes::NONE (0) if no errors)
     */
    int getErrorCode();

    /*!
     * \brief The errorCodes enum Enum of all error codes
     */
    enum errorCodes {NONE, ERR_SYNTAX, ERR_OVERFLOW};

    private:

    /*!
        \brief Mode of the parser
    */
    bool isDecimal_;

    /*!
     * \brief errorCode_ Used to store the error code (if needed)
     */
    int errorCode_;

    /*!
        \brief Evaluate a postfix notation expression
        \return double. Value of the evalutated output
    */
    double evaluatePostFix(const std::string &input, bool& failed);

    /*!
        \brief Implementation of Dijkstra's shunting yard algo to create postfix notation
        \return string. The postfix notation to evalute
    */
    std::queue<std::string> createPostFix(const std::string &input, bool &failed);

    /*!
        \brief Split the initial string in tokens (Each number, operators separated)
        \return std::vector<std::string> containing each token
    */
    std::vector<std::string> parseStringToToken(const std::string &input, bool& failed);

    /*!
        \brief Takes two numbers and evalutes them according to the operator
        \return double
    */
    double doOperation(double firstNb, double secondNb, char operators, bool& isOverflow);

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
        \brief Takes a string and returns it as a double
        \return double
    */
    double convertStringToNumber(const std::string &input, bool& failed);

    /*!
        \brief Test for addition overflow
        \return bool
    */
    bool testAdditionOverflow(double a, double b);
    /*!
        \brief Test for substraction overflow
        \return bool
    */
    bool testSubstractionOverflow(double a, double b);
    /*!
        \brief Test for multiplication overflow
        \return bool
    */
    bool testMultiplicationOverflow(double a, double b);

    /*!
        \brief Test for division overflow
        \return bool
    */
    bool testDivisionOverflow(double a, double b);

    /*!
         * \brief testExponentOverflow Test for exponentoverflow
         * \return bool
     */
    bool testExponentOverflow(double a, double b);

};

#endif // PARSER_H_INCLUDED
