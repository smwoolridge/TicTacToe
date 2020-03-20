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



     void on_onePlayerButton_clicked();

     void on_twoPlayerButton_clicked();

     void on_easyButton_clicked();

     void on_mediumButton_clicked();

     void on_hardButton_clicked();

     void on_startButton_clicked();

     void on_l1_00_clicked();

     void on_l1_10_clicked();

     void on_l1_20_clicked();

     void on_l1_01_clicked();

     void on_l1_11_clicked();

     void on_l1_21_clicked();

     void on_l1_02_clicked();

     void on_l1_12_clicked();

     void on_l1_22_clicked();

private:
    Ui::MainWindow *ui;
    int clickCount = 0;
    int buttonClicked [9] = {0,0,0,0,0,0,0,0,0};
    int checkPlayer;
    int playerTurn (int index);

    int winCombinations[8][3] = {{0,3,6}, {0,1,2}, {2,5,8}, {6,7,8}, {0,4,8},{2,4,6},{3,4,5}, {1,4,7}};
    void gameReset();
    bool gameIsDone = false;
    int easyLevelAi();
    void mediumLevelAi();
    void hardLevelAi();

};









#endif // MAINWINDOW_H
