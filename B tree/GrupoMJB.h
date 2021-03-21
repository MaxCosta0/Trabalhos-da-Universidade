typedef struct NO *ArvB;

//Função para criar uma Arvore B
ArvB* cria_ArvB();

//Funções para apagar e liberar a Arvore B
void libera_ArvB(ArvB *raiz);
void libera_NO(ArvB nodo);

//Funções para inserir um valor na Arvore B
int insere_ArvB(ArvB* raiz, int valor);
int insere_NO(ArvB *nodo, int valor);
void reorganiza_ArvB(ArvB* nodo, int valor);
ArvB divide_NO(ArvB* nodo);
ArvB divide_NO_raiz(ArvB* nodo);

//Funções para remover um elemento da Arvore B
int remove_ArvB(ArvB *raiz, int valor);
int remove_Valor(ArvB *nodo, int valor);

//Função para buscar um elemento na Arvore B
int busca_ArvB(ArvB *raiz, int valor);

//Função para verificar se uma Arvore B é vazia
int ehVazia_ArvB(ArvB *raiz);

//Funções para verificar quantos nós tem a Arvore B
int totalNO_ArvB(ArvB *raiz);
int total(ArvB *raiz, int *cont);

//Função para mostrar os valores da Arvore B na tela
void emOrdem(ArvB *raiz);