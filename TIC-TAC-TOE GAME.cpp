#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>>& board);
bool isWinner(const vector<vector<char>>& board, char player);
bool isBoardFull(const vector<vector<char>>& board);
void playGame();
bool playAgain();

int main() {
    do {
        playGame();
    } while (playAgain());
    return 0;
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "\nCurrent Board:\n";
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

bool isWinner(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;
    bool gameWon = false;

    displayBoard(board);

    while (!gameWon && !isBoardFull(board)) {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        --row; // Convert to 0-based index
        --col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            displayBoard(board);

            if (isWinner(board, currentPlayer)) {
                cout << "Player " << currentPlayer << " wins!\n";
                gameWon = true;
            } else if (isBoardFull(board)) {
                cout << "The game is a draw.\n";
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}

bool playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}
