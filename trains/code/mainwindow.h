#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_trem1_sliderReleased();

    void on_horizontalSlider_trem2_sliderReleased();

    void on_horizontalSlider_trem3_sliderReleased();

    void on_horizontalSlider_trem4_sliderReleased();

    void on_horizontalSlider_trem5_sliderReleased();

private:
    Ui::MainWindow *ui;

    //Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
};
#endif // MAINWINDOW_H
