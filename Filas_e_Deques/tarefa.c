/*
Desenvolva um programa onde uma função que ordene os
valores de um vetor de N elementos. Ao final, o programa deve
exibir o vetor de forma ordenada.
*/
#include<stdio.h>
#include<stdlib.h>

int ordenaVetor(int *vet, int cont){
	int i = 0;
	int j = 0;
	int aux;
	
	for(i=0; i<cont; i++){
		for(j=i; j<cont; j++){
			if(*(vet + i) >= *(vet + j)){
				aux = *(vet + i);
				*(vet + i) = *(vet + j);
				*(vet + j) = aux;
			}
		}
	}
	
	for(i=0; i<cont; i++){
		printf("%d ", *(vet + i));
	}
	return 0;
}

int main (void){
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
