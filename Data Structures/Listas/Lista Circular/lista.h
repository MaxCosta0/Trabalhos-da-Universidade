typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_fim(Lista *lst, int elemento);
int remove_inicio(Lista *lst, int *elemento);
void imprime(Lista lst);