typedef struct pilha Pilha;

Pilha* criaPilha();
void push(Pilha *p, float valor);
float pop(Pilha *p);
int pilhaVazia(Pilha *p);
void pilhaLibera(Pilha *p);
void pilhaImprime(Pilha *p);
float topo(Pilha *p);
void concatenaPilha(Pilha *p1, Pilha *p2);
Pilha* copiaPilha(Pilha *p);