/*1-Remover duplicações de uma lista:  
	[a, a, a, b, b, c, c, d, a, a] → [a, b, c, d, a]
*/
removeDup([],[]).
removeDup([X],[X]).
removeDup([X,X|Xs],Zs) :- removeDup([X|Xs],Zs).
removeDup([X,Y|Ys],[X|Zs]) :- X \= Y, removeDup([Y|Ys],Zs).

/*2-Empacota elementos iguais em sublistas
	 [a, a, a, b, b, c, c, d, a, a] → [[a, a, a], [b, b], [c, c], [d], [a, a]]
*/
insere([H|T], X, Lista):- append(H, [X], L), Lista = [L|T].


empacota([X], [[X]]).
empacota([X,X|T], Lista):- empacota([X|T], L), insere(L, X, Lista), !.
empacota([X,Y|T], Lista):- empacota([Y|T], L), append([[]], L, L1), insere(L1, X, Lista).

/*3-Desempacota lista
	[[4, a], [1, b], [2, c], [2, a]] → [a, a, a, a, b, c, c, a, a]
*/
repete(X, 1, Entrada, [X|Entrada]):- !.
repete(X, N, Entrada, Saida):- N > 1, N1 is N - 1, repete(X, N1, Entrada, S), Saida = [X|S].

descompacta([], []).
descompacta([[Q, C]|T], Lista):- descompacta(T, L), repete(C, Q, L, Lista).

/*4-Duplica todos os elementos da lista*/
duplica([],[]).
duplica([X|Xs],[X,X|Ys]) :- duplica(Xs,Ys).

/*5-Ordena Lista*/
ordenada([]):- !.
ordenada([_]):- !.
ordenada([X1, X2|T]):- X1 =< X2, ordenada([X2|T]).

maiorNoFinal([H1, H2], [H1, H2]):- H1 =< H2, !.
maiorNoFinal([H1, H2], [H2, H1]):- H2 < H1, !.
maiorNoFinal([H1, H2|T], [H1|L]):- H1 =< H2, maiorNoFinal([H2|T], L), !.
maiorNoFinal([H1, H2|T], [H2|L]):- H2 < H1, maiorNoFinal([H1|T], L).

ordena(Entrada, Entrada):- ordenada(Entrada), !.
ordena(Entrada, Saida):- maiorNoFinal(Entrada, Aux), ordena(Aux, Saida).

/*6-Encontra o ultimo elemento da lista*/
ultimo(X, [X]):- !.
ultimo(X, [_|T]):- ultimo(X, T).

/*7-Encontra o k-esimo elemento de uma lista*/
k_esimo(H, [H|_], 1):- !.
k_esimo(X, [_|T], K):- K > 1, Ke is K -1, k_esimo(X, T, Ke).

/*8-Encontra posição de um elemento da lista*/
encontraIndice(Elemento, [Elemento|_], 1).
encontraIndice(Elemento, [_|T], Indice):- encontraIndice(Elemento, T, Ind), Indice is Ind + 1.

/*9-Quantidade de elementos de uma lista*/
quantidade(0, []).
quantidade(X, [_|T]):- quantidade(Xs, T), X is Xs + 1. 

/*10-Inverter uma lista*/
concatena([], L, L).
concatena([H|T], L, [H|C]):- concatena(T, L, C). 
inverte([],[]).
inverte([H|T], L):- inverte(T,  Lst), concatena(Lst, [H], L).

/*11-soma todos os elementos de uma lista*/
soma([], 0).
soma([H|T], S):- soma(T, X), S is X + H. 

/*12-Media aritmetica de uma lista*/
mediaA([H|T], M):- soma([H|T], S), quantidade(Q, [H|T]), M is S/Q.

/*13-Produto Vetorial de duas listas*/
prodVet([X1], [X2], Pv):- Pv is X1*X2, !.
prodVet([H1|T1], [H2|T2], Pv):- prodVet([H1], [H2], Aux), prodVet(T1, T2, P), Pv is Aux + P.

/*14-Media ponderada de uma lista*/
mediaPond(Valores, Pesos, Media):- prodVet(Valores, Pesos, Pv), soma(Pesos, S), Media is Pv / S.

/*15-Insere um elemento no começo da lista*/
insereC(Lst, X, [X|Lst]).

/*16-Insere um elemento no final da lista*/
insereF([], X, [X]).
insereF([H|T], X, [H|T1]):- insereF(T, X, T1).

/*17-Remove um elemento de uma lista*/
remover(X, [X|T], T).
remover(X, [H|T], [H|T1]):- remover(X, T, T1).

/*18-Remove um elemento da lista a partir do indice*/
removeIndice(0, [_|T], T).
removeIndice(Indice, [H|T], [H|Lista]):- Ind is Indice - 1, removeIndice(Ind, T, Lista).

/*19-Linearizar uma lista*/
ehLista([]).
ehLista([_]).
ehLista([_|_]).

ehLinear([]).
ehLinear([X]):- \+ehLista(X),!.
ehLinear([H|T]):- \+ehLista(H), ehLinear(T). 

lineariza1([X], [X]):- \+ehLista(X), !.
lineariza1([H|T], [H|Tn]):- \+ehLista(H), lineariza1(T, Tn), !.
lineariza1([H|T], Lista):- append(H, T, Lista).

linearizaT(Lista, Lista):- ehLinear(Lista), !.
linearizaT(Entrada, Saida):- lineariza1(Entrada, S), linearizaT(S, Saida).

/*20-Verificar se é uma lista de binarios*/
bit(0).
bit(1).

binary([H]):- bit(H), !.
binary([H|T]):- bit(H), binary(T), !.

/*21-Converter um valor binario para decimal*/
bin2dec([0], 0).
bin2dec([1], 1).
bin2dec([H|T], Decimal):- bin2dec(T, Aux), length(T, TamanhoTail), Decimal is Aux + H*(2^TamanhoTail), !.

/*22-Numeros Assombrosos do Livro de Escher Bach: Gödel.

	Breve Descrição: ”...se (N) for ímpar nós o triplicamos e adicionamos 1.
	Se(N) for par o dividimos à metade. Em seguida repetimos o processo. 
	Denominemos o número que eventualmente chegar a 1 neste processo como assombroso...”
*/
par(N):- N mod 2 =:= 0.
impar(N):- \+par(N).

assombrosoVerifica(1).
assombrosoVerifica(N):- N \= 1, par(N), N1 is N // 2, assombroso(N1), !.
assombrosoVerifica(N):- N \= 1, impar(N), N1 is (N*3)+1, assombroso(N1).

assombroso(N):- N \= 1, par(N), N1 is N // 2, assombrosoVerifica(N1), !.
assombroso(N):- N \= 1, impar(N), N1 is (N*3)+1, assombrosoVerifica(N1).

/*23-Função Ackermann*/
ackermann(0, N, Res):- Res is N + 1, !.
ackermann(M, 0, Res):- M > 0, M1 is M - 1, ackermann(M1, 1, Res), !.
ackermann(M, N, Res):- M > 0, N > 0, M1 is M - 1, N1 is N - 1, ackermann(M, N1, Aux), ackermann(M1, Aux, Res).

/*24-Conjectura de Goldach

	Breve Descrição: A Conjectura de Goldbach diz que todo número par 
	maior que 2 pode ser representado pela soma de dois números primos.
*/
eh_divisivel(N, F):- N mod F =:= 0, !.
eh_divisivel(N, F):- F*F < N, F2 is F + 2, eh_divisivel(N, F2).

eh_primo(2).
eh_primo(3).
eh_primo(N):- N mod 2 \= 0, \+eh_divisivel(N, 3). /*N nao pode ser divisivel por 2 nem por nenhum impar.
													Note que excluimos os pares (o F de eh_divisivel pula de 2 em 2)
													pois com exceção do 2, nao existem pares primos.*/

proximoPrimo(X, Proxprimo):- P is X + 1, eh_primo(P), Proxprimo is  P, !.
proximoPrimo(X, Proxprimo):- proximoPrimo(X+1, Aux), Proxprimo is Aux. 

buscaPrimos(Primo, N):- Aux is  N - Primo, eh_primo(Aux), !.
buscaPrimos(Primo, N):- proximoPrimo(Primo, P), P < N, buscaPrimos(P, N).

goldbach(4).
goldbach(N):- N > 4, buscaPrimos(3, N).

/*25-Solucionar o criptograma: AB
							  +AB
							  138	
*/
digito(0).
digito(1).
digito(2).
digito(3).
digito(4).
digito(5).
digito(6).
digito(7).
digito(8).
digito(9).

solucao(S):- digito(A), A > 0, digito(B), 138 is 10*A+B+10*A+B, S = [A,B].