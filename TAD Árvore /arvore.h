typedef struct arv Arv;
Arv* criaVazia();
Arv* cria(float c, Arv *sae, Arv *sad);
void imprimePre(Arv *a);
void imprimeSim(Arv *a);
void imprimePos(Arv *a);
int arvoreVazia(Arv *a);
Arv* libera(Arv *a);
void imprimeFolhas(Arv *a);
int contaFolhas(Arv *a);