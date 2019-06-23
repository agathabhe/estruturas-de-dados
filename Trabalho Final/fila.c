#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/*Cria uma fila vazia*/
Fila *criaFila()
{
	Fila *f = (Fila *)malloc(sizeof(Fila));
	f->n = 0;
	f->inicio = 0;

	return f;
}

Computador *criaComputador()
{
	Computador *computador = (Computador *)malloc(sizeof(Computador));
	computador->tamanhoBuffer = 0;
	computador->altaPrioridade = criaFila();
	computador->mediaPrioridade = criaFila();
	computador->baixaPrioridade = criaFila();

	return computador;
}

Pacote *criaPacote()
{
	Pacote *pacote = (Pacote *)malloc(sizeof(Pacote));
	pacote->identificacao = 0;
	pacote->tamanho = 0;
	pacote->prioridade = -1;

	return pacote;
}

/*Insere um elemento na fila*/
void insere(Fila *f, Pacote *pacote)
{
	int fim;
	if (f->n == TAM)
	{
		printf("Fila cheia!");
		exit(1);
	}
	fim = (f->inicio + f->n) % TAM;
	f->vet[fim] = *pacote;
	f->n++;
}

/*Verifica se a fila está vazia*/
int filaVazia(Fila *f)
{
	return (f->n == 0);
}

/*Libera a memória da fila*/
void libera(Fila *f)
{
	free(f);
}

/*Remove um elemento da fila*/
Pacote remova(Fila *f)
{
	Pacote pacote;
	if (filaVazia(f))
	{
		printf("Fila vazia!\n");
		exit(1);
	}
	pacote = f->vet[f->inicio];
	f->inicio = (f->inicio + 1) % TAM;
	f->n--;

	return pacote;
}

/*Imprime os elementos com vetor*/
void filaImprime(Fila *f)
{
	for (int i = 0; i < f->n; i++)
	{
		printf("Identificacao do pacote: %d\n", f->vet[(f->inicio + i) % TAM].identificacao);
	}
}

int verificarEnvio(Fila *f, int identificacao)
{
	for (int i = 0; i < f->n; i++)
	{
		if (f->vet[(f->inicio + i) % TAM].identificacao == identificacao)
			return 1;
	}
	return 0;
}

int verificaEspacoOcupado(Computador *computador)
{
	int espacoOcupado = 0;
	for (int i = 0; i < computador->baixaPrioridade->n; i++)
	{
		espacoOcupado += computador->baixaPrioridade->vet[(computador->baixaPrioridade->inicio + i) % TAM].tamanho;
	}
	for (int i = 0; i < computador->mediaPrioridade->n; i++)
	{
		espacoOcupado += computador->mediaPrioridade->vet[(computador->mediaPrioridade->inicio + i) % TAM].tamanho;
	}
	for (int i = 0; i < computador->altaPrioridade->n; i++)
	{
		espacoOcupado += computador->altaPrioridade->vet[(computador->altaPrioridade->inicio + i) % TAM].tamanho;
	}
	return espacoOcupado;
}