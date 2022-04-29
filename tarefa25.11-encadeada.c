#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct filme{
	char nome[10];
	char categoria[10];
};

struct elemento{
	struct filme f;
	struct elemento *prox;
};

typedef struct elemento *lista;
typedef struct elemento Elem;


lista* crialista(){
	lista* li = (lista*)malloc(sizeof(lista));
	
	if(li != NULL){
		*li = NULL;
	}
	
	return li;
}

int inserirnalista(struct filme fi, lista* li){
	if(li == NULL){
		return 0;
	}
	
	Elem* no = (Elem*)malloc(sizeof(Elem));
	
	if(no == NULL){
	}
	
	no->f = pc;
	no->prox = (*li); 
	*li = no;
	
	return 1;
}

void mostra(lista*li){
	
	Elem* aux = *li;
	
	while(aux != NULL){
	
		printf("%s \n", aux->f.nome);
		printf("%s \n", aux->f.categoria);
	
	aux = aux->prox;
	}
}

int main (void){
	struct filme cadastrafilme;
	int op=0, i, ok;
	lista* li;
	li = crialista();
	
	while(op == 0){
		fgetc(stdin);
		printf("informe o nome do filme: ");
		fgets(cadastrafilme.nome, 10, stdin);
			
		printf("informe a categoria do filme: ");
		fgets(cadastrafilme.categoria, 10, stdin);
			
		ok = inserirnalista(cadastrafilme, li);
			
		printf("deseja continuar? 0-sim\n");
		scanf("%d", &op);
	}
	mostra (li);
	free(li);
}
