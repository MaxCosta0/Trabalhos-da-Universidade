/*QUESTAO 1: Intercalar 3 Listas*/
intercala2([], L, L).
intercala2(L, [], L).
intercala2([H1|T1], [H2|T2], I):- H1 =< H2, intercala2(T1, [H2|T2], R), I = [H1|R].
intercala2([H1|T1], [H2|T2], I):- H2 < H1, intercala2([H1|T1], T2, R), I = [H2|R].

intercala([H1|T1], [H2|T2], [H3|T3], I):- intercala2([H1|T1], [H2|T2], R1), intercala2(R1, [H3|T3], I).

/*QUESTAO 2: Determinar o que cada regra faz*/

/*Letra a*/
p([],[],_) :- !.
p([X],[[Q,X]],Q) :- !.
p([X,X|T], S,N) :- M is N+1, p( [X|T], S,M),!.
p([X,Y|T],[[N,X]|S],N) :- p( [Y|T],S,1).

/*Faz isso ai, o que é isso? Eu nao sei: 
		?-p([1, 2, 3, 4, 5], S, [6]).

		S = [[[6],1],[1,2],[1,3],[1,4],[1,5]]
*/

/*Letra b*/
y([X1,X2],[X1,X2]) :- X1 < X2,!.
y([X1,X2],[X2,X1]) :- X2 =< X1,!.
y([H1,H2|T],[H1|R]) :- H1<H2, y([H2|T],R),!.
y([H1,H2|T],[H2|R]) :- H2=<H1, y([H1|T],R),!.

/*Coloca o maior elemento da lista passada no ultimo lugar da lista
	 ?- y([5, 4, 3, 8, 6], Lista).

		Lista = [4,3,5,6,8]
*/

/*QUESTAO 3: Movimentos de um cavalo no xadrez*/

/*Letra a*/
move([L1, C1], [L2, C2]):- movimento(L, C), L2 is L1 + L, C2 is C1 + C, L2 > 0, L2 < 8, C2 > 0, C2 < 8.

movimento(1,2).
movimento(1,-2).
movimento(-1,2).
movimento(-1,-2).
movimento(2,1).
movimento(2,-1).
movimento(-2,1).
movimento(-2,-1).
movimento(0,0).

/*Letra b*/
move2([L1, C1], [L2, C2]):- move([L1, C1], [AuxL, AuxC]), move([AuxL, AuxC], [L2, C2]).

/*QUESTAO 4: Tour do cavalo*/
tour([], R):- tour([[1,1]], R).
tour([H|T], R):- move(H, NewSpot), \+member(NewSpot, T), tour([NewSpot,H|T], R), !.
tour([H|T], [H|T]):- length([H|T], Len), Len is 64.

/*QUESTAO 5: Matching para cada regra*/
/*a*/ a([X,Y,X|_]):- X is Y + 1.	/* a([2, 1, 2, 3, 4]). */

/*b*/ b([X|X]).		/* b([[3],3]).*/

/*c*/ c([_,_,_]).	/* c([1, 2, 3]).*/

/*d*/ d([X, Y |Z]):- c(X), c(Y ), c(Z).	/* d([[1, 2, 3], [3, 2, 1], 4, 6, 5]).*/

/*QUESTAO 6: Criptograma*/

/*Letra a*/
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

solucaoA(S):- digito(M), M > 0, digito(O), digito(T), digito(H), digito(E), digito(R),
			 digito(F), F > 0, digito(A), digito(P), P > 0, digito(N), 
			 100000*M+10000*O+1000*T+100*H+10*E+R+100000*F+10000*A+1000*T+100*H+10*E+R =:= 100000*P+10000*A+1000*R+100*E+10*N+T,
			 S = [M,O,T,H,E,R,F,A,P,N].

/*Letra B*/

solucaoB(S):- digito(A), A > 0, digito(B), digito(C), 100*A+10*B+C+10*A+3 =:= 100*A+10*C*B, S = [A, B, C].

/*QUESTAO 7: Lista supercrescente*/
verificaSuper([H], S):- S =< H.
verificaSuper([H|T], S):- S1 is S + H, S =< H, verificaSuper(T, S1), !.

super(Lista):- verificaSuper(Lista, 0). 