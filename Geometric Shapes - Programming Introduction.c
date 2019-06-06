/*	CENTRO UNIVERSIT�RIO CARIOCA - UNICARIOCA
	ATIVIDADE PR�TICA SUPERVISIONADA - INTRODU��O A PROGRAMA��O - 442
	
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
	printf("\n*****Este programa cria formas geom�tricas.*****");	
		/* Repeti��o do menu caso escolha imprir uma nova figura. */
		while (denovo!='N' && denovo!='n'){		
			printf("\n\nEscolha uma das op��es: ");
			printf("\n[1] Losango");
			printf("\n[2] Tri�ngulo");
			printf("\n[3] Quadrado");
			printf("\n[0] Sair\n");
			printf("\nOp��o: "); 
			scanf("%d", &escolha);
			/* Escolha da figura a ser gerada. */
			switch (escolha){			
				/* Se escolha for losango. */
				case (1):
					printf("\nVoc� escolheu losango.\n");
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
	
				/* Se escolha for tri�ngulo. */
				case (2):
					printf("\nVoc� escolheu Tri�ngulo.\n");
					printf("Digite a quantidade de *(s) para os lados: ");
					scanf("%d", &lados);
						printf("\n");
						/* Montagem da estrutura do tri�ngulo. */
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
					printf("\nVoc� escolheu Quadrado.\n");
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
						
				/* Se escolha for diferente das 3 op��es dadas. */
				case (0):
					printf("\nSair\n");
					return 0;				
				default:
					printf("\nN�o � uma op��o val�da.\n");
					break;
			}
			/* Verifica��o do la�o de repeti��o. */
			printf("\nDeseja criar uma nova forma? (S/N): ");	
			denovo = getche();	
		}
	/* Fim do programa. */
	printf("\n\nFim do Programa.\n\n");	
	system("pause");
	return 0;
}
