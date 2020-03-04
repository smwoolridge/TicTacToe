#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


     bool checkForWinner(int buttonClicked[], int player);

private slots:
     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_9_clicked();

     void on_pushButton_3_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_8_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    int clickCount = 0;
    int buttonClicked [9] = {0,0,0,0,0,0,0,0,0};
    int checkPlayer;
    int playerTurn (int index);

    int winCombinations[8][3] = {{0,3,6}, {0,1,2}, {2,5,8}, {6,7,8}, {0,4,8},{2,4,6},{3,4,5}, {1,4,7}};

};









#endif // MAINWINDOW_H
