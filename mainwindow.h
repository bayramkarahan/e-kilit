#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMenu>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
//#include<QWebEngineView>
#include<QTimer>
#include<QMessageBox>
#include<QComboBox>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "qrcodegen.hpp"

using std::uint8_t;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *object, QEvent* event);
public slots:
    void updateQrCode( QString text,int w,int h );
int getRand(int min, int max);

void formGoster();
void klavyeButtonClick();
void listToFile(QString path, QStringList list, QString filename);
QStringList fileToList(QString path,QString filename);
QString listGetLine(QStringList list, QString data);
QStringList listRemove(QStringList list, QString data);

void onLoadFinished1();
void onUrlChanged1();
void onLoadFinished2();
void onUrlChanged2();
void handleHTML(QString sHTML);
void qrkodPngSlot();
bool kontrol(QString _user,QString _password);
QString sudoYetkiKontolSlot(QString _user);
QString passwordKontrolSlot(QString _user,QString _password);
QString myMessageBox(QString baslik, QString mesaj, QString evet, QString hayir, QString tamam, QMessageBox::Icon icon);

signals:
    void getHTML(QString sHTML);

private:
   /* bool status;
    QLineEdit *localPassword;
    QComboBox *localUsername;
    QString sudoyetki="";
    QString user;
    QString passwordstatus;
*/
int en,boy;
    //Ui::MainWindow *ui;
    QWidget *giris();
    QPushButton *keybordButton;
QLineEdit *passwd;
QLabel *sifre;
QLabel *loginCountLabel;
QMenu *kilitMenu();
QMenu *ayarMenu();
QMenu *hakkindaMenu();
QMenu *girisMenu();
int qrnumber;
QPushButton *enterButton;
QString localDir;
int wbLoadNumber=0;

//QWebEngineView *wb1;
//QWebEngineView *wb2;
QTimer *qrkodpngtimer;
QLabel *qw;
};

#endif // MAINWINDOW_H
