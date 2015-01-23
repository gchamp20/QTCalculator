#ifndef LCDSCREEN_H
#define LCDSCREEN_H

#include <QWidget>
#include <QLabel>

class LCDScreen : public QWidget
{
    Q_OBJECT
public:
    explicit LCDScreen(QWidget *parent = 0);
    explicit LCDScreen(const QString& text, QWidget *parent = 0);
    ~LCDScreen();

signals:

public slots:

    void setText(const QString& text);
    void addText(const QString& text);

private:
        QLabel *textContainer;
        QString text_;

        void updateTextContainer();
        void initiliazeDesign();
        void resizeEvent(QResizeEvent *);
};

#endif // LCDSCREEN_H
