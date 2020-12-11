#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMenu>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void updateQrCode( QString text );
int getRand(int min, int max);
void zamanlama();
void klavyeButtonClick();
QStringList listRemove(QStringList list,QString data);
QStringList fileToList(QString filename);
void listToFile(QStringList list, QString filename);
QString listGetLine(QStringList list,QString data);

private:
    //Ui::MainWindow *ui;
QLineEdit *passwd;
QLabel *sifre;
QLabel *loginCountLabel;
QMenu *kilitMenu();
QMenu *ayarMenu();
int qrnumber;
QPushButton *enterButton;
QString localDir;
};

#endif // MAINWINDOW_H
