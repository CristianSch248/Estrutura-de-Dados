/*
Desenvolva um algoritmo que implemente um caso de
ordenação por seleção de um vetor de N elementos.
*/

#include<stdio.h>
#include<stdlib.h>

int ordenaVetor(int *vet, int cont){
	
	int i, j, aux, menor, indice;
	
	for(i=0; i<cont; i++){
		
		menor = *(vet + i);
		indice = i;
		
		for(j=i+1; j<cont; j++){
			if(*(vet + j) < menor){
				menor = *(vet + j);
				indice = j;
			}	
		}
		aux = *(vet + i);
		*(vet + i) = *(vet + indice);
		*(vet + indice) = aux;	
	}
	
	for(i=0; i<cont; i++){
		printf("%d ", *(vet + i));
	}
	
	return 0;
}

int main(void){
	int cont=0, num;
	int *v;
	
	v = (int *) malloc (sizeof (int));
	
	do{
		printf("Informe um numero maior que ZERO:");
		scanf("%d", &num);
		
		if(num >= 0){
			*(v + cont) = num;
			cont++;
			
			v=(int*)realloc(v,sizeof(int));
		}	
	}while(num >= 0);
	
	ordenaVetor(v, cont);

	free(v);
}
