#include <stdio.h>
#include <stdlib.h>

// Global array to represent the board layout
char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

// Function declarations
int checkwin();
void board();

int main() {
    int player = 1;
    int i, choice;
    char mark;

    do {
        board();

        // Alternate turns between Player 1 and Player 2
        player = (player % 2) ? 1 : 2;

        // Get player input
        printf("Player %d, enter a number (1-9): ", player);
        scanf("%d", &choice);

        // Assign marker based on current player
        mark = (player == 1) ? 'X' : 'O';

        // Check if the choice is valid and not already taken
        if (choice >= 1 && choice <= 9 && square[choice] == (choice + '0')) {
            square[choice] = mark;
        } else {
            printf("Invalid move! Press Enter to try again.");
            player--; // Counteract the player switch to repeat the turn
            while (getchar() != '\n'); // Clear input buffer
            getchar();
        }

        i = checkwin();
        player++;

    } while (i == -1);

    // Print the final board state
    board();

    // Announce results
    if (i == 1) {
        printf("==>\aPlayer %d wins!\n", --player);
    } else {
        printf("==>\aGame draw!\n");
    }

    return 0;
}

/**
 * Function to return game status:
 *  1 for game is over with a winner
 * -1 for game is still in progress
 *  0 for game is over and is a draw
 */
int checkwin() {
    // Check horizontal rows
    if (square[1] == square[2] && square[2] == square[3]) return 1;
    else if (square[4] == square[5] && square[5] == square[6]) return 1;
    else if (square[7] == square[8] && square[8] == square[9]) return 1;

    // Check vertical columns
    else if (square[1] == square[4] && square[4] == square[7]) return 1;
    else if (square[2] == square[5] && square[5] == square[8]) return 1;
    else if (square[3] == square[6] && square[6] == square[9]) return 1;

    // Check diagonal lines
    else if (square[1] == square[5] && square[5] == square[9]) return 1;
    else if (square[3] == square[5] && square[5] == square[7]) return 1;

    // Check if the board is completely full (Draw)
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9') {
        return 0;
    }
    else {
        return -1;
    }
}

/**
 * Function to clear the screen and draw the Tic-Tac-Toe board
 */
void board() {
    // Uses system call to clear terminal. Use "cls" on Windows or "clear" on Linux/macOS
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("     |     |     \n\n");
}
