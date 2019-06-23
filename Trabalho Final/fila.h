#define TAM 500

/*Prioridades: 0 baixa, 1 média, 2 alta*/
struct pacote{
	int identificacao;
	int tamanho;
	int prioridade;
};typedef struct pacote Pacote;

struct fila{
	int n;
	int inicio;
	Pacote vet[TAM];
};
typedef struct fila Fila;

struct computador{
    int tamanhoBuffer;
   	Fila *altaPrioridade;
	Fila *mediaPrioridade;
	Fila *baixaPrioridade;
    
};typedef struct computador Computador;

Fila* criaFila();
void insere(Fila *f, Pacote *pacote);
int filaVazia(Fila *f);
void libera(Fila *f);
Pacote remova(Fila *f);
void filaImprime(Fila *f);
Computador* criaComputador();
Pacote* criaPacote();
int verificaEspacoOcupado(Computador *computador);
int verificarEnvio(Fila *f, int identificacao);