#ifndef LCDSCREEN_H
#define LCDSCREEN_H
#include <QWidget>
#include <QLabel>

/*!
 *\file lcdscreen.h
 * \Author Guillaume Champagne
 * \date 22 January 2015
 * \brief The LCDScreen class
 */

/*!
 * \brief The LCDScreen class represent a simple display
 */
class LCDScreen : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief LCDScreen Constructor
     * \param parent Parent QWidget (null by default)
     */
    explicit LCDScreen(QWidget *parent = 0);

    /*!
     * \brief LCDScreen Constructor
     * \param text String to write on display
     * \param parent Parent QWidget (null by default)
     */
    explicit LCDScreen(const QString& text, QWidget *parent = 0);
    ~LCDScreen();

signals:

public slots:

    /*!
     * \brief setText Set text on display
     * \param text String to add
     */
    void setText(const QString& text);

    /*!
     * \brief setText Set text on display
     * \param toConvert Int to convert, then add
     */
    void setText(const int &toConvert);

    /*!
     * \brief addText Appends text to what's already on display
     * \param text String to append
     * \param position Position to start insertion (default = 0)
     */
    void addText(const QString& text, const int& position = 0);

    /*!
     * \brief addText Appends text to what's already on display
     * \param toConvert Int to convert, to append
     * \parem position Position to start insertion (default = 0)
     */
    void addText(const int& toConvert, const int& position = 0);

private:
    /*!
     * \brief textContainer QLabel where text_ is written
     */
    QLabel *textContainer;

    /*!
     * \brief text_ QString that represent text on display
     */
    QString text_;

    /*!
     * \brief updateTextContainer Sends new text ot textContainer_
     */
    void updateTextContainer();

    /*!
     * \brief initiliazeDesign Set basic properties of textContainer_
     */
    void initiliazeDesign();

    /*!
     * \brief resizeEvent Override resizeEvent (used to resize textContainer_)
     */
    void resizeEvent(QResizeEvent *);
};

#endif // LCDSCREEN_H
