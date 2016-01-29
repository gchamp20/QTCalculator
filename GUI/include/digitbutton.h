#ifndef DIGITBUTTON_H
#define DIGITBUTTON_H
#include <QPushButton>

/*!
 *\file digitbutton.h
 * \Author Guillaume Champagne
 * \date 22 January 2015
 * \brief The DigitButton class
 */

//!DigitButton class
/*!
 * Object that represent the calculator numeric buttons
 */

class DigitButton : public QPushButton
{
    Q_OBJECT
public:
    /*!
     * \brief DigitButton Constructor
     * \param parent Parent QWidget (Default set to null)
     */
    explicit DigitButton(QWidget *parent = 0);

    /*!
     * \brief DigitButton Constructor
     * \param text String written on the button
     * \param parent Parent QWidget (Default set to null
     */
    explicit DigitButton(const QString& text, QWidget *parent = 0);

    /*!
      *\brief DigitButton destructor
      */
    ~DigitButton();

signals:

    /*!
     * \brief pressed Signas trigged on button pressed event
     * \param value Integer value of the button
     */
    void pressed(int value);

private slots:
    /*!
     * \brief triggerPressed Slot to trigger custom pressed event
     */
    void triggerPressed();
private:

    /*!
     * \brief value_ Integer value of the button
     */
    int value_;

    void resizeEvent(QResizeEvent *);

};

#endif // DIGITBUTTON_H
