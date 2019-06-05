/*	CENTRO UNIVERSITARIO CARIOCA - UNICARIOCA
	ATIVIDADE PRÁTICA SUPERVISIONADA - Programação Estruturada - 432	
	RICK OLIVEIRA ALVES		2017101842							*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#define Nom 40
#define Carg 20
#define temp 60

int main(void){
setlocale(LC_ALL,"portuguese");
	int opcao;

    while (1){
        do{
        	system("cls");
			printf("\n--- Lista de Funcionários ---\n");
            printf("\nMenu Principal\n");
			printf("\n[1] Cadastrar funcionário");
            printf("\n[2] Exibir lista de funcionários cadastrados");
            printf("\n[0] Sair");
            printf("\n\nDigite sua opção: ");
            scanf("%i", &opcao);
            
        }while((opcao<1) && (opcao>3));
	
		switch(opcao){
            case 1:
                if(cadastrar()==0)
                    printf("\nFuncionário cadastrado!\n");
                    printf("\n");
                    system("pause");
                	break;

            case 2:
                if(lista()==1)
                    printf("\nErro ao abrir o arquivo!\n");
                    printf("\n");
                    system("pause");
                	break;
            
			case 0:
                printf("\nSair\n");
				exit(0);
        }
    }
}

/*Informações do endereço do funcionário*/
struct endereco{
	char end[temp];
	char numero[temp];
	char bairro[temp];
	char cidade[temp];
	char estado[temp];
	char cep[temp];
};

/*Informações do funcionário*/
struct funcionario{
    int codigo;
    char nome[40];
    char cargo[20];
    float sal;
    char tel[temp];
    char status[temp];
   	struct endereco casa;
};

/*Cadastrar funcionário*/
int cadastrar(void){
	struct funcionario fun;										getchar(); // limpar
	system("cls");
	
	printf("\n--- Lista de Funcionários ---\n");
    printf("\nAdicionar Funcionário\n\n");
	
	printf("Nome: ");		fgets(fun.nome, Nom, stdin);
    printf("Código: ");     scanf("%d",&fun.codigo, stdin);		getchar(); // limpar
    printf("Cargo: ");      fgets(fun.cargo, Carg, stdin);
	printf("Salário: ");    scanf("%f",&fun.sal, stdin);   		getchar(); // limpar
	 
	printf("\nEndereço: "); fgets(fun.casa.end, temp, stdin);
	printf("Número: ");     fgets(fun.casa.numero, temp, stdin);
	printf("Bairro: ");     fgets(fun.casa.bairro, temp, stdin);
	printf("Cidade: ");     fgets(fun.casa.cidade, temp, stdin);
	printf("Estado: ");     fgets(fun.casa.estado, temp, stdin);
	printf("CEP: ");        fgets(fun.casa.cep, temp, stdin);
	printf("Telefone: ");   fgets(fun.tel, temp, stdin);
	
	printf("\nStatus: ");   fgets(fun.status, temp, stdin);
	
    FILE *file;
    	file=fopen("Lista.dat", "a");
    if(verificar(fun.codigo)==1){
    	return 1;
	}
	else{
    	fwrite (&fun, sizeof(struct funcionario), 1, file);
    	fclose (file);
    	return 0;
	}
}

/*Verificar se o funcionário já existe*/
int verificar(int n){
	int i=0;
	int v[100];
    FILE *file;
    file=fopen("Lista.dat", "r");
    if(!file)
        return 1;
    else{
    	struct funcionario f;
        while (fread(&f, sizeof(struct funcionario), 1, file)){
		 	 v[i]=f.codigo;
		 	 i++;
        }
        fclose(file);
    }
		for(i=0;i<100;i++){
			if(v[i]==n){
				printf("\nCódigo já cadastrado no sistema.");
				printf("\n");
				printf("\n");
				return 1;
			}	
		}	
	return 0;
}

/*Calcular os descontos do salário*/
float salfinal(float sl){
	float INSS=sl*0.11;
	float ValeT=sl*0.06;
	float sfin=sl
	-ValeT-INSS;
	return sfin;
};

/*Exibir a lista de funcionários cadastrados*/
int lista(void){
    FILE *file;
    file=fopen ("Lista.dat", "r");
    if(!file)
    	return 1;
    else{
    	struct funcionario f;
       	system("cls");
		printf("\n--- Lista de Funcionários ---\n");
    	printf("\nFuncionários Cadastrados\n\n");
        printf("---------------------------------------------------\n");
		
		while (fread(&f, sizeof(struct funcionario), 1, file)){
			printf("\nStatus: %s",f.status);
			printf("Nome: %s", f.nome);
            printf("Código: %d",f.codigo);
            printf("\nCargo: %s",f.cargo);
            printf("Salário: R$ %.2f",f.sal); 			
			
			printf("\n\nEndereço: %s",f.casa.end);
            printf("Nº: %s",f.casa.numero);
            printf("Bairro: %s",f.casa.bairro);
            printf("Cidade: %s",f.casa.cidade);
            printf("Estado: %s",f.casa.estado);
            printf("CEP: %s",f.casa.cep);
            printf("Telefone: %s",f.tel);
        	printf("\n");
           
        	float sfin = salfinal(f.sal);
        	printf("Salário com descontos: R$ %.2f\n",sfin);
           
            printf("\n");
            printf("---------------------------------------------------");
      		printf("\n");
        }
    	fclose(file);
    }
    return 0;
}
