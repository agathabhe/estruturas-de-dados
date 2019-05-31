#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"


int main(){
	
	Pilha* l;
	Pilha* m;
	
	l = criaPilha();
	push(l, 4);
	push(l, 5);
	push(l, 6);

	m = criaPilha();
	push(m, 7);
	push(m, 8);
	push(m, 9);

	//Imprime o topo
	//printf("%.2f\n", topo(l));

	concatenaPilha(l, m);
	printf("imprime pilha\n");
	pilhaImprime(l);
	
	return 0;
}