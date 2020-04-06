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
            if(player == 1){
            ui->level1_label->setText(playerOne + " Wins!");
            } else {
            ui->level1_label->setText(playerTwo + " Wins!");
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
    QFont customFont("Helvetica[Cronyx]", 12,75,false);
    // check array index
    if(buttonClicked[index] == 0){
        clickCount++;
        checkPlayer = clickCount % 2;
        switch(checkPlayer){
        case 1:

            // switch label to player 2
            ui->level1_label->setText(playerTwo + "'s Turn");
            ui->level1_label->setFont(customFont);
            //change current index 1
            buttonClicked[index] = 1;
            return 1;
        case 0:
            // switch label to player 1
            ui->level1_label->setText(playerOne + "'s Turn");
            ui->level1_label->setFont(customFont);
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
    ui->level1_label->setText(playerOne);

    //put game is done back to false after called
    gameIsDone = false;
}

// find the next zero in the array and add a button there
void MainWindow::easyLevelAi(int button)
{




}





void MainWindow::setCharlieTurn(){
    QFont customFont("Helvetica[Cronyx]", 20,75,false);
    if(gameIsDone){
        gameReset();
    }
    if(currentButton->text()!= "X" && currentButton->text()!= "O"){
        currentButton->setText("X");
        currentButton->setFont(customFont);
        currentButton->setEnabled(false);
        //mutex.lock();
        //mutex.tryLock(1000);
        //mutex.unlock();
        //easyLevelAi();
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
    ui->playerTwoTextEdit->setText("Charlie");
    ui->playerTwoTextEdit->setReadOnly(true);

    charlieEnabled = true;

    ui->playerOneTextEdit->setPlaceholderText("Player One");

}

void MainWindow::on_twoPlayerButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

    charlieEnabled = false;

    ui->playerOneTextEdit->setPlaceholderText("Player One");
    ui->playerTwoTextEdit->setPlaceholderText("Player Two");

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

void MainWindow::setTurnButton(){
    QFont customFont("Helvetica[Cronyx]", 20,75,false);
    if(gameIsDone){
        gameReset();
    }
    if(currentButton->text()!= "X" && currentButton->text()!= "O"){
        if(currentPlayer == 1){
            currentButton->setText("X");
            currentButton->setFont(customFont);
            currentButton->setEnabled(false);
        } else if (currentPlayer == 2) {
            if(!charlieEnabled){
           currentButton->setText("O");
           currentButton->setFont(customFont);
           currentButton->setEnabled(false);
            }
            else{
                setCharlieTurn();
                clickCount++;
            }
        }
    }
}

void MainWindow::on_l1_00_clicked()
{
    currentPlayer = playerTurn(0);
    gameIsDone = checkForWinner(buttonClicked, currentPlayer);
    currentButton = ui->l1_00;
    setTurnButton();

}

void MainWindow::on_l1_10_clicked()
{
    currentPlayer= playerTurn(1);
    currentButton = ui->l1_10;
    setTurnButton();
    gameIsDone = checkForWinner(buttonClicked, currentPlayer);
}

void MainWindow::on_l1_20_clicked()
{
    currentPlayer= playerTurn(2);
    currentButton = ui->l1_20;
    setTurnButton();
    gameIsDone = checkForWinner(buttonClicked, currentPlayer);
}

void MainWindow::on_l1_01_clicked()
{
    currentPlayer = playerTurn(3);
    currentButton = ui->l1_01;
    setTurnButton();
    gameIsDone = checkForWinner(buttonClicked, currentPlayer);
}

void MainWindow::on_l1_11_clicked()
{
    currentPlayer = playerTurn(4);
    currentButton = ui->l1_11;
    setTurnButton();
    gameIsDone = checkForWinner(buttonClicked, currentPlayer);
}

void MainWindow::on_l1_21_clicked()
{
    currentPlayer = playerTurn(5);
    currentButton = ui->l1_21;
    setTurnButton();
    gameIsDone = checkForWinner(buttonClicked, currentPlayer);
}

void MainWindow::on_l1_02_clicked()
{
    currentPlayer = playerTurn(6);
    currentButton = ui->l1_02;
    setTurnButton();
    gameIsDone = checkForWinner(buttonClicked, currentPlayer);
}

void MainWindow::on_l1_12_clicked()
{
    currentPlayer = playerTurn(7);
    currentButton = ui->l1_12;
    setTurnButton();
    gameIsDone = checkForWinner(buttonClicked, currentPlayer);
}

void MainWindow::on_l1_22_clicked()
{
    currentPlayer = playerTurn(8);
    currentButton = ui->l1_22;
    setTurnButton();
    gameIsDone = checkForWinner(buttonClicked, currentPlayer);
}

void MainWindow::on_help_button_clicked()
{
    QMessageBox::information(
            this,
            tr("Tic Tac Toe Ultimate Rules"),
            tr("1. The game is played on a 3 by 3, 4 by 4 or 5 by 5 grid.\n\n"
               "2. Player 1 is X, Player 2 (or \"Charlie\") is O. Players take turns putting their marks in empty squares.\n\n"
               "3. The first player to get 3, 4 or 5 (depending on the level) of their marks in a row (up, down, across, or diagonally) is the winner.\n\n"
               "4. If no player has 3, 4 or 5 marks in a row, when all squares are full the game is over, and the game ends in a tie.") );
}

void MainWindow::on_backButton_names_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_backButton_levels_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
