#include<stdio.h>
#include<stdlib.h>
#include "arvore.h"

struct arv{
	float info;
	struct arv *esq;
	struct arv *dir;
};
typedef struct arv Arv;

/*Cria uma arvore vazia*/
Arv* criaVazia(){
	return NULL;
}

/*Cria uma árvore não vazia*/
Arv* cria(float c, Arv *sae, Arv *sad){
	Arv* a = (Arv*) malloc(sizeof(Arv));
	a->info = c;
	a->esq = sae;
	a->dir = sad;

	return a;
}

/*Verifica se está vazia*/
int arvoreVazia(Arv *a){
	return (a == NULL);
}

/*Imprime pré-ordem (trata raiz, percorre sae, percorre sad)*/
void imprimePre(Arv *a){
	if(!arvoreVazia(a)){
		printf("%.2f ",a->info);
		imprimePre(a->esq);
		imprimePre(a->dir);
	}
}
/*Imprime simétrico (percorre sae, trata raiz, percorre sad)*/
void imprimeSim(Arv *a){
	if(!arvoreVazia(a)){
		imprimeSim(a->esq);
		printf("%.2f ",a->info);
		imprimeSim(a->dir);
	}
}
/*Imprime pós-ordem (percorre sae, percorre sad, trata raiz)*/
void imprimePos(Arv *a){
	if(!arvoreVazia(a)){
		imprimePos(a->esq);
		imprimePos(a->dir);
		printf("%.2f ",a->info);
	}
}
 
/*Libera árvore*/
Arv* libera(Arv *a){
	if(!arvoreVazia(a)){
		libera(a->esq);
		libera(a->dir);
		free(a);
	}
	return NULL;
}

/*Função que imprime somente as folhas (1.50, 2.00 e 3.00)*/
void imprimeFolhas(Arv *a){
	if (!arvoreVazia(a)){
		if (arvoreVazia(a->esq) && arvoreVazia(a->dir)){
			printf("%.2f ",a->info);
		}else{
			imprimeFolhas(a->esq);
			imprimeFolhas(a->dir);
		}
				
	}
}

/*Função que imprime quantas folhas tem a árvore*/
int contaFolhas(Arv *a){
	if (!arvoreVazia(a)){
		if (arvoreVazia(a->esq) && arvoreVazia(a->dir)){
			return 1;
		}else{
			return contaFolhas(a->esq) + contaFolhas(a->dir);
		}		
	}
}