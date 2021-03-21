typedef struct lista *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elemento(Lista lst, int elemento);
int remove_elemento(Lista lst, int elemento);
void imprime_lista(Lista lst);
int remove_todos(Lista lst, int elemento);
int insere_no_inicio(Lista lst, int elemento);
int remove_impares(Lista lst);
int menor(Lista lst);
int tamanho(Lista lst);
Lista concatena(Lista lst1, Lista lst2);
