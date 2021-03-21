typedef struct lista *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_ord(Lista lst, int elemento);
int remove_ord(Lista lst, int elemento);
void imprime_lista(Lista lst);
int remove_pares(Lista lst);
int maior(Lista lst);
int tamanho(Lista lst);
int iguais(Lista lst1, Lista lst2);
Lista intercala(Lista lst1, Lista lst2);
