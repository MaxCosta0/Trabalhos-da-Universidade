typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elemento(Lista *lst, int elemento);
int remove_elemento(Lista *lst, int elemento);
void imprime(Lista lst);
