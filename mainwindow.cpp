#include "mainwindow.h"
//#include<qrencode.h>
#include<QColor>

#include <random>
#include "QDateTime"
#include<QDebug>
#include<QLineEdit>
#include<QPushButton>
#include<QLabel>
#include<QMessageBox>
#include<QDesktopWidget>
#include<QRect>
#include<QInputDialog>
#include<QTimer>
#include<QCoreApplication>
#include<QSize>
#include <QApplication>
#include<QScreen>
#include<QPixmap>
#include<QPalette>
#include<QFile>
#include<QDir>
#include<QRegularExpression>
#include<filecrud.h>
#include<menu.h>
#include<QEvent>
#include<QProcess>
void MainWindow::formGoster()
{
    /// if(this->isActiveWindow()) return;

     //     qDebug()<<"formGoster..e-kilit...."<<this->isActiveWindow();


       this->activateWindow();

        passwd->setFocus();

   }
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)//    ui(new Ui::MainWindow)
{

#ifdef WIN32
   // Windows code here
     qDebug()<<"windows...";
     system("c:\\windows\\system32\\taskkill.exe /f /im explorer.exe");
     system("sleep 0.5");

   #else
   // UNIX code here
      qDebug()<<"linux...";
    /*QStringList args1;
    QProcess p1;
    args1 << "-e" << "eta-disable-gestures@pardus.org.tr";
    p1.execute("gnome-shell-extension-tool", args1);
    system("sleep 0.5");

    QStringList args2;
    QProcess p2;
    args2 << "set" << "org.gnome.mutter" << "overlay-key" << "''";
    p2.execute("gsettings", args2);
    system("sleep 0.5");

    //power buttun pasifleşiyor gizleniyor
    system("gsettings set org.gnome.settings-daemon.plugins.power power-button-action nothing");
    system("sleep 0.5");

    //panel gizleniyor
    system("gdbus call --session --dest org.gnome.Shell --object-path /org/gnome/Shell --method org.gnome.Shell.Eval string:'Main.panel.actor.hide();'");
    system("sleep 0.5");
*/
   #endif


    localDir=QDir::homePath()+"/";
    QSize screenSize = qApp->screens()[0]->size();

     int boyut=screenSize.height()/8;
   //  qDebug()<<screenSize.width()/13;
    en=screenSize.width()/25;
    boy=(en/10)*6;
/*************************************************/
    //this->resize(800,800);
    this->resize(screenSize.width(),screenSize.height());
    this->move(0,0);

   //  setAttribute(Qt::WA_TranslucentBackground, true);
  /*  Qt::WindowFlags flags = 0;
     flags |= Qt::FramelessWindowHint;
   // flags |= Qt::ToolTip;
    flags |= Qt::WindowStaysOnTopHint;
    flags |= Qt::BypassWindowManagerHint;
    this->setWindowFlags(flags);
*/
    //this->showFullScreen();
/*   this->setWindowFlags(Qt::Window|
                        Qt::FramelessWindowHint |
                      Qt::WindowStaysOnTopHint
                        |Qt::X11BypassWindowManagerHint);
*/
   this->setAttribute(Qt::WA_ShowWithoutActivating, true);
   this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint | Qt::X11BypassWindowManagerHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    //| Qt::WindowTransparentForInput);
    //| Qt::WindowDoesNotAcceptFocus);
    ///QTimer *timerformGoster = new QTimer(this);
   /// connect(timerformGoster, SIGNAL(timeout()), this, SLOT(formGoster()));
  /// timerformGoster->start(1000);1616

/******************qr-code***********************************/
    qrnumber=getRand(100000,999999);
    qw=new QLabel(this);
   // qw->setQRData(QString::number(qrnumber));
    qw->resize(boyut*2,boyut*2);
    qw->move(boyut/2,screenSize.height()-boyut*3);
    updateQrCode(QString::number(qrnumber),boyut*2,boyut*2);
   // qw->hide();
   // qDebug()<<qrnumber;
/****************************************************/


    /*************************Login Number count********************************/

    auto appIcon = QIcon(":/icons/lock.ico");
    this->setWindowIcon(appIcon);


    QPixmap bkgnd(":/icons/lock.png");
    bkgnd = bkgnd.scaled(screenSize.width()/3,screenSize.height()/3, Qt::IgnoreAspectRatio);
    //QPalette palette;
   // palette.setBrush(QPalette::Background, bkgnd);
    QLabel *simge=new QLabel(this);
    simge->setPixmap(bkgnd);
    simge->resize(screenSize.width()/3,screenSize.height()/3);
    simge->move(screenSize.width()/2-simge->width()/2,boy*2);


    loginCountLabel=new QLabel(this);
    loginCountLabel->resize(screenSize.width()/5,boy);
    loginCountLabel->move(simge->pos()+QPoint(screenSize.width()/12,screenSize.height()/5));

    //loginCountLabel->setText("Şifre");
    QFont fn( "Arial", 18, QFont::Bold);
    loginCountLabel->setFont(fn);
    loginCountLabel->setStyleSheet("color: #000000");

    if(QFileInfo::exists(localDir+"/e-kilit"))
    {
       //qDebug()<<"var";
       QStringList list=fileToList(localDir,"e-kilit");
       QString line=listGetLine(list,"lc"); //değiştirilecek satır getiriliyor

       if(line!="") //iplistname dosyasında varsa
       {
           QStringList lst1=line.split("=");

           //qDebug()<<"okunan"<<lst1[1];

           int logincount=lst1[1].toInt()+1;
           //qDebug()<<"currentlogin"<<logincount;

           QString kmt="echo lc="+QString::number(logincount)+">"+localDir+"e-kilit";
           system(kmt.toStdString().c_str());

           loginCountLabel->setText("Giriş Sayısı: "+QString::number(logincount));

       }
    }
    else
    {
       // qDebug()<<"yok";

        QString kmt="echo lc=1>"+localDir+"e-kilit";
        system(kmt.toStdString().c_str());
        loginCountLabel->setText("Giriş Sayısı: 1");

    }


    //QStringList list=fileToList("iplistname");
    /*****************************************************/
        sifre=new QLabel(this);
        sifre->resize(en*4,boy);
        sifre->move(screenSize.width()/2-sifre->width()/2,screenSize.height()/2-boy);
        QFont f1( "Arial", 12, QFont::Normal);
        sifre->setFont(f1);
        sifre->setStyleSheet("QLabel { color : black; }");
        sifre->setText("Şifre");
        //sifre->setText("Şifre"+QString::number(qrnumber));

       passwd = new QLineEdit(this);
        QFont f2( "Arial", 42, QFont::Normal);
       passwd->setFont(f2);
          passwd->installEventFilter(this);
        passwd->setFixedSize(en*4,boy*2);
        passwd->move(screenSize.width()/2-passwd->width()/2,screenSize.height()/2);
        passwd->setEchoMode(QLineEdit::Password);
        /********************************************************/
        QPushButton *ayarButton= new QPushButton(this);
        ayarButton->setFixedSize(en, boy*2);
        ayarButton->setIconSize(QSize(en,boy*1.5));
       // ayarButton->setText("Yeniden Başlat");
        ayarButton->setStyleSheet("Text-align:left");
        ayarButton->setFlat(true);
         ayarButton->move(screenSize.width()-en*1.5,boy*2);
         ayarButton->setIcon(QIcon(":icons/settings.png"));
        connect(ayarButton, &QPushButton::clicked, [=]() {
             QMenu *ayarMenus=ayarMenu();
            ayarMenus->exec(mapToGlobal(ayarButton->pos()-QPoint(en,-en)));


});

/********************************************************/
        keybordButton= new QPushButton(this);
        keybordButton->setFixedSize(en, boy*2);
        keybordButton->setIconSize(QSize(en,boy*1.5));
       // keybordButton->setText("Klavye");
        keybordButton->setStyleSheet("Text-align:left");
        keybordButton->setFlat(true);
         keybordButton->move(passwd->pos()+QPoint(passwd->width(),0));
         keybordButton->setIcon(QIcon(":icons/klavye.png"));
         QMenu *kilitMenus=kilitMenu();

        connect(keybordButton, &QPushButton::clicked, [=]() {
       kilitMenus->exec(mapToGlobal(keybordButton->pos()));
       passwd->setFocus(); 
        });

           connect(passwd, SIGNAL(returnPressed()),enterButton,SIGNAL(clicked()));

                  /************************Eba QR Kod*******************************/
                   qrkodpngtimer = new QTimer(this);
                   connect(qrkodpngtimer, SIGNAL(timeout()), this, SLOT(qrkodPngSlot()));
             /*  wb1=new QWebEngineView(this);
               wb1->setZoomFactor(0.50);
               wb1->page()->load(QUrl("https://giris.eba.gov.tr/EBA_GIRIS/studentQrcode.jsp"));
               wb1->resize(boyut*2,boyut*2.5);

               wb1->move(screenSize.width()-boyut*2.5,screenSize.height()-boyut*3-50);
*/
/*QLabel *ust=new QLabel(this);
                //ust->setStyleSheet("QLabel {background-color:gray; color : black; }");
                ust->setStyleSheet("background:rgb(240,240,240);");
                ust->resize(boyut*2,50);
                ust->move(wb1->pos());
                 QLabel *yan=new QLabel(this);
                 yan->setStyleSheet("QLabel {background:rgb(240,240,240); color : black; }");
                yan->resize(25,boyut*2.5);
                yan->move(wb1->pos()+QPoint(wb1->width()-25,0));
*/
             ///  connect(wb1, &QWebEngineView::loadFinished, this, &MainWindow::onLoadFinished1);
            ///   connect(wb1, &QWebEngineView::urlChanged, this, &MainWindow::onUrlChanged1);

            /*  QObject::connect(we, &QWebEngineView::urlChanged, [=] (const QUrl& url) {
                   qDebug()<<"sayfa değişti"<<url.toString();
               QString nurl="https://ders.eba.gov.tr/ders/proxy/VCollabPlayer";
               QRegularExpression re(nurl);

               if(url.toString().contains(re))
               {
                   qDebug()<<"Eba sayfası açıldı";
                   exit(0);
               }

               });
*/
                   /******************************************************/
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if(object == passwd && event->type() == QEvent::MouseButtonPress) {
        QMenu *kilitMenus=kilitMenu();

      // connect(keybordButton, &QPushButton::clicked, [=]() {
      kilitMenus->exec(mapToGlobal(keybordButton->pos()));
    //  passwd->setFocus();

        return false; // lets the event continue to the edit
    }


    return false;
}
int MainWindow::getRand(int min, int max){
    unsigned int ms = static_cast<unsigned>(QDateTime::currentMSecsSinceEpoch());
    std::mt19937 gen(ms);
    std::uniform_int_distribution<> uid(min, max);
    return uid(gen);
}
void MainWindow::onUrlChanged1()
{
  qDebug()<<"Durum"<<"web browse1 Sayfa Açıldı";

  ///self.browser1.setUrl(QUrl('https://uygulama-ebaders.eba.gov.tr/ders/FrontEndService//home/user/getuserinfo'))
  /*wb2=new QWebEngineView(this);
  wb2->page()->load(QUrl("https://uygulama-ebaders.eba.gov.tr/ders/FrontEndService//home/user/getuserinfo"));
  wb2->resize(350,1050);

  connect(wb2, &QWebEngineView::loadFinished, this, &MainWindow::onLoadFinished2);
  connect(wb2, &QWebEngineView::urlChanged, this, &MainWindow::onUrlChanged2);
*/
}

void MainWindow::onUrlChanged2()
{
  qDebug()<<"Durum"<<"web browser2 Sayfa Açıldı";
}

MainWindow::~MainWindow()
{
    qDebug()<<"e-kilit Kapatıldı";
#ifdef WIN32
   // Windows code here
    qDebug()<<"windows..";
   // system("c:\\Windows\\explorer.exe");
   // system("sleep 2");
    QProcess *process = new QProcess(this);
    QString file = "c:\\Windows\\explorer.exe";
    process->startDetached(file);

   #else
   // UNIX code here
    //  delete ui;
    //top panel açılıyor
     qDebug()<<"linux..";
    /*system("gdbus call --session --dest org.gnome.Shell --object-path /org/gnome/Shell --method org.gnome.Shell.Eval string:'Main.panel.actor.show();'");
    system("sleep 0.5");

    //power button aktifleştriliyor
    system("gsettings set org.gnome.settings-daemon.plugins.power power-button-action interactive");
    system("sleep 0.5");

    //gesture açılıyor
    QStringList args3;
    QProcess p3;
    args3 << "-d" << "eta-disable-gestures@pardus.org.tr";
    p3.execute("gnome-shell-extension-tool", args3);
    system("sleep 0.5");

    QStringList args4;
    QProcess p4;
    args4 << "set" << "org.gnome.mutter" << "overlay-key" << "'SUPER_L'";
    p4.execute("gsettings", args4);
*/
   #endif


}

void MainWindow::qrkodPngSlot()
{
    qDebug()<<"foto-saved";
    /*int left, top, width, height;
        left =100;
        top = 170;
        width = 300;
        height = 300;

        QImage image(height, width, QImage::Format_RGB32);
        QRegion rg(left, top, width, height);
        QPainter painter(&image);
        we->page()->view()->render(&painter, QPoint(), rg);
        painter.end();
        image.save("test.png", "PNG", 80);
        qrkodpngtimer->stop();



       /* QPixmap bkgnd("test.png");
        bkgnd = bkgnd.scaled(200,200, Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);


        QWidget *qww=new QWidget(this);

        qww->resize(200,200);
        qww->setAutoFillBackground(true);
        //qww->setStyleSheet("{background-image: url(:/icons/lock.png);}");
        qww->setPalette(palette);
        qww->move(this->width()-250,50);
        qww->show();
      // we->hide();
      */
}
void MainWindow::onLoadFinished1()
{
    qDebug()<<"Durum"<<"web browser1 yüklendi";
    //system("sleep 2");
   // qrkodpngtimer->start(2000);

}
void MainWindow::onLoadFinished2()
{
  /*  wbLoadNumber++;
    if(wbLoadNumber>1)
    {
        //qDebug()<<"Durum"<<"web browser2 yüklendi";
        connect(this, SIGNAL(getHTML(QString)), this, SLOT(handleHTML(QString)));

        wb2->page()->toHtml([this](const QString& result) mutable {emit getHTML(result);});


    }
*/
}

void MainWindow::handleHTML(QString sHTML)
{
    QString ad="";
    QString soyad="";
    QString id="";
    QString rol="";

     /// qDebug()<< "The HTML is :" << sHTML;
    QStringList line=sHTML.split("{");

    for(int i=0;i<line.count();i++)
    {
        //qDebug()<<"Satır"<<i<<line[i];
        if(line[i].contains("userId", Qt::CaseInsensitive)==true)
        {
            QStringList linesplit=line[i].split(",");
            ///qDebug()<<"Satır***:"<<i<<line[i];
            for(int j=0;j<linesplit.count();j++)
            {
                if(linesplit[j].contains("userId", Qt::CaseInsensitive)==true)  id=linesplit[j];
                if(linesplit[j].contains("name", Qt::CaseInsensitive)==true)    ad=linesplit[j];
                if(linesplit[j].contains("surname", Qt::CaseInsensitive)==true) soyad=linesplit[j];
                if(linesplit[j].contains("role", Qt::CaseInsensitive)==true)    rol=linesplit[j];
            }
        }
    }

    if(rol=="\"role\":2")
    {
        qDebug()<<"Öğretmen!"<<id<<ad<<soyad<<rol;
         exit(0);

    }

}

void MainWindow::klavyeButtonClick(){

  /******************************************************/
  // system("qdbus org.eta.virtualkeyboard /VirtualKeyboard org.eta.virtualkeyboard.toggle");
 //system("killall eta-keyboard");
  //system("sleep 1");
  //system("eta-keyboard show");

// komut.append("sed -i 's/false/true/' ").append(stdout).append("/.config/eta/virtualkeyboard/config.ini");
// qDebug()<<komut;
 // arg << "-c" <<komut;
 //p1.start("/bin/bash",arg);
 //p1.waitForFinished(-1); // will wait forever until finished
  //system("sleep 1");


  //system("nohup eta-keyboard show &\n");
  //system("sleep 1");
  //p1.execute("eta-keyboard show");
 //
  // system("qdbus org.eta.virtualkeyboard /VirtualKeyboard org.eta.virtualkeyboard.toggleAutoShow");
   //system("qdbus org.eta.virtualkeyboard /VirtualKeyboard org.eta.virtualkeyboard.toggleAutoShow");
  // sleep(5);
  // system("qdbus org.eta.virtualkeyboard /VirtualKeyboard org.eta.virtualkeyboard.showFromBottom");
   //system("qdbus org.eta.virtualkeyboard /VirtualKeyboard org.eta.virtualkeyboard.toggle");
/******************************************************************/


}


void MainWindow::updateQrCode(QString text , int w, int h)
{ using namespace qrcodegen;
    // Create the QR Code object
    QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );
    qint32 sz = qr.getSize();
    QImage im(sz,sz, QImage::Format_RGB32);
      QRgb black = qRgb(  0,  0,  0);
      QRgb white = qRgb(255,255,255);
    for (int y = 0; y < sz; y++)
      for (int x = 0; x < sz; x++)
        im.setPixel(x,y,qr.getModule(x, y) ? black : white );
   // qDebug()<<w<<h;
    qw->setPixmap( QPixmap::fromImage(im.scaled(w,h,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );
   // qw->setPixmap( QPixmap::fromImage(im,Qt::MonoOnly) );

}


bool MainWindow::kontrol(QString _user,QString _password)
{
   // status=true;
    /********************password null text kontrol********************************/
     if(_password=="")
    {
          QString sonuc=myMessageBox("e-kilit", "\n"
                                                     "\nLütfen Şifre Giriniz..\n"
                                                       "\n","","","tamam",QMessageBox::Critical);

        //status=false;
        return false;
    }
    /*********************sudo yetki kontrol*************************/

     if(sudoYetkiKontolSlot(_user)=="0")
    { QString sonuc=myMessageBox("e-kilit", "\n"
                                            "\nLütfen Yetkili Bir Kullanıcı ile İşlem Yapınız...\n"
                                              "\n","","","tamam",QMessageBox::Critical);

         //status=false;
        return false;
    }

    /*************************şifre kontrol***********************/
  // passwordKontrolSlot(_user,_password);
   if(passwordKontrolSlot(_user,_password)=="0")
    {
       QString sonuc=myMessageBox("e-kilit", "\n"
                                           "\nLütfen Şifrenizi Doğru Giriniz..\n"
                                             "\n","","","tamam",QMessageBox::Critical);

       // status=false ;
        return false;
    }

return true;
}
QString MainWindow::sudoYetkiKontolSlot(QString _user)
{
     /*******************sudo yetki kontrol**************************/
    QStringList arguments1;
    arguments1 << "-c" << QString("id "+_user+"|grep 'sudo'");
    QProcess process1;
    process1.start("/bin/bash",arguments1);
    if(process1.waitForFinished())
    {
     QString sudoyetki = process1.readAll();
        if (sudoyetki=="") return "0";else return "1";
        //   result.chop(3);
    }
    return "0";
}
QString MainWindow::passwordKontrolSlot(QString _user,QString _password)
{
    /***************password kontrol***************************/

QStringList liste;
liste<<"#!/usr/bin/expect";
liste<<"spawn su - "+_user;
liste<<"expect \"Parola:\"";
liste<<"send \""+_password+"\\n\"";
liste<<"send \"echo "+_password+"|sudo -S touch /tmp/e-kilityetki\\n\"";
liste<<"send \"echo "+_password+"|sudo -S chmod 777 /tmp/e-kilityetki\\n\"";
liste<<"send \"echo "+_password+"|sudo -S chown "+_user+" /tmp/e-kilityetki\\n\"";
liste<<"send \"exit\\n\"";
liste<<"interact";
listToFile("/tmp/",liste,"runkilit.sh");
QString kmt19="chmod 777 /tmp/runkilit.sh";
system(kmt19.toStdString().c_str());
QString result="";
QStringList arguments;
        arguments << "-c" << QString("/tmp/runkilit.sh");
        QProcess process;
        process.start("/bin/bash",arguments);
         if(process.waitForFinished())
{
   // version = process.readAll();
   //   result.chop(3);
}
QString passwordstatus="0";
         QString kmt21="rm -rf /tmp/runkilit.sh";
         system(kmt21.toStdString().c_str());
         if(QFile::exists("/tmp/e-kilityetki")==true)
                 {
                 passwordstatus="1";
                  ///qDebug()<<"Şifre: doğru "<<passwordstatus;

                 }else
                 {
                     passwordstatus="0";
                    /// qDebug()<<"Şifre: yanlış "<<passwordstatus;
                 }


         QString kmt22="rm -rf /tmp/e-kilityetki";
         system(kmt22.toStdString().c_str());
       //  qDebug()<<"Şifre:"<<passwordstatus;
         return passwordstatus;

}
QString MainWindow::myMessageBox(QString baslik, QString mesaj, QString evet, QString hayir, QString tamam, QMessageBox::Icon icon)
{
    Qt::WindowFlags flags = 0;
    flags |= Qt::Dialog;
    flags |= Qt::X11BypassWindowManagerHint;

    QMessageBox messageBox(this);
    messageBox.setStyleSheet("QMessageBox {background-color: rgb(255, 255, 255);"
        "border: 1px solid black;border-radius:6px;}");

    messageBox.setWindowFlags(flags);
    messageBox.setText(baslik+"\t\t\t");
    messageBox.setInformativeText(mesaj);
    QAbstractButton *evetButton;
    QAbstractButton *hayirButton;
    QAbstractButton *tamamButton;

    if(evet=="evet") evetButton =messageBox.addButton(tr("Evet"), QMessageBox::ActionRole);
    if(hayir=="hayir") hayirButton =messageBox.addButton(tr("Hayır"), QMessageBox::ActionRole);
    if(tamam=="tamam") tamamButton =messageBox.addButton(tr("Tamam"), QMessageBox::ActionRole);

    messageBox.setIcon(icon);


    messageBox.exec();
    if(messageBox.clickedButton()==evetButton) return "evet";
    if(messageBox.clickedButton()==hayirButton) return "hayır";
    if(messageBox.clickedButton()==tamamButton) return "tamam";
    return "";
}

QStringList MainWindow::listRemove(QStringList list,QString data)
 {
       QRegularExpression re(data);
     for(int i=0;i<list.count();i++)if(list[i].contains(re)) list.removeAt(i);
    // qDebug()<<list;
     return list;
 }
QString MainWindow::listGetLine(QStringList list,QString data)
{
    QRegularExpression re(data);
   for(int i=0;i<list.count();i++) if(list[i].contains(re)) return list[i];
   //qDebug()<<list;
   return "";
}
QStringList MainWindow::fileToList(QString path, QString filename)
{
  FileCrud *fcc=new FileCrud();
  fcc->dosya=path+filename;
 // qDebug()<<fcc->dosya;
  QStringList list;
  for(int i=1;i<=fcc->fileCount();i++)
  {
       QString line=fcc->fileGetLine(i);
      // qDebug()<<line;
       if(line!="")
       {
           line.chop(1);
           QStringList lst=line.split("|");
           QString ln="";
           if(lst.count()>0)ln.append(lst[0]);
           if(lst.count()>1)ln.append("|").append(lst[1]);
           if(lst.count()>2)ln.append("|").append(lst[2]);
           if(lst.count()>3)ln.append("|").append(lst[3]);
           if(lst.count()>4)ln.append("|").append(lst[4]);
           if(lst.count()>5)ln.append("|").append(lst[5]);
           if(lst.count()>6)ln.append("|").append(lst[6]);
           if(lst.count()>7)ln.append("|").append(lst[7]);
           if(lst.count()>8)ln.append("|").append(lst[8]);
           if(lst.count()>9)ln.append("|").append(lst[9]);
           if(lst.count()>10)ln.append("|").append(lst[10]);
           if(lst.count()>11)ln.append("|").append(lst[11]);
           if(lst.count()>12)ln.append("|").append(lst[12]);
           if(lst.count()>13)ln.append("|").append(lst[13]);

             list <<ln;
           //qDebug()<<ln;
           // list <<lst[0]+"|"+lst[1]+"|"+lst[2]+"|"+lst[3]+"|"+lst[4]+"|"+lst[5];

       }
  }
     return list;
}
void MainWindow::listToFile(QString path,QStringList list, QString filename)
{
  FileCrud *fcc=new FileCrud();
  fcc->dosya=path+filename;
  fcc->fileRemove();
  for(int i=0;i<list.count();i++)
  {
       QString line=list[i];
       if(line!="")
       {
           //line.chop(1);
           QStringList lst=line.split("|");
           //qDebug()<<line;
           QString ln="";
           if(lst.count()>0)ln.append(lst[0]);
           if(lst.count()>1)ln.append("|").append(lst[1]);
           if(lst.count()>2)ln.append("|").append(lst[2]);
           if(lst.count()>3)ln.append("|").append(lst[3]);
           if(lst.count()>4)ln.append("|").append(lst[4]);
           if(lst.count()>5)ln.append("|").append(lst[5]);
           if(lst.count()>6)ln.append("|").append(lst[6]);
           if(lst.count()>7)ln.append("|").append(lst[7]);
           if(lst.count()>8)ln.append("|").append(lst[8]);
           if(lst.count()>9)ln.append("|").append(lst[9]);
           if(lst.count()>10)ln.append("|").append(lst[10]);
           if(lst.count()>11)ln.append("|").append(lst[11]);
           if(lst.count()>12)ln.append("|").append(lst[12]);
           if(lst.count()>13)ln.append("|").append(lst[13]);

           //qDebug()<<ln;
           fcc->fileWrite(ln);

       }

  }
}

