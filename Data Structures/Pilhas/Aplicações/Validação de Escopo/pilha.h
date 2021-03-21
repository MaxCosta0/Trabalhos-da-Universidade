typedef struct no *Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int push(Pilha *p, char elemento);
int pop(Pilha *p, char *elemento);
int le_topo(Pilha *p, char *elemento);
void imprime(Pilha p);