/*	CENTRO UNIVERSITARIO CARIOCA - UNICARIOCA
	AV3 - Cifra de Cesar - Programação Estruturada - 432	
	RICK OLIVEIRA ALVES		2017101842							*/
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(){
setlocale(LC_ALL,"Portuguese");
	int opcao=5, chave, i, cont=0, c;
	char msg[100]={0}, cod[100]={0}, letra;
	
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
	            system("cls");
				printf("\n--- Cifra de Cesar ---\n");
				printf("\nCifrar\n");
				printf("\nDigite a mensagem: ");
				fflush(stdin);
				gets(msg);
				fflush(stdin);
				printf("\nDigite uma senha númerica: ");
				scanf("%d", &chave);
				cifraCesar(msg, cod, chave);
				chave=0;
				break;
									
	        case 2:
	 			/*Abrir arquivo com mensagem cifrada e ler sem alterar seu conteúdo*/;
				FILE *arquivo;
	    			arquivo=fopen("arqIn.txt", "r");
	    		if(!arquivo){
	    			printf("\nArquivo não encontrado.\n\n");
					system("pause");
	  			}
				else{
					fgets(&msg, sizeof(char[100]), arquivo);	
					system("cls");
					printf("\n--- Cifra de Cesar ---\n");
					printf("\nDecifrar\n");
					printf("\nMensagem cifrada encontrada: %s\n",msg);
					printf("\nDigite a senha para decifrar: ");
					scanf("%d", &chave);						
					decifraCesar(msg, cod, chave);
				}
				break;
			case 0:
	        	printf("\nSair");
				exit(0);
		}
	}
	return 0;
}

/*Função Cifrar*/
void cifraCesar(char arqIn[], char arqOut[], int k){
int i, cont=0;
char letra, msg[100];
	
	/*Faz uma copia da mensagem*/
	strcpy(msg,arqIn);	
	
	/*Ler toda a mensagem*/
	for(i=0; msg[i]!='\0'; ++i){       		
		letra=msg[i];
		
		/*Letras minúsculas*/
		if(letra>='a' && letra<='z'){
			/*Codificando a letra ou número com a soma da senha*/
			letra=letra+k;
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
			letra=letra+k; 
			while(letra>'Z' || letra<'A'){	/*Intervalo de 'A' até 'Z' na tabela ASCII*/
				letra=letra-26;
			}			
			msg[i]=letra;						
		}	
		
		/*Números*/
		if(letra>='0' && letra<='9'){
			letra=letra+k;
			while(letra>'9' || letra<'0'){	/*Intervalo de '0' até '9' na tabela ASCII*/
				letra=letra-10;	
			}
			msg[i]=letra;						
		}		
	}
	
	/*Copia a mensagem cifrada*/
	strcpy(arqOut, msg); 
	
	/*Conta o tamanho da msg*/
	cont=strlen(arqOut);
    	
	if(strlen(arqOut)==0){
		printf("\nErro em cifrar mensagem!\n");
	    printf("\n");
	    system("pause");
	}
	else{
		printf("\nMensagem cifrada com exito!\n");
		printf("\nMensagem cifrada: %s\n",arqOut);
	
		/*Gravar mensagem cifrada em um arquivo texto*/
		FILE *arquivo;
		arquivo=fopen("arqIn.txt", "w+");
    	fwrite(arqOut, sizeof(char[cont]), 1, arquivo);
    	fclose(arquivo);

    	printf("\nSalvo no arquivo: ArqIn.txt\n\n");
    	system("pause");
	}
}

/*Função decifrar*/
void decifraCesar(char arqIn[], char arqOut[], int k){
int i, cont=0;
char letra, msg[100];

	strcpy(msg,arqIn);
		
		/*Ler toda a mensagem*/
		for(i=0; msg[i]!='\0'; ++i){
        	letra=msg[i];
			
			/*Letras minúsculas*/
			if(letra>='a' && letra<='z'){
				/*decodificando a letra ou número com a subtração da senha*/
				letra=letra-k;
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
				letra=letra-k;
				while(letra>'Z' || letra<'A'){
					letra=letra+26;	
				}
				msg[i]=letra;
			}
			
			/*Números*/
			if(letra>='0' && letra<='9'){
				letra=letra-k;
				while(letra>'9' || letra<'0'){
					letra=letra+10;	
				}
				msg[i]=letra;
			}
		}

	strcpy(arqOut, msg); 
	cont=strlen(arqOut);

	if(arqOut==NULL){
		printf("\nErro em decifrar mensagem!\n");
	    printf("\n");
	    system("pause");
	}
	else{
		printf("\nMensagem decifrada com exito!\n");
		printf("\nMensagem decifrada: %s\n",arqOut);
	
	/*Gravar mensagem decifrada em um arquivo texto*/
	FILE *arquivo;
	arquivo=fopen("arqOut.txt", "w+");
    fwrite(arqOut, sizeof(char[cont]), 1, arquivo);
    fclose(arquivo);
	
	printf("\nSalvo no arquivo: ArqOut.txt\n\n");
	system("pause");
	}
}
