typedef struct deque *Deque;

Deque cria_deque();
int deque_vazia(Deque d);
int deque_cheia(Deque d);
int insere_inicio(Deque d, int elemento);
int insere_fim(Deque d, int elemento);
int remove_inicio(Deque d, int *elemento);
int remove_fim(Deque d, int *elemento);
void imprime(Deque d);