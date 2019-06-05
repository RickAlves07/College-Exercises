/*	CENTRO UNIVERSITARIO CARIOCA - UNICARIOCA
	ATIVIDADE PR�TICA SUPERVISIONADA - Estrutura de Dados - 422
	RICK OLIVEIRA ALVES						2017101842	*/
	
#include <stdio.h>
#include <locale.h>
#include <conio.h>
	
struct elemento{
	float dado;
	struct elemento *prox;
}; typedef struct elemento elem;

elem* cria_List(){
	elem *li = (elem*)malloc(sizeof(elem));
	li->prox = NULL;
	printf("\nLista criada com sucesso!");
	return li;
}

int inserir_lista_inicio(elem *noIni, float valor){
	elem *novono = (elem*)malloc(sizeof(elem));
	novono->dado = valor;
	novono->prox = noIni->prox;
	noIni->prox = novono;
	printf("\nN�mero cadastrado com exito!\n\n");
}

void menu(){
	system("cls");
	puts("Estrutura de Dados\nLista Encadeada");
	puts("\nEscolha a op��o pretendida:\n");
	puts("[1] Adicionar a lista");
	puts("[2] Remover da lista");
	puts("[3] Ver a lista");
	puts("[4] Consultar uma posi��o na lista");
	puts("[0] Sair");
	printf("\nOp��o: ");
}

main(){
setlocale(LC_ALL,"portuguese");
	int opc, inserir, excluir, consulta, posicao, exibir, cont=0;
	float valor;
	char escolha;
	cria_List();
	elem *noIni = (elem*)malloc(sizeof(elem));
	noIni->prox = NULL;
	do{
		menu();
			scanf("%d",&opc);
	  	  	switch(opc){
				case 1:
					system("cls");
					printf("\nDigite o valor: ");
					scanf("%f", &valor);
					inserir = inserir_lista_inicio(noIni, valor);
					cont++;
					system("pause");
					break;
				case 2:
					system("cls");
					consulta = consulta_Lista(noIni, cont);
					printf("\nO �ltimo valor cadastrado � %.\nDeseja remover?(S/N) ", consulta);
					escolha = getche();
					if(escolha=='s'){
						excluir = excluir_Lista(noIni, cont);
						cont--;
						system("pause");
						break;
					}
					else{
						printf("\n\nN�mero n�o foi removido.\n\n");
						break;
					}
				case 3:
					system("cls");
					exibir = exibir_Lista(noIni, cont);
					system("pause");
					break;
				case 4:
					system("cls");
					printf("\nDigite o n�mero da posi��o: ");
					scanf("%d", &posicao);
					consulta = consulta_Lista(noIni, posicao);
					system("pause");
					break;
				case 0:
	       			puts("\nSair");
	       			break;
				default:
					puts("C�digo inv�lido");
					system("pause");
			}
	} while(opc!=0);
}

int excluir_Lista(elem *noIni, int posicao){
	elem *noexcluir = (elem*)malloc(sizeof(elem));
	*noexcluir = *noIni;
	int i=1;
	while(noexcluir != NULL && i <= posicao){
		noexcluir = noexcluir->prox;
		i++;
	}
	noexcluir->dado='NULL';
	printf("\n\nN�mero removido com exito.\n\n");
}

int consulta_Lista(elem *noIni, int posicao){
	elem *nobusca = (elem*)malloc(sizeof(elem));
	*nobusca = *noIni;
	int i=1;
	while(nobusca != NULL && i <= posicao){
		nobusca = nobusca->prox;
		i++;
	}
	int dado = nobusca->dado;
	printf("\nPosicao %d da lista, dado = %d\n", posicao, dado);
	return dado;
}

int exibir_Lista(elem *noIni, int posicao){
	int dado;
	elem *nobusca = (elem*)malloc(sizeof(elem));
	*nobusca = *noIni;
	int i=1;
	posicao++;
	while(nobusca->prox != NULL){
		nobusca = nobusca->prox;
		i++;
		posicao--;
		dado = nobusca->dado;
		printf("%d", dado);
		if(posicao==1){
			printf(".\n");
		}
		else{
			printf(", ");
		}
	}
	return 0;
}
