#include <iostream>

using namespace std;

void draw_board(char board[3][3]) { //function to create the tic-tac-toe board
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

int check_win(char player, char board[3][3]) { //function to check if player won
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main() {
    char player1 = 'X';
    char player2 = 'O';
    const int ROWS = 3;
    const int COLUMNS = 3;
    int row;
    int column;
    char board[ROWS][COLUMNS] = { { ' ', ' ', ' '},
                                  { ' ', ' ', ' '},
                                  { ' ', ' ', ' '} };
    
    cout << "Tic-Tac-Toe\n\n";;
    draw_board(board);

    for (int i = 0; i < 9; i++) { //Player input
        while (true) { //Player X turn
            cout << "Player X (Rows and Columns (0-2)):\n";
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> column;
            if ((board[row][column] != ' ') || (row < 0) || (row > 2) || (column < 0) || (column > 2)) {
                cout << "\nInvalid Option. Please try again.\n";
            }
            else {
                break;
            }
        }
        board[row][column] = player1;
        draw_board(board);
        if (check_win(player1, board)) {
            cout << "\nPlayer X won!";
            break;
        }

        while (true) { //Player O turn
            cout << "Player O (Rows and Columns (0-2)):\n";
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> column;
            if ((board[row][column] != ' ') || (row < 0) || (row > 2) || (column < 0) || (column > 2)) {
                cout << "\nInvalid Option. Please try again.\n";
            }
            else {
                break;
            }

        }
        board[row][column] = player2;
        draw_board(board);
        check_win(player2, board);
        if (check_win(player2, board)) {
            cout << "\nPlayer O won!";
            break;
        }
    }

    return 0;
}


