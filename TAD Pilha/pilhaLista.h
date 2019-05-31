typedef struct lista Lista;
typedef struct pilha Pilha;

Pilha* criaPilha();
void push(Pilha *p, float valor);
int pilhaVazia(Pilha *p);
float pop(Pilha *p);
void pilhaLibera(Pilha *p);
void pilhaImprime(Pilha *p);
