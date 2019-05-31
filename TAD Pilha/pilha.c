#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"


#define TAM 50

struct pilha{
	int qtdeItens;
	float vet[TAM];
};

typedef struct pilha Pilha;

/*Cria uma pilha vazia*/
Pilha* criaPilha(){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->qtdeItens = 0; /*inicializa com zero elementos*/
	
	return p;
}

/*Insere um elemento na pilha */
void push(Pilha *p, float valor){
	if (p->qtdeItens == TAM){
		printf("Pilha cheia!\n");
		exit(1);
	}

	p->vet[p->qtdeItens] = valor;
	p->qtdeItens++;
}

/*Remove o elemento do topo*/
float pop(Pilha *p){
	float topo;
	if (pilhaVazia(p)){
		printf("Pilha vazia!\n");
		exit(1);
	}
	topo = p->vet[p->qtdeItens - 1];
	p->qtdeItens--;
	
	return topo;
}

/*Verifica se a pilha está vazia*/
int pilhaVazia(Pilha *p){
	return (p->qtdeItens == 0);
}

/*Libera a pilha*/
void pilhaLibera(Pilha *p){
	free(p);
}

/*Imprime os elementos com vetor*/
void pilhaImprime(Pilha *p){
	for (int i = (p->qtdeItens - 1); i >= 0; i--){
		printf("%.2f\n",p->vet[i]);
	}
}

/*Uma função que receba uma pilha como parâmetro e retorne o
valor armazenado em seu topo, restaurando o conteúdo da pilha*/
float topo(Pilha *p){

	float valor = pop(p);
	push(p, valor);
	
	return valor;
}

/*Uma função que receba duas pilhas, p1 e p2, e passe todo os
elementos da pilha p2 para o topo da pilha p1*/
void concatenaPilha(Pilha *p1, Pilha *p2){
	if (pilhaVazia(p2)){
		printf("Pilha vazia!\n");
		exit(1);
	}
	float valor;

	for(int i = (p2->qtdeItens - 1); i >= 0; i--){	
		valor = pop(p2);
		push(p1, valor);
	}
}

/*Uma função que receba uma pilha como parâmetro e retorne como
resultado uma cópia dessa pilha*/
Pilha* copiaPilha(Pilha *p){

}