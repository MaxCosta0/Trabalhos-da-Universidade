/*
	Grupo MJB
	Integrantes:
	Maxley Soares da Costa		11911BCC038
	Joao Vitor Afonso Pereira	11911BCC037
	Bruno Olivera Sinhoroto		11821BCC044
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "GrupoMJB.h"

#define MAXC 3
const int METADE = ceil(MAXC/2);

//Formato de um noh de uma arvore B
struct NO{
	int qteChaves;					//qte de valores dentro de um noh
	int chave[MAXC];				//valores dentro de um noh
	int ehfolha;					//identidade do noh
	struct NO *filho[MAXC+1];		//vetor de ponteiros para os filhos do noh
};

//Funcao para criar uma nova arvore B
ArvB* cria_ArvB(){

	//Cria ponteiro para ponteiro de uma arvore B
	ArvB* nodo = (ArvB*) malloc(sizeof(ArvB));

	//Inicializa conteudo do ponteiro criado
	if(nodo != NULL){
		*nodo = NULL;
	}

	return nodo;
}

//Funcao que libera o noh raiz e chama uma recursao que libera o resto da arvore
void libera_ArvB(ArvB *raiz){

	//nao existe arvore a ser deletada
	if(raiz == NULL)
		return;

	//Libera o resto da arvore
	libera_NO(*raiz);

	//libera o noh raiz;
	free(raiz);
}

//Funcao auxiliar que libera noh a noh da arvore B
void libera_NO(ArvB nodo){

	//Caso seja filho de um noh folha
	if(nodo == NULL)
		return;

	//Chama a Funcao recursivamente ate os nohs folha
	for(int i = 0; i <= MAXC; i++)
		libera_NO(nodo->filho[i]);

	//libera um noh da arvore
	free(nodo);
	nodo = NULL;
}

//Funcao que insere uma nova chave na arvore
int insere_ArvB(ArvB *raiz, int valor){

	//Caso nao exista arvore para inserir
	if(raiz == NULL)
		return 0;


	//Caso a arvore seja vazia, devemos criar uma
	if(ehVazia_ArvB(raiz)){
		ArvB nodo;

		//Aloca um novo noh
		nodo = (ArvB) malloc(sizeof(struct NO));


		//Inicializando os filhos do novo noh
		for(int i = 0; i <= MAXC; i++)
			nodo->filho[i] = NULL;

		//Inicializando os valores do novo noh
		nodo->chave[0] = valor;
		nodo->qteChaves = 1;
		nodo->ehfolha = 1;

		//O noh criado sera apontado pelo ponteiro raiz
		*raiz = nodo;

		return 1;
	}

	//nohs auxiliares
	ArvB ant = *raiz;
	ArvB atual = *raiz;

	//Procura o noh onde a nova chave deve ser inserida
	while(atual != NULL){
		ant = atual;

		//Desce na arvore quando a chave for maior do que o valor
		for(int i = 0; i < atual->qteChaves; i++){
			if(valor <= atual->chave[i]){
				atual = ant->filho[i];
				break;
			}
		}

		//Caso especial onde o valor a inserir eh maior do que todas as chaves do noh
		if(atual == ant)
			atual = ant->filho[atual->qteChaves];
	}

	//Inicializando o noh auxiliar para utilizacao
	for(int i = 0; i <= MAXC; i++)
		ant->filho[i] = NULL;

	//Insere o elemento na arvore
	insere_NO(&(ant), valor);

	//rebalanceia nohs prestes a esourar
	reorganiza_ArvB(&(*raiz), valor);

	return 1;
}

//Funcao auxiliar para inserir um valor na arvore
int insere_NO(ArvB *nodo, int valor){

	int i = 0;

	//Auxiliar para simplificar a escrita
	ArvB temp = *nodo;

	//Procura a posicao onde o valor deve ser inserido
	for(i = 0; i < (temp)->qteChaves; i++){

		//Caso tenha encontrado a posicao de insercao
		if(valor < (temp)->chave[i]){

			//Desloca as chaves maiores para a direita
			for(int j = (temp)->qteChaves; j > i; j--){
				(temp)->chave[j] = (temp)->chave[j-1];
			}

			//Insere o valor no noh
			(temp)->chave[i] = valor;
			(temp)->qteChaves++;

			return 1;
		}

		//Caso o valor a ser inserido ja esteja na arvore.
		else if(valor == (temp)-> chave[i]){
			return 0;
		}
	}

	//Atualiza as caracteristicas do noh
	(temp)->qteChaves++;
	(temp)->chave[i] = valor;

	return 1;
}

//Funcao para rebalancear a Arvore
void reorganiza_ArvB(ArvB *nodo, int valor){

	//nohs auxiliares
	ArvB ant = *nodo;
	ArvB atual = *nodo;

	//Variavel auxiliar para determinar se o ponto de interesse eh a raiz
	int ehraiz = 1;

	//Desce na arvore ate encontrar o noh onde o valor foi inserido
	while( (atual != NULL) && (atual->qteChaves <= MAXC) ){
		ant = atual;


		for(int i = 0; i < atual->qteChaves; i++){
			if(valor <= ant->chave[i]){
				atual = ant->filho[i];
				ehraiz = 0;
				break;
			}
		}

		if(atual == ant){
			atual = ant->filho[atual->qteChaves];
			ehraiz = 0;
		}
	}

	//Caso nao houver estouro de um noh
	if(atual == NULL)
		return;

	//Caso o estouro tiver ocorrido em um noh
	if(!ehraiz){

		//Divide um noh
		nodo = divide_NO(&ant);

		//Propaga o resultado da divis�o do noh
		reorganiza_ArvB(nodo, valor);
	}

	//Caso o estouro tiver ocorrido na raiz
	else{

		//Divide um noh raiz
		*nodo = divide_NO_raiz(nodo);
		return;
	}

	return;
}

//Funcao que divide um noh da arvore
ArvB divide_NO(ArvB* nodo){
	int aux;

	//Auxiliar para simplificar escrita
	ArvB n0 = *nodo;

	//Procura noh alvo desbalanceado
	for(int i = 0; i < MAXC; i++){
		if((n0)->filho[i]->qteChaves >= MAXC){
			n0 = (n0)->filho[i];
			aux = i;
			break;
		}
	}

	//Cria primeiro noh auxiliar
	ArvB n1;

	//Aloca e inicializa noh auxiliar
	n1 = (ArvB) malloc(sizeof(struct NO));
	n1->qteChaves = 0;
	n1->ehfolha = 1;

	//Inicializa os filhos do noh auxiliar
	for(int i = 0; i <= MAXC; i++)
		n1->filho[i] = NULL;

	//Insere a primeira metade das chaves do noh alvo no noh auxiliar
	for(int i = 0; i < METADE; i++)
		insere_NO(&n1, n0->chave[i]);

	//Faz os filhos do noh auxiliar apontar para os filhos do noh alvo
	for(int i = 0; i <= METADE; i++)
		n1->filho[i] = n0->filho[i];


	//Cria segundo noh auxiliar
	ArvB n2;

	n2 = (ArvB) malloc(sizeof(struct NO));
	n2->qteChaves = 0;
	n2->ehfolha = 1;

	for(int i = 0; i <= MAXC; i++)
		n2->filho[i] = NULL;

	//Insere a segunda metade das chaves do noh alvo no noh auxiliar
	for(int i = METADE+1; i < n0->qteChaves; i++)
		insere_NO(&n2, n0->chave[i]);

	for(int i = 0; i <= METADE; i++)
		n2->filho[i] = n0->filho[METADE+1+i];


	//Reajustando os filhos do noh antigo
	for(int i = MAXC; i > aux; i--)
		(*nodo)->filho[i] = (*nodo)->filho[i-1];

	//O noh antigo recebe a chave do meio e se torna a nova raiz
	insere_NO(nodo, n0->chave[METADE]);

	//Ajustando valores do noh antigo
	(*nodo)->filho[aux] = n1;
	(*nodo)->filho[aux+1] = n2;
	(*nodo)->ehfolha = 0;


	return nodo;

}

//Funcao que divide a raiz da arvore
ArvB divide_NO_raiz(ArvB* nodo){

    //Cria arvore auxiliar
	ArvB n0;
	n0 = (ArvB) malloc(sizeof(struct NO));
	n0->qteChaves = 0;
	n0->ehfolha = 0;

    //Inicializa os filhos do auxiliar
	for(int i = 0; i <= MAXC; i++)
		n0->filho[i] = NULL;

    //Insere a primeira metade das chaves da raiz alvo na raiz auxiliar
	for(int i = 0; i < METADE; i++)
		insere_NO(&n0, (*nodo)->chave[i]);

    //Faz os filhos do noh auxiliar apontarem para os filhos da raiz
	for(int i = 0; i <= METADE; i++)
		n0->filho[i] = (*nodo)->filho[i];

    //Cria segundo auxiliar
	ArvB n1;
	n1 = (ArvB) malloc(sizeof(struct NO));
	n1->qteChaves = 0;
	n1->ehfolha = 0;

	for(int i = 0; i <= MAXC; i++)
		n1->filho[i] = NULL;

    //Insere a segunda metade das chaves da raiz alvo na raiz auxiliar
	for(int i = METADE+1; i < (*nodo)->qteChaves; i++)
		insere_NO(&n1, (*nodo)->chave[i]);

	for(int i = 0; i <= METADE; i++)
		n1->filho[i] = (*nodo)->filho[METADE+1+i];

    //Cria segundo auxiliar
	ArvB n2;
	n2 = (ArvB) malloc(sizeof(struct NO));
	n2->qteChaves = 0;
	n2->ehfolha = 0;

	for(int i = 0; i <= MAXC; i++)
		n2->filho[i] = NULL;

    //Faz o auxiliar receber o valor do meio da chave se tornando a nova raiz
	insere_NO(&n2, (*nodo)->chave[METADE]);

	//Ajusta os valores
	n2->filho[0] = n0;
	n2->filho[1] = n1;

	return n2;
}

//Funcao para remocao de chaves da arvore
int remove_ArvB(ArvB *raiz, int valor){
    //Nohs Auxiliares
	ArvB ant = *raiz;
	ArvB atual = *raiz;

	//Procura a chave a ser removida
	while(atual != NULL){
		ant = atual;

        //Desce na arvore se a chave for maior que o valor
		for(int i = 0; i < atual->qteChaves; i++){
			if(valor <= atual->chave[i]){
				atual = ant->filho[i];
				break;
			}
		}

        //Caso especial para quando o valor a ser removido for maior que todas as chaves
		if(atual == ant)
			atual = ant->filho[atual->qteChaves];
	}

	//Remove o elemento
	if(remove_Valor(&ant, valor))
		return 1;

	return 0;
}

//Funcao auxiliar para remover o valor da arvore
int remove_Valor(ArvB *nodo, int valor){
	int alvo = 0;

	//Procura a posicao do valor a ser removido
	for(int i = 0; i < (*nodo)->qteChaves; i++){

        //Caso tenha encontrado o valor a ser removido
		if(valor == (*nodo)->chave[i]){
			alvo = i;
			break;
		}

		//O valor nao esta na arvore
		else if(valor > (*nodo)->chave[i]){
			return 0;
		}
	}

	//Desloca as chaves para a esquerda
	for(int i = alvo; i > (*nodo)->qteChaves; i--){
		(*nodo)->chave[i] = (*nodo)->chave[i+1];
	}

	//Diminui a quantidade de chave
	(*nodo)->qteChaves--;
	return 1;
}

//Funcao para buscar um valor na arvore
int busca_ArvB(ArvB *raiz, int valor){

    //Nao existe arvore
	if(raiz == NULL)
		return 0;

    //Nohs Auxiliares
	ArvB atual = *raiz;
	ArvB ant = *raiz;

	//Procura a chave desejada
	while(atual != NULL){
		ant = atual;

		//Se encontrar o valor procurado retorna
		for(int i = 0; i < atual->qteChaves; i++){
			if(valor == atual->chave[i])
				return 1;
		}

		//Desce na arvore se a chave for maior que o valor
		for(int i = 0; i < atual->qteChaves; i++){
			if(valor <= atual->chave[i]){
				atual = ant->filho[i];
				break;
			}
		}

        //Caso especial: o valor buscado eh maior que todas as chaves do noh
		if(atual == ant){
			atual = ant->filho[atual->qteChaves];
		}
	}

	return 0;
}

//Funcao para verificar se a arvore eh vazia
int ehVazia_ArvB(ArvB *raiz){
	//Nao existe arvore, entao eh vazia
	if(raiz == NULL)				
		return 1;

	//Arvore vazia
	if(*raiz == NULL)		
		return 1;

	return 0;
}

//Funcao para calcular a quantidade de nohs da arvore
int totalNO_ArvB(ArvB *raiz){
	int cont = 0;

	//Chama funcao recursiva que calcula a quantidade de nohs
	return total(raiz, &cont);
}

//Funcao auxiliar para calcular a quantidade de nohs da arvore
int total(ArvB *raiz, int *cont){
	//Caso em que nao existe nenhum noh
	if(ehVazia_ArvB(raiz))
		return 0;

	//Incrementa ponteiro que guarda a quantidade de nohs
	*cont = *cont + 1;

	// Percorre a arvore de forma recursiva incrementando os nohs
	for(int i = 0; i < (*raiz)->qteChaves; i++){
		total(&((*raiz)->filho[i]), cont);
	}
	
	return *cont;

}

//Funcao para printar as chaves da arvore (em-ordem)
void emOrdem(ArvB *raiz){
    // Caso em que a arvore nao esta alocada
	if(raiz == NULL)
        return;

	// Se a Arvore nao for vazia
    if(*raiz != NULL){

    	//Pe
        for(int i = 0; i < (*raiz)->qteChaves; i++){

        	//Desce até o ultimo noh da arvore de forma recursiva
        	emOrdem(&((*raiz)->filho[i]));

        	//printa as chaves do noh
            printf("%d ", (*raiz)->chave[i]);
        }

        //Desce nos filhos da chave mais a direita do noh
        emOrdem(&((*raiz)->filho[(*raiz)->qteChaves]));

    }

    return;
}
