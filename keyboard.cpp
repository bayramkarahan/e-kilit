#include "keyboard.h"
#include <QDebug>
#include<QPushButton>
#include<QVBoxLayout>


Keyboard::Keyboard(QWidget *parent) :
    QWidget(parent),
    data("Hello QR")//Note: The encoding fails with empty string so I just default to something else. Use the setQRData() call to change this.
{
    QPushButton *loginButton= new QPushButton(this);
    loginButton->setFixedSize(80, 30);
    loginButton->setIconSize(QSize(60,30));
    loginButton->setText("Kilit Aç");
    loginButton->setStyleSheet("Text-align:left");
    loginButton->setFlat(true);
   // loginButton->move(screenSize.width()/2-40,screenSize.height()/2-30);
    // loginButton->setIcon(QIcon(":icons/saveprofile.png"));
    //connect(passwd, SIGNAL(returnPressed()),loginButton,SIGNAL(clicked()));

    connect(loginButton, &QPushButton::clicked, [=]() {

});


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(loginButton);
    //layout->addWidget(textEdit);
    //layout->addWidget(closeButton);
     //layout->addWidget(qe1);
    setLayout(layout);


}

/*void Keyboard::setQRData(QString data){
    this->data=data;
    update();
}

*/
