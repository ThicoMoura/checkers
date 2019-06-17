#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void exibir_tabuleiro(char tabuleiro[8][8]); // Função para exibir tabuleiro
void cls(); // Função limpar tela
int selecionar_dama(char tabuleiro[8][8], int, int);
void mover_dama(char tabuleiro[8][8], char, int, int);
int verifica_movimento_dama(char tabuleiro[8][8], char, int, int, int, int, int);
int captura_dama(char tabuleiro[8][8], char, int, int, int, int, int);
int verifica_captura(char tabuleiro[8][8], char, int, int);

int main()
{
	char tabuleiro[8][8] = {
	'V','X','V','X','V','X','V','X',
 	'X','P','X','P','X','V','X','V',
 	'V','X','V','X','O','X','V','X',
 	'X','P','X','P','X','V','X','V',
 	'V','X','V','X','V','X','V','X',
 	'X','V','X','V','X','V','X','V',
 	'V','X','V','X','V','X','V','X',
 	'X','V','X','V','X','V','X','V'};

 	int linha_i, coluna_i, linha_f, coluna_f, selecio = 0, move = 0, verifica_linha, verifica_coluna;

 	cls();

 	exibir_tabuleiro(tabuleiro);

 	do
 	{
 		printf("\t\t\tEntre com linha e coluna\n");
 		printf("\t\t\tLinha: ");
 		scanf("%d", &linha_i);
 		printf("\t\t\tColuna: ");
 		scanf("%d", &coluna_i);

 		linha_i -= 1;
 		coluna_i -= 1;

 		selecio = selecionar_dama(tabuleiro, linha_i, coluna_i);

 	}while(selecio == 0);

 	printf("\t\t\tPosição selecionada com sucesso\n");


 	mover_dama(tabuleiro, 'B', linha_i, coluna_i);

 	cls();

 	exibir_tabuleiro(tabuleiro);
}

void exibir_tabuleiro(char tabuleiro[8][8])

{

   int i, j;
	printf("\n\n\n\n\n");
   printf("\t\t\t +---+---+---+---+---+---+---+---+\n");

   for (i = 7; i >= 0; --i)

   {

       printf("\t\t\t%d", i+1);

       printf("| ");

       for (j = 0; j < 8; ++j)

       {

           if(tabuleiro[i][j] == 'X' && j == 0|| tabuleiro[i][j] == 'V' && j == 0)

               printf("  |");

           else if(tabuleiro[i][j] == 'X' && j == 7|| tabuleiro[i][j] == 'V' && j == 7)

               printf("  ");

           else if (tabuleiro[i][j] == 'X' && j != 7 && j != 0|| tabuleiro[i][j] == 'V' && j != 7 && j != 0)

               printf("   |");

           else if(tabuleiro[i][j] == 'B' && j == 0 || tabuleiro[i][j] == 'P' && j == 0 || tabuleiro[i][j] == '0' && j == 0 || tabuleiro[i][j] == 'O' && j == 0 )

               printf("%c |", tabuleiro [i][j]);

           else if(tabuleiro[i][j] == 'B' && j == 7 || tabuleiro[i][j] == 'P' && j == 7 || tabuleiro[i][j] == '0' && j == 7 || tabuleiro[i][j] == 'O' && j == 7)

               printf(" %c", tabuleiro [i][j]);

           else if (tabuleiro[i][j] == 'B' && j != 7 && j != 0 || tabuleiro[i][j] == 'P' && j != 7 && j != 0 || tabuleiro[i][j] == '0' && j != 7 && j != 0 || tabuleiro[i][j] == 'O' && j != 7 && j != 0)

               printf(" %c |", tabuleiro [i][j]);

       }

       printf(" |");

       printf("\n");

       printf("\t\t\t +---+---+---+---+---+---+---+---+\n");

   }

      printf("\t\t\t   1   2   3   4   5   6    7   8\n\n");
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

int selecionar_dama(char tabuleiro[8][8], int linha_i, int coluna_i)

{
	if (tabuleiro[linha_i][coluna_i] == 'O')
	{
		if (tabuleiro[linha_i + 1][coluna_i + 1] == 'V' || tabuleiro[linha_i + 1][coluna_i - 1] == 'V' || tabuleiro[linha_i - 1][coluna_i + 1] == 'V' || tabuleiro[linha_i - 1][coluna_i - 1] == 'V')
		{
			return 1;
		}
		else if (tabuleiro[linha_i + 1][coluna_i + 1] == 'P' || tabuleiro[linha_i + 1][coluna_i + 1] == '0')
		{
			if (tabuleiro[linha_i + 1][coluna_i + 1] == 'V')
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (tabuleiro[linha_i + 1][coluna_i - 1] == 'P' || tabuleiro[linha_i + 1][coluna_i - 1] == '0')
		{
			if (tabuleiro[linha_i + 1][coluna_i - 1] == 'V')
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (tabuleiro[linha_i - 1][coluna_i + 1] == 'P' || tabuleiro[linha_i - 1][coluna_i + 1] == '0')
		{
			if (tabuleiro[linha_i - 1][coluna_i + 1] == 'V')
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (tabuleiro[linha_i - 1][coluna_i - 1] == 'P' || tabuleiro[linha_i - 1][coluna_i - 1] == '0')
		{
			if (tabuleiro[linha_i - 1][coluna_i - 1] == 'V')
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void mover_dama(char tabuleiro[8][8], char peca, int linha_i, int coluna_i)

{
	int diferencial_l, diferencial_c, validador = 1, continua = 0, condicao = 0, linha_f, coluna_f;
	char oposto;

	if (peca == '0')
	{
		oposto = 'B';
	}
	else
	{
		oposto = 'P';
	}

	do
	{
		do
		{
			printf("\t\t\tLinha: ");
	 		scanf("%d", &linha_f);
	 		printf("\t\t\tColuna: ");
	 		scanf("%d", &coluna_f);

	 		linha_f -= 1;
	 		coluna_f -= 1;

			if (continua == 2)
			{

				if (linha_f <= linha_i - 2 && coluna_f <= coluna_i - 2 || linha_f <= linha_i - 2 && coluna_f >= coluna_i + 2 || linha_f >= linha_i + 2 && coluna_f <= coluna_i - 2 || linha_f >= linha_i + 2 && coluna_f >= coluna_i + 2)
				{
					condicao = 1;
				}
				else
				{
					printf("\t\t\tA captura é obrigatória, entre com valores validos\n");
					condicao = 0;
				}
			}
			else
			{
				condicao = 1;
			}
		}while(condicao == 0);

		diferencial_l = linha_f - linha_i;
		diferencial_c = coluna_f - coluna_i;

	 	if (verifica_movimento_dama(tabuleiro, peca, diferencial_l, diferencial_l, diferencial_c, linha_i, coluna_i) == 0)
	 	{
	 		continua = 1;
	 	}
	 	else
	 	{
	 		if (abs(diferencial_l) == abs(diferencial_c))
			{
				tabuleiro[linha_i][coluna_i] = 'V';
				captura_dama(tabuleiro, oposto, diferencial_l, diferencial_l, diferencial_c, linha_i, coluna_i);
				tabuleiro[linha_f][coluna_f] = 'O';

				linha_i = linha_f;
				coluna_i = coluna_f;

				if (verifica_captura(tabuleiro, oposto, linha_i, coluna_i) == 6)
		        {
	          		cls();
	        		exibir_tabuleiro(tabuleiro);

	          		printf("\t\t\tAinda há peças para serem capturadas.\n\t\t\tDevido as regras do jogo, o jogador deverá as capturar\n");
	          		continua = 2;
	          	}
				else
				{
					continua = 1;
				}
	 		}
	 		else
	 		{
	 			printf("Valor invalido\n");
	 		}
	 	}
	}while(continua <= 0 || continua >= 2);
}

int verifica_movimento_dama(char tabuleiro[8][8], char peca, int contador, int diferencial_l, int diferencial_c, int linha, int coluna)
{
	char dama;

	if (peca == 'P')
	{
		dama = '0';
	}
	else
	{
		dama = 'O';
	}

	for (int i = 1; i <= abs(contador); ++i)
 	{
 		if (diferencial_l > 0)
 		{
 			if (diferencial_c > 0)
 			{
 				if (tabuleiro[linha + i][coluna + i] == peca || tabuleiro[linha + i][coluna + i] == dama)
 				{
 					return 0;
 					break;
 				}
 				else
 				{
 					return 1;
 				}
 			}
 			else if (diferencial_c < 0)
 			{
 				if (tabuleiro[linha + i][coluna - i] == peca || tabuleiro[linha + i][coluna - i] == dama)
 				{
 					return 0;
 					break;
 				}
 				else
 				{
 					return 1;
 				}
 			}
 		}
 		else if (diferencial_l < 0)
 		{
 			if (diferencial_c > 0)
 			{
 				if (tabuleiro[linha - i][coluna + i] == peca || tabuleiro[linha - i][coluna + i] == dama)
 				{
 					return 0;
 					break;
 				}
 				else
 				{
 					return 1;
 				}
 			}
 			else if (diferencial_c < 0)
 			{
 				if (tabuleiro[linha - i][coluna - i] == peca || tabuleiro[linha - i][coluna - i] == dama)
 				{
 					return 0;
 					break;
 				}
 				else
 				{
 					return 1;
 				}
 			}
 		}
 	}
}

int captura_dama(char tabuleiro[8][8], char oposto, int contador, int diferenca_l, int diferenca_c, int linha, int coluna)
{
	char dama;

	if (oposto == 'P')
	{
		dama = '0';
	}
	else
	{
		dama = 'O';
	}

	for (int i = 1; i < abs(contador); ++i)
	{
		if (diferenca_l > 0)
 		{
 			if (diferenca_c > 0)
 			{
 				if (tabuleiro[linha + i][coluna + i] == oposto || tabuleiro[linha + i][coluna + i] == dama)
 				{
 					if (tabuleiro[linha + i + 1][coluna + i + 1] == 'V')
 					{
 						tabuleiro[linha + i][coluna + i] = 'V';
 					}
 				}
 			}
 			else if (diferenca_c < 0)
 			{
 				if (tabuleiro[linha + i][coluna - i] == oposto || tabuleiro[linha + i][coluna - i] == dama)
 				{
 					if (tabuleiro[linha + i + 1][coluna - i - 1] == 'V')
 					{
 						tabuleiro[linha + i][coluna - i] = 'V';
 					}
 				}
 			}
 		}
 		else if (diferenca_l < 0)
 		{
 			if (diferenca_c > 0)
 			{
 				if (tabuleiro[linha - i][coluna + i] == oposto || tabuleiro[linha - i][coluna + i] == dama)
 				{
 					if (tabuleiro[linha - i - 1][coluna + i + 1] == 'V')
 					{
 						tabuleiro[linha - i][coluna + i] = 'V';
 					}
 				}
 			}
 			else if (diferenca_c < 0)
 			{
 				if (tabuleiro[linha - i][coluna - i] == oposto || tabuleiro[linha - i][coluna - i] == dama)
 				{
 					if (tabuleiro[linha - i - 1][coluna - i - 1] == 'V')
 					{
 						tabuleiro[linha - i][coluna - i] = 'V';
 					}
 				}
 			}
 		}
	}
}

int verifica_captura(char tabuleiro[8][8], char oposto, int linha, int coluna)
{
	int possibilidade = 1;
	char dama;

	if (oposto == 'P')
	{
		dama = '0';
	}
	else
	{
		dama = 'O';
	}

	do
	{

		switch (possibilidade)
		{
			case 1:

				if (tabuleiro[linha + 1][coluna - 1] == oposto || tabuleiro[linha + 1][coluna - 1] == dama)
				{
					if (tabuleiro[linha + 2][coluna - 2] == 'V')
					{
						possibilidade = 6;
						break;
					}
					else
					{
						possibilidade++;
						break;
					}
				}
				else
				{
					possibilidade++;
					break;
				}

			case 2:

				if (tabuleiro[linha + 1][coluna + 1] == oposto || tabuleiro[linha + 1][coluna + 1] == dama)
				{
					if (tabuleiro[linha + 2][coluna + 2] == 'V')
					{
						possibilidade = 6;
						break;
					}
					else
					{
						possibilidade++;
						break;
					}
				}
				else
				{
					possibilidade++;
					break;
				}

			case 3:

				if (tabuleiro[linha - 1][coluna - 1] == oposto || tabuleiro[linha - 1][coluna - 1] == dama)
				{
					if (tabuleiro[linha - 2][coluna - 2] == 'V')
					{
						possibilidade = 6;
						break;
					}
					else
					{
						possibilidade++;
						break;
					}
				}
				else
				{
					possibilidade++;
					break;
				}

			case 4:

				if (tabuleiro[linha - 1][coluna + 1] == oposto || tabuleiro[linha - 1][coluna + 1] == dama)
				{
					if (tabuleiro[linha - 2][coluna + 2] == 'V')
					{
						possibilidade = 6;
						break;
					}
					else
					{
						possibilidade++;
						break;
					}
				}
				else
				{
					possibilidade++;
					break;
				}
		}

	}while(possibilidade <= 4);

	return possibilidade;
}