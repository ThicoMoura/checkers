#include <stdio.h>
#include <stdlib.h>

#define BLACK 1
#define WHITE 2

#define BLACK_KING 3
#define WHITE_KING 4

#define EMPTY 0

#define MIN 0
#define MAX 8

#define PLAYER_ONE 1
#define PLAYER_TWO 2

#define GAMMING 0
#define BLACK_WIN 1
#define WHITE_WIN 2
#define DRAW 3

typedef struct {
    int ** Board;
    int Turn;
    int CurrentPlayer;
    int Status;
} Game;

typedef struct {
    int x;
    int y;
} Pos;

void newGame(Game *);
void printBoard(Game *);
int validMove(Game *, Pos, Pos);
int move(Game *, Pos, Pos);

int main(int argc, char ** argv) {
    Game game;

    newGame(&game);
    printBoard(&game);

    // Test move
    Pos start = {1, 5};
    Pos end = {3, 3};

    move(&game, start, end);
    printBoard(&game);

    return 0;
}

void newGame(Game * game) {
    (*game).Board = malloc(MAX * sizeof (int *));
    for (int i = MIN; i < MAX; i++)
        (*game).Board[i] = malloc(MAX * sizeof (int *));
    for (int i = MIN; i < MAX; i++)
        for (int j = MIN; j < MAX; j++)
            if (i < 3 && ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))) {
                (*game).Board[i][j] = WHITE;
            } else if (i > 4 && ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))) {
                (*game).Board[i][j] = BLACK;
            } else {
                (*game).Board[i][j] = EMPTY;
            }
    (*game).Turn = 1;
    (*game).CurrentPlayer = PLAYER_ONE;
    (*game).Status = GAMMING;
}

void printBoard(Game * game) {
    printf("   A   B   C   D   E   F   G   H\n");
    printf(" +---+---+---+---+---+---+---+---+\n");
    for (int i = MIN; i < MAX; i++) {
        printf("%d|", 8 - i);
        for (int j = MIN; j < MAX; j++) {
            if ((*game).Board[i][j] == WHITE) printf(" O |");
            else if((*game).Board[i][j] == BLACK) printf(" 0 |");
            else printf("   |");
        }
        printf("\n");
    }
    printf(" +---+---+---+---+---+---+---+---+\n");
    printf("   A   B   C   D   E   F   G   H\n");
}

int validMove(Game* game, Pos start, Pos end) {
    if (((*game).Board[start.y][start.x] == (*game).CurrentPlayer)) {
        if((*game).CurrentPlayer == WHITE && (end.y == (start.y + 2) && (end.x == (start.x - 2) || end.x == (start.x + 2)))) return 1;
        if((*game).CurrentPlayer == BLACK && (end.y == (start.y - 2) && (end.x == (start.x - 2) || end.x == (start.x + 2)))) return 1;
    }
    return 0;
}

int move(Game * game, Pos start, Pos end) {
    if (validMove(game, start, end)) {
        int swap = (*game).Board[start.y][start.x];
        (*game).Board[start.y][start.x] = 0;
        (*game).Board[end.y][end.x] = swap;
    }
    return 1; 
}