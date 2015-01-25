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
		\brief Add a new character to the expression
		\param character new character to add
	*/
	void addCharacter(const std::string character);

    /*!
        \brief removeCharacter Removes character from the current equation (starts at the end)
        \param number Number of characters to remove
    */
    void removeCharacter(const int& number);

	/*!
        \brief clearAll Clear string and value
    */
	void clearAll();

    /*!
        \brief Set value member
    */
    void setValue(double value);


    protected:

    /*!
        \brief Check if the input is valid. Changes isValid member accordingly
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
