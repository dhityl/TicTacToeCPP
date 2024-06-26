#include <iostream>
using namespace std;

class TicTacToe {
    private:

    char gameBoard[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
        };
    char currentPlayer;
    int row, column;
    bool winner;

    public:
    // generator for first player
    TicTacToe(){
        currentPlayer = 'O';
    }

    // print current board
    void printBoard(){

    cout << "   |   |   " << endl;
    cout << " " << gameBoard[0][0] << " | " << gameBoard[0][1] << " | " << gameBoard[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << gameBoard[1][0] << " | " << gameBoard[1][1] << " | " << gameBoard[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << gameBoard[2][0] << " | " << gameBoard[2][1] << " | " << gameBoard[2][2] << endl;
    cout << "   |   |   " << endl;

    }

    // change current player
    void changePlayer(){

        if (currentPlayer == 'O'){
            currentPlayer = 'X';
        }
        else
        if (currentPlayer == 'X'){
            currentPlayer = 'O';
        }

    }

    // record the move played aka change the board
    void changeBoard(){

        gameBoard[row][column] = currentPlayer;

    }

    // ask the user for the move
    void enterMove(){
        cout << "Player "<< currentPlayer << ":" << endl << "Enter your move: (row, column)" << endl;
        cin >> row >> column;
    }

    // check if the board has a winner
    bool checkWinner(){
        // check rows
        for (int r = 0; r < 3; r++) {
            if (gameBoard[r][0] != ' ' && gameBoard[r][0] == gameBoard[r][1] && gameBoard[r][1] == gameBoard[r][2]) {
                winner = true;;
                break;
            }
        }

        // check columns
        for (int c = 0; c < 3; c++) {
            if (gameBoard[0][c] != ' ' && gameBoard[0][c] == gameBoard[1][c] && gameBoard[1][c] == gameBoard[2][c]) {
                winner = true;;
                break;
            }
        }

        // check diagonals
        if (gameBoard[0][0] != ' ' && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) {
            winner = true;
        }
        else if (gameBoard[0][2] != ' ' && gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) {
            winner = true;
        }

        return winner;
    }

    // display winner
    void displayWinner(){
        cout<<"Game Over!"<< endl << "Player "<< currentPlayer <<" Won.";
    }


};

int main(){

    TicTacToe t;
    for (int i = 0; i<9; i++){
        t.printBoard();
        t.enterMove();
        t.changeBoard();

        if (t.checkWinner()){
            t.printBoard();
            t.displayWinner();
            break;
        }
        t.changePlayer();

        if (i==8){
            t.printBoard();
            cout<<"Game Over!\nIt's a draw.";
        }
    }


    return 0;
}
