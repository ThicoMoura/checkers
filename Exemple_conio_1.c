#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio2.h>

void Menu_principal();
void desenhar_op();
void back_menu();
int tabuleiro ();
void nome_jogador();


int main()
{
    setlocale(LC_ALL,"");
    Menu_principal();
}



// Função para Menu
void Menu_principal()
{

    char opcao;
    textbackground(BLUE);
    textcolor(WHITE);
    clrscr();
    setlocale(LC_ALL,"");
    desenhar_op();
    opcao = getch();
    switch(opcao)
    {
        case 'J':
        case 'j':
        nome_jogador();
        tabuleiro ();


        case 'O':
        case 'o':


        case 'S':
        case 's':
            exit;
            break;

        default :
            printf("\n\n Opção Invalida.\n\n Deseja Voltar ao menu Inicial (S/N)");
            back_menu();
    }

}

//funcao que desenha o opções do jogo
void desenhar_op()
{
    gotoxy(28,5);
    printf("Bem Vindo ao Jogo de Xadrez\n\n\n\n\n");
    textcolor(WHITE);
    gotoxy(26,10);
    printf("- - -   Opções de Jogo    - - -");
    gotoxy(32,14);
    printf("[J]- player vs player");
    gotoxy(32,16);
    printf("[O]-opções do jogo");
    gotoxy(32,18);
    printf("[s]-Sair do jogo ");
}

// funcao voltar ao menu
void back_menu()
{
    char op;
    op = getch();

    switch(op)
    {
        case 'S':
        case 's':
            clrscr();
            system("PAUSE");
            Menu_principal();
            break;

        case 'N':
        case 'n':
            exit;
            break;

            default:
                printf("\n Opção invalida. O Programa vai encerrar!\n\n");
                exit;
                break;
    }
}

int tabuleiro ()
{

    int tab[10][10],x, y ,i;
        clrscr();
        i=6;
    for(x=1; x<=10; x++)
    {
        i++;
        gotoxy(30,i);
    for(y=1; y<=10; y++)
    {
        if( (x+y)%2 == 0 ) textcolor(WHITE);
            else textcolor(BLACK);
                cprintf("%c%c",219,219);
    }
    }
    gotoxy(20,20);
    printf ("introduza as coordenadas a inprimir\n");
    gotoxy(20,21);
    scanf("%d %d",&x,&y);
    tab[x][y];
    printf("**", tab[x][y]);
}

void nome_jogador()
{
    char P1[25];
    char P2[25];
    clrscr();
    printf("\n Introduza o Nome do Primeiro jogador.\n");
    gotoxy(2,4);
    gets(P1);
    printf("\n Introduza o Nome do Segundo jogador.\n");
    gotoxy(2,8);
    gets(P2);
}
