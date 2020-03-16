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
            ui->playerTurnLabel->setText("Player " + QString::number(player));
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
            ui->playerTurnLabel->setText("player 2");
            //change current index 1
            buttonClicked[index] = 1;
            return 1;
        case 0:
            // switch label to player 1
            ui->playerTurnLabel->setText("player 1");
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
    //set click count to 0 and button index to 0
    clickCount = 0;
    for(int i = 0; i < 9; i++){
        buttonClicked[i] = 0;
    }

    //clear button text label
    QPushButton* buttonArray[] = {ui->pushButton0, ui->pushButton1, ui->pushButton2,
                                 ui->pushButton3, ui->pushButton4, ui->pushButton5,
                                 ui->pushButton6, ui->pushButton7, ui->pushButton8};
    for(int i = 0; i < 9 ; i++){
        buttonArray[i]->setText("");
    }
    // reset the player turn and remove winner word label
    ui->playerTurnLabel->setText("Player 1");
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
            ui->pushButton0->setText("O");
        } else if(i == 1){
            ui->pushButton1->setText("O");
        } else if(i == 2){
            ui->pushButton2->setText("O");
        } else if(i == 3){
            ui->pushButton3->setText("O");
        } else if(i == 4){
            ui->pushButton4->setText("O");
        } else if(i == 5){
            ui->pushButton5->setText("O");
        } else if(i == 6){
            ui->pushButton6->setText("O");
        } else if(i == 7){
           ui->pushButton7->setText("O");
        } else if(i == 8){
            ui->pushButton8->setText("O");
        }
        }
    }



void MainWindow::mediumLevelAi()
{

}

void MainWindow::hardLevelAi()
{

}


void MainWindow::on_pushButton0_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(0);
    // player 1 is human
    if(ui->onePlayerButton->isChecked()){
        if(player == 1){
            ui->pushButton0->setText("X");
           } else if (player == 2){
            // called the ai function for player 2
            easyLevelAi();

        }
        //check for winner
       gameIsDone = checkForWinner(buttonClicked, player);

        // button is not connect yet so I can't test it
       // normal game between two players
    } else if (ui->twoPlayerButton->isChecked()){
        if(player == 1){
            ui->pushButton0->setText("X");
           } else if (player == 2){
            ui->pushButton0->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}

}

void MainWindow::on_pushButton1_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(1);
        if(player == 1){
            ui->pushButton1->setText("X");
           } else if (player == 2){
            ui->pushButton1->setText("O");
        }
       gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton2_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(2);
        if(player == 1){
            ui->pushButton2->setText("X");
           } else if (player == 2){
            ui->pushButton2->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton3_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(3);
        if(player == 1){
            ui->pushButton3->setText("X");
           } else if (player == 2){
            ui->pushButton3->setText("O");
        }
        gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton4_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(4);
        if(player == 1){
            ui->pushButton4->setText("X");
           } else if (player == 2){
            ui->pushButton4->setText("O");
        }
       gameIsDone =  checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton5_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(5);
        if(player == 1){
            ui->pushButton5->setText("X");
           } else if (player == 2){
            ui->pushButton5->setText("O");
        }
       gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton6_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(6);
        if(player == 1){
            ui->pushButton6->setText("X");
           } else if (player == 2){
            ui->pushButton6->setText("O");
        }
       gameIsDone =  checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton7_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(7);
        if(player == 1){
            ui->pushButton7->setText("X");
           } else if (player == 2){
            ui->pushButton7->setText("O");
        }
       gameIsDone = checkForWinner(buttonClicked, player);
}

void MainWindow::on_pushButton8_clicked()
{
    if(gameIsDone){
        gameReset();
    }
    int player = playerTurn(8);
        if(player == 1){
            ui->pushButton8->setText("X");
           } else if (player == 2){
            ui->pushButton8->setText("O");
        }
       gameIsDone = checkForWinner(buttonClicked, player);
}
