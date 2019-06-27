#include <stdio.h>
#include "menu.h"

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

				    		printf("\n\t\t\t Valor inválido, insira um valor valido\n\n");

				    		printf("\t\t\tPor favor, precione alguma tecla para continuar...\n");
    						getchar();

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
			    printf("\t\t\t|  3- Para a captura de uma peca, a casa subsequente da   |\n");
			    printf("\t\t\t|     diagonal deve estar vazía.                          |\n");
			    printf("\t\t\t|  4- Somente será considerado vitória se as peças de um  |\n");
			    printf("\t\t\t|     dos jogadores acabar ou não houver mais movimentos. |\n");
			    printf("\t\t\t|                                                         |\n");
			    printf("\t\t\t+---------------------------------------------------------+\n");	

			    printf("\t\t\tPor favor, precione alguma tecla para continuar...\n");
    			getchar();

	    		break;

	    	case 3:

	    		printf("\t\t\t Agredeço a escolha de jogo, adeus!!!\n");

	    		exit(0);

	    		break;

	    	default:

	    		printf("\n\t\t\t Valor inválido, insira um valor valido\n\n");

				printf("\t\t\tPor favor, precione alguma tecla para continuar...\n");
    			getchar();

	    		break;
	    }

	}while(jogo == 0);
}