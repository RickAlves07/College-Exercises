/*	CENTRO UNIVERSITARIO CARIOCA - UNICARIOCA
	AV3 - Cifra de Cesar V 2.0 - Programação Estruturada - 432	
	RICK OLIVEIRA ALVES		2017101842							*/
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(){
setlocale(LC_ALL,"Portuguese");
	int opcao=5;

	while (opcao!=0){
		system("cls");
		printf("\n--- Cifra de Cesar ---\n");
		printf("\nMenu Principal\n");
		printf("\n[1] Cifrar uma mensagem");
	    printf("\n[2] Decifrar uma mensagem");
	    printf("\n[0] Sair");
	    printf("\n\nDigite sua opção: ");
	    scanf("%i", &opcao);
	        
		switch(opcao){
	        case 1:
	            if(cifrar()==0){
	            	printf("\nMensagem cifrada com exito!\n");
	            	printf("\n");
	            	system("pause");
	            	break;
	            }
				else{
				 	printf("\nErro em cifrar mensagem!\n");
	                printf("\n");
	                system("pause");
	              	break;
	           	}
	        case 2:
	            if(decifrar()==0){
	                printf("\nMensagem decifrada com exito!\n");
	                printf("\n");
	                system("pause");
	            	break;
	            }
	            else{
	                printf("\nErro em decifrar mensagem!\n");
	                printf("\n");
					system("pause");
	               	break;
	            }	            
			case 0:
	        	printf("\nSair");
				exit(0);
		}
	}
	return 0;
}

/*Função Cifrar*/
int cifrar(void){
int chave, i, cont=0;
char msg[100]={0}, letra;

	system("cls");
	printf("\n--- Cifra de Cesar ---\n");
	printf("\nCifrar\n");
	printf("\nDigite a mensagem: ");
	fflush(stdin);
	gets(msg);
	printf("\nDigite uma senha númerica: ");
	scanf("%d", &chave);
	
	/*Ler toda a mensagem*/
	for(i=0; msg[i]!='\0'; ++i){       		
		letra=msg[i];
		
		/*Letras minúsculas*/
		if(letra>='a' && letra<='z'){
			/*Codificando a letra ou número com a soma da senha*/
			letra=letra+chave;
			/*loop até que a letra ou numero esteja dentro do intervalo que corresponde
			ao caracter, no caso, intervalo de 'a' até 'z' na tabela ASCII*/
			while(letra>'z' || letra<'a'){
				letra=letra-26;
			}
			/*substuir o caracter*/
			msg[i]=letra;
		}		
		
		/*Letras maiúsculas*/
		if(letra>='A' && letra<='Z'){
			letra=letra+chave; 
			while(letra>'Z' || letra<'A'){	/*Intervalo de 'A' até 'Z' na tabela ASCII*/
				letra=letra-26;
			}			
			msg[i]=letra;						
		}	
		
		/*Números*/
		if(letra>='0' && letra<='9'){
			letra=letra+chave;
			while(letra>'9' || letra<'0'){	/*Intervalo de '0' até '9' na tabela ASCII*/
				letra=letra-10;	
			}
			msg[i]=letra;						
		}		
	}
	
	/*Contar o tamanho da mensagem*/
	for(i=0;i<100;i++){
		if(msg[i]!=0){
			cont++;
		} 
    }
    
	printf("\nMensagem Cifrada: %s\n",msg);
	printf("\nSalvo no arquivo: ArqIn.txt\n");	
	
	/*Gravar mensagem cifrada em um arquivo texto*/
	FILE *arquivo;
	arquivo=fopen("arqIn.txt", "w+");
    	fwrite(&msg, sizeof(char[cont]), 1, arquivo);
    	fclose(arquivo);
    	return 0;
}

/*Função decifrar*/
int decifrar(void){
	char msg[100]={0}, letra;
	int chave, i, cont=0;

	/*Abrir arquivo com mensagem cifrada e ler sem alterar seu conteúdo*/
	FILE *arquivo;
	    arquivo=fopen("arqIn.txt.", "r");
	    if(!arquivo){
	    	printf("\nArquivo não encontrado.\n");
			return 1;
	  	}
		else{
			fgets(&msg, sizeof(char[100]), arquivo);
			
			system("cls");
			printf("\n--- Cifra de Cesar ---\n");
			printf("\nDecifrar\n");
			printf("\nMensagem cifrada encontrada: %s\n",msg);
			printf("\nDigite a senha para decifrar: ");
			scanf("%d", &chave);
			
			/*Ler toda a mensagem*/
			for(i=0; msg[i]!='\0'; ++i){
	        	letra=msg[i];
				
				/*Letras minúsculas*/
				if(letra>='a' && letra<='z'){
					/*decodificando a letra ou número com a subtração da senha*/
					letra=letra-chave;
					/*loop até que a letra ou numero esteja dentro do intervalo que corresponde
					ao caracter, no caso, intervalo de 'a' até 'z' na tabela ASCII*/
					while(letra>'z' || letra<'a'){
						letra=letra+26;
					}	
					/*substuir o caracter*/
					msg[i]=letra;
				}
				
				/*Letras maiúsculas*/	
				if(letra>='A' && letra<='Z'){
					letra=letra-chave;
					while(letra>'Z' || letra<'A'){
						letra=letra+26;	
					}
					msg[i]=letra;
				}
				
				/*Números*/
				if(letra>='0' && letra<='9'){
					letra=letra-chave;
					while(letra>'9' || letra<'0'){
						letra=letra+10;	
					}
					msg[i]=letra;
				}
			}
		
			/*Contar o tamnha da mensagem*/
			for(i=0;i<100;i++){
				if(msg[i]!=0){
					cont++;
				} 
		    }
			printf("\nMensagem decifrada: %s\n",msg);
			printf("\nSalvo no arquivo: ArqOut.txt\n");
			
			/*Gravar mensagem decifrada em um arquivo texto*/
			FILE *arquivo;
				arquivo=fopen("arqOut.txt", "w+");
		    	fwrite(&msg, sizeof(char[cont]), 1, arquivo);
		    	fclose(arquivo);
		    return 0;
		}
}
