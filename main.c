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

void cls();
void newGame(Game *);
void printBoard(Game);
void gameStatus(Game *);
Pos readPos();
int validPosition(Game *, Pos);
int validMove(Game *, Pos, Pos);
int move(Game *, Pos, Pos);

int main(int argc, char ** argv) {
    Game game;

    newGame(&game);

    while (game.Status == 0) {
        cls();
        printBoard(game);
        Pos start = readPos();
        if (!validPosition(&game, start)) {
            printf("Invalid piece! Please, select a valid piece\n");
            continue;
        }

        cls();
        printBoard(game);
        Pos end;
        do {
            end = readPos();
            if (validMove(&game, start, end)) break;
            printf("Invalid move! Please, select a valid move\n");
        } while(1);

        move(&game, start, end);
    }

    return 0;
}

void cls() {
    #ifdef _WIN32
        system("cls");
    #else
        printf("\e[1;1H\e[2J");
    #endif
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

void printBoard(Game game) {
    printf("   A   B   C   D   E   F   G   H\n");
    printf(" +---+---+---+---+---+---+---+---+\n");
    for (int i = MIN; i < MAX; i++) {
        printf("%d|", 8 - i);
        for (int j = MIN; j < MAX; j++) {
            if (game.Board[i][j] == WHITE) printf(" O |");
            else if(game.Board[i][j] == BLACK) printf(" 0 |");
            else printf("   |");
        }
        printf("\n");
    }
    printf(" +---+---+---+---+---+---+---+---+\n");
    printf("   A   B   C   D   E   F   G   H\n");
}

Pos readPos() {
    char * pos;

    pos = malloc(2 * sizeof (char *));

    do {
        printf("Insert position: ");
        scanf("%s", pos);
        if(
            ((pos[0] >= 'A' && pos[0] <= 'H') || (pos[0] >= 'a' && pos[0] <= 'h')) &&
            (pos[1] >= '1' && pos[1] <= '8')
        )
            return (Pos) { .x = ((int)(pos[0]) - ((pos[0] >= 'A' && pos[0] <= 'H') ? 'A' : 'a')), .y = (int)(pos[1]) - '0'};
        else 
            printf("Invalid position, please, insert a valid position!\n");
    } while (1); 
}

int validPosition(Game* game, Pos pos) {
    if ((*game).Board[pos.y][pos.x] != EMPTY)
        if ((*game).Board[pos.y][pos.x] == (*game).CurrentPlayer)
            if (
                ((*game).CurrentPlayer == BLACK && pos.y > 0 && 
                    ( pos.x > 0 && (*game).Board[pos.y - 1][pos.x - 1] == EMPTY) ||
                    ( pos.x < 7 && (*game).Board[pos.y - 1][pos.x + 1] == EMPTY) ||
                    ( pos.x > 1 && pos.y > 1 && (*game).Board[pos.y - 1][pos.x - 1] == WHITE && (*game).Board[pos.y - 2][pos.x - 2] == EMPTY) ||
                    ( pos.x > 1 && pos.y > 1 && (*game).Board[pos.y - 1][pos.x + 1] == WHITE && (*game).Board[pos.y - 2][pos.x + 2] == EMPTY)
                ) ||
                ((*game).CurrentPlayer == WHITE && pos.y < 7 && 
                    ( pos.x > 0 && (*game).Board[pos.y + 1][pos.x - 1] == EMPTY) ||
                    ( pos.x < 7 && (*game).Board[pos.y + 1][pos.x + 1] == EMPTY) ||
                    ( pos.x > 1 && pos.y < 6 && (*game).Board[pos.y + 1][pos.x - 1] == BLACK && (*game).Board[pos.y + 2][pos.x - 2] == EMPTY) ||
                    ( pos.x > 1 && pos.y < 6 && (*game).Board[pos.y + 1][pos.x + 1] == BLACK && (*game).Board[pos.y + 2][pos.x + 2] == EMPTY)
                )
            ) return 0;
    return 1;
}

int validMove(Game* game, Pos start, Pos end) {
    if (((*game).Board[start.y][start.x] == (*game).CurrentPlayer)) {
        if (
            (*game).CurrentPlayer == WHITE && 
            (end.y == (start.y + 1) && (end.x == (start.x + 1) || end.x == (start.x - 1)) && ((*game).Board[end.y][end.x] == EMPTY))
        ) return 0;
        if (
            (*game).CurrentPlayer == BLACK && 
            (end.y == (start.y - 1) && (end.x == (start.x + 1) || end.x == (start.x - 1)) && ((*game).Board[end.y][end.x] == EMPTY))
        ) return 0;
        if(
            (*game).CurrentPlayer == WHITE && 
            (end.y == (start.y + 2) &&
                (
                    (end.x == (start.x - 2) && (*game).Board[start.y + 1][start.x - 1] == BLACK && (*game).Board[end.y][end.x] ==  EMPTY) || 
                    (end.x == (start.x + 2) && (*game).Board[start.y + 1][start.x + 1] == BLACK && (*game).Board[end.y][end.x] == EMPTY)
                )
            )
        ) return 0;
        if(
            (*game).CurrentPlayer == BLACK && 
            (end.y == (start.y - 2) &&
                (
                    (end.x == (start.x - 2) && (*game).Board[start.y - 1][start.x - 1] == WHITE && (*game).Board[end.y][end.x] ==  EMPTY) || 
                    (end.x == (start.x + 2) && (*game).Board[start.y - 1][start.x + 1] == WHITE && (*game).Board[end.y][end.x] == EMPTY)
                )
            )
        ) return 0;
    }
    return 1;
}

int move(Game * game, Pos start, Pos end) {
    if (!validMove(game, start, end)) {
        int swap = (*game).Board[start.y][start.x];
        (*game).Board[start.y][start.x] = 0;
        (*game).Board[end.y][end.x] = swap;
        if (((*game).CurrentPlayer == BLACK && start.y > (end.y + 1)) || ((*game).CurrentPlayer == WHITE && start.y < (end.y - 1)))
            (*game).Board[end.y + ((end.y - start.y) < 0 ? +1 : - 1)][end.x + ((end.x - start.x) < 0 ? +1 : - 1)] = EMPTY;
        (*game).CurrentPlayer = (*game).CurrentPlayer == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;
        return 1;
    }
    return 0; 
}