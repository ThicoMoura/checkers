#include <stdio.h>
#include <stdlib.h>

#define WHITE 1
#define BLACK 2

#define WHITE_KING 3
#define BLACK_KING 4

#define MIN 0
#define MAX 8

#define PLAYER_ONE 1
#define PLAYER_TWO 2

#define GAMMING 0
#define WHITE_WIN 1
#define BLACK_WIN 2
#define DRAW 3

typedef struct {
    int ** Board;
    int Turn;
    int CurrentPlayer;
    int Status;
} Game;

void newGame(Game *);

int main(int argc, char ** argv) {
    Game game;
    newGame(&game);
    printf("%d", game.Turn);
    return 0;
}

void newGame(Game * game) {
    (*game).Board = malloc(MAX * sizeof (int *));
    for (int i = MIN; i < MAX; i++)
        (*game).Board[i] = malloc(MAX * sizeof (int *));
    (*game).Turn = 1;
    (*game).CurrentPlayer = PLAYER_ONE;
    (*game).Status = GAMMING;
}