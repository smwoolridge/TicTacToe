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

/*
bool MainWindow::checkForWinner(int buttonClicked[], int player)
{
    bool win = true;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 3; j++){
            if(buttonClicked[winCombinations[i][j]] != player){
                win = false;
                break;
            }
        }
        if(win){
            // set winning player name
            ui->winnerLabel->setText("Winner: ");
            ui->playerLabel->setText("Player " + QString::number(player));
            return true;
        }
        win = true;
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

void MainWindow::on_pushButton_9_clicked()
{
    int player = playerTurn(3);
    if(player == 1){
        ui->pushButton_9->setText("X");
       } else if (player == 2){
        ui->pushButton_9->setText("O");
    }
    checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton_3_clicked()
{
    int player = playerTurn(4);
    if(player == 1){
        ui->pushButton_3->setText("X");
       } else if (player == 2){
        ui->pushButton_3->setText("O");
    }
    checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton_5_clicked()
{
    int player = playerTurn(5);
    if(player == 1){
        ui->pushButton_5->setText("X");
       } else if (player == 2){
        ui->pushButton_5->setText("O");
    }
    checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton_8_clicked()
{
    int player = playerTurn(6);
    if(player == 1){
        ui->pushButton_8->setText("X");
       } else if (player == 2){
        ui->pushButton_8->setText("O");
    }
    checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton_7_clicked()
{
    int player = playerTurn(7);
    if(player == 1){
        ui->pushButton_7->setText("X");
       } else if (player == 2){
        ui->pushButton_7->setText("O");
    }
    checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton_6_clicked()
{
    int player = playerTurn(8);
    if(player == 1){
        ui->pushButton_6->setText("X");
       } else if (player == 2){
        ui->pushButton_6->setText("O");
    }
    checkForWinner(buttonClicked, player);
}
*/
