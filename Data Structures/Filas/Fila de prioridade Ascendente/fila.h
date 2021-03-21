typedef struct fila *Fila;
typedef struct no *No;

Fila criar_fila();
int fila_vazia(Fila f);
int insere_ordenado(Fila f, int elemento);
int remove_inicio(Fila f, int *elemento);
void imprime(Fila f);

