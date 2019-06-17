#include <stdio.h> //Printf e Scanf
#include <stdlib.h> //Comando rand e srand para a pseudo inteligencia artificial
#include <time.h> // time NULL no setar a semente com o tempo em nulo
#include <locale.h> // setar liguagem padrão portugues

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

void cls(); // Função limpar tela
void pause(); // Função pausar
void language(); // Função para resetar o linux (funcionar locale.h)
int menu(); //Função do menu
void gerar_tabuleiro(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]); // Função que gera um novo tabuleiro
void exibir_tabuleiro(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]); // Função para exibir tabuleiro
int empate_veri(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int **contador_sucessivo, int **contador_pretas, int **contador_brancas, int, int); // função verifica se há empate
int movimento_dama(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int, int, int ); // função verifica se há empate de vinte jogadas sucessivas de dama
int empate_3_dama(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], char, char); // função que verifica se há empate com 3 damas contra uma
int empate_mesmo_movimento(int ,int ,int ,int , int, int movimento_peca[4]); // função que verifica se a empate com 3 movimentos repetidos
int conta_peca(char, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]); // Função para verificar a quantidade de peças
char verifica_dama(char, int); // Função para virar dama
int selecionar_computador(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], char, int, int); // Função para selecionar peça
void movimento_computador(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], char, int, int, int, int); // Função de movimento de peça
int verifica_captura(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], char, int, int, int, int); // Função que verifica a captura
void computador(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]); // Função que faz a jogada do computador
int validacao_peca(char, int, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]); //Prototipo da função para validar a linha e coluna inseridas pela jogador
int verifica_selecao(char, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int *linha_inicial, int *coluna_inicial); //Prototipo da função para verificar se é permitido selecionar a peça
int verifica_movimento(char, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int **linha_inicial, int **coluna_inicial, int *linha_final, int *coluna_final); //Prototipo da função para verificar se é permitido mover peça para a região
int selecionar_peca(char, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int *empate, int *contador_sucessivo, int *contador_brancas, int *contador_pretas, int *contador_mesmo_movimento, int movimento_peca[4]); //Prototipo da função para selecionar peça
void movimento(char, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int *linha_inicial, int *coluna_inicial, int **empate, int **contador_mesmo_movimento, int movimento_peca[4]); //Prototipo da função para mover a peça

int main ()
{
	int jogo, brancas, pretas, empate = 1, derrota = 1; // modificadores de jogo
	int contador_pretas = 0, contador_brancas = 0, contador_mesmo_movimento = 0, contador_sucessivo = 0, movimento_peca[4] = {0,0,0,0}; // contadores de empate
	char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO]; // tabuleiro
	char novamente = "n";

	do
	{
		jogo = menu(); //chamada da função menu, retornará qual o modo de jogo

		cls();

		gerar_tabuleiro(tabuleiro);

		switch (jogo)
		{
			case 1: 

				do
				{
					brancas = conta_peca(BRANCAS, tabuleiro); // conta a quantidade de peças do jogador
					pretas = conta_peca(PRETAS, tabuleiro);

					exibir_tabuleiro(tabuleiro);

					printf("\t\t\tVez do Jogador\n");
					printf("\t\t\tPeças restantes: %d\n", brancas);
					printf("\t\t\tInsira a linha e a coluna da peça que deseja mover\n");

					derrota = selecionar_peca(BRANCAS, tabuleiro, &empate, &contador_sucessivo, &contador_brancas, &contador_pretas, &contador_mesmo_movimento, movimento_peca); // chamada da função de seleção, se não houver peças, gera derrota

					cls();

					exibir_tabuleiro(tabuleiro);

					computador(tabuleiro); // chamada da função do computador

					cls();

				}while(brancas > 0 && pretas > 0 && empate > 0 && derrota > 0);

				if (brancas == 0)
				{
					printf("\n\n\n\n\n");
					printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t|              VITÓRIA DA PEÇAS PRETAS!!!                 |\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t Deseja jogar novamente? (S/N)\n");
				    printf("\t\t\t Resposta: ");
				    scanf("%s", &novamente);
				}
				else if (pretas == 0)
				{
					printf("\n\n\n\n\n");
					printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t|              VITÓRIA DA PEÇAS BRANCAS!!!                |\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t Deseja jogar novamente? (S/N)\n");
				    printf("\t\t\t Resposta: ");
				    scanf("%s", &novamente);
				}
				else if (empate == 0)
				{
					printf("\n\n\n\n\n");
					printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t|                       EMPATE!!!                         |\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t Deseja jogar novamente? (S/N)\n");
				    printf("\t\t\t Resposta: ");
				    scanf("%s", &novamente);
				}
				else if (derrota == 0)
				{
					if (brancas > pretas)
					{
						printf("\n\n\n\n\n");
						printf("\t\t\t+---------------------------------------------------------+\n");
					    printf("\t\t\t|                                                         |\n");
					    printf("\t\t\t|              VITÓRIA DA PEÇAS BRANCAS!!!                |\n");
					    printf("\t\t\t|                                                         |\n");
					    printf("\t\t\t+---------------------------------------------------------+\n");
					    printf("\t\t\t Deseja jogar novamente? (S/N)\n");
					    printf("\t\t\t Resposta: ");
					    scanf("%s", &novamente);
					}
					else
					{
						printf("\n\n\n\n\n");
						printf("\t\t\t+---------------------------------------------------------+\n");
					    printf("\t\t\t|                                                         |\n");
					    printf("\t\t\t|              VITÓRIA DA PEÇAS PRETAS!!!                 |\n");
					    printf("\t\t\t|                                                         |\n");
					    printf("\t\t\t+---------------------------------------------------------+\n");
					    printf("\t\t\t Deseja jogar novamente? (S/N)\n");
					    printf("\t\t\t Resposta: ");
					    scanf("%s", &novamente);
					}
				}

				break;

			case 2:

				do
				{

					brancas = conta_peca(BRANCAS, tabuleiro);
					pretas = conta_peca(PRETAS, tabuleiro);

					exibir_tabuleiro(tabuleiro);

					printf("\t\t\tVez do primeiro Jogador\n");
					printf("\t\t\tPeças restantes: %d\n", brancas);
					printf("\t\t\tInsira a linha e a coluna da peça que deseja mover\n");

					derrota = selecionar_peca(BRANCAS, tabuleiro, &empate, &contador_sucessivo, &contador_brancas, &contador_pretas, &contador_mesmo_movimento, movimento_peca);

					cls();

					exibir_tabuleiro(tabuleiro);

					printf("\t\t\tVez do segundo Jogador\n");
					printf("\t\t\tPeças restantes: %d\n", pretas);
					printf("\t\t\tInsira a linha e a coluna da peça que deseja mover\n");

					derrota = selecionar_peca(PRETAS, tabuleiro, &empate, &contador_sucessivo, &contador_brancas, &contador_pretas, &contador_mesmo_movimento, movimento_peca);

					cls();

				}while(brancas > 0 && pretas > 0 && empate > 0 && derrota > 0);

				if (brancas == 0)
				{
					printf("\n\n\n\n\n");
					printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t|              VITÓRIA DA PEÇAS PRETAS!!!                 |\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t Deseja jogar novamente? (S/N)\n");
				    printf("\t\t\t Resposta: ");
				    scanf("%s", &novamente);
				}
				else if (pretas == 0)
				{
					printf("\n\n\n\n\n");
					printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t|              VITÓRIA DA PEÇAS BRANCAS!!!                |\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t Deseja jogar novamente? (S/N)\n");
				    printf("\t\t\t Resposta: ");
				    scanf("%s", &novamente);
				}
				else if (empate == 0)
				{
					printf("\n\n\n\n\n");
					printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t|                       EMPATE!!!                         |\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t Deseja jogar novamente? (S/N)\n");
				    printf("\t\t\t Resposta: ");
				    scanf("%s", &novamente);
				}
				else if (derrota == 0)
				{
					if (brancas > pretas)
					{
						printf("\n\n\n\n\n");
						printf("\t\t\t+---------------------------------------------------------+\n");
					    printf("\t\t\t|                                                         |\n");
					    printf("\t\t\t|              VITÓRIA DA PEÇAS BRANCAS!!!                |\n");
					    printf("\t\t\t|                                                         |\n");
					    printf("\t\t\t+---------------------------------------------------------+\n");
					    printf("\t\t\t Deseja jogar novamente? (S/N)\n");
					    printf("\t\t\t Resposta: ");
					    scanf("%s", &novamente);
					}
					else
					{
						printf("\n\n\n\n\n");
						printf("\t\t\t+---------------------------------------------------------+\n");
					    printf("\t\t\t|                                                         |\n");
					    printf("\t\t\t|              VITÓRIA DA PEÇAS PRETAS!!!                 |\n");
					    printf("\t\t\t|                                                         |\n");
					    printf("\t\t\t+---------------------------------------------------------+\n");
					    printf("\t\t\t Deseja jogar novamente? (S/N)\n");
					    printf("\t\t\t Resposta: ");
					    scanf("%s", &novamente);
					}
				}

				break;
		}
	}while(novamente == 'S' || novamente == 's');

	return 0;
}

void cls()
{
	#ifdef __unix__  
    //código especifico para linux
    printf("\e[H\e[2J");
    #else
    //código específico para windows
    system ("cls");
    #endif
}

void pause()
{
	#ifdef __unix__  
    //código especifico para linux
    printf("\t\t\tPor favor, precione alguma tecla para continuar...\n");
    getchar();
    #else
    //código específico para windows
    system("pause");
    #endif
}

void language()
{
	#ifdef __unix__  
    //código especifico para linux
    system("reset");
    #endif
}

int menu ()
{
	int menu, jogo = 0;

	do
	{
		cls();
		printf("\n\n\n\n\n");
		printf("\t\t\t+---------------------------------------------------------+\n");
	    printf("\t\t\t|                                                         |\n");
	    printf("\t\t\t|                         Menu                            |\n");
	    printf("\t\t\t|                                                         |\n");
	    printf("\t\t\t|           | 1- Jogar | 2- Regras | 3- Sair |            |\n");
	    printf("\t\t\t|                                                         |\n");
	    printf("\t\t\t+---------------------------------------------------------+\n");
	    printf("\t\t\t Opção: ");

	    scanf("%d", &menu);

	    switch (menu)
	    {
	    	case 1:

	    		do
	    		{
	    			cls();
	    			printf("\n\n\n\n\n");
		    		printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t|               Escolha o modo de jogo:                   |\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t|     1- Um Jogador | 2- Dois Jogadores | 3- Voltar       |\n");
				    printf("\t\t\t|                                                         |\n");
				    printf("\t\t\t+---------------------------------------------------------+\n");
				    printf("\t\t\t Opção: ");

				    scanf("%d", &jogo);

				    switch(jogo)
				    {
				    	case 1:

				    		return jogo;

				    		break;

				    	case 2:

				    		return jogo;

				    		break;

				    	case 3:

				    		break;

				    	default:

				    		printf("\n\t\t\t Valor invalido, insira um valor valido\n\n");

				    		pause();

				    		break;
				    }

				}while(jogo < 1 || jogo > 3);

				if (jogo == 3)
				{
					jogo = 0;
				}

	    		break;

	    	case 2:

	    		cls();
	    		printf("\n\n\n\n\n");
	    		printf("\t\t\t+---------------------------------------------------------+\n");
			    printf("\t\t\t|                                                         |\n");
			    printf("\t\t\t|                       Regras:                           |\n");
			    printf("\t\t\t|             B: Brancas, O: Damas brancas                |\n");
			    printf("\t\t\t|              P: Pretas, 0: Damas pretas                 |\n");
			    printf("\t\t\t|                                                         |\n");
			    printf("\t\t\t|  1- As peças andam somente nas diagonais.               |\n");
			    printf("\t\t\t|  2- Somente damas podem mais de uma casa.               |\n");
			    printf("\t\t\t|  3- Para a captura de uma peça, a casa subsequente da   |\n");
			    printf("\t\t\t|     diagonal deve estar vazia.                          |\n");
			    printf("\t\t\t|  4- Somente sera considerado vitoria se as pecas de um  |\n");
			    printf("\t\t\t|     dos jogadores acabar ou não houver mais movimentos. |\n");
			    printf("\t\t\t|                                                         |\n");
			    printf("\t\t\t+---------------------------------------------------------+\n");

			    pause();

	    		break;

	    	case 3:

	    		printf("\t\t\t Agredeço a escolha de jogo, adeus!!!\n");

	    		exit(0);

	    		break;

	    	default:

	    		printf("\n\t\t\t Valor invalido, insira um valor valido\n\n");

				pause();

	    		break;
	    }

	}while(jogo == 0);
}

void gerar_tabuleiro(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO])

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

void exibir_tabuleiro(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO])

{

   int i, j;
	printf("\n\n\n\n\n");
   printf("\t\t\t +---+---+---+---+---+---+---+---+\n");

   for (i = MAX; i >= MIN; --i)

   {

       printf("\t\t\t%d", i+MIN_CONVERTIDO);

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

       printf("\t\t\t +---+---+---+---+---+---+---+---+\n");

   }

      printf("\t\t\t   1   2   3   4   5   6    7   8\n\n");
}

int empate_veri(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int **contador_sucessivo, int **contador_pretas, int **contador_brancas, int linha, int coluna)

{
	int movimento, brancas = 0, pretas = 0;
	movimento = movimento_dama(tabuleiro, linha, coluna, &contador_sucessivo);

	if (movimento == 0)
	{
		**contador_sucessivo = 0;
		return 1;
	}
	else if(movimento == 2)
	{
		return 0;
	}
	else
	{
		**contador_sucessivo++;
		return 1;
	}

	if (pretas == 0)
	{
		pretas = empate_3_dama(tabuleiro, '0', 'O');
		return 1;
	}
	if(brancas == 0)
	{
		brancas = empate_3_dama(tabuleiro, 'O', '0');
		return 1;
	}

	if(brancas > 0 || pretas > 0)
	{
		if (pretas == 1)
		{
			**contador_pretas++;
			return 1;
		}
		if (brancas == 1)
		{
			**contador_brancas++;
			return 1;
		}
	}

	if (**contador_brancas > 20 || **contador_pretas > 20)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int movimento_dama(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int linha, int coluna, int contador)
{
	if (tabuleiro[linha][coluna] == 'O' || tabuleiro[linha][coluna] == '0')
	{
		if (contador <= 19)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 0;
	}
}

int empate_3_dama(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], char peca, char oposto)

{
	int contador_peca = 0, contador_oposto = 0;

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (tabuleiro[i][j] == peca)
			{
				contador_peca++;
			}
			else if(tabuleiro[i][j] == oposto)
			{
				contador_oposto++;
			}
		}
	}

	if (contador_peca == 3 && contador_oposto == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int empate_mesmo_movimento(int linha_inicial, int linha_final, int coluna_inicial, int coluna_final, int contador, int movimento_peca[4])

{
	if (movimento_peca[0] == 0 && movimento_peca[1] == 0 && movimento_peca[2] == 0 && movimento_peca[3] == 0)
	{
		movimento_peca[0] = linha_final;
		movimento_peca[1] = coluna_final;
		movimento_peca[2] = linha_inicial;
		movimento_peca[3] = coluna_inicial;
 	}
 	else
 	{
	 	if (linha_inicial == movimento_peca[0] && coluna_inicial == movimento_peca[1] && linha_final == movimento_peca[2] && coluna_final == movimento_peca[3])
		{
			return 1;
		}
		else 
		{
			return 0;
			movimento_peca[0] = 0;
			movimento_peca[1] = 0;
			movimento_peca[2] = 0;
			movimento_peca[3] = 0;
		}
 	}

 	if (contador == 3)
	{
		return 2;
	}	
}

int conta_peca(char peca, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO])

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

char verifica_dama(char peca, int linha)

{
	switch (peca)
	{
		case 'B':

			if (linha == 7)
			{
				return 'O';
			}
			else
			{
				return peca;
			}
			break;

		case 'P':
			if (linha == 0)
			{
				return '0';
			}
			else
			{
				return peca;
			}
	}
}

int selecionar_computador(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], char peca, int linha, int coluna)
{

	switch (peca)
	{
		case PRETAS:

			if (tabuleiro[linha][coluna] == PRETAS)
			{
				if (tabuleiro[linha - 1][coluna - 1] == VAZIO || tabuleiro[linha - 1][coluna + 1] == VAZIO)
				{
					return 0;
				}
				else if(tabuleiro[linha + 1][coluna - 1] == BRANCAS || tabuleiro[linha + 1][coluna + 1] == BRANCAS || tabuleiro[linha + 1][coluna - 1] == DAMA_BRANCA || tabuleiro[linha + 1][coluna + 1] == DAMA_BRANCA)
				{
					if (tabuleiro[linha - 2][coluna - 2] == VAZIO || tabuleiro[linha - 2][coluna + 2] == VAZIO)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				else
				{
					return 1;
				}
			}
			else
			{
				return 1;
			}
			
			break;

		case DAMA_PRETA:

			if (tabuleiro[linha][coluna] == BRANCAS)
			{
				if (tabuleiro[linha - 1][coluna - 1] == VAZIO || tabuleiro[linha - 1][coluna + 1] == VAZIO)
				{
					return 0;
				}
				else if(tabuleiro[linha + 1][coluna - 1] == BRANCAS || tabuleiro[linha + 1][coluna + 1] == BRANCAS || tabuleiro[linha + 1][coluna - 1] == DAMA_BRANCA || tabuleiro[linha + 1][coluna + 1] == DAMA_BRANCA)
				{
					if (tabuleiro[linha - 2][coluna - 2] == VAZIO || tabuleiro[linha - 2][coluna + 2] == VAZIO)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				else if (tabuleiro[linha - 1][coluna - 1] == BRANCAS || tabuleiro[linha - 1][coluna + 1] == BRANCAS || tabuleiro[linha - 1][coluna - 1] == DAMA_BRANCA || tabuleiro[linha - 1][coluna + 1] == DAMA_BRANCA)
				{
					if (tabuleiro[linha + 2][coluna - 2] == VAZIO || tabuleiro[linha + 2][coluna + 2] == VAZIO)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				else
				{
					return 1;
				}
			}
			else
			{
				return 1;
			}

			break;
	}
}

void movimento_computador(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], char peca, int selecao_l, int selecao_c, int movimento_l, int movimento_c)

{
	if (movimento_l == selecao_l - 1 && movimento_c == selecao_c + 1)
	{
		if (tabuleiro[movimento_l][movimento_c] == VAZIO)
		{
			tabuleiro[selecao_l][selecao_c] = VAZIO;
			tabuleiro[movimento_l][movimento_c] = verifica_dama(peca, movimento_l);
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if (movimento_l == selecao_l - 1 && movimento_c == selecao_c - 1)
	{
		if (tabuleiro[movimento_l][movimento_c] == VAZIO)
		{
			tabuleiro[selecao_l][selecao_c] = VAZIO;
			tabuleiro[movimento_l][movimento_c] = verifica_dama(peca, movimento_l);
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if (movimento_l == selecao_l - 2 && movimento_c == selecao_c + 2)
	{
		if (tabuleiro[selecao_l - 1][selecao_c + 1] == BRANCAS || tabuleiro[selecao_l - 1][selecao_c + 1] == DAMA_BRANCA)
		{
			if (tabuleiro[selecao_l - 2][selecao_c + 2] == VAZIO)
			{
				tabuleiro[selecao_l][selecao_c] = VAZIO;
				tabuleiro[selecao_l - 1][selecao_c + 1] = VAZIO;
				tabuleiro[movimento_l][movimento_c] = verifica_dama(peca, movimento_l);
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 1;
		}
	}
	else if (movimento_l == selecao_l - 2 && movimento_c == selecao_c - 2)
	{
		if (tabuleiro[selecao_l - 1][selecao_c - 1] == BRANCAS || tabuleiro[selecao_l - 1][selecao_c - 1] == DAMA_BRANCA)
		{
			if (tabuleiro[selecao_l - 2][selecao_c - 2] == VAZIO)
			{
				tabuleiro[selecao_l][selecao_c] = VAZIO;
				tabuleiro[selecao_l - 1][selecao_c - 1] = VAZIO;
				tabuleiro[movimento_l][movimento_c] = verifica_dama(peca, movimento_l);
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
}

int verifica_captura(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], char peca, int selecao_l, int selecao_c, int movimento_l, int movimento_c)

{
	switch (peca)
	{
		case PRETAS:

			if (tabuleiro[selecao_l - 1][selecao_c + 1] == BRANCAS || tabuleiro[selecao_l - 1][selecao_c + 1] == DAMA_BRANCA)
			{
				if (tabuleiro[selecao_l - 2][selecao_c + 2] == VAZIO)
				{
					if(tabuleiro[selecao_l - 1][selecao_c - 1] == BRANCAS || tabuleiro[selecao_l - 1][selecao_c - 1] == DAMA_BRANCA)
					{
						if (tabuleiro[selecao_l - 2][selecao_c - 2] == VAZIO)
						{
							if (movimento_l == selecao_l - 2 && movimento_c == selecao_c - 2 || movimento_l == selecao_l - 2 && movimento_c == selecao_c + 2)
							{
								return 0;
							}
							else
							{
								return 1;
							}
						}
						else
						{
							if (movimento_l == selecao_l - 2 && movimento_c == selecao_c + 2)
							{
								return 0;
							}
							else
							{
								return 1;
							}
						}
					}
					else
					{
						if (movimento_l == selecao_l - 2 && movimento_c == selecao_c + 2)
						{
							return 0;
						}
						else
						{
							return 1;
						}
					}
				}
				else if(tabuleiro[selecao_l - 1][selecao_c - 1] == BRANCAS || tabuleiro[selecao_l - 1][selecao_c - 1] == DAMA_BRANCA)
				{
					if (tabuleiro[selecao_l - 2][selecao_c - 2] == VAZIO)
					{
						if (movimento_l == selecao_l - 2 && movimento_c == selecao_c - 2)
						{
							return 0;
						}
						else
						{
							return 1;
						}
					}
					else
					{
						return 1;
					}
				}
				else
				{
					return 1;
				}
			}
			else if(tabuleiro[selecao_l - 1][selecao_c - 1] == BRANCAS || tabuleiro[selecao_l - 1][selecao_c - 1] == DAMA_BRANCA)
			{
				if (tabuleiro[selecao_l - 2][selecao_c - 2] == VAZIO)
				{
					if (movimento_l == selecao_l - 2 && movimento_c == selecao_c - 2)
					{
						return 0;
					}
					else
					{
						return 1;
					}
				}
				else
				{
					return 1;
				}
			}
			else if (tabuleiro[selecao_l - 1][selecao_c - 1] == VAZIO || tabuleiro[selecao_l - 1][selecao_c + 1] == VAZIO)
			{
				if (movimento_l == selecao_l - 1 && movimento_c == selecao_c - 1 || movimento_l == selecao_l - 1 && movimento_c == selecao_c + 1)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			else
			{
				return 1;
			}

			break;

		case DAMA_PRETA:
			break;
	}
}

void computador(char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO])

{
	int selecao_l, selecao_c, movimento_l, movimento_c, validador_selecao = 1, validador_movimento = 1;
	char peca;

	srand(time(NULL));

	do
	{
		selecao_l = (rand() % 7);
		selecao_c = (rand() % 7);

		if (tabuleiro[selecao_l][selecao_c] == '0')
		{
			peca = '0';
		}
		else
		{
			peca = 'P';	
		}

		validador_selecao = selecionar_computador(tabuleiro, peca ,selecao_l, selecao_c);

	}while(validador_selecao == 1);

	do
	{
		movimento_l = (rand() % 7);
		movimento_c = (rand() % 7);

		validador_movimento = verifica_captura(tabuleiro, peca, selecao_l, selecao_c, movimento_l, movimento_c);

	}while(validador_movimento == 1);

	movimento_computador(tabuleiro, peca, selecao_l, selecao_c, movimento_l, movimento_c);
}

int validacao_peca(char orientacao, int valor, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO])

{
  if (orientacao == 'l')
  {
    while(valor < MIN_CONVERTIDO || valor > MAX_CONVERTIDO)
    {
      cls();
      exibir_tabuleiro(tabuleiro);
      printf("\t\t\tLinha invalida, por favor, insira uma linha valida!\n");
      printf("\t\t\tLinha: ");
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
      printf("\t\t\tColuna invalida, por favor, insira uma coluna valida!\n");
      printf("\t\t\tColuna: ");
      scanf("%d", &valor);
    }
    return valor - 1;
  }
}

int verifica_selecao(char peca, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int *linha_inicial, int *coluna_inicial)

{
  if (tabuleiro[*linha_inicial][*coluna_inicial] == BRANCAS && peca == BRANCAS)
  {
    if (tabuleiro[*linha_inicial + 1][*coluna_inicial - 1] == VAZIO || tabuleiro[*linha_inicial + 1][*coluna_inicial + 1] == VAZIO)
    {
      cls();
      exibir_tabuleiro(tabuleiro);

      printf("\t\t\tPosicao selecionada com sucesso!\n");
      return MIN_CONVERTIDO;
    }
    else if(tabuleiro[*linha_inicial + 1][*coluna_inicial - 1] == PRETAS || tabuleiro[*linha_inicial + 1][*coluna_inicial + 1] == PRETAS)
    {
      if (tabuleiro[*linha_inicial + 2][*coluna_inicial + 2] == VAZIO || tabuleiro[*linha_inicial + 2][*coluna_inicial - 2] == VAZIO)
      {
        cls();
        exibir_tabuleiro(tabuleiro);

        printf("\t\t\tPosicao selecionada com sucesso!\n");
        return MIN_CONVERTIDO;
      }
      else
      {
        cls();
        exibir_tabuleiro(tabuleiro);
        printf("\t\t\tNao foi possivel selecionar esta posicao, pois nao ha jogadas permitidas para esta peca\n");
        return MIN;
      }
    }
    else
    {
      cls();
      exibir_tabuleiro(tabuleiro);
      printf("\t\t\tNao foi possivel selecionar esta posicao, pois nao ha jogadas permitidas para esta peca\n");
      return MIN;
    }
  }
  else if (tabuleiro[*linha_inicial][*coluna_inicial] == PRETAS && peca == PRETAS)
  {
    if (tabuleiro[*linha_inicial - 1][*coluna_inicial - 1] == VAZIO || tabuleiro[*linha_inicial - 1][*coluna_inicial + 1] == VAZIO)
    {
      cls();
      exibir_tabuleiro(tabuleiro);

      printf("\t\t\tPosicao selecionada com sucesso!\n");
      return MIN_CONVERTIDO;
    }
    else if(tabuleiro[*linha_inicial - 1][*coluna_inicial - 1] == BRANCAS || tabuleiro[*linha_inicial - 1][*coluna_inicial + 1] == BRANCAS)
    {
      if (tabuleiro[*linha_inicial - 2][*coluna_inicial + 2] == VAZIO || tabuleiro[*linha_inicial - 2][*coluna_inicial - 2] == VAZIO)
      {
        cls();
        exibir_tabuleiro(tabuleiro);

        printf("\t\t\tPosicao selecionada com sucesso!\n");
        return MIN_CONVERTIDO;
      }
      else
      {
        cls();
        exibir_tabuleiro(tabuleiro);
        printf("\t\t\tNao foi possivel selecionar esta posicao, pois nao ha jogadas permitidas para esta peca\n");
        return MIN;
      }
    }
    else
    {
      cls();
      exibir_tabuleiro(tabuleiro);
      printf("\t\t\tNao foi possivel selecionar esta posicao, pois nao ha jogadas permitidas para esta peca\n");
      return MIN;
    }
  }
  else
  {
    cls();
    exibir_tabuleiro(tabuleiro);
    printf("\t\t\tNão há peças nesta posição\n");
    return MIN;
  }
}

int verifica_movimento(char peca, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int **linha_inicial, int **coluna_inicial, int *linha_final, int *coluna_final)

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

        printf("\t\t\tPosicao invalida\n\t\t\tA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
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

        printf("\t\t\tPosicao invalida\n\t\t\tA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
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

          printf("\t\t\tPosicao invalida\n\t\t\tA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
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

          printf("\t\t\tPosicao invalida\n\t\t\tA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
          return MIN;
        }
      }
    }
    else
    {
      cls();
      exibir_tabuleiro(tabuleiro);

      printf("\t\t\tPosicao invalida\n\t\t\tA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
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
        printf("\t\t\tPosicao invalida\n\t\t\tA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
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
        printf("\t\t\tPosicao invalida\n\t\t\tA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
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
          printf("\t\t\tPosicao invalida\n\t\t\tA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
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
          printf("\t\t\tPosicao invalida\n\t\t\tA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
          return MIN;
        }
      }
    }
    else
    {
      cls();
      exibir_tabuleiro(tabuleiro);

      printf("\t\t\tPosicao invalida\n\t\t\tA posicao solicitada pelo jogador nao eh permitida ou ja encontra-se ocupada\n");
      return MIN;
    }
  }
}

int selecionar_peca(char peca, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int *empate, int *contador_sucessivo, int *contador_brancas, int *contador_pretas, int *contador_mesmo_movimento, int movimento_peca[4])

{
    int retorno = MIN, linha_inicial, coluna_inicial, contador = 0;

    if(peca == BRANCAS)

    {

    	for (int i = 0; i < MAX_CONVERTIDO; ++i)
	    {
	    	for (int j = 0; j < MAX_CONVERTIDO; ++j)
	    	{
	    		if(tabuleiro[i][j] == peca || tabuleiro[i][j] == DAMA_BRANCA)
	    		{
	    			if (tabuleiro[i + 1][j - 1] == VAZIO || tabuleiro[i + 1][j + 1] == VAZIO)
	    			{
	    				contador++;
	    			}
	    			else if (tabuleiro[i + 1][j - 1] == PRETAS || tabuleiro[i + 1][j + 1] == PRETAS || tabuleiro[i + 1][j - 1] == DAMA_PRETA || tabuleiro[i + 1][j + 1] == DAMA_PRETA)
	    			{
	    				if (tabuleiro[i + 2][j - 2] == VAZIO || tabuleiro[i + 2][j + 2] == VAZIO)
	    				{
	    					contador++;
	    				}
	    			}
	    		}
	    	}
	    }

	    if (contador > 0)
	    {

	    	do

			{
				printf("\t\t\tpeca: %c\n", peca);
				printf("\t\t\tLinha: ");
				scanf("%d", &linha_inicial);

				linha_inicial = validacao_peca('l', linha_inicial, tabuleiro);

				printf("\t\t\tColuna: ");
				scanf("%d", &coluna_inicial);

				coluna_inicial = validacao_peca('c', coluna_inicial, tabuleiro);

				retorno = verifica_selecao(BRANCAS, tabuleiro, &linha_inicial, &coluna_inicial);

			}while(retorno <= MIN);

			*empate = empate_veri(tabuleiro, &contador_sucessivo, &contador_pretas, &contador_brancas, linha_inicial, coluna_inicial);

			printf("\t\t\tInsira a linha e a coluna para onde deseja mover a peça\n");

			movimento(BRANCAS, tabuleiro, &linha_inicial, &coluna_inicial, &empate, &contador_mesmo_movimento, movimento_peca);

			return 1;

	    }
	    else
	    {
	    	return 0;
	    }

    }

    else

    {

    	for (int i = 0; i < MAX_CONVERTIDO; ++i)
	    {
	    	for (int j = 0; j < MAX_CONVERTIDO; ++j)
	    	{
	    		if(tabuleiro[i][j] == peca || tabuleiro[i][j] == DAMA_BRANCA)
	    		{
	    			if (tabuleiro[i + 1][j - 1] == VAZIO || tabuleiro[i + 1][j + 1] == VAZIO)
	    			{
	    				contador++;
	    			}
	    			else if (tabuleiro[i + 1][j - 1] == PRETAS || tabuleiro[i + 1][j + 1] == PRETAS || tabuleiro[i + 1][j - 1] == DAMA_PRETA || tabuleiro[i + 1][j + 1] == DAMA_PRETA)
	    			{
	    				if (tabuleiro[i + 2][j - 2] == VAZIO || tabuleiro[i + 2][j + 2] == VAZIO)
	    				{
	    					contador++;
	    				}
	    			}
	    		}
	    	}
	    }

	    if (contador > 0)
	    {
	    	do

		    {
		    	printf("\t\t\tLinha: ");
		        scanf("%d", &linha_inicial);

		        linha_inicial = validacao_peca('l', linha_inicial, tabuleiro);


		        printf("\t\t\tColuna: ");
		        scanf("%d", &coluna_inicial);

		        coluna_inicial = validacao_peca('c', coluna_inicial, tabuleiro);

		        retorno = verifica_selecao(PRETAS, tabuleiro, &linha_inicial, &coluna_inicial);

		    }while(retorno <= MIN);

		    printf("\t\t\tInsira a linha e a coluna para onde deseja mover a peça\n");

		    *empate = empate_veri(tabuleiro, &contador_sucessivo, &contador_pretas, &contador_brancas, linha_inicial, coluna_inicial);

		    movimento(PRETAS, tabuleiro, &linha_inicial, &coluna_inicial, &empate, &contador_mesmo_movimento, movimento_peca);

		    return 1;
	    }

	    else
	    {
	    	return 0;
	    }
    }
}

void movimento (char peca, char tabuleiro[MAX_CONVERTIDO][MAX_CONVERTIDO], int *linha_inicial, int *coluna_inicial, int **empate, int **contador_mesmo_movimento, int movimento_peca[4])

{
  int retorno = MIN, linha_final, coluna_final, mesmo_movimento;

  if (peca == BRANCAS)

  {
    do

    {

      printf("\t\t\tLinha: ");
      scanf("%d", &linha_final);

      linha_final = validacao_peca('l', linha_final, tabuleiro);


      printf("\t\t\tColuna: ");
      scanf("%d", &coluna_final);

      coluna_final = validacao_peca('c', coluna_final, tabuleiro);

      retorno = verifica_movimento(BRANCAS, tabuleiro, &linha_inicial, &coluna_inicial, &linha_final, &coluna_final);

    }while(retorno <= MIN);

    mesmo_movimento = empate_mesmo_movimento(*linha_inicial, linha_final, *coluna_inicial, coluna_final, *contador_mesmo_movimento, movimento_peca);

    if (mesmo_movimento == 2)
    {
    	**empate = 0;
    }
    else if(mesmo_movimento == 1)
    {
    	**contador_mesmo_movimento++;
    }
    else
    {
    	**contador_mesmo_movimento = 0;
    }

  }

  else

  {
    do

    {
      printf("\t\t\tLinha: ");
      scanf("%d", &linha_final);

      linha_final = validacao_peca('l', linha_final, tabuleiro);


      printf("\t\t\tColuna: ");
      scanf("%d", &coluna_final);

      coluna_final = validacao_peca('c', coluna_final, tabuleiro);

      retorno = verifica_movimento(PRETAS, tabuleiro, &linha_inicial, &coluna_inicial, &linha_final, &coluna_final);


    }while(retorno <= MIN);

    mesmo_movimento = empate_mesmo_movimento(*linha_inicial, linha_final, *coluna_inicial, coluna_final, *contador_mesmo_movimento, movimento_peca);

    if (mesmo_movimento == 2)
    {
    	**empate = 0;
    }
    else if(mesmo_movimento == 1)
    {
    	**contador_mesmo_movimento++;
    }
    else
    {
    	**contador_mesmo_movimento = 0;
    }
  }
}