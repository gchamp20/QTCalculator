#ifndef EXPRESSION_H_INCLUDED
#define EXPRESSION_H_INCLUDED

#include <string>

/*!
    \file Expression.h
    \Author Guillaume Champagne
    \date 12 January 2015
    \brief Expression class
*/


//! Expression class
/*!
    Class wich represents a mathematical expression (numbers only)
*/
class Expression {
    public:

    //! Default constructor
    /*!
        Create empty expression set to decimal mode
    */
    Expression();

    //! Constructor
    /*!
        Create custom expression set to decimal mode
    */
    Expression(const std::string &input);

    //!Destructor
    /*!
        Nothing done here
    */
    ~Expression();

    /*!
        \brief Get value member
        \return double
    */
    double getValue() const;

    /*!
        \brief Get expression member
        \return String
    */
    std::string getString() const;

    /*!
        \brief Set value member
    */
    void setValue(double value);

    protected:

    /*!
        \brief Check the input is valid. Changes isValid member accordingly
        \return bool. Value of the test
    */
    bool checkValidity() const;

    /*!
        Value of the expression when evalutad (via Parser object)
    */
    double value_;

    /*!
        The expression entered as input
    */
    std::string expression_;

    /*!
        Set to true if there's no error in the expression (string input)
    */
    bool isValid_;

};

#endif