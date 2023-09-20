#include <iostream>
#include <vector>

// Constants for board size and player symbols
const int BOARD_SIZE = 3;
const char PLAYER_SYMBOL = 'X';
const char AI_SYMBOL = 'O';

// Function to initialize the game board
void initializeBoard(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board.push_back(std::vector<char>(BOARD_SIZE, ' '));
    }
}

// Function to display the game board
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won the game
bool checkWin(const std::vector<std::vector<char>>& board, char symbol) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return true;
    }
    if (board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol) {
        return true;
    }

    return false;
}

// Function to check if the game has ended in a draw
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to get the user's move
void getPlayerMove(std::vector<std::vector<char>>& board) {
    int row, col;
    std::cout << "Enter your move (row and column): ";
    std::cin >> row >> col;
    board[row][col] = PLAYER_SYMBOL;
}

// Function to get the AI's move using the minimax algorithm
int minimax(std::vector<std::vector<char>>& board, int depth, bool isMaximizer) {
    if (checkWin(board, PLAYER_SYMBOL)) {
        return -1;
    }
    if (checkWin(board, AI_SYMBOL)) {
        return 1;
    }
    if (checkDraw(board)) {
        return 0;
    }

    int bestScore;

    if (isMaximizer) {
        bestScore = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = AI_SYMBOL;
                    int score = minimax(board, depth + 1, false);
                    board[i][j] = ' ';
                    bestScore = std::max(bestScore, score);
                }
            }
        }
    } else {
        bestScore = 1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = PLAYER_SYMBOL;
                    int score = minimax(board, depth + 1, true);
                    board[i][j] = ' ';
                    bestScore = std::min(bestScore, score);
                }
            }
        }
    }

    return bestScore;
}

// Function to get the AI's move
void getAIMove(std::vector<std::vector<char>>& board) {
    int bestScore = -1000;
    int bestMoveRow, bestMoveCol;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = AI_SYMBOL;
                int score = minimax(board, 0, false);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    bestMoveRow = i;
                    bestMoveCol = j;
                }
            }
        }
    }

    board[bestMoveRow][bestMoveCol] = AI_SYMBOL;
}

// Function to play the Tic-Tac-Toe game
void playGame() {
    std::vector<std::vector<char>> board;
    initializeBoard(board);
    std::cout << "Welcome to the Tic-Tac-Toe Game!\n";
    std::cout << "Player symbol: " << PLAYER_SYMBOL << std::endl;
    std::cout << "AI symbol: " << AI_SYMBOL << std::endl;

    displayBoard(board);

    while (true) {
        getPlayerMove(board);
        displayBoard(board);

        if (checkWin(board, PLAYER_SYMBOL)) {
            std::cout << "Congratulations! You won the game.\n";
            break;
        }

        if (checkDraw(board)) {
            std::cout << "The game ended in a draw.\n";
            break;
        }

        getAIMove(board);
        displayBoard(board);

        if (checkWin(board, AI_SYMBOL)) {
            std::cout << "The AI won the game. Better luck next time!\n";
            break;
        }

        if (checkDraw(board)) {
            std::cout << "The game ended in a draw.\n";
            break;
        }
    }
}

int main() {
    playGame();
    return 0;
}
