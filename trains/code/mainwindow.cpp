#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,270,30);
    trem2 = new Trem(2,540,30);
    trem3 = new Trem(3,144,150);
    trem4 = new Trem(4,415,150);
    trem5 = new Trem(5,685,150);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();

}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    trem1->terminate();
    trem2->terminate();
    trem3->terminate();
    trem4->terminate();
    trem5->terminate();
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */
//void MainWindow::on_pushButton_clicked()
//{
//    trem1->start();
//    trem2->start();
//    trem3->start();
//    trem4->start();
//    trem5->start();
//}

/*
 * Ao clicar, trens param execução
 */
//void MainWindow::on_pushButton_2_clicked()
//{
//    trem1->terminate();
//    trem2->terminate();
//    trem3->terminate();
//    trem4->terminate();
//    trem5->terminate();
//}

/*
 * Ao arrastar, trens mudam a velocidade
 */
void MainWindow::on_horizontalSlider_trem1_sliderReleased()
{
    trem1->changeSpeed(200 - ui->horizontalSlider_trem1->value());
}

void MainWindow::on_horizontalSlider_trem2_sliderReleased()
{
    trem2->changeSpeed(200 - ui->horizontalSlider_trem2->value());
}

void MainWindow::on_horizontalSlider_trem3_sliderReleased()
{
    trem3->changeSpeed(200 - ui->horizontalSlider_trem3->value());
}

void MainWindow::on_horizontalSlider_trem4_sliderReleased()
{
    trem4->changeSpeed(200 - ui->horizontalSlider_trem4->value());
}

void MainWindow::on_horizontalSlider_trem5_sliderReleased()
{
    trem5->changeSpeed(200 - ui->horizontalSlider_trem5->value());
}
