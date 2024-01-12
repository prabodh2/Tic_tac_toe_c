#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // The Tic Tac Toe board

void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
}

int checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    return 0;
}

int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0; // Board is not full
        }
    }
    return 1; // Board is full
}

void makeComputerMove() {
    int emptyCells[9][2];
    int numEmptyCells = 0;

    // Find empty cells
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                emptyCells[numEmptyCells][0] = i;
                emptyCells[numEmptyCells][1] = j;
                numEmptyCells++;
            }
        }
    }

    // Make a random move
    if (numEmptyCells > 0) {
        int randomIndex = rand() % numEmptyCells;
        int row = emptyCells[randomIndex][0];
        int col = emptyCells[randomIndex][1];
        board[row][col] = 'O'; // Computer's move
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    initializeBoard();
    printBoard();

    while (1) {
        int row, col;

        // Player's move
        printf("Enter row (0-2) and column (0-2) for your move: ");
        scanf("%d %d", &row, &col);
        if (board[row][col] == ' ') {
            board[row][col] = 'X';
        } else {
            printf("Cell already taken. Try again.\n");
            continue;
        }

        if (checkWin('X')) {
            printBoard();
            printf("You win!\n");
            break;
        } else if (isBoardFull()) {
            printBoard();
            printf("It's a draw.\n");
            break;
        }

        printBoard();

        // Computer's move
        makeComputerMove();
        if (checkWin('O')) {
            printBoard();
            printf("Computer wins.\n");
            break;
        } else if (isBoardFull()) {
            printBoard();
            printf("It's a draw.\n");
            break;
        }

        printBoard();
    }

    return 0;
}





