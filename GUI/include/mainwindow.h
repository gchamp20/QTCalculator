#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QList>
#include <QGridLayout>
#include "lcdscreen.h"
#include "digitbutton.h"

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

private:

    /*!
     * \brief buttonContainer_ QWidget for the bottom part of calculator
     */
    QWidget *buttonContainer_;

    /*!
     * \brief buttonLayout_ Row/column layout for buttons
     */
    QGridLayout *buttonLayout_;

    /*!
     * \brief screen_ Top screen to show data
     */
    LCDScreen *screen_;

    /*!
     * \brief digitButtons_ Container of all DigitButton used
     */
    QList<DigitButton* > digitButtons_;

    /*!
     * \brief createDigitButtons Create all digit buttons (0 to 9)
     */
    void createDigitButtons();

    /*!
     * \brief setButtonContainerLayout Initialize row/columns layout for buttons
     */
    void setButtonContainerLayout();

    /*!
     * \brief setChildsDimensions Calculate and set child QWidget dimensions
     */
    void setChildsDimensions();

    /*!
     * \brief resizeEvent Override to resize children components
     */
    void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
