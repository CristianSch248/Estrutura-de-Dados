/*
Implementar um programa para a biblioteca setorial do politécnico, 
onde o programa vai: 
cadastrar,
remover e
mostrar livros 
(id, nome, quandidade de cópias).
A estrutura de armazenamento dos livros deve ser feito em pilha.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 3

struct livro{
	int id;
	char nome[50];
	int qtdd_cop;
};

struct pilha{
	int qtdd;
	struct livro info[TAM];
};

typedef struct pilha Pilha_de_livro;

Pilha_de_livro* criar(){
	Pilha_de_livro *Pil;
	
	Pil = (Pilha_de_livro*) malloc(sizeof(struct pilha));
	
	if(Pil == NULL){
		printf("Erro para alocar espaço!!!\n");
	}
	else{
		printf("pilha criada!!!\n");
		Pil->qtdd = 0;
		return Pil;
	}
	
}

//inserir
int push(Pilha_de_livro* Pil, struct livro obra){
	printf("estou aqui\n");
	if (Pil == NULL){
		printf("Deu alguma coisa errada!!!\n");
		return 0;
	}
	
	if(Pil->qtdd == TAM){
		printf("pilha esta cheia!!!\n");
		return 0;
	}
	else{
		Pil->info[Pil->qtdd] = obra;
		Pil->qtdd++;
		return 1;
		printf("Livro inserido com sucesso!!!\n");
	}	
}

void mostrarLivros(Pilha_de_livro* Pil){
	printf("estou aqui\n");
	int i=0;
	
	if(Pil == NULL){
		return 0;
	}
	
	for(i = Pil->qtdd-1; i >= 0; i--){
		puts(Pil->info[i].nome);
		printf("\n");
		printf("ID: [%d]\n", Pil->info[i].id);
		printf("Quantidade: [%d]\n", Pil->info[i].qtdd_cop);
	}
}

int pop(Pilha_de_livro* Pil){
	
	printf("estou aqui\n");
	
	if(Pil == NULL || Pil->qtdd == 0){
		return 0;
	}
	else{
		Pil->qtdd--;
		return 1;
	}
}

int liberaPilhaDeLivros(Pilha_de_livro* Pil){
	free(Pil);
}

int main (void){
	
	struct livro exemplar;
	int op;
	Pilha_de_livro* Pil = criar();
	
	do{
		printf("1 - inserir livros na pilha: \n");
		printf("2 - remover livros da pilha: \n");
		printf("3 - mostrar a pilha de livros: \n");
		printf("4 - sair\n");
		printf("opcao:");
		scanf("%d", &op);
		
		switch (op){
			case 1:{
				setbuf(stdin, NULL);
				printf("Nome do livro: ");
				gets(exemplar.nome);
				
				printf("ID do livro:");
				scanf("%d", &exemplar.id);
				
				printf("Quantidade de copias: ");
				scanf("%d", &exemplar.qtdd_cop);
				
				push(Pil, exemplar);
				break;
			}
			case 2:{
				pop(Pil);
				break;
			}
			case 3:{
				mostrarLivros(Pil);
				break;
			}
			case 4:{
				printf("sair!!!\n");
				
				break;
			}
			default:{
				printf("opcão errada!!!\n");
				break;
			}
		}
	}while(op =! 4);
	liberaPilhaDeLivros(Pil);
}
