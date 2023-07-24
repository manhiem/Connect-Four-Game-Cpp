#include <iostream>
#include <vector>
using namespace std;

class Player {
public:
    string name;
    char color;
    int movesPlayed;

    Player(string nm, char cl) : name(nm), color(cl), movesPlayed(0) {}
};

class Game {
public:
    Player playerOne;
    Player playerTwo;
    const int n = 6, m = 7;
    vector<vector<char>> Board;

    Game(Player other1, Player other2) : playerOne(other1), playerTwo(other2) {
        Board.resize(n, vector<char>(m, ' '));
        StartGame();
    }

    void StartGame() {
        cout << "\x1b[2J\x1b[H"; // Clear screen using ANSI escape sequences

        cout << "Player " << playerOne.name << " (Red) vs. Player " << playerTwo.name << " (Yellow)" << endl;
        cout << "Let's play C-0-nn-3-ct Four!" << endl;

        DisplayBoard();
    }

    void DisplayBoard() const {
        cout << "\x1b[0m"; // Reset text color to default
        cout << "  1   2   3   4   5   6   7 " << endl;
        for (int i = 0; i < n; i++) {
            cout << "+---+---+---+---+---+---+---+" << endl;
            cout << "| ";
            for (int j = 0; j < m; j++) {
                if (Board[i][j] == 'R') {
                    cout << "\x1b[31m"; // Set text color to red
                } else if (Board[i][j] == 'Y') {
                    cout << "\x1b[33m"; // Set text color to yellow
                }
                cout << Board[i][j] << " ";
                cout << "\x1b[0m"; // Reset text color to default
                cout << "| ";
            }
            cout << endl;
        }
        cout << "+---+---+---+---+---+---+---+" << endl;
    }

    bool FillBoard(char color, int col) {
        col--; // Adjust the column input to match the index in the vector
        int row = n - 1; // Start filling from the bottom of the board

        // Find the first empty row in the selected column
        while (row >= 0 && Board[row][col] != ' ') {
            row--;
        }

        // Check if the column is already full
        if (row < 0) {
            cout << "Column " << col + 1 << " is already full. Please choose another column." << endl;
            return false;
        }

        Board[row][col] = color;
        movesPlayed++;

        // Print the updated board
        DisplayBoard();

        // Check if the current player has won
        if (CheckWinner(row, col, color)) {
            cout << "CONGO! Player " << (color == 'R' ? playerOne.name : playerTwo.name) << " wins!" << endl;
            return true;
        }

        return false;
    }

    bool CheckWinner(int row, int col, char color) {
        // Check rows
        if (CheckConsecutive(Board[row], color)) {
            return true;
        }

        // Check columns
        vector<char> colVector;
        for (int i = 0; i < n; i++) {
            colVector.push_back(Board[i][col]);
        }
        if (CheckConsecutive(colVector, color)) {
            return true;
        }

        // Check diagonals
        if (CheckDiagonal(Board, color)) {
            return true;
        }

        // Check reverse diagonals
        if (CheckDiagonalReverse(Board, color)) {
            return true;
        }

        return false;
    }

    bool CheckConsecutive(const vector<char>& arr, char color) {
        int count = 0;
        for (char c : arr) {
            if (c == color) {
                count++;
                if (count == 4) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
        return false;
    }

    bool CheckDiagonal(const vector<vector<char>>& board, char color) {
        for (int i = 0; i <= n - 4; i++) {
            for (int j = 0; j <= m - 4; j++) {
                int count = 0;
                for (int k = 0; k < 4; k++) {
                    if (board[i + k][j + k] == color) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == 4) {
                    return true;
                }
            }
        }
        return false;
    }

    bool CheckDiagonalReverse(const vector<vector<char>>& board, char color) {
        for (int i = 0; i <= n - 4; i++) {
            for (int j = m - 1; j >= 3; j--) {
                int count = 0;
                for (int k = 0; k < 4; k++) {
                    if (board[i + k][j - k] == color) {
                        count++;
                    } else {
                        break;
                    }
                }
                if (count == 4) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    int movesPlayed = 0;
};

int main() {
    string Name1, Name2;
    cout << "Enter the names of Player1 and Player2: \n";
    cin >> Name1 >> Name2;

    char colorP1, colorP2;
    cout << "Enter the color of P1 and P2 (R|Y) : \n";
    cin >> colorP1 >> colorP2;

    cout << "\n\n Its with the classic rules of a connect four game! i.e.,\n";
    cout << "1. Choose your HARD! (R/Y). Player 1 always starts the game first because Player1 is people's favorite.\n";
    cout << "2. The board is of (6, 7) where a player wins if he gets 4 consecutive coins of his color or matrix is full\n";
    cout << "3. People's favorite won't win always make sure to note that!!\n";
    cout << "4. Keep rocking! Keep playing!";

    Player Player1(Name1, colorP1);
    Player Player2(Name2, colorP2);

    cout << "\n\n\n";
    Game playGame(Player1, Player2);

    bool hasWon = false;
    int player = 0;
    while (!hasWon) {
        int col;
        Player &currentPlayer = (player == 0) ? Player1 : Player2;
        cout << "\nPlayer " << currentPlayer.name << ", enter the column you want to put your coin (1-7): \n";
        cin >> col;
        hasWon = playGame.FillBoard(currentPlayer.color, col);
        player = 1 - player; // Toggle player between 0 and 1
    }

    if(hasWon) {
      // Display winning message
      Player &winningPlayer = (player == 0) ? Player2 : Player1;
      cout << "Congratulations, " << winningPlayer.name << "! You won!" << endl;
    }

    while(1) {
        continue;
    }

}
