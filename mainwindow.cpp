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
    QString playerOne = ui->playerOneTextEdit->toPlainText();
    QString playerTwo = ui->playerTwoTextEdit->toPlainText();
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
            if(player == 1){
            ui->playerTurnLabel->setText(playerOne);
            } else {
            ui->playerTurnLabel->setText(playerTwo);
            }
            return true;
        }
        win = true;
    }
    return false;
}

int MainWindow::playerTurn(int index)
{
    //set player name
    QString playerOne = ui->playerOneTextEdit->toPlainText();
    QString playerTwo = ui->playerTwoTextEdit->toPlainText();
    // check array index
    if(buttonClicked[index] == 0){
        clickCount++;
        checkPlayer = clickCount % 2;
        switch(checkPlayer){
        case 1:
            // switch label to player 2
            ui->playerTurnLabel->setText(playerTwo);
            //change current index 1
            buttonClicked[index] = 1;
            return 1;
        case 0:
            // switch label to player 1
            ui->playerTurnLabel->setText(playerOne);
            // change current index 2
            buttonClicked[index] = 2;
            return 2;
        }
    }
    return 0;
}

// if there is a winner reset the game
void MainWindow::gameReset()
{
    QString playerOne = ui->playerOneTextEdit->toPlainText();
    //set click count to 0 and button index to 0
    clickCount = 0;
    for(int i = 0; i < 9; i++){
        buttonClicked[i] = 0;
    }

    //clear button text label
    QPushButton* buttonArray[] = {ui->l1_00, ui->l1_10, ui->l1_20,
                                 ui->l1_01, ui->l1_11, ui->l1_21,
                                 ui->l1_02, ui->l1_12, ui->l1_22};
    for(int i = 0; i < 9 ; i++){
        buttonArray[i]->setText("");
    }
    // reset the player turn and remove winner word label
    ui->playerTurnLabel->setText(playerOne);
    ui->winnerLabel->setText("");
    //put game is done back to false after called
    gameIsDone = false;
}


// find the next zero in the array and add a button there
int MainWindow::easyLevelAi()
{
    for(int i = 0; i < 9; i++){
        if (buttonClicked[i] == 0){
            return i;
               }
        if(i == 0){
            ui->l1_00->setText("O");
        } else if(i == 1){
            ui->l1_10->setText("O");
        } else if(i == 2){
            ui->l1_20->setText("O");
        } else if(i == 3){
            ui->l1_01->setText("O");
        } else if(i == 4){
            ui->l1_11->setText("O");
        } else if(i == 5){
            ui->l1_21->setText("O");
        } else if(i == 6){
            ui->l1_02->setText("O");
        } else if(i == 7){
           ui->l1_12->setText("O");
        } else if(i == 8){
            ui->l1_22->setText("O");
        }
        }
    }



void MainWindow::mediumLevelAi()
{

}

void MainWindow::hardLevelAi()
{

}





void MainWindow::on_onePlayerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_twoPlayerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_easyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_mediumButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_hardButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_startButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_l1_00_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(0);
        if(player == 1){
            ui->l1_00->setText("X");
           } else if (player == 2){
            ui-> l1_00->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_l1_10_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(1);
        if(player == 1){
            ui->l1_10->setText("X");
           } else if (player == 2){
            ui-> l1_10->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_l1_20_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(2);
        if(player == 1){
            ui->l1_20->setText("X");
           } else if (player == 2){
            ui-> l1_20->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_l1_01_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(3);
        if(player == 1){
            ui->l1_01->setText("X");
           } else if (player == 2){
            ui-> l1_01->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_l1_11_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(4);
        if(player == 1){
            ui->l1_11->setText("X");
           } else if (player == 2){
            ui-> l1_11->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_l1_21_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(5);
        if(player == 1){
            ui->l1_21->setText("X");
           } else if (player == 2){
            ui-> l1_21->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_l1_02_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(6);
        if(player == 1){
            ui->l1_02->setText("X");
           } else if (player == 2){
            ui-> l1_02->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_l1_12_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(7);
        if(player == 1){
            ui->l1_12->setText("X");
           } else if (player == 2){
            ui-> l1_12->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_l1_22_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(8);
        if(player == 1){
            ui->l1_22->setText("X");
           } else if (player == 2){
            ui-> l1_22->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}
