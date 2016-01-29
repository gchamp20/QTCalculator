#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QList>
#include <QMap>
#include <QGridLayout>
#include "../../Core/include/Parser.h"
#include "../../Core/include/Expression.h"
#include "lcdscreen.h"
#include "numpad.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
     * \brief MainWindow Constructor
     * \param parent Parent QWidget (default = null)
     */
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void handleEnter();
    /*!
     * \brief handleClear Erases the whole LCDScreen when clear button is pressed
     */
    void handleClear();

    /*!
     * \brief handleErease Erases 1 character for the LCDScreen when erease is pressed
     */
    void handleErase();

    /*!
     * \brief handleEquation Updates Expression object with correct characters
     */
    void handleEquation(QString character);

    /*!
     * \brief handleCharacterPressed Updates screen_ with correct charactgers
     */
    void handleCharacterPressed(QString character);

private:

    /*!
     * \brief screen_ Top screen to show data
     */
    LCDScreen *screen_;

    /*!
     * \brief pad_ Container for digits,control and operation buttons
     */
    Numpad *pad_;

    /*!
     * \brief equation_ Equation on the display
     */
    Expression equation_;

    /*!
     * \brief solver_ Parser object used to solve mathematical equations
     */
    Parser solver_;

    /*!
     * \brief errorState_ Set to true if the calculator encountered an error. Reset by clearing/erasing display
     */
    bool errorState_;
    /*!
     * \brief setChildsDimensions Calculate and set child QWidget dimensions
     */
    void setChildsDimensions();

    /*!
     * \brief isInErrorState Returns errorState_
     */
    bool isInErrorState();

    /*!
     * \brief resizeEvent Override to resize children components
     */
    void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
