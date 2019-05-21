#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

char tab [8][8], Jogar;
int i, j, c;

void novo_tabuleiro();
void tabuleiro();
void inicio();
void jogada(int);

int main()
{
    setlocale(LC_ALL,"");
    system("reset");
    inicio();
    do{

        scanf("%d", &c);

        switch( c ){

            case 1:
                    novo_tabuleiro();

                    system("clear");

                    tabuleiro();

                    system("sleep 40");

                break;

            case 2:
                tabuleiro();
                break;

            case 3:

                printf("Tchau!!!\n");
                break;

            default:

                system("clear");

                printf("Valor invalido\n");
                printf("\nInsira um valor valido: ");
        }
    }while(c < 1 || c > 3);

    return 0;
}

void novo_tabuleiro()
{
    for (i = 0; i < 3; i++)
        if(i%2 == 0)
            for(j = 0; j < 8; j++)
                if(j%2 == 0)
                    tab [i][j] = 'X';
                else
                    tab [i][j] = 'P';
        else
            for (j = 0; j < 8; j++)
                if(j%2 == 0)
                    tab [i][j] = 'P';
                else
                    tab [i][j] = 'X';

    for (i = 3; i < 5; i++)
        if(i%2 == 0)
            for(j = 0; j < 8; j++)
                if(j%2 == 0)
                    tab [i][j] = 'X';
                else
                    tab [i][j] = 'V';
        else
            for (j = 0; j < 8; j++)
                if(j%2 == 0)
                    tab [i][j] = 'V';
                else
                    tab [i][j] = 'X';

    for (i = 5; i < 8; i++)
        if(i%2 == 0)
            for(j = 0; j < 8; j++)
                if(j%2 == 0)
                    tab [i][j] = 'X';
                else
                    tab [i][j] = 'B';
        else
            for (j = 0; j < 8; j++)
                if(j%2 == 0)
                    tab [i][j] = 'B';
                else
                    tab [i][j] = 'X';
}

void tabuleiro()
{
    printf("   1   2   3   4   5   6   7   8  \n");
    printf(" +---+---+---+---+---+---+---+---+\n");
    for (i = 0; i < 8; ++i)
    {
        printf("%d", i+1);
        printf("| ");
        for (j = 0; j < 8; ++j)
        {
            if(tab[i][j] == 'X' && j == 0|| tab[i][j] == 'V' && j == 0)
                printf("  |");
            else if(tab[i][j] == 'X' && j == 7|| tab[i][j] == 'V' && j == 7)
                printf("  ");
            else if (tab[i][j] == 'X' && j != 7 && j != 0|| tab[i][j] == 'V' && j != 7 && j != 0)
                printf("   |");
            else if(tab[i][j] == 'B' && j == 0|| tab[i][j] == 'P' && j == 0)
                printf("%c |", tab [i][j]);
            else if(tab[i][j] == 'B' && j == 7|| tab[i][j] == 'P' && j == 7)
                printf(" %c", tab [i][j]);
            else if (tab[i][j] == 'B' && j != 7 && j != 0|| tab[i][j] == 'P' && j != 7 && j != 0)
                printf(" %c |", tab [i][j]);
        }
        printf(" |");
        printf("%d", i+1);
        printf("\n");
        printf(" +---+---+---+---+---+---+---+---+\n");
    }
    printf("   1   2   3   4   5   6   7   8  \n");
}

void inicio()
{

    system("clear");

    printf("+---------------------------------------------------------+\n");
    printf("|                                                         |\n");
    printf("|              Bem Vindo ao Jogo de Dama                  |\n");
    printf("|                                                         |\n");
    printf("|                      Regras:                            |\n");
    printf("|  1- Este jogo pode ser jogado de um a dois jogadores;   |\n");
    printf("|  2- As peças andam somente nas diagonais;               |\n");
    printf("|  3- Somente damas podem mais de uma casa;               |\n");
    printf("|  4- Para a captura de uma peça, a casa subsequente da   |\n");
    printf("|     diagonal deve estar vazia.                          |\n");
    printf("|  5- Somente sera considerado vitoria se as pecas de um  |\n");
    printf("|     dos jogadores acabar                                |\n");
    printf("|  6-                                                     |\n");
    printf("|                                                         |\n");
    printf("|                                                         |\n");
    printf("+---------------------------------------------------------+\n");

    system("sleep 40");
    system("clear");

    printf("+---------------------------------------------------------+\n");
    printf("|                                                         |\n");
    printf("|               Escolha o modo de jogo:                   |\n");
    printf("|                                                         |\n");
    printf("|    | 1- Um jogador | 2- Dois Jogadores | 3- Sair |      |\n");
    printf("|                                                         |\n");
    printf("+---------------------------------------------------------+\n");
    printf("+ Escolha um modo de jogo: ");
}

void jogada(int peca){
    int posi_linha, posi_coluna, movi_linha, movi_coluna, result;

    do{
        switch ( peca ){
            case 1:
                do {
                    printf("Digite a linha da peca que deseja mover: ");

                    scanf("%d", &posi_linha);

                    posi_linha -= 1;

                    if (posi_linha < 0 || posi_linha > 7)
                        do{
                            printf("Digite a linha da peca que deseja mover: ");
                            scanf("%d", &posi_linha);
                            posi_linha -= 1;
                        }while(posi_linha < 0 || posi_linha > 7);

                    printf("Digite a coluna da peca que deseja mover: ");

                    scanf("%d", &posi_coluna);

                    posi_coluna -= 1;

                    if (posi_coluna < 0 || posi_coluna > 7)
                        do{
                            printf("Digite a coluna da peca que deseja mover: ");
                            scanf("%d", &posi_coluna);
                            posi_coluna -= 1;
                        }while(posi_coluna < 0 || posi_coluna > 7);

                }while (tab[posi_linha][posi_coluna] == 'P' || tab[posi_linha][posi_coluna] == 'T');

                break;

            case 2:

                printf("Digite a linha da peca que deseja mover: ");

                scanf("%d", &posi_linha);

                posi_linha -= 1;

                if (posi_linha < 0 || posi_linha > 7)
                    do{
                        printf("Digite a linha da peca que deseja mover: ");
                        scanf("%d", &posi_linha);
                        posi_linha -= 1;
                    }while(posi_linha < 0 || posi_linha > 7);

                printf("Digite a coluna da peca que deseja mover: ");

                scanf("%d", &posi_coluna);

                posi_coluna -= 1;

                if (posi_coluna < 0 || posi_coluna > 7)
                    do{
                        printf("Digite a coluna da peca que deseja mover: ");
                        scanf("%d", &posi_coluna);
                        posi_coluna -= 1;
                    }while(posi_coluna < 0 || posi_coluna > 7);

                break;
        }
    }while(result == 1);

    do{

    }while(result == 1);
}
