#ifndef NUMPAD_H
#define NUMPAD_H
#include <QWidget>
#include <QVector>
#include "digitbutton.h"
#include "characterButton.h"

/*!
 *\file numpad.h
 * \Author Guillaume Champagne
 * \date 23 January 2015
 * \brief The Numpad class
 */

/*!
 * \brief The Numpad class
 * Object that reprensent the calculator numpad (digits, operators, enter)
 */

class Numpad : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief Numpad Deault constructor
     * \param parent Parent QWidget (default = null)
     */
    explicit Numpad(QWidget* parent = 0);

    /*!
     * \brief Numpad
     * \param width Width desired for the numpad
     * \param height Heigh desired
     * \param parent Parent QWidget (default = null)
     */
    explicit Numpad(const int& width, const int& height, QWidget* parent = 0);
    ~Numpad();
signals:

    /*!
     * \brief digitPressed Triggers when a DigitButton is pressed
     * \param value Integer value of the digit
     */
    void digitPressed(int value);

    /*!
     * \brief operatorPressed Triggers when an operator button is pressed
     * \parem value String of the operator
     */
    void operatorPressed(QString value);

    /*!
     * \brief characterPressed Triggers when any button requiring a new character is pressed
     * \param value String written on the button
     */
    void characterPressed(QString value);

    /*!
     * \brief enterPressed Triggers when enter button is pressed
     */
    void enterPressed();

    /*!
     * \brief clearPressed Triggers when clear button is pressed
     */
    void clearPressed();
private slots:
    /*!
     * \brief triggerDigits Slot used to inform object when digits are pressed
     */
    void triggerDigits(int);

    /*!
     * \brief triggerOperator Slot used to inform object when operators are pressed
     */
    void triggerOperator(QString);

    /*!
     * \brief triggerEnter Slot used to inform object when enter is pressed
     */
    void triggerEnter();

    /*!
     * \brief triggerClear Slot to used inform object when clear is pressed
     */
    void triggerClear();

private:

    /*!
     * \brief The Operation enum. Used as index in operators_ vector
     */
    enum class Operation:int {ADDITION, SUBSTRACION, MULTIPLICATION, DIVISION, LPARENTHESIS, RPARENTHESIS, MINUS, END_ENUM};

    /*!
     * \brief The Control enum. Used as index in controls_ vector
     */
    enum class Control:int {ENTER, CLEAR, END_ENUM};

    /*!
     * \brief digits_ Container for digits buttons
     */
    QVector<DigitButton* > digits_;

    /*!
     * \brief operators_ Container for operators buttons
     */
    QVector<CharacterButton* > operators_;

    /*!
     * \brief controls_ Container for controls buttons (enter, clear)
     */
    QVector<QPushButton* > controls_;

    /*!
     * \brief buttonSize Size of a sigle button
     */
    QSize buttonSize_;

    /*!
     * \brief createButtons Allocates space for all buttons
     */
    void createButtons();

    /*!
     * \brief initializeButtons Initializes (setText mostly) all buttons
     */
    void initializeButtons();

    /*!
     * \brief connectSignals Connect signals to button to slots of Numpad object
     */
    void connectSignals();

    /*!
     * \brief createLayout Place buttons in the container
     */
    void createLayout();

    QRect calculatePosition(int row, int column, int rowSpacing, int columnSpacing);

};


#endif
