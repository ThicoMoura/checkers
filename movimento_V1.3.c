#include <stdio.h> //Printf e Scanf
#include <stdlib.h> //

#define BRANCAS 'B' //Constante da peça Branca
#define PRETAS 'P' //Constante da peça Preta
#define DAMA_BRANCA 'O' //Constante da dama Branca
#define DAMA_PRETA '0' //Constante da dama Preta
#define VAZIO 'V' //Constante de espaço vazio
#define INVALIDO 'X' //Constante de espaço invalido

#define MAX_CONVERTIDO 8 //Constante do numero maximo do tabuleiro
#define MAX 7 //Constante do numero maximo da matriz
#define MIN_CONVERTIDO 1 //Constante do numero minimo do tabuleiro
#define MIN 0 //Constante do numero minimo da matriz

//Compiler version gcc  6.3.0

void cls(); //Prototipo da função para limpar a tela
void pause(); //Prototipo da função para pausar
int computador();
void gerar_tabuleiro(int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]); //Prototipo da função para gerar um novo tabuleiro
int validacao_peca(char, int, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]); //Prototipo da função para validar a linha e coluna inseridas pela jogador
int verifica_selecao(char, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int *linha_inicial, int *coluna_inicial); //Prototipo da função para verificar se é permitido selecionar a peça
int verifica_movimento(char, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int **linha_inicial, int **coluna_inicial, int *linha_final, int *coluna_final); //Prototipo da função para verificar se é permitido mover peça para a região
void exibir_tabuleiro(int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]); //Prototipo da função para exibir o tabuleiro
int conta_peca(char, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]); //Prototipo da função para contar a quantidade de peças
void selecionar_peca(char, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]); //Prototipo da função para selecionar peça
void movimento(char, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int *linha_inicial, int *coluna_inicial); //Prototipo da função para mover a peça
int verifica_empate(int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]); //Prototipo da função para verificação se o jogo empatou

int main()

{
  int peca_B, peca_P, tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], fim, empate;

  cls();

  gerar_tabuleiro(tabuleiro);

  peca_B = conta_peca(BRANCAS, tabuleiro);
  peca_P = conta_peca(PRETAS, tabuleiro);

  do

  {

    exibir_tabuleiro(tabuleiro);
    //pause();
    computador();
    printf("Vez das Brancas!\n");
    printf("Quantidade de pecas Brancas: %d\n", peca_B);
    selecionar_peca(BRANCAS, tabuleiro);
    cls();

    exibir_tabuleiro(tabuleiro);
    printf("Vez das Pretas!\n");
    printf("Quantidade de pecas Pretas: %d\n", peca_P);
    selecionar_peca(PRETAS, tabuleiro);
    cls();

    peca_P = conta_peca(PRETAS, tabuleiro);
    peca_B = conta_peca(BRANCAS, tabuleiro);
    empate = verifica_empate(tabuleiro);

    if (peca_B <= MIN && peca_P <= MIN && empate <= MIN)
    {
      fim = MIN_CONVERTIDO;
    }

  }while(fim >= MIN);

  exibir_tabuleiro(tabuleiro);
  if (peca_B > peca_P)
  {
    printf("Vitoria das pecas Brancas\n");
  }
  else
  {
    printf("Vitoria das pecas Pretas\n");
  }
  

  return 0;
}

void cls()

{
    /*caso seja no linux pode-se usar o printf desta maneira para limpar a tela pois usa a
    tabela do controlador de dispositivo ANSI para limpar a tela,
    para usar da mesma maneira no windows é necessário apenas
    inserir a linha device=c:\windows\system32\ansi.sys
    dentro de c:\config.sys e reiniciar o computador
    */
    //printf("\e[H\e[2J");

    #ifdef LINUX
    //código especifico para linux
    //system ("clear");//poderia ser este mas escolhi este outro pois é mais a cara do C
    printf("\e[H\e[2J");
    #elif defined WIN32
    //código específico para windows
    system ("cls");
    #else
    printf("\e[H\e[2J");
    #endif

}

void pause()

{
    #ifdef LINUX
    //código especifico para linux
    system ("read -p '$*'"); //poderia ser este mas escolhi este outro pois é mais a cara do C
    #elif defined WIN32
    //código específico para windows
    system ("pause");
    #else
    system ("read -p '$*'");
    #endif
}

int computador()

{
  srand(time(NULL));
  printf("%d ", rand() % 7);
}

void gerar_tabuleiro(int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO])

{
    int i, j;
	for (i = 0; i < 3; i++)

       if(i % 2 == MIN)

           for(j = MIN; j < MAX_CONVERTIDO; j++)

               if(j % 2 == MIN)

                   tabuleiro [i][j] = BRANCAS;

               else

                   tabuleiro [i][j] = INVALIDO;

       else

           for (j = MIN; j < MAX_CONVERTIDO; j++)

               if(j % 2 == MIN)

                   tabuleiro [i][j] = INVALIDO;

               else

                   tabuleiro [i][j] = BRANCAS;


   for (i = 3; i < 5; i++)

       if(i % 2 == MIN)

           for(j = MIN; j < MAX_CONVERTIDO; j++)

               if(j % 2 == MIN)

                   tabuleiro [i][j] = VAZIO;

               else

                   tabuleiro [i][j] = INVALIDO;

       else

           for (j = MIN; j < MAX_CONVERTIDO; j++)

               if(j % 2 == MIN)

                   tabuleiro [i][j] = INVALIDO;

               else

                   tabuleiro [i][j] = VAZIO;


   for (i = 5; i < MAX_CONVERTIDO; i++)

       if(i % 2 == MIN)

           for(j = MIN; j < MAX_CONVERTIDO; j++)

               if(j % 2 == MIN)

                   tabuleiro [i][j] = PRETAS;

               else

                   tabuleiro [i][j] = INVALIDO;

       else

           for (j = MIN; j < MAX_CONVERTIDO; j++)

               if(j % 2 == MIN)

                   tabuleiro [i][j] = INVALIDO;

               else

                   tabuleiro [i][j] = PRETAS;
}

int validacao_peca(char orientacao, int valor, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO])

{
  if (orientacao == 'l')
  {
    while(valor < MIN_CONVERTIDO || valor > MAX_CONVERTIDO)
    {
      cls();
      exibir_tabuleiro(tabuleiro);
      printf("Linha invalida, por favor, insira uma linha valida!\n");
      printf("Digite a linha desejada: ");
      scanf("%d", &valor);
    }
    return valor - 1;
  }
  else if (orientacao == 'c')
  {
    while(valor < MIN_CONVERTIDO || valor > MAX_CONVERTIDO)
    {
      cls();
      exibir_tabuleiro(tabuleiro);
      printf("Coluna invalida, por favor, insira uma coluna valida!\n");
      printf("Digite a coluna desejada: ");
      scanf("%d", &valor);
    }
    return valor - 1;
  }
}

int verifica_selecao(char peca, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int *linha_inicial, int *coluna_inicial)

{
  if (tabuleiro[*linha_inicial][*coluna_inicial] == BRANCAS && peca == BRANCAS)
  {
    if (tabuleiro[*linha_inicial + 1][*coluna_inicial - 1] == VAZIO || tabuleiro[*linha_inicial + 1][*coluna_inicial + 1] == VAZIO)
    {
      cls();
      exibir_tabuleiro(tabuleiro);

      printf("Posicao selecionada com sucesso!\n");
      return MIN_CONVERTIDO;
    }
    else if(tabuleiro[*linha_inicial + 1][*coluna_inicial - 1] == PRETAS || tabuleiro[*linha_inicial + 1][*coluna_inicial + 1] == PRETAS)
    {
      if (tabuleiro[*linha_inicial + 2][*coluna_inicial + 2] == VAZIO || tabuleiro[*linha_inicial + 2][*coluna_inicial - 2] == VAZIO)
      {
        cls();
        exibir_tabuleiro(tabuleiro);

        printf("Posicao selecionada com sucesso!\n");
        return MIN_CONVERTIDO;
      }
      else
      {
        cls();
        exibir_tabuleiro(tabuleiro);
        printf("Nao foi possivel selecionar esta posicao, pois nao ha jogadas permitidas para esta peca\n");
        return MIN;
      }
    }
    else
    {
      cls();
      exibir_tabuleiro(tabuleiro);
      printf("Nao foi possivel selecionar esta posicao, pois nao ha jogadas permitidas para esta peca\n");
      return MIN;
    }
  }
  else if (tabuleiro[*linha_inicial][*coluna_inicial] == PRETAS && peca == PRETAS)
  {
    if (tabuleiro[*linha_inicial - 1][*coluna_inicial - 1] == VAZIO || tabuleiro[*linha_inicial - 1][*coluna_inicial + 1] == VAZIO)
    {
      cls();
      exibir_tabuleiro(tabuleiro);

      printf("Posicao selecionada com sucesso!\n");
      return MIN_CONVERTIDO;
    }
    else if(tabuleiro[*linha_inicial - 1][*coluna_inicial - 1] == BRANCAS || tabuleiro[*linha_inicial - 1][*coluna_inicial + 1] == BRANCAS)
    {
      if (tabuleiro[*linha_inicial - 2][*coluna_inicial + 2] == VAZIO || tabuleiro[*linha_inicial - 2][*coluna_inicial - 2] == VAZIO)
      {
        cls();
        exibir_tabuleiro(tabuleiro);

        printf("Posicao selecionada com sucesso!\n");
        return MIN_CONVERTIDO;
      }
      else
      {
        cls();
        exibir_tabuleiro(tabuleiro);
        printf("Nao foi possivel selecionar esta posicao, pois nao ha jogadas permitidas para esta peca\n");
        return MIN;
      }
    }
    else
    {
      cls();
      exibir_tabuleiro(tabuleiro);
      printf("Nao foi possivel selecionar esta posicao, pois nao ha jogadas permitidas para esta peca\n");
      return MIN;
    }
  }
  else if (peca == BRANCAS || peca == PRETAS)
  {
    cls();
    exibir_tabuleiro(tabuleiro);
    printf("Nao foi possivel selecionar esta posicao, pois nao ha pecas nesta posicao\n");
    return MIN;
  }
  else
  {
    cls();
    exibir_tabuleiro(tabuleiro);
    printf("Erro\n");
    return MIN;
  }
}

int verifica_movimento(char peca, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int **linha_inicial, int **coluna_inicial, int *linha_final, int *coluna_final)

{
  if (peca == BRANCAS)
  {
    if (*coluna_final == **coluna_inicial + 1 && *linha_final == **linha_inicial + 1)
    {
      if (tabuleiro[*linha_final][*coluna_final] == VAZIO)
      {
        if (*linha_final == 7)
        {
          tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
          tabuleiro[*linha_final][*coluna_final] = DAMA_BRANCA;
          return MIN_CONVERTIDO;
        }
        else
        {
          tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
          tabuleiro[*linha_final][*coluna_final] = BRANCAS;
          return MIN_CONVERTIDO;
        }

      }
      else
      {
        cls();
        exibir_tabuleiro(tabuleiro);

        printf("Posicao invalida\nA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
        return MIN;
      }
    }
    else if(*coluna_final == **coluna_inicial - 1 && *linha_final == **linha_inicial + 1)
    {
      if (tabuleiro[*linha_final][*coluna_final] == VAZIO)
      {
        if (*linha_final == 7)
        {
          tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
          tabuleiro[*linha_final][*coluna_final] = DAMA_BRANCA;
          return MIN_CONVERTIDO;
        }
        else
        {
          tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
          tabuleiro[*linha_final][*coluna_final] = BRANCAS;
          return MIN_CONVERTIDO;
        }
      }
      else
      {
        cls();
        exibir_tabuleiro(tabuleiro);

        printf("Posicao invalida\nA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
        return MIN;
      }
    }
    else if(*coluna_final == **coluna_inicial + 2 && *linha_final == **linha_inicial + 2)
    {
      if(tabuleiro[**linha_inicial + 1][**coluna_inicial + 1] == PRETAS)
      {
        if (tabuleiro[*linha_final][*coluna_final] == VAZIO)
        {
          if (*linha_final == 7)
          {
            tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
            tabuleiro[**linha_inicial + 1][**coluna_inicial + 1] = VAZIO;
            tabuleiro[*linha_final][*coluna_final] = DAMA_BRANCA;
            return MIN_CONVERTIDO;
          }
          else
          {
            tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
            tabuleiro[**linha_inicial + 1][**coluna_inicial + 1] = VAZIO;
            tabuleiro[*linha_final][*coluna_final] = BRANCAS;
            return MIN_CONVERTIDO;
          }
        }
        else
        {
          cls();
          exibir_tabuleiro(tabuleiro);

          printf("Posicao invalida\nA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
          return MIN;
        }
      }
    }
    else if(*coluna_final == **coluna_inicial - 2 && *linha_final == **linha_inicial + 2)
    {
      if(tabuleiro[**linha_inicial + 1][**coluna_inicial - 1] == PRETAS)
      {
        if (tabuleiro[*linha_final][*coluna_final] == VAZIO)
        {
          if (*linha_final == 7)
          {
            tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
            tabuleiro[**linha_inicial + 1][**coluna_inicial - 1] = VAZIO;
            tabuleiro[*linha_final][*coluna_final] = DAMA_BRANCA;
            return MIN_CONVERTIDO;
          }
          else
          {
            tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
            tabuleiro[**linha_inicial + 1][**coluna_inicial - 1] = VAZIO;
            tabuleiro[*linha_final][*coluna_final] = BRANCAS;
            return MIN_CONVERTIDO;
          }
        }
        else
        {
          cls();
          exibir_tabuleiro(tabuleiro);

          printf("Posicao invalida\nA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
          return MIN;
        }
      }
    }
    else
    {
      cls();
      exibir_tabuleiro(tabuleiro);

      printf("Posicao invalida\nA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
      return MIN;
    }
  }
  else if(peca == PRETAS)
  {
    if (*coluna_final == **coluna_inicial + 1 && *linha_final == **linha_inicial - 1)
    {
      if (tabuleiro[*linha_final][*coluna_final] == VAZIO)
      {
        if (*linha_final == 0)
        {
          tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
          tabuleiro[*linha_final][*coluna_final] = DAMA_PRETA;
          return MIN_CONVERTIDO;
        }
        else
        {
          tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
          tabuleiro[*linha_final][*coluna_final] = PRETAS;
          return MIN_CONVERTIDO;
        }
      }
      else
      {
        printf("Posicao invalida\nA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
        return MIN;
      }
    }
    else if(*coluna_final == **coluna_inicial - 1 && *linha_final == **linha_inicial - 1)
    {
      if (tabuleiro[*linha_final][*coluna_final] == VAZIO)
      {
        if (*linha_final == 0)
        {
          tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
          tabuleiro[*linha_final][*coluna_final] = DAMA_PRETA;
          return MIN_CONVERTIDO;
        }
        else
        {
          tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
          tabuleiro[*linha_final][*coluna_final] = PRETAS;
          return MIN_CONVERTIDO;
        }
      }
      else
      {
        printf("Posicao invalida\nA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
        return MIN;
      }
    }
    else if(*coluna_final == **coluna_inicial + 2 && *linha_final == **linha_inicial - 2)
    {
      if(tabuleiro[**linha_inicial - 1][**coluna_inicial + 1] == BRANCAS)
      {
        if (tabuleiro[*linha_final][*coluna_final] == VAZIO)
        {
          if (*linha_final == 0)
          {
            tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
            tabuleiro[**linha_inicial - 1][**coluna_inicial + 1] = VAZIO;
            tabuleiro[*linha_final][*coluna_final] = DAMA_PRETA;
            return MIN_CONVERTIDO;
          }
          else
          {
            tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
            tabuleiro[**linha_inicial - 1][**coluna_inicial + 1] = VAZIO;
            tabuleiro[*linha_final][*coluna_final] = PRETAS;
            return MIN_CONVERTIDO;
          }
        }
        else
        {
          printf("Posicao invalida\nA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
          return MIN;
        }
      }
    }
    else if(*coluna_final == **coluna_inicial - 2 && *linha_final == **linha_inicial - 2)
    {
      if(tabuleiro[**linha_inicial - 1][**coluna_inicial - 1] == BRANCAS)
      {
        if (tabuleiro[*linha_final][*coluna_final] == VAZIO)
        {
          if (*linha_final == 0)
          {
            tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
            tabuleiro[**linha_inicial - 1][**coluna_inicial - 1] = VAZIO;
            tabuleiro[*linha_final][*coluna_final] = DAMA_PRETA;
            return MIN_CONVERTIDO;
          }
          else
          {
            tabuleiro[**linha_inicial][**coluna_inicial] = VAZIO;
            tabuleiro[**linha_inicial - 1][**coluna_inicial - 1] = VAZIO;
            tabuleiro[*linha_final][*coluna_final] = PRETAS;
            return MIN_CONVERTIDO;
          }
        }
        else
        {
          printf("Posicao invalida\nA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
          return MIN;
        }
      }
    }
    else
    {
      cls();
      exibir_tabuleiro(tabuleiro);

      printf("Posicao invalida\nA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
      return MIN;
    }
  }
}

void exibir_tabuleiro(int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO])

{

    int i, j;

   printf(" +---+---+---+---+---+---+---+---+\n");

   for (i = MAX; i >= MIN; --i)

   {

       printf("%d", i+MIN_CONVERTIDO);

       printf("| ");

       for (j = MIN; j < MAX_CONVERTIDO; ++j)

       {

           if(tabuleiro[i][j] == INVALIDO && j == MIN|| tabuleiro[i][j] == VAZIO && j == MIN)

               printf("  |");

           else if(tabuleiro[i][j] == INVALIDO && j == MAX|| tabuleiro[i][j] == VAZIO && j == MAX)

               printf("  ");

           else if (tabuleiro[i][j] == INVALIDO && j != MAX && j != MIN|| tabuleiro[i][j] == VAZIO && j != MAX && j != MIN)

               printf("   |");

           else if(tabuleiro[i][j] == BRANCAS && j == MIN || tabuleiro[i][j] == PRETAS && j == MIN || tabuleiro[i][j] == DAMA_PRETA && j == MIN || tabuleiro[i][j] == DAMA_BRANCA && j == MIN )

               printf("%c |", tabuleiro [i][j]);

           else if(tabuleiro[i][j] == BRANCAS && j == MAX || tabuleiro[i][j] == PRETAS && j == MAX || tabuleiro[i][j] == DAMA_PRETA && j == MAX || tabuleiro[i][j] == DAMA_BRANCA && j == MAX)

               printf(" %c", tabuleiro [i][j]);

           else if (tabuleiro[i][j] == BRANCAS && j != MAX && j != MIN || tabuleiro[i][j] == PRETAS && j != MAX && j != MIN || tabuleiro[i][j] == DAMA_PRETA && j != MAX && j != MIN || tabuleiro[i][j] == DAMA_BRANCA && j != MAX && j != MIN)

               printf(" %c |", tabuleiro [i][j]);

       }

       printf(" |");

       printf("\n");

       printf(" +---+---+---+---+---+---+---+---+\n");

   }

      printf("   1   2   3   4   5   6    7   8\n\n");
}

int conta_peca(char peca, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO])

{

  int contador = MIN, i, j;

  switch (peca){
    case BRANCAS:

      for (i = MIN; i < MAX_CONVERTIDO; ++i)
        for (j = MIN; j <MAX_CONVERTIDO; j++)
          if(tabuleiro [i][j] == BRANCAS || tabuleiro [i][j] == DAMA_BRANCA)
            contador ++;

      return contador;

      break;

    case PRETAS:

      for (i = MIN; i < MAX_CONVERTIDO; ++i)
        for (j = MIN; j <MAX_CONVERTIDO; j++)
          if(tabuleiro [i][j] == PRETAS || tabuleiro [i][j] == DAMA_PRETA)
            contador ++;

      return contador;

      break;
  }
}

void selecionar_peca(char peca, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO])

{
    int retorno = MIN, linha_inicial, coluna_inicial;

    if(peca == BRANCAS)

    {
      do

      {

        printf("Digite a linha da peca que deseja selecionar: ");
        scanf("%d", &linha_inicial);

        linha_inicial = validacao_peca('l', linha_inicial, tabuleiro);
        

        printf("Digite a coluna da peca que deseja selecionar: ");
        scanf("%d", &coluna_inicial);

        coluna_inicial = validacao_peca('c', coluna_inicial, tabuleiro);

        retorno = verifica_selecao(BRANCAS, tabuleiro, &linha_inicial, &coluna_inicial);

      }while(retorno <= MIN);

      movimento(BRANCAS, tabuleiro, &linha_inicial, &coluna_inicial);

    }

    else

    {

      do

      {
        printf("Digite a linha da peca que deseja selecionar: ");
        scanf("%d", &linha_inicial);

        linha_inicial = validacao_peca('l', linha_inicial, tabuleiro);
        

        printf("Digite a coluna da peca que deseja selecionar: ");
        scanf("%d", &coluna_inicial);

        coluna_inicial = validacao_peca('c', coluna_inicial, tabuleiro);

        retorno = verifica_selecao(PRETAS, tabuleiro, &linha_inicial, &coluna_inicial);

      }while(retorno <= MIN);

      movimento(PRETAS, tabuleiro, &linha_inicial, &coluna_inicial);

    }

}

void movimento (char peca, int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int *linha_inicial, int *coluna_inicial)

{
  int retorno = MIN, linha_final, coluna_final;

  if (peca == BRANCAS)
  
  {
    do

    {

      printf("Digite a linha para onde deseja mover a peca: ");
      scanf("%d", &linha_final);

      linha_final = validacao_peca('l', linha_final, tabuleiro);
      

      printf("Digite a coluna para onde deseja mover a peca: ");
      scanf("%d", &coluna_final);

      coluna_final = validacao_peca('c', coluna_final, tabuleiro);

      retorno = verifica_movimento(BRANCAS, tabuleiro, &linha_inicial, &coluna_inicial, &linha_final, &coluna_final);

    }while(retorno <= MIN);
  }

  else 

  {
    do

    {
      printf("Digite a linha para onde deseja mover a peca: ");
      scanf("%d", &linha_final);

      linha_final = validacao_peca('l', linha_final, tabuleiro);
      

      printf("Digite a coluna para onde deseja mover a peca: ");
      scanf("%d", &coluna_final);

      coluna_final = validacao_peca('c', coluna_final, tabuleiro);

      retorno = verifica_movimento(PRETAS, tabuleiro, &linha_inicial, &coluna_inicial, &linha_final, &coluna_final);


    }while(retorno <= MIN);

  }

}

int verifica_empate(int tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO])

{
  return 1;
}