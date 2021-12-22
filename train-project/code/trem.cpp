#include "trem.h"
#include <QtCore>
#include <QMutex>
#include <QSemaphore>

#define N 5 //trens
#define WAITING 0
#define MOVE 1

QMutex R0;
QMutex R1;
QMutex R2;
QMutex R3;
QMutex R4;
QMutex R5;
QMutex R6;

QSemaphore D0; //T1 - T3 - T4
QSemaphore D1; //T1 - T2 - T4
QSemaphore D2; //T2 - T4 - T5


//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade = 100;
}

void Trem::changeSpeed(int value){
    velocidade = value;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if(velocidade!=200){
                if (y == 30 && x<540){
                   if(x==520){
                      //qDebug("T1 ACQUIRE D1");
                      D1.acquire();
                      //qDebug("T1 LOCK R0");
                      R0.lock();
                   }
                   x+=10;
                }
                else if (x == 540 && y < 150){
                    if(y==130){
                      //qDebug("T1 ACQUIRE D0");
                      //D0.acquire();
                      //qDebug("T1 LOCK R2");
                      R2.lock();
                    }
                    y+=10;
                }
                else if (x > 270 && y == 150){
                    if(x==520){
                      R0.unlock();
                    }
                    if(x==390){
                      //qDebug("T1 UNLOCK R2");
                      R2.unlock();
                      //qDebug("T1 RELEASE D1");
                      D1.release();
                    }
                    if(x==440){
                      //qDebug("T1 LOCK R1");
                      R1.lock();
                    }
                    x-=10;
                }
                else{
                    if(y==130){
                      //qDebug("T1 UNLOCK R1");
                      R1.unlock();
                      //qDebug("T1 RELEASE D0");
                      //D0.release();
                    }
                    y-=10;
                }
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 2: //Trem 2
            if(velocidade!=200){
                if (y == 30 && x <810){
                    if(x==560){
                        //qDebug("T2 UNLOCK R0");
                        R0.unlock();
                        //qDebug("T2 RELEASE D1");
                        D1.release();
                    }
                x+=10;
              }
            else if (x == 810 && y < 150){
                if(y==130){
                  //qDebug("T2 ACQUIRE D2");
                  D2.acquire();
                  //qDebug("T2 LOCK R4");
                  R4.lock();
                }
                y+=10;
            }
            else if (x > 540 && y == 150){
                if(x==560){
                    //qDebug("T2 LOCK R0");
                    R0.lock();
                }
                if(x==710){
                    //qDebug("T2 ACQUIRE D1");
                    D1.acquire();
                    //qDebug("T2 LOCK R3");
                    R3.lock();
                }
                if(x==660){
                    //qDebug("T2 UNLOCK R4");
                    R4.unlock();
                }
                x-=10;
            }
            else{
                if(y==130){
                    //qDebug("T2 UNLOCK R3");
                    R3.unlock();
                    //qDebug("T2 RELEASE D2");
                    D2.release();
                }
                y-=10;
            }
           }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if(velocidade!=200){
                if (y == 150 && x < 414){
                    if(x==244){
                      //qDebug("T3 ACQUIRE D0");
                      D0.acquire();
                      //qDebug("T3 LOCK R1");
                      R1.lock();
                    }
                    if(x==394){
                      //qDebug("T3 LOCK R5");
                      R5.lock();
                    }
                    x+=10;
                }
                else if (x == 414 && y < 270){
                    if(y==170){
                      //qDebug("T3 UNLOCK R1");
                      R1.unlock();
                    }
                    y+=10;
                }
                else if (x > 144 && y == 270){
                    if(x==394){
                      //qDebug("T3 UNLOCK R5");
                      R5.unlock();
                      //qDebug("T3 RELEASE D0");
                      D0.release();
                    }
                    x-=10;
                }
                else
                    y-=10;
                }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 4: //Trem 4
            if(velocidade!=200){
            if (y == 150 && x <685){
                if(x==565){
                   //qDebug("T4 UNLOCK R2");
                   R2.unlock();
                   //qDebug("T4 RELEASE D0");
                   //D0.release();
                }
                if(x==515){
                  //qDebug("T4 ACQUIRE D2");
                  //D2.acquire();
                  //qDebug("T4 LOCK R3");
                  R3.lock();
                }
                if(x==445){
                  //qDebug("T4 UNLOCK R5");
                  R5.unlock();
                  //qDebug("T4 RELEASE D0");
                  D0.release();
                }
                if(x==665){
                  //qDebug("T4 LOCK R6");
                  R6.lock();
                }
                x+=10;
            }
            else if (x == 685 && y < 270){
                if(y==170){
                   //qDebug("T4 UNLOCK R3");
                   R3.unlock();
                   //qDebug("T4 RELEASE D1");
                   D1.release();
                }
                y+=10;
            }
            else if (x > 415 && y == 270){
                if(x==445){
                  //qDebug("T4 ACQUIRE D0");
                  D0.acquire();
                  //qDebug("T4 LOCK R5");
                  R5.lock();
                }
                if(x==665){
                  //qDebug("T4 UNLOCK R6");
                  R6.unlock();
                  //qDebug("T4 RELEASE D2");
                  //D2.release();
                }
                x-=10;
            }
            else{
                if(y==170){
                  //qDebug("T4 ACQUIRE D1");
                  D1.acquire();
                  //qDebug("T4 LOCK R2");
                  R2.lock();
                }
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            }
            break;
        case 5: //Trem 5
            if(velocidade!=200){
            if (y == 150 && x <955){
                if(x==835){
                  //qDebug("T5 UNLOCK R4");
                  R4.unlock();
                  //qDebug("T5 RELEASE D2");
                  D2.release();
                }
                if(x==705){
                  //qDebug("T5 UNLOCK R6");
                  R6.unlock();
                }
                x+=10;
            }
            else if (x == 955 && y < 270)
                y+=10;
            else if (x > 685 && y == 270){
                if(x==705){
                  //qDebug("T5 ACQUIRE D2");
                  D2.acquire();
                  //qDebug("T5 LOCK R6");
                  R6.lock();
                }
                x-=10;
            }
            else{
                if(y==170){
                  //qDebug("T5 LOCK R4");
                  R4.lock();
                }
                y-=10;
            }
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}




