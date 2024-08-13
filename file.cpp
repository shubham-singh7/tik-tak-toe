#include <iostream>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "Player 1 (X)  -  Player 2 (O)\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    for (int i = 0; i < 3; i++) {
        // Rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
        // Columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }
    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }

    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }
}

void game() {
    cout << "Player 1, choose your marker: X or O: ";
    char markerP1;
    cin >> markerP1;

    currentPlayer = 1;
    currentMarker = markerP1;

    if (markerP1 == 'X') {
        currentMarker = 'X';
    } else {
        currentMarker = 'O';
    }

    drawBoard();

    int playerWon;

    for (int i = 0; i < 9; i++) {
        cout << "It's player " << currentPlayer << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already occupied! Try again.\n";
            i--;
            continue;
        }

        drawBoard();

        playerWon = winner();

        if (playerWon == 1) {
            cout << "Player 1 wins! Congratulations!\n";
            break;
        } else if (playerWon == 2) {
            cout << "Player 2 wins! Congratulations!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (playerWon == 0) {
        cout << "It's a draw!\n";
    }
}

int main() {
    game();
    return 0;
}
