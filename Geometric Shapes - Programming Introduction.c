/*	CENTRO UNIVERSITÁRIO CARIOCA - UNICARIOCA
	ATIVIDADE PRÁTICA SUPERVISIONADA - INTRODUÇÃO A PROGRAMAÇÃO - 442
	
	GABRIEL ARRUDA DE OLIVEIRA				2017100178	
	JOHANN ABENTROTH MENICHELLI PALHEIROS	2017100581	
	PATRICK DA SILVA PALMA LOPES			2017101869	
	RICK OLIVEIRA ALVES						2017101842	*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main ()
{
setlocale(LC_ALL,"Portuguese");
int escolha, lados, estrelasL, estrelasT, estrelasQ, linhasL, linhasT, linhasQ, fim, margem;
char denovo='\0';
	printf("\n*****Este programa cria formas geométricas.*****");	
		/* Repetição do menu caso escolha imprir uma nova figura. */
		while (denovo!='N' && denovo!='n'){		
			printf("\n\nEscolha uma das opções: ");
			printf("\n[1] Losango");
			printf("\n[2] Triângulo");
			printf("\n[3] Quadrado");
			printf("\n[0] Sair\n");
			printf("\nOpção: "); 
			scanf("%d", &escolha);
			/* Escolha da figura a ser gerada. */
			switch (escolha){			
				/* Se escolha for losango. */
				case (1):
					printf("\nVocê escolheu losango.\n");
					printf("Digite a quantidade de *(s) para os lados: ");
					scanf("%d", &lados);						
						printf("\n");					    
						/* Montagem da estrutura da parte superior do losango. */
						for(margem=1; margem<=lados; margem++) {							
							for(linhasL=1; linhasL<=lados-margem; linhasL++){
								printf(" ");
							}								
							while(estrelasL!=(2*margem-1)){
								if(estrelasL==0 || estrelasL==2*margem-2)
								    printf("*");
								else
								    printf(" ");
								    estrelasL++;
							}
							estrelasL=0;
							printf("\n");
						}
						lados--;
						/* Montagem da estrutura da parte inferior do losango. */
						for(margem=lados;margem>=1; margem--){
							for(linhasL=0; linhasL<=lados-margem; linhasL++){
								printf(" ");
							}	
							estrelasL = 0;
							while(estrelasL!= (2*margem - 1)){
								if(estrelasL==0 || estrelasL==2*margem-2)
								    printf("*");
								else
								    printf(" ");
									estrelasL++;
							}
							printf("\n");							
						}
					break;
	
				/* Se escolha for triângulo. */
				case (2):
					printf("\nVocê escolheu Triângulo.\n");
					printf("Digite a quantidade de *(s) para os lados: ");
					scanf("%d", &lados);
						printf("\n");
						/* Montagem da estrutura do triângulo. */
						for(estrelasT=1; estrelasT<=lados; estrelasT++){
	        				for(linhasT=1; linhasT<=estrelasT; linhasT++){ 
	            				if(linhasT==1 || linhasT==estrelasT || estrelasT==lados)	            				
	                				printf("*");	            				
	            				else	            				
	               					printf(" ");
	        				}
	       					printf("\n");
	    				}										
					break;
						
				/* Se escolha for quadrado. */
				case (3):
					printf("\nVocê escolheu Quadrado.\n");
					printf("Digite a quantidade de *(s) para os lados: ");
					scanf("%d", &lados);
						printf("\n"); 
						/* Montagem da estrutura do quadrado. */
						for(estrelasQ=0; estrelasQ<lados; estrelasQ++){		
	        				for(linhasQ=0; linhasQ<lados; linhasQ++){		
	           					if(estrelasQ==0 || estrelasQ==lados-1 || linhasQ==0 || linhasQ==lados-1)
	                				printf("* ");
	            				else
	                				printf("  ");
	        				}
							printf("\n");	    			
						}
					break;
						
				/* Se escolha for diferente das 3 opções dadas. */
				case (0):
					printf("\nSair\n");
					return 0;				
				default:
					printf("\nNão é uma opção valída.\n");
					break;
			}
			/* Verificação do laço de repetição. */
			printf("\nDeseja criar uma nova forma? (S/N): ");	
			denovo = getche();	
		}
	/* Fim do programa. */
	printf("\n\nFim do Programa.\n\n");	
	system("pause");
	return 0;
}
