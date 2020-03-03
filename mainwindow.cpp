#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkForWinner(int buttonClicked[], int player)
{
    bool winning = true;
    for(int i = 0; i < 8; i++){
        for(int j = 0; i < 3; j++){
            if(buttonClicked[winCombinations[i][j]] != player){
                winning = false;
                break;
            }
        }
        if(winning){
            // set winning player name
            return true;
        }
        winning = true;
    }
    return false;
}

int MainWindow::playerTurn(int index)
{
    // check array index
    if(buttonClicked[index] == 0){
        clickCount++;
        checkPlayer = clickCount % 2;
        switch(checkPlayer){
        case 1:
            // switch label to player 2
            ui->playerLabel->setText("player 2");
            //change current index 1
            buttonClicked[index] = 1;
            return 1;
        case 0:
            // switch label to player 1
            ui->playerLabel->setText("player 1");
            // change current index 2
            buttonClicked[index] = 2;
            return 2;
        }
    }
    return 0;
}

void MainWindow::on_pushButton_clicked()
{
    int player = playerTurn(0);
    if(player == 1){
        ui->pushButton->setText("X");
       } else if (player == 2){
        ui->pushButton->setText("O");
    }
    checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton_2_clicked()
{
    int player = playerTurn(1);
    if(player == 1){
        ui->pushButton_2->setText("X");
       } else if (player == 2){
        ui->pushButton_2->setText("O");
    }
    checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton_4_clicked()
{
    int player = playerTurn(2);
    if(player == 1){
        ui->pushButton_4->setText("X");
       } else if (player == 2){
        ui->pushButton_4->setText("O");
    }
    checkForWinner(buttonClicked, player);
}
