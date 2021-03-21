typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elemento(Lista *end_lst, int elemento);
int remove_elemento(Lista *end_lst, int elemento);
void imprime_lista(Lista *lst);
int remove_todos(Lista *lst, int elemento);
int insere_no_final(Lista *end_lst, int elemento);
int remove_impares(Lista *end_lst);
int menor(Lista lst);
int tamanho(Lista lst);
Lista concatena(Lista *lst1, Lista *lst2);

