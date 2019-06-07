#include <stdio.h>
#include <stdlib.h>

//Compiler version gcc  6.3.0

void tab(int m[8][8]);
void exibir_tabuleiro(int m[8][8]);
int conta_peca(char, int m[8][8]);
void selecionar_peca(char, int m[8][8]);
void movimento(char, int m[8][8], int *li, int *ci);

int main()
{
  int peca_B, peca_P, m[8][8];
  system("cls");

  tab(m);

  peca_B = conta_peca('B', m);
  peca_P = conta_peca('P', m);

  do{

    exibir_tabuleiro(m);
    peca_B = conta_peca('B', m);
    printf("Quantidade de pecas Brancas: %d\n", peca_B);
    selecionar_peca('B', m);
    peca_B = conta_peca('B', m);
    system("cls");

    exibir_tabuleiro(m);
    peca_P = conta_peca('P', m);
    printf("Quantidade de pecas Pretas: %d\n", peca_P);
    selecionar_peca('P', m);
    peca_P = conta_peca('P', m);
    system("cls");

  }while(peca_B > 0 || peca_P > 0);

  exibir_tabuleiro(m);
  return 0;
}

void tab(int m[8][8]){
    int i, j;
	for (i = 0; i < 3; i++)

       if(i%2 == 0)

           for(j = 0; j < 8; j++)

               if(j%2 == 0)

                   m [i][j] = 'B';

               else

                   m [i][j] = 'X';

       else

           for (j = 0; j < 8; j++)

               if(j%2 == 0)

                   m [i][j] = 'X';

               else

                   m [i][j] = 'B';


   for (i = 3; i < 5; i++)

       if(i%2 == 0)

           for(j = 0; j < 8; j++)

               if(j%2 == 0)

                   m [i][j] = 'V';

               else

                   m [i][j] = 'X';

       else

           for (j = 0; j < 8; j++)

               if(j%2 == 0)

                   m [i][j] = 'X';

               else

                   m [i][j] = 'V';


   for (i = 5; i < 8; i++)

       if(i%2 == 0)

           for(j = 0; j < 8; j++)

               if(j%2 == 0)

                   m [i][j] = 'P';

               else

                   m [i][j] = 'X';

       else

           for (j = 0; j < 8; j++)

               if(j%2 == 0)

                   m [i][j] = 'X';

               else

                   m [i][j] = 'P';


}

void exibir_tabuleiro(int m[8][8]){

    int i, j;

   printf(" +---+---+---+---+---+---+---+---+\n");

   for (i = 7; i >= 0; --i)

   {

       printf("%d", i+1);

       printf("| ");

       for (j = 0; j < 8; ++j)

       {

           if(m[i][j] == 'X' && j == 0|| m[i][j] == 'V' && j == 0)

               printf("  |");

           else if(m[i][j] == 'X' && j == 7|| m[i][j] == 'V' && j == 7)

               printf("  ");

           else if (m[i][j] == 'X' && j != 7 && j != 0|| m[i][j] == 'V' && j != 7 && j != 0)

               printf("   |");

           else if(m[i][j] == 'B' && j == 0|| m[i][j] == 'P' && j == 0)

               printf("%c |", m [i][j]);

           else if(m[i][j] == 'B' && j == 7|| m[i][j] == 'P' && j == 7)

               printf(" %c", m [i][j]);

           else if (m[i][j] == 'B' && j != 7 && j != 0|| m[i][j] == 'P' && j != 7 && j != 0)

               printf(" %c |", m [i][j]);

       }

       printf(" |");

       printf("\n");

       printf(" +---+---+---+---+---+---+---+---+\n");

   }

      printf("   1   2   3   4   5   6    7   8\n\n");
}

int conta_peca(char c, int m[8][8]){

  int count = 0, i, j;

  switch ( c ){
    case 'B':

      for (i = 0; i < 8; ++i)
        for (j = 0; j <8; j++)
          if(m [i][j] == 'B' || m [i][j] == 'T')
            count ++;

      return count;

      break;

    case 'P':

      for (i = 0; i < 8; ++i)
        for (j = 0; j <8; j++)
          if(m [i][j] == 'P' || m [i][j] == 'Q')
            count ++;

      return count;

      break;
  }
}

void selecionar_peca(char c, int t[8][8]){
    int p = 0, li, ci;

    switch ( c ){
    case 'B':
      printf("Vez das Brancas!\n");
      do{
        printf("Qual linha da peca que deseja mover: ");
        scanf("%d", &li);
        while(li < 1 || li > 8){
          printf("Linha invalida\nPor favor, digite uma linha valida: ");
          scanf("%d", &li);
        }
        li -= 1;
        printf("Qual coluna da peca que deseja mover: ");
        scanf("%d", &ci);
        while(ci < 1 || ci > 8){
          printf("Coluna invalida\nPor favor, digite uma coluna valida: ");
          scanf("%d", &ci);
        }
        ci -= 1;
        if(t[li][ci] == 'B' && t[li+1][ci-1] == 'V' || t[li][ci] == 'B' && t[li+1][ci+1] == 'V' || t[li][ci] == 'B' && t[li+1][ci+1] == 'P' && t[li + 2][ci + 2] == 'V' || t[li][ci] == 'B' && t[li+1][ci-1] == 'P' && t[li + 2][ci - 2] == 'V'){

          system("cls");
          exibir_tabuleiro(t);

          printf("Posicao selecionada com sucesso!\n");

          p = 1;
        } else{

          system("cls");
          exibir_tabuleiro(t);

          printf("Posicao invalida, por favor insira novamente os valores!!\n");
          p = 0;
        }
      }while(p <= 0);

      movimento('B', t, &li, &ci);

      break;

    case 'P':

      printf("Vez das Pretas!\n");
      do{
        printf("Qual linha da peca que deseja mover: ");
        scanf("%d", &li);
        while(li < 1 || li > 8){
          printf("Linha invalida\nPor favor, digite uma linha valida: ");
          scanf("%d", &li);
        }
        li -= 1;
        printf("Qual coluna da peca que deseja mover: ");
        scanf("%d", &ci);
        while(ci < 1 || ci > 8){
          printf("Coluna invalida\nPor favor, digite uma coluna valida: ");
          scanf("%d", &ci);
        }
        ci -= 1;
        if(t[li][ci] == 'P' && t[li-1][ci-1] == 'V' || t[li][ci] == 'P' && t[li-1][ci+1] == 'V' || t[li][ci] == 'P' && t[li-1][ci+1] == 'B' && t[li - 2][ci + 2] == 'V' || t[li][ci] == 'P' && t[li-1][ci-1] == 'B' && t[li - 2][ci - 2] == 'V'){

          system("cls");
          exibir_tabuleiro(t);

          printf("Posicao selecionada com sucesso!\n");

          p = 1;
        } else{

          system("cls");
          exibir_tabuleiro(t);

          printf("Posicao invalida, por favor insira novamente os valores!!\n");
          p = 0;
        }
      }while(p <= 0);

      movimento('P', t, &li, &ci);

      break;
  }
}

void movimento (char c, int t[8][8], int *li, int *ci){
  int f = 0, lf, cf;

  switch ( c ){
    case 'B':
          do{

            do{

              printf("Digite a linha para onde deseja mover a peca: ");
              scanf("%d", &lf);

              if (lf < 1 || lf > 8)
              {
                system("cls");
                exibir_tabuleiro(t);
                printf("Linha invalida, por favor, insira uma linha valida!\n");
              }

            }while(lf < 1 || lf > 8);
            lf -= 1;
            do{

              printf("Digite a coluna para onde deseja mover a peca: ");
              scanf("%d", &cf);

              if (cf < 1 || cf > 8)
              {
                system("cls");
                exibir_tabuleiro(t);
                printf("Coluna invalida, por favor, insira uma coluna valida!\n");
              }

            }while(cf < 1 || cf > 8);
            cf -= 1;

            if(cf == *ci + 1 && cf <= 7 && lf == *li +1 && lf <= 7 || cf == *ci - 1 && cf >= 0 && lf == *li +1 && lf <= 7){
              if(t[lf][cf] == 'V'){
                t[*li][*ci] = 'V';
                if (lf == 7)
                {
                  t[lf][cf] = 'T';
                }else{
                  t[lf][cf] = 'B';
                }
                f = 1;
              }else{
                system("cls");
                exibir_tabuleiro(t);

                printf("Posicao invalida, por favor, insira novamente os valores!\n");
              }
            }else if(cf == *ci + 2 && cf <= 7 && lf == *li + 2 && lf <= 7 || cf == *ci - 2 && cf >= 0 && lf == *li + 2 && lf <= 7){
              if(t[lf][cf] == 'V' && t[*li + 1][*ci - 1] == 'P'){
                t[*li + 1][*ci - 1] = 'V';
                t[*li][*ci] = 'V';
                if (lf == 7)
                {
                  t[lf][cf] = 'T';
                }else{
                  t[lf][cf] = 'B';
                }
                f = 1;
              }else if (t[lf][cf] == 'V' && t[*li + 1][*ci + 1] == 'P'){
                t[*li + 1][*ci + 1] = 'V';
                t[*li][*ci] = 'V';
                if (lf == 7)
                {
                  t[lf][cf] = 'T';
                }else{
                  t[lf][cf] = 'B';
                }
                f = 1;
              }else{
                system("cls");
                exibir_tabuleiro(t);

                printf("Não é possivel capturar essa peça.\n");
              }
            }else{

              system("cls");
              exibir_tabuleiro(t);

              printf("Posicao invalida, por favor, insira novamente os valores!\n");
            }

          }while(f <= 0);

      break;

    case 'P':

          do{

            do{

              printf("Digite a linha para onde deseja mover a peca: ");
              scanf("%d", &lf);

              if (lf < 1 || lf > 8)
              {
                system("cls");
                exibir_tabuleiro(t);
                printf("Linha invalida, por favor, insira uma linha valida!\n");
              }

            }while(lf < 1 || lf > 8);
            lf -= 1;
            do{

              printf("Digite a coluna para onde deseja mover a peca: ");
              scanf("%d", &cf);

              if (cf < 1 || cf > 8)
              {
                system("cls");
                exibir_tabuleiro(t);
                printf("Coluna invalida, por favor, insira uma coluna valida!\n");
              }

            }while(cf < 1 || cf > 8);
            cf -= 1;

            if(cf == *ci + 1 && cf <= 7 && lf == *li - 1 && lf >= 0 || cf == *ci - 1 && cf >= 0 && lf == *li - 1 && lf >= 0){
              if(t[lf][cf] == 'V'){
                t[*li][*ci] = 'V';
                t[lf][cf] = 'P';
                f = 1;
              }else{
                system("cls");
                exibir_tabuleiro(t);

                printf("Posicao invalida, por favor, insira novamente os valores!\n");
              }
            }else if(cf == *ci + 2 && cf <= 7 && lf == *li - 2 && lf <= 1 || cf == *ci - 2 && cf >= 0 && lf == *li - 2 && lf <= 1){
              if(t[lf][cf] == 'V' && t[*li - 1][*ci - 1] == 'B'){
                t[*li - 1][*ci - 1] = 'V';
                t[*li][*ci] = 'V';
                t[lf][cf] = 'P';
                f = 1;
              }else if (t[lf][cf] == 'V' && t[*li - 1][*ci + 1] == 'B'){
                t[*li - 1][*ci + 1] = 'V';
                t[*li][*ci] = 'V';
                t[lf][cf] = 'P';
                f = 1;
              }else{
                system("cls");
                exibir_tabuleiro(t);

                printf("Não é possivel capturar essa peça.\n");
              }
            }else{

              system("cls");
              exibir_tabuleiro(t);

              printf("Posicao invalida, por favor, insira novamente os valores!\n");
            }

          }while(f <= 0);

      break;
  }
}
