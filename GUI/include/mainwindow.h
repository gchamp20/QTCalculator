#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QList>
#include <QMap>
#include <QGridLayout>
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
     * \brief setChildsDimensions Calculate and set child QWidget dimensions
     */
    void setChildsDimensions();

    /*!
     * \brief resizeEvent Override to resize children components
     */
    void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
