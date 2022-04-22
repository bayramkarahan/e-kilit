#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QWidget>

class Keyboard : public QWidget{
    Q_OBJECT
private:
    QString data;
public:
    explicit Keyboard(QWidget *parent = 0);
    //void setQRData(QString data);

protected:
   // void paintEvent(QPaintEvent *);
};
#endif // KEYBOARD_H
