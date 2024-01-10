#include <stdio.h>

char board[3][3];

void initialize_board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void print_board() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int check_winner(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player & board[i][1] == player & board[i][2] == player)
            return 1;
        if (board[0][i] == player & board[1][i] == player & board[2][i] == player)
            return 1;
    }
    if (board[0][0] == player & board[1][1] == player & board[2][2] == player)
        return 1;
    if (board[0][2] == player & board[1][1] == player & board[2][0] == player)
        return 1;
    return 0;
}

int is_board_full() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return 0;
    return 1;
}

int main() {

    int row, col, currentPlayer = 1;
    initialize_board();

    printf("Tic Tac Toe\n");
    printf("prabodh (X) - naidu (O)\n");


    while (1) {
        print_board();

        printf("prabodh %d, enter row (0-2) and column (0-2) to place your symbol: ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = (currentPlayer == 1) ? 'X' : 'O';

        if (check_winner(board[row][col])) {
            print_board();
            printf("player %d wins!\n", currentPlayer);
            break;
        } else if (is_board_full()) {
            print_board();
            printf("It's a draw!\n");
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}

