#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include <time.h>

int main()
{

	Computador *altoDesempenho = criaComputador();
	Computador *computador1 = criaComputador();
	Computador *computador2 = criaComputador();
	Computador *computador3 = criaComputador();
	Computador *computador4 = criaComputador();
	Computador *computador5 = criaComputador();

	srand(time(NULL));

	int numeroDePacotes = rand() % 501;

	for (int i = 0; i < numeroDePacotes; i++)
	{
		Pacote *pacote = criaPacote();
		pacote->identificacao = i + 1;
		pacote->tamanho = rand() % 101;
		pacote->prioridade = rand() % 3;
		if (pacote->prioridade == 0)
			insere(altoDesempenho->baixaPrioridade, pacote);
		else if (pacote->prioridade == 1)
			insere(altoDesempenho->mediaPrioridade, pacote);
		else if (pacote->prioridade == 2)
			insere(altoDesempenho->altaPrioridade, pacote);

		//altoDesempenho->tamanhoBuffer += pacote->tamanho;
	}

	altoDesempenho->tamanhoBuffer = verificaEspacoOcupado(altoDesempenho);

	printf("Numero de pacotes criados: %d\n", numeroDePacotes);


	computador1->tamanhoBuffer = altoDesempenho->tamanhoBuffer / ((rand() % 4) + 2);
	computador2->tamanhoBuffer = altoDesempenho->tamanhoBuffer / ((rand() % 4) + 2);
	computador3->tamanhoBuffer = altoDesempenho->tamanhoBuffer / ((rand() % 4) + 2);
	computador4->tamanhoBuffer = altoDesempenho->tamanhoBuffer / ((rand() % 4) + 2);
	computador5->tamanhoBuffer = altoDesempenho->tamanhoBuffer / ((rand() % 4) + 2);

	int contadorAltaPrioridade = 0;
	int contadorMediaPrioridade = 0;
	int contadorBaixaPrioridade = 0;
	
	while (verificaEspacoOcupado(altoDesempenho) > 0)
	{
		int espacoOcupadoAtual = verificaEspacoOcupado(altoDesempenho);
		//Enviar 6 de Alta Prioridade
		while (contadorAltaPrioridade != 6 && !filaVazia(altoDesempenho->altaPrioridade))
		{
			Pacote *pacote = &altoDesempenho->altaPrioridade->vet[altoDesempenho->altaPrioridade->inicio];
			int enviadoParaTodos = 1;
			printf("Pacote com prioridade alta de ID %d\n", pacote->identificacao);
			if (verificaEspacoOcupado(computador1) + pacote->tamanho <= computador1->tamanhoBuffer && !verificarEnvio(computador1->altaPrioridade, pacote->identificacao))
			{
				insere(computador1->altaPrioridade, pacote);
				printf("Enviado para PC 1\n");
			}
			else
			{
				printf("Não enviado para PC 1\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador2) + pacote->tamanho <= computador2->tamanhoBuffer && !verificarEnvio(computador2->altaPrioridade, pacote->identificacao))
			{
				insere(computador2->altaPrioridade, pacote);
				printf("Enviado para PC 2\n");
			}
			else
			{
				printf("Não enviado para PC 2\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador3) + pacote->tamanho <= computador3->tamanhoBuffer && !verificarEnvio(computador3->altaPrioridade, pacote->identificacao))
			{
				insere(computador3->altaPrioridade, pacote);
				printf("Enviado para PC 3\n");
			}
			else
			{
				printf("Não enviado para PC 3\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador4) + pacote->tamanho <= computador4->tamanhoBuffer && !verificarEnvio(computador4->altaPrioridade, pacote->identificacao))
			{
				insere(computador4->altaPrioridade, pacote);
				printf("Enviado para PC 4\n");
			}
			else
			{
				printf("Não enviado para PC 4\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador5) + pacote->tamanho <= computador5->tamanhoBuffer && !verificarEnvio(computador5->altaPrioridade, pacote->identificacao))
			{
				insere(computador5->altaPrioridade, pacote);
				printf("Enviado para PC 5\n");
			}
			else
			{
				printf("Não enviado para PC 5\n");
				enviadoParaTodos = 0;
			}

			if (enviadoParaTodos == 0)
			{
				remova(altoDesempenho->altaPrioridade);
				insere(altoDesempenho->altaPrioridade, pacote);
			}
			else
			{

				remova(altoDesempenho->altaPrioridade);
			}

			contadorAltaPrioridade++;
		}

		//Enviar 1 de media a cada 6 de alta

		if (contadorMediaPrioridade != 3 && !filaVazia(altoDesempenho->mediaPrioridade))
		{
			Pacote *pacote = &altoDesempenho->mediaPrioridade->vet[altoDesempenho->mediaPrioridade->inicio];
			int enviadoParaTodos = 1;
			printf("Pacote com prioridade media de ID %d\n", pacote->identificacao);
			if (verificaEspacoOcupado(computador1) + pacote->tamanho <= computador1->tamanhoBuffer && !verificarEnvio(computador1->mediaPrioridade, pacote->identificacao))
			{
				insere(computador1->mediaPrioridade, pacote);
				printf("Enviado para PC 1\n");
			}
			else
			{
				printf("Não enviado para PC 1\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador2) + pacote->tamanho <= computador2->tamanhoBuffer && !verificarEnvio(computador2->mediaPrioridade, pacote->identificacao))
			{
				insere(computador2->mediaPrioridade, pacote);
				printf("Enviado para PC 2\n");
			}
			else
			{
				printf("Não enviado para PC 2\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador3) + pacote->tamanho <= computador3->tamanhoBuffer && !verificarEnvio(computador3->mediaPrioridade, pacote->identificacao))
			{
				insere(computador3->mediaPrioridade, pacote);
				printf("Enviado para PC 3\n");
			}
			else
			{
				printf("Não enviado para PC 3\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador4) + pacote->tamanho <= computador4->tamanhoBuffer && !verificarEnvio(computador4->mediaPrioridade, pacote->identificacao))
			{
				insere(computador4->mediaPrioridade, pacote);
				printf("Enviado para PC 4\n");
			}
			else
			{
				printf("Não enviado para PC 4\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador5) + pacote->tamanho <= computador5->tamanhoBuffer && !verificarEnvio(computador5->mediaPrioridade, pacote->identificacao))
			{
				insere(computador5->mediaPrioridade, pacote);
				printf("Enviado para PC 5\n");
			}
			else
			{
				printf("Não enviado para PC 5\n");
				enviadoParaTodos = 0;
			}

			if (enviadoParaTodos == 0)
			{
				remova(altoDesempenho->mediaPrioridade);
				insere(altoDesempenho->mediaPrioridade, pacote);
			}
			else
			{

				remova(altoDesempenho->mediaPrioridade);
			}

			contadorMediaPrioridade++;
			contadorAltaPrioridade = 0;
		}

		if ((contadorMediaPrioridade == 3 || filaVazia(altoDesempenho->mediaPrioridade)) && !filaVazia(altoDesempenho->baixaPrioridade))
		{
			Pacote *pacote = &altoDesempenho->baixaPrioridade->vet[altoDesempenho->baixaPrioridade->inicio];
			int enviadoParaTodos = 1;
			printf("Pacote com prioridade baixa de ID %d\n", pacote->identificacao);
			if (verificaEspacoOcupado(computador1) + pacote->tamanho <= computador1->tamanhoBuffer && !verificarEnvio(computador1->baixaPrioridade, pacote->identificacao))
			{
				insere(computador1->baixaPrioridade, pacote);
				printf("Enviado para PC 1\n");
			}
			else
			{
				printf("Não enviado para PC 1\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador2) + pacote->tamanho <= computador2->tamanhoBuffer && !verificarEnvio(computador2->baixaPrioridade, pacote->identificacao))
			{
				insere(computador2->baixaPrioridade, pacote);
				printf("Enviado para PC 2\n");
			}
			else
			{
				printf("Não enviado para PC 2\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador3) + pacote->tamanho <= computador3->tamanhoBuffer && !verificarEnvio(computador3->baixaPrioridade, pacote->identificacao))
			{
				insere(computador3->baixaPrioridade, pacote);
				printf("Enviado para PC 3\n");
			}
			else
			{
				printf("Não enviado para PC 3\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador4) + pacote->tamanho <= computador4->tamanhoBuffer && !verificarEnvio(computador4->baixaPrioridade, pacote->identificacao))
			{
				insere(computador4->baixaPrioridade, pacote);
				printf("Enviado para PC 4\n");
			}
			else
			{
				printf("Não enviado para PC 4\n");
				enviadoParaTodos = 0;
			}
			if (verificaEspacoOcupado(computador5) + pacote->tamanho <= computador5->tamanhoBuffer && !verificarEnvio(computador5->baixaPrioridade, pacote->identificacao))
			{
				insere(computador5->baixaPrioridade, pacote);
				printf("Enviado para PC 5\n");
			}
			else
			{
				printf("Não enviado para PC 5\n");
				enviadoParaTodos = 0;
			}

			if (enviadoParaTodos == 0)
			{
				remova(altoDesempenho->baixaPrioridade);
				insere(altoDesempenho->baixaPrioridade, pacote);
			}
			else
			{

				remova(altoDesempenho->baixaPrioridade);
			}

			contadorAltaPrioridade = 0;
			contadorMediaPrioridade = 0;
			contadorBaixaPrioridade = 0;
		}

		if (espacoOcupadoAtual == verificaEspacoOcupado(altoDesempenho))
			break;
	}

	printf("Buffer AD: %d/%d\n", verificaEspacoOcupado(altoDesempenho), altoDesempenho->tamanhoBuffer);

	printf("Buffer C1: %d/%d\n", verificaEspacoOcupado(computador1), computador1->tamanhoBuffer);

	printf("Buffer C2: %d/%d\n", verificaEspacoOcupado(computador2), computador2->tamanhoBuffer);

	printf("Buffer C3: %d/%d\n", verificaEspacoOcupado(computador3), computador3->tamanhoBuffer);

	printf("Buffer C4: %d/%d\n", verificaEspacoOcupado(computador4), computador4->tamanhoBuffer);

	printf("Buffer C5: %d/%d\n", verificaEspacoOcupado(computador5), computador5->tamanhoBuffer);

	// printf("%d\n", numeroDePacotes);

	// printf("Baixa prioridade:\n");
	// filaImprime(altoDesempenho->baixaPrioridade);
	// printf("Media prioridade:\n");
	// filaImprime(altoDesempenho->mediaPrioridade);
	// printf("Alta prioridade:\n");
	// filaImprime(altoDesempenho->altaPrioridade);

	// printf("PC1:\n");
	// printf("Baixa prioridade:\n");
	// filaImprime(computador1->baixaPrioridade);
	// printf("Media prioridade:\n");
	// filaImprime(computador1->mediaPrioridade);
	// printf("Alta prioridade:\n");
	// filaImprime(computador1->altaPrioridade);

	// printf("PC2:\n");
	// printf("Baixa prioridade:\n");
	// filaImprime(computador2->baixaPrioridade);
	// printf("Media prioridade:\n");
	// filaImprime(computador2->mediaPrioridade);
	// printf("Alta prioridade:\n");
	// filaImprime(computador2->altaPrioridade);

	// printf("PC3:\n");
	// printf("Baixa prioridade:\n");
	// filaImprime(computador3->baixaPrioridade);
	// printf("Media prioridade:\n");
	// filaImprime(computador3->mediaPrioridade);
	// printf("Alta prioridade:\n");
	// filaImprime(computador3->altaPrioridade);

	// printf("PC4:\n");
	// printf("Baixa prioridade:\n");
	// filaImprime(computador4->baixaPrioridade);
	// printf("Media prioridade:\n");
	// filaImprime(computador4->mediaPrioridade);
	// printf("Alta prioridade:\n");
	// filaImprime(computador4->altaPrioridade);

	// printf("PC5:\n");
	// printf("Baixa prioridade:\n");
	// filaImprime(computador5->baixaPrioridade);
	// printf("Media prioridade:\n");
	// filaImprime(computador5->mediaPrioridade);
	// printf("Alta prioridade:\n");
	// filaImprime(computador5->altaPrioridade);
	return 0;
}
