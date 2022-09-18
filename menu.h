#ifndef MENU_H
#define MENU_H

#include<QWidgetAction>
#include<QGridLayout>
#include<QtMath>
#include<QProcess>


QMenu *MainWindow::girisMenu()
{
    QMenu *girisPage=new QMenu();
    /*******************************************************/
    QLabel *localuserLabel=new QLabel(girisPage);
    localuserLabel->setText("Kullanıcı Adı");
    localuserLabel->setFixedSize(boy*4,boy);
    // localuserLabel->setStyleSheet("background-color: #acacac");

    //user=QDir::homePath().split("/")[2];
    QComboBox* localUsername=new QComboBox(girisPage);
    localUsername->setFixedSize(boy*4,boy);
    //localUsername->setText(user);
    localUsername->setStyleSheet("background-color: #ffffff");
    system("ls /home >/tmp/users");
    QStringList userlst=fileToList("/tmp/","users");
    localUsername->addItems(userlst);

    QLabel *localpasswordLabel=new QLabel(girisPage);
    localpasswordLabel->setText("Kullanıcı Parolası");
    localpasswordLabel->setFixedSize(boy*4,boy);
    // localpasswordLabel->setStyleSheet("background-color: #acacac");

    QLineEdit* localPassword=new QLineEdit(girisPage);
    localPassword->setFixedSize(boy*4,boy);
    localPassword->setEchoMode(QLineEdit::Password);
    // localPassword->setStyleSheet("background-color: #ffffff");

    /* auto  screenbtn = new QPushButton(girisPage);
        screenbtn->setFixedSize(QSize(boy*3,boy*3));
        screenbtn->setIconSize(QSize(boy*3,boy*3));
        screenbtn->setAutoFillBackground(true);
        screenbtn->setIcon(QIcon(":/icons/e-ag-x11client.svg"));
        screenbtn->setFlat(true);
    */
        QPushButton *girisButton= new QPushButton;
    girisButton->setFixedSize(boy*8+10, boy);
    ///ayarKaydetButton->setIconSize(QSize(150,30));
    girisButton->setText("Giriş");
    girisButton->setStyleSheet("Text-align:center");

    connect(girisButton, &QPushButton::clicked, [=]() {
       if (kontrol(localUsername->currentText(),localPassword->text())==false) return;
        // qDebug()<<"Giriş Başarılı";
       //exit(0); ////~MainWindow(); close fonksiyonunu çağırmıyor
        close(); //~MainWindow(); close fonksiyonunu çağırıyor
    });

         auto layout = new QGridLayout(girisPage);
         layout->setContentsMargins(5, 5, 5,5);

       layout->setVerticalSpacing(5);
        //layout->setColumnMinimumWidth(0, 37);
        layout->addWidget(new QLabel("<font size=3>e-kilit Yönetici Giriş Penceresi</font>"),0,0,1,2,Qt::AlignHCenter);
     ///   layout->addWidget(screenbtn, 5,0,1,2,Qt::AlignHCenter);
        layout->addWidget(localuserLabel, 7,0,1,1);
        layout->addWidget(localUsername, 7,1,1,1);
        layout->addWidget(localpasswordLabel, 8,0,1,1);
        layout->addWidget(localPassword, 8,1,1,1);
        layout->addWidget(girisButton,9,0,1,2);

        return girisPage;

}
QMenu *MainWindow::ayarMenu()
{
     QMenu *menu = new QMenu(this);
    int e=32;
      int b=30;
QSize screenSize = qApp->screens()[0]->size();


QPushButton *refreshButton= new QPushButton(this);
refreshButton->setFixedSize(e*5, b);
refreshButton->setIconSize(QSize(e*4,b));
refreshButton->setText("Eba QR Kod Yenile");
refreshButton->setStyleSheet("Text-align:left");
refreshButton->setFlat(true);
// restartButton->move(screenSize.width()/2+40,100-0);
 refreshButton->setIcon(QIcon(":icons/ebaqrcode.png"));
connect(refreshButton, &QPushButton::clicked, [=]() {
    //wb1->page()->load(QUrl("https://giris.eba.gov.tr/EBA_GIRIS/studentQrcode.jsp"));
  //  exit(0);
   // close();
});

QPushButton *qrButton= new QPushButton(this);
qrButton->setFixedSize(e*5, b);
qrButton->setIconSize(QSize(e*4,b));
qrButton->setText("QR Kod Girişi");
qrButton->setStyleSheet("Text-align:left");
qrButton->setFlat(true);
// restartButton->move(screenSize.width()/2+40,100-0);
 qrButton->setIcon(QIcon(":icons/qrcode.png"));
connect(qrButton, &QPushButton::clicked, [=]() {
qw->show();
///close();
});

      QPushButton *restartButton= new QPushButton(this);
      restartButton->setFixedSize(e*5, b);
      restartButton->setIconSize(QSize(e*4,b));
      restartButton->setText("Yeniden Başlat");
      restartButton->setStyleSheet("Text-align:left");
      restartButton->setFlat(true);
      // restartButton->move(screenSize.width()/2+40,100-0);
       restartButton->setIcon(QIcon(":icons/redo.png"));
      connect(restartButton, &QPushButton::clicked, [=]() {
           //QMenu *ayarMenus=ayarMenu();
          //kilitMenus->exec(mapToGlobal(ayarButton->pos()-QPoint(-60,30)));
        system("systemctl reboot");

});

      QPushButton *poweroffButton= new QPushButton(this);
      poweroffButton->setFixedSize(e*5, b);
      poweroffButton->setIconSize(QSize(e*4,b));
     poweroffButton->setText("Kapat");
      poweroffButton->setStyleSheet("Text-align:left");
      poweroffButton->setFlat(true);
       //poweroffButton->move(screenSize.width()/2+40,screenSize.height()/2-60);
       poweroffButton->setIcon(QIcon(":icons/close.png"));
      connect(poweroffButton, &QPushButton::clicked, [=]() {
          // QMenu *ayarMenus=ayarMenu();
          //kilitMenus->exec(mapToGlobal(ayarButton->pos()-QPoint(-60,30)));
        system("systemctl poweroff");

});

      QPushButton *infoButton= new QPushButton(this);
      infoButton->setFixedSize(e*5, b);
      infoButton->setIconSize(QSize(e*4,b));
     infoButton->setText("Bilgi");
      infoButton->setStyleSheet("Text-align:left");
      infoButton->setFlat(true);
     //  infoButton->move(screenSize.width()/2+40,screenSize.height()/2-60);
       infoButton->setIcon(QIcon(":icons/about.png"));
      connect(infoButton, &QPushButton::clicked, [=]() {        
          QSize screenSize = qApp->screens()[0]->size();
          QMenu *hakkindaMenus=hakkindaMenu();
           hakkindaMenus->show();
            hakkindaMenus->hide();
         hakkindaMenus->exec(mapToGlobal(QPoint(qFabs(screenSize.width()/2)-hakkindaMenus->width()/2,qFabs(screenSize.height()/2)-hakkindaMenus->height()/2)));
});

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
    layout->setContentsMargins(5, 5, 5,5);
   // layout->setVerticalSpacing(0);
  //  layout->setColumnMinimumWidth(0, 37);

   //  layout->addWidget(kalemKapatButton, 7,1,1,1);
    layout->addWidget(refreshButton, 1,1,1,1,Qt::AlignCenter);
    layout->addWidget(qrButton, 2,1,1,1,Qt::AlignCenter);
    layout->addWidget(infoButton, 3, 1,1,1,Qt::AlignCenter);
    layout->addWidget(restartButton, 4,1,1,1,Qt::AlignCenter);
    layout->addWidget(poweroffButton, 5, 1,1,1,Qt::AlignCenter);

   // layout->addWidget(new QLabel("<font size=2>Yeniden Başlat</font>"),2,2,1,1,Qt::AlignLeft);
   // layout->addWidget(new QLabel("<font size=2>Kapat</font>"),4,2,1,1,Qt::AlignLeft);
    //layout->addWidget(new QLabel("<font size=2>Bilgi</font>"),6,2,1,1,Qt::AlignLeft);


  //  layout->setColumnStretch(6, 255);

    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

   //  menu->setStyleSheet("QMenu { width: auto; height: auto; }");
   return menu;
}

QMenu *MainWindow::hakkindaMenu()
{   QMenu *menu = new QMenu(this);
    int e=32;
      int b=30;
QSize screenSize = qApp->screens()[0]->size();




      auto *bilgi=new QLabel();
      bilgi->setText( "\n"
                      "Tahtaların QR Kod ile güvenli bir şekilde kullanmak için yazılmış uygulamadır.."
                      "\nBu uygulamayı kullanmaktan doğabilecek her türlü hukuki sorumluluğu kullanıcı kabul etmiş sayılır."
                      "\n");
      auto *caption=new QLabel();
      caption->setText( "<b>e-kilit 4.8.1</b>");
      auto *email=new QLabel();
      email->setText("İstek ve önerileriniz için;"
                      "\nE-Posta: bayramk@gmail.com"
                      "\nbayramkarahan.blogspot.com"
                      "\n");



    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
    layout->setContentsMargins(5, 5, 5,5);
   // layout->setVerticalSpacing(0);
  //  layout->setColumnMinimumWidth(0, 37);
    layout->addWidget(caption, 1, 1,1,1,Qt::AlignCenter);
    layout->addWidget(bilgi, 2, 1,1,1,Qt::AlignCenter);
    layout->addWidget(email,3, 1,1,1,Qt::AlignCenter);

    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
  //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

   //  menu->setStyleSheet("QMenu { width: auto; height: auto; }");
   return menu;
}

QMenu *MainWindow::kilitMenu()
{   QMenu *menu = new QMenu(this);

    QPushButton *birButton= new QPushButton;
    birButton->setFixedSize(en, boy);
    birButton->setIconSize(QSize(en,boy));
    birButton->setText("1");
    birButton->setStyleSheet("Text-align:center");
    //birButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(birButton, &QPushButton::clicked, [=]() {

    passwd->setText(passwd->text()+"1");

    });

    QPushButton *ikiButton= new QPushButton;
    ikiButton->setFixedSize(en, boy);
    ikiButton->setIconSize(QSize(en,boy));
    ikiButton->setText("2");
    ikiButton->setStyleSheet("Text-align:center");
   // ikiButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(ikiButton, &QPushButton::clicked, [=]() {
        passwd->setText(passwd->text()+"2");


    });


    QPushButton *ucButton= new QPushButton;
    ucButton->setFixedSize(en, boy);
    ucButton->setIconSize(QSize(en,boy));
    ucButton->setText("3");
    ucButton->setStyleSheet("Text-align:center");
   // ucButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(ucButton, &QPushButton::clicked, [=]() {
        passwd->setText(passwd->text()+"3");

        // menu->close();

    });
    /***************************4***************/
    QPushButton *dortButton= new QPushButton;
    dortButton->setFixedSize(en, boy);
    dortButton->setIconSize(QSize(en,boy));
    dortButton->setText("4");
    dortButton->setStyleSheet("Text-align:center");
   // dortButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(dortButton, &QPushButton::clicked, [=]() {
        passwd->setText(passwd->text()+"4");


    });

    /***************************5***************/
    QPushButton *besButton= new QPushButton;
    besButton->setFixedSize(en, boy);
    besButton->setIconSize(QSize(en,boy));
    besButton->setText("5");
    besButton->setStyleSheet("Text-align:center");
    //besButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(besButton, &QPushButton::clicked, [=]() {
        passwd->setText(passwd->text()+"5");


    });

    /***************************6***************/
    QPushButton *altiButton= new QPushButton;
    altiButton->setFixedSize(en, boy);
    altiButton->setIconSize(QSize(en,boy));
    altiButton->setText("6");
    altiButton->setStyleSheet("Text-align:center");
   // altiButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(altiButton, &QPushButton::clicked, [=]() {
        passwd->setText(passwd->text()+"6");


    });

    /***************************7***************/
    QPushButton *yediButton= new QPushButton;
    yediButton->setFixedSize(en, boy);
    yediButton->setIconSize(QSize(en,boy));
    yediButton->setText("7");
    yediButton->setStyleSheet("Text-align:center");
    //yediButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(yediButton, &QPushButton::clicked, [=]() {
        passwd->setText(passwd->text()+"7");


    });

    /***************************8***************/
    QPushButton *sekizButton= new QPushButton;
    sekizButton->setFixedSize(en, boy);
    sekizButton->setIconSize(QSize(en,boy));
    sekizButton->setText("8");
    sekizButton->setStyleSheet("Text-align:center");
    //sekizButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(sekizButton, &QPushButton::clicked, [=]() {

        passwd->setText(passwd->text()+"8");

    });

    /***************************9***************/
    QPushButton *dokuzButton= new QPushButton;
    dokuzButton->setFixedSize(en, boy);
    dokuzButton->setIconSize(QSize(en,boy));
    dokuzButton->setText("9");
    dokuzButton->setStyleSheet("Text-align:center");
   // dokuzButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(dokuzButton, &QPushButton::clicked, [=]() {
        passwd->setText(passwd->text()+"9");


    });

    /***************************0***************/
    QPushButton *sifirButton= new QPushButton;
    sifirButton->setFixedSize(en, boy);
    sifirButton->setIconSize(QSize(en,boy));
    sifirButton->setText("0");
    sifirButton->setStyleSheet("Text-align:center");
    //sifirButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(sifirButton, &QPushButton::clicked, [=]() {

        passwd->setText(passwd->text()+"0");

    });

    /***************************backspace***************/
    QPushButton *geriSilButton= new QPushButton;
    geriSilButton->setFixedSize(en, boy);
    geriSilButton->setIconSize(QSize(en,boy));
    geriSilButton->setText("<-");
    geriSilButton->setStyleSheet("Text-align:center");
    //geriSilButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(geriSilButton, &QPushButton::clicked, [=]() {
        QString str=passwd->text();
        str.chop(1);

        passwd->setText(str);


    });

    /***************************Enter***************/
    enterButton= new QPushButton;
    enterButton->setFixedSize(en, boy);
    enterButton->setIconSize(QSize(en,boy));
    enterButton->setText("Giriş");
    enterButton->setStyleSheet("Text-align:center");
   // enterButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(enterButton, &QPushButton::clicked, [=]() {

        if(passwd->text()==QString::number(qrnumber))
        {
         // close();
         QCoreApplication::quit();
        }else
        {
             passwd->setText("");
            QFont f1( "Arial", 12, QFont::Normal);
            sifre->setFont(f1);
            sifre->setStyleSheet("QLabel { color : red; }");

            sifre->setText("Şifre Yanlış");
        }

    });


    /***************************Enter***************/
    QPushButton *rootButton= new QPushButton;
    rootButton->setFixedSize(en*3+12, boy);
    rootButton->setIconSize(QSize(en,boy));
    rootButton->setText("Yetkili Kullanıcı İle Giriş");
    rootButton->setStyleSheet("Text-align:center");
   // enterButton->setFlat(true);
    // kilitButton->setIcon(QIcon(":icons/saveprofile.png"));

    connect(rootButton, &QPushButton::clicked, [=]() {
menu->close();
        QSize screenSize = qApp->screens()[0]->size();
        QMenu *girisMenus=girisMenu();
         girisMenus->show();
          girisMenus->hide();
       girisMenus->exec(mapToGlobal(QPoint(qFabs(screenSize.width()/2)-girisMenus->width()/2,qFabs(screenSize.height()/2)-girisMenus->height()/2)));

    });

    auto widget = new QWidget;
    auto layout = new QGridLayout(widget);
    layout->setContentsMargins(5, 5, 5,5);
   // layout->setVerticalSpacing(0);
     // layout->setColumnMinimumWidth(0, 10);
    layout->addWidget(birButton, 1,1,1,1);
    layout->addWidget(ikiButton, 1,2,1,1);
    layout->addWidget(ucButton, 1,3,1,1);
    layout->addWidget(dortButton, 2,1,1,1);
    layout->addWidget(besButton, 2,2,1,1);
    layout->addWidget(altiButton, 2,3,1,1);
    layout->addWidget(yediButton, 3,1,1,1);
    layout->addWidget(sekizButton, 3,2,1,1);
    layout->addWidget(dokuzButton, 3,3,1,1);
    layout->addWidget(sifirButton, 4,1,1,1);
    layout->addWidget(geriSilButton, 4,2,1,1);
    layout->addWidget(enterButton, 4,3,1,1);
  ///  layout->addWidget(rootButton, 5,1,1,3);

    // layout->addWidget(new QLabel("<font size=1>Ayarları Kaydet</font>"),6,1,1,1,Qt::AlignHCenter);
    // layout->setColumnStretch(6, 255);

    // add a widget action to the context menu
    auto wa = new QWidgetAction(this);
    //  wa->setIcon(QIcon(":/icon1"));
    wa->setDefaultWidget(widget);
    menu->addAction(wa);

   // menu->setStyleSheet("QMenu { width: 262 px; height: 335 px; }");
    return menu;
}

#endif // MENU_H
