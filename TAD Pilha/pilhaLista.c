#include<stdio.h>
#include<stdlib.h>
#include "pilhaLista.h"


struct lista{
	float info;
	struct lista *prox;
};
typedef struct lista Lista;

struct pilha{
	Lista *prim;
};
typedef struct pilha Pilha;


/*Cria uma pilha vazia*/
Pilha* criaPilha(){
	Pilha *p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;

	return p;
}
/*Insere um elemento no início da lista*/
void push(Pilha *p, float valor){
	Lista *novo = (Lista*) malloc(sizeof(Lista));
	novo->info = valor;
	novo->prox = p->prim;
	p->prim = novo;
}
/*Verifica se a pilha está vazia*/
int pilhaVazia(Pilha *p){
	return (p->prim == NULL)
}
float pop(Pilha *p){
	Lista *t;
	float topo;
	if(pilhaVazia(p)){
		printf("Pilha vazia!\n");
		exit(1);
	}
	t = p->prim;
	topo = t->info;
	p->prim = t->prox;
	
	free(t);

	return topo;
}
/*Libera memória*/
void pilhaLibera(Pilha *p){
	Lista *q = p->prim;
	while(q != NULL){
		Lista *t = q->prox;
		free(q);
		q = t;
	}

	free(p);
}
/*Imprime os elementos com lista encadeada*/
void pilhaImprime(Pilha *p){
Lista *q;
	for(q = p->prim; q != NULL; q = q->prox){
		printf("%f\n", q->info);
	}
}