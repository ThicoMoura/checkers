#include <stdio.h>
#include <stdlib.h>

//Compiler version gcc  6.3.0

int li, lf, ci, cf, m[8][8], i, j;

void tab();
void exibir_tabuleiro();
int conta_peca(char);
void movimento(char);

int main()
{
  int peca_B, peca_P;
  system("clear");

	tab();

  peca_B = conta_peca('B');
  peca_P = conta_peca('P');

  do{

    exibir_tabuleiro();
    movimento('B');
    peca_B = conta_peca('B');
    system("clear");

    exibir_tabuleiro();
    movimento('P');
    peca_P = conta_peca('P');
    system("clear");

  }while(peca_B > 0 || peca_P > 0);

  exibir_tabuleiro();
  return 0;
}

void tab(){
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

void exibir_tabuleiro(){

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

int conta_peca(char c){

  int count = 0;

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

void movimento (char c){
	int p, f;

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
        if(m[li][ci] == 'B'){

          system("clear");
          exibir_tabuleiro();

          printf("Posicao selecionada com sucesso!\n");

          do{

            printf("Digite a linha para onde deseja mover a peca: ");
            scanf("%d", &lf);
		lf -= 1;
              
            system("clear");
            exibir_tabuleiro();

            printf("Digite a coluna para onde deseja mover a peca: ");
            scanf("%d", &cf);
            cf -= 1;
            
            if(cf == ci + 1 && ci != 7 || cf == ci - 1 && ci != 0)
              if(m[lf][cf] == 'V'){
                m[li][ci] = 'V';
                m[lf][cf] = 'B';
                f = 1;
              }
            else{
              
              system("clear");
              exibir_tabuleiro();

              printf("Posicao invalida, por favor, insira novamente os valores!\n");
            }
            
          }while(f == 0);
          
          p = 1;
        } else{

          system("clear");
          exibir_tabuleiro();

          printf("Posicao invalida, por favor insira novamente os valores!!\n");
          p = 0;
        }
      }while(p == 0);

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
        if(m[li][ci] == 'P'){
          do{
            if(m[li][ci] == 'T'){
              system("clear");
              exibir_tabuleiro();
              printf("Posicao selecionada com sucesso!\nDigite a linha para onde deseja mover a peca: ");
              scanf("%d", &lf);
            }else{
              system("clear");
              exibir_tabuleiro();
              printf("Posicao selecionada com sucesso!\n");
              lf = li - 1;
            }
              
            printf("Digite a coluna para onde deseja mover a peca: ");
            scanf("%d", &cf);
            cf -= 1;
            
            if(cf == ci + 1 && ci != 7 || cf == ci - 1 && ci != 0)
              if(m[lf][cf] == 'V'){
                m[li][ci] = 'V';
                m[lf][cf] = 'P';
                f = 1;
              }
            
          }while(f == 0);
          
          p = 1;
        } else{
          system("clear");
          exibir_tabuleiro();
          printf("Posicao invalida, por favor insira novamente linha e coluna de uma posicao valida!\n");
          p = 0;
        }
      }while(p == 0);

      break;
  }
}
