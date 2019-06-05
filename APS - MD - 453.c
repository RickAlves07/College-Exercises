/*	CENTRO UNIVERSITARIO CARIOCA - UNICARIOCA
	ATIVIDADE PRÁTICA SUPERVISIONADA - Matemática Discreta - 453

	JOHANN ABENTROTH MENICHELLI PALHEIROS	2017100581
	PAULO RICARDO MIRANDA GERALDES			2017100583
	RICK OLIVEIRA ALVES						2017101842	*/

#include <stdio.h>	
#include <locale.h>	
#include <math.h>
	
void menu(){
	system("cls");
	puts("Matemática Discreta");
	puts("\nEscolha a opção pretendida:\n");
	puts("[1] Arranjo");
	puts("[2] Permutação");
	puts("[3] Análise Combinatória");
	puts("[0] Sair");
	printf("\nOpção: "); 
}

unsigned long long int fatorial(unsigned long long int d){ 
unsigned long long int i, fator=1;      
    for(i=d;i>=1;i--){
		fator=fator*i;
	}
	return fator;
}

main(){
setlocale(LC_ALL,"portuguese");
unsigned long long int arranjo;
unsigned long long int elemento, agrupamento, num; 
int opc; 
	do{
		menu();
		scanf("%d",&opc); 
    	switch(opc){
			case 1: 
				system("cls");
				printf("Arranjo\n");
				printf("\nDigite o número de elementos do arranjo: ");
				scanf("%llu", &elemento);
				printf("Digite o valor do agrupamento do arranjo: ");
				scanf("%llu", &agrupamento);
				num=elemento-agrupamento;
	  			if(num==0)
	      			num=1;
					printf("\nFórmula \n%llu!÷(%llu-%llu)!", elemento, elemento, agrupamento);
					printf("\nO fatorial de %llu é %llu",elemento,fatorial(elemento));
					printf("\nO fatorial de (%llu-%llu) é %llu", elemento, agrupamento, fatorial(num));
					arranjo=fatorial(elemento)/fatorial(num);
					printf("\nTotal de arranjos formados de %llu elementos agrupados %llu a %llu é %llu\n\n", elemento, agrupamento, agrupamento, arranjo);
				
				break;
			
			case 2: 
				system("cls");
				printf("Permutação\n");
				printf("\nDigite o valor que deseja permutar: "); 
				scanf("%llu", &elemento);
				if(elemento==0)
					num=1;   
				else   
					num=elemento;
					printf("\nFórmula\n%llu! = ",num);
					while(num!=0){
						printf("%llu",num);
						num=num-1;
						if(num>0)
							printf("x");
					}
					num=elemento;
					printf("\nA permutação de %llu é %llu\n\n", elemento, fatorial(num));
				break;
			
			case 3:  
				system("cls");
				printf("Análise Combinatória\n");
				printf("\nDigite o número de de elementos da análise: ");
				scanf("%llu", &elemento);
				printf("Digite o valor do agrupamento da análise: ");
				scanf("%llu", &agrupamento);
   				num=elemento-agrupamento;
	     		if( num==0)
					num=1; 
					printf("\nFórmula \n%llu!÷(%llu-%llu)!x%llu!", elemento, elemento, agrupamento, agrupamento);
					printf("\nO fatorial de %llu é %llu", elemento, fatorial(elemento));
					printf("\nO fatorial de (%llu-%llu) é %llu", elemento, agrupamento, fatorial(num));
					printf("\nO fatorial de %llu é %llu", agrupamento, fatorial(agrupamento));

    				arranjo=fatorial(elemento)/(fatorial(num)*fatorial(agrupamento));
    				
    				printf("\nTotal de Combinações formadas de %llu elementos agrupados %llu a %llu é %llu\n\n", elemento, agrupamento, agrupamento, arranjo);
				break;
				
       		case 0:
       			puts("\nSair");
       			break;
			default:
				puts("Código inválido");
		}
	system("pause");	
   }while(opc!=0);
} 
