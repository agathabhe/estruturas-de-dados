#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"


int main(){
	
	Arv *a = cria(3.5,
				cria(2.5,
					criaVazia(),
					cria(1.5, criaVazia(), criaVazia())
				),
				cria(1.0, 
					cria(2.0, criaVazia(), criaVazia()),
					cria(3.0, criaVazia(), criaVazia())
				)
			);
	printf("Pré-ordem\n");
	imprimePre(a);
	printf("\n");
	printf("Simétrico\n");
	imprimeSim(a);
	printf("\n");
	printf("Pós-ordem\n");
	imprimePos(a);
	printf("\n");

	printf("Folhas\n");
	imprimeFolhas(a);
	printf("\n");

	
	printf("%d\n ", contaFolhas(a));
	return 0;
}