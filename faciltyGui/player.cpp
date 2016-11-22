#include "player.h"
#include <QDebug>
Player::Player(QObject *parent): QThread(parent)
{
    //speak.setSpeed(1);

    init = 0;



}

/*Player::Player(QMutex *mutex, QWaitCondition *condition, FacilitOffice doc, Speak speak, QObject *parent): QThread(parent)
{
    this->mutex = mutex;
    this->condition = condition;
    this->doc = doc;
    this->speak = speak;
}*/

void Player::run()
{
    Speak speak;
    if(!init)
    {
       // speak.init();
        init = 1;
    }
    while(1)
    {
        //doc.moveNext();
      // qDebug() << "TEXT " << doc.getSelectedText().c_str() << endl;


       speak.sayText("Ciao puorco");


    }
    /*else
    {
        speak.sayText("Hai raggiunto la fine del file");
        QMessageBox::warning(this, "Letto tutto", "Hai raggiunto la fine del file", "Ok");
    }*/
}

void Player::setMutex(QMutex *mutex)
{
    this->mutex = mutex;
}

void Player::setCondition(QWaitCondition *condition)
{
    this->condition = condition;
}


void Player::setSpeak(Speak speak)
{
  //  this->speak = speak;
}

void Player::ok()
{
    start();
}
