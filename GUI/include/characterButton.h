#ifndef CHARACTERBUTTON_H
#define CHARACTERBUTTON_H
#include <QPushButton>

/*!
 *\file characterButton.h
 * \Author Guillaume Champagne
 * \date 24 January 2015
 * \brief CharacterButton class
 * QPushButton that returns its text on pressed signals
 */

/*!
 * \brief The CharacterButton class
 */
class CharacterButton : public QPushButton
{
    Q_OBJECT
public:
    /*!
     * \brief CharacterButton Default constructor
     * \param parent QWidget parent object (default = null)
     */
    explicit CharacterButton(QWidget *parent = 0);

    /*!
     * \brief CharacterButton
     * \param text String written on the button
     * \param parent QWidget parent object (defaul = null)
     */
    explicit CharacterButton(const QString& text, QWidget *parent = 0);
    ~CharacterButton();

    /*!
     * \brief setText Override of parent's object setText
     * \param text  String written on button
     */
    void setText(const QString& text);

    /*!
     * \brief setTextValue Set realValue_
     * \param text New value
     */
    void setTextValue(const QString& text);

    /*!
     * \brief getTextValue Accessor for realValue_
     */
    QString getTextValue();

signals:
    /*!
     * \brief pressed Signals emitted when button is pressed
     * \param value String written on the buton
     * \param realValue Real value to add to the equation (Ex: x pressed but add *)
     */
    void pressed(QString value, QString realValue);

private slots:

    /*!
     * \brief triggerPressed Signal used to trigger pressed(QString)
     */
    void triggerPressed();
private:
    /*!
     * \brief realValue_ Used if the button need to hold a different value than its text
     */
    QString realValue_;
    void resizeEvent(QResizeEvent *);
};

#endif
