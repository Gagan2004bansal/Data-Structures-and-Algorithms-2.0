#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAXRANDOMVALUE 3
#define MAXPREV 500

int arr[4][4] = { 0 }, c[4], score = 0, highscore = 0, count = 0, temp = 0;

int findlen(int n);

// Function to print the game board
void print() {
    int i, j, k, len1;

    printf("\n\t\t\t\t\t===============2048==============\n");
    printf("\t\t\t\t\tYOUR SCORE=%d\n\t\t\t\t\t", score);
    if (score < highscore) {
        printf("HIGH SCORE=%d\t\t\t\t\t\n", highscore);
    } else {
        highscore = score;
        printf("HIGH SCORE=%d\t\t\t\t\t\n", highscore);
    }
    printf("\t\t\t\t\t---------------------------------\n");

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j == 0) {
                printf("\t\t\t\t\t|");
            }
            if (arr[i][j] != 0) {
                len1 = findlen(arr[i][j]);
                for (k = 0; k < 4 - len1; k++) {
                    printf(" ");
                }
                printf("%d", arr[i][j]);
                for (k = 0; k < 4 - len1; k++) {
                    printf(" ");
                }
                printf("|");
            } else {
                printf("    |");
            }
        }
        printf("\n");
        if (i != 3) {
            printf("\t\t\t\t\t---------------------------------\n");
        }
    }
    printf("\t\t\t\t\t---------------------------------\n");
    printf("\t\t\t\t\tPREV-> P\t\t\t\t\t\n");
    printf("\t\t\t\t\tRESTART-> R\t\t\t\t\t\n");
    printf("\t\t\t\t\tEXIT-> U\t\t\t\t\t\n");
    printf("\t\t\t\t\tENTER YOUR CHOICE -> W, S, A, D\n\t\t\t\t\t");
}

// Function to find the length of a number (count of digits)
int findlen(int n) {
    int len = 0;
    while (n > 0) {
        len++;
        n /= 10;
    }
    return len;
}

// Function to move and merge tiles
void move_and_merge(int reverse) {
    int i, j;
    for (i = 0; i < 4; i++) {
        // Copy the row/column to c[] and reverse if necessary
        for (j = 0; j < 4; j++) {
            c[j] = reverse ? arr[i][3 - j] : arr[i][j];
        }

        // Perform merging
        for (j = 0; j < 3; j++) {
            if (c[j] != 0 && c[j] == c[j + 1]) {
                c[j] *= 2;
                score += c[j];
                c[j + 1] = 0;
            }
        }

        // Shift non-zero values to the front
        int index = 0;
        for (j = 0; j < 4; j++) {
            if (c[j] != 0) {
                c[index++] = c[j];
            }
        }
        while (index < 4) {
            c[index++] = 0;
        }

        // Copy back to the array and reverse if necessary
        for (j = 0; j < 4; j++) {
            if (reverse) {
                arr[i][3 - j] = c[j];
            } else {
                arr[i][j] = c[j];
            }
        }
    }
}

// Function to rotate the array 90 degrees clockwise
void rotate_clockwise() {
    int i, j, temp[4][4];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp[j][3 - i] = arr[i][j];
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

// Function to add a random number to the game board
void add_random_number() {
    int i, j, free_spaces = 0;
    int empty_tiles[16][2];

    // Find all empty tiles
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (arr[i][j] == 0) {
                empty_tiles[free_spaces][0] = i;
                empty_tiles[free_spaces][1] = j;
                free_spaces++;
            }
        }
    }

    if (free_spaces > 0) {
        srand(time(NULL));
        int r = rand() % free_spaces;
        arr[empty_tiles[r][0]][empty_tiles[r][1]] = (rand() % 10 == 0) ? 4 : 2;
    }
}

// Function to check if any moves are possible
int moves_possible() {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (arr[i][j] == 0) return 1; // Empty tile found
            if (j < 3 && arr[i][j] == arr[i][j + 1]) return 1; // Horizontal match
            if (i < 3 && arr[i][j] == arr[i + 1][j]) return 1; // Vertical match
        }
    }
    return 0; // No moves possible
}

// Function to reset the game
void reset_game() {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arr[i][j] = 0;
        }
    }
    score = 0;
    add_random_number();
    add_random_number();
}

// Function to clear the screen (cross-platform)
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    char choice;
    FILE *ptr;
    ptr = fopen("highscore.txt", "r");
    if (ptr != NULL) {
        fscanf(ptr, "%d", &highscore);
        fclose(ptr);
    }

    reset_game();
    print();

    while (1) {
        choice = getchar();
        if (choice == 'u' || choice == 'U') {
            break;
        }

        if (choice == 'w' || choice == 'W') {
            rotate_clockwise();
            rotate_clockwise();
            rotate_clockwise();
            move_and_merge(0);
            rotate_clockwise();
        } else if (choice == 's' || choice == 'S') {
            rotate_clockwise();
            move_and_merge(0);
            rotate_clockwise();
            rotate_clockwise();
            rotate_clockwise();
        } else if (choice == 'a' || choice == 'A') {
            move_and_merge(0);
        } else if (choice == 'd' || choice == 'D') {
            move_and_merge(1);
        } else if (choice == 'r' || choice == 'R') {
            reset_game();
        }

        if (choice == 'w' || choice == 'a' || choice == 's' || choice == 'd') {
            add_random_number();
            clear_screen();
            print();

            if (!moves_possible()) {
                printf("\n=============GAME OVER============\n");
                printf("WANT TO PLAY MORE? Y/N: ");
                choice = getchar();
                if (choice == 'y' || choice == 'Y') {
                    reset_game();
                    clear_screen();
                    print();
                } else {
                    break;
                }
            }
        }
    }

    // Save high score
    if (score > highscore) {
        ptr = fopen("highscore.txt", "w");
        if (ptr != NULL) {
            fprintf(ptr, "%d", score);
            fclose(ptr);
        }
    }

    return 0;
}
