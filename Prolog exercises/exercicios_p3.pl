:-use_module(library(clpb)).

/*P17(*)--Split a list into two parts; the length of the first part is given.*/
split([H|T], 1, [H], T):- !.
split([H|T], K, [H|List1], List2):- K > 1, K1 is K - 1, split(T, K1, List1, List2), !.

/*P18(**)--Extract a Slice from a List*/
add([H|_], 1, [H]):- !.
add([H|T], K, [H|List]):- K > 0, K1 is K - 1, add(T, K1, List).

slice(List, 1, K, NewList):- add(List, K, NewList), !.
slice([_|T], I, K, NewList):- I > 0, K > I, I1 is I - 1, K1 is K - 1, slice(T, I1, K1, NewList).

/*P19(**)--Rotate a list N places to the left*/
rotate([H|T], N, Rotated):- N > 1, split([H|T], N, L1, L2), append(L2, L1, Rotated), !;
							length([H|T], Len), K is Len + N, split([H|T], K, L1, L2), append(L2, L1, Rotated).

/*P20(*)--Remove the N'th element from a list*/
dropN([_|T], 0, T):- !.
dropN([H|T], N, [H|NewList]):- N > 0, N1 is N - 1, dropN(T, N1, NewList).

/*P21(*)--Insert an element at a given position into a list.*/
insert_at(X, [H|T], 1, [X,H|T]):- !.
insert_at(X, [H|T], Position, [H|NewList]):- P is Position - 1, insert_at(X, T, P, NewList).

/*P26(**)--Generate the combinations of K distinct objects chosen from the N elements of a list*/
combination(0, _, []):- !.
combination(K, List, [X|Combinations]):- K > 0, getNext(X, List, Returned), K1 is K-1, combination(K1, Returned, Combinations).

getNext(X, [X|L], L).
getNext(X, [_|L], R):- getNext(X, L, R).

/*P31(**)--Determine whether a given integer number is prime.*/

prime(2):- !.
prime(3):- !.
prime(N):- N > 3, N mod 2 =\= 0, \+has_factor(N, 3).

has_factor(N, L):- N mod L =:= 0, !.
has_factor(N, L):- L * L < N, L2 is L + 2, has_factor(N, L2).

/*P32(**)--Determine the greatest common divisor of two positive integer numbers.*/
gcd(N1, N2, Gcd):- Residue is N1 mod N2, Residue =:= 0, Gcd is N2, !.
gcd(N1, N2, Gcd):- Residue is N1 mod N2, gcd(N2, Residue, Gcd).

/*P33(*)--Determine whether two positive integer numbers are coprime.*/
coprime(N1, N2):- gcd(N1, N2, Gcd), Gcd is 1.

%========================================================LOGIC PROPOSALS========================================================%
answer(A1, A2, A3, A4, A5, A6):- sat(A1 =:= (A2*A3*A4*A5*A6)), sat(A2 =:= ~(A3+A4+A5+A6)),
								sat(A3 =:= (A1*A2*A3)), sat(A4 =:= (A1+A2+A3)),
								sat(A5 =:= ~(A1+A2+A3+A4)), sat(A6 =:= ~(A1+A2+A3+A4+A5)), 
								labeling([A1, A2, A3, A4, A5, A6]), !.


knk(1,A,B):- sat(A =:= (~A*B)), labeling([A,B]).
knk(2,A,B):- sat(A =:= (~A+(~B))), labeling([A, B]).
knk(3,A,B,C):- sat(A =:= (~A * ~B * ~C)), sat(B =:= (A*(~B)*(~C)) + ((~A)*B*(~C)) + ((~A)*(~B)*C)), labeling([A,B,C]).
knk(4,A,B,C):- sat(A =:= ~B), sat(B =:= (A =:= C)), labeling([A,B,C]).

%========================================================SUPERCRESCENT LIST========================================================%
supercrescent([H|T]):- checkSuper([H|T], 0), !.

checkSuper([X,Y], Sum):- Y >= X + Sum, !.
checkSuper([H|T], Sum):- S is Sum + H, checkSuper(T, S).

%========================================================CRIPTOGRAMS========================================================%
digit(0).
digit(1).
digit(2).
digit(3).
digit(4).
digit(5).
digit(6).
digit(7).
digit(8).
digit(9).

solve(A, B, C):- digit(A), A \= 0, digit(B), digit(C), 
				100*A + 10*B + C + 10*A + 3 =:= 100*A + 10*C + B.

solve(M,O,T,H,E,R,F,A,P,N):- digit(M), digit(O), digit(T), digit(H), digit(E), 
							digit(R), digit(F), digit(A), digit(P), digit(N), 
							M*100000 + O*10000 + T*1000 + H*100 + E*10 + R +
							F*100000 + A*10000 + T*1000 + H*100 + E*10 + R =:=
							P*100000 + A*10000 + R*1000 + E*100 + N*10 + T.


%========================================================CHESS PAWN========================================================%

%chess board 8x8.
pos(1).
pos(2).
pos(3).
pos(4).
pos(5).
pos(6).
pos(7).
pos(8).

look(1).
look(-1).

%Possible Movements
move([L,C],[NewL,C]):- NewL is L + 1, pos(NewL).

%Look if there are parts on your diagonal.
lookAround([L,C], [L,C1]):- look(Aux), C1 is C + Aux, pos(C1).

%Pawn moves.
pawn(PawnSpot, [EnemyL, EnemyC], PawnSpot):- move(PawnSpot, [L, C]), L is EnemyL, C is EnemyC, !.															%Enemy ahead
pawn(PawnSpot, [EnemyL, EnemyC], [EnemyL, EnemyC]):- move(PawnSpot, TryMove), lookAround(TryMove, [SideL,SideC]), SideL is EnemyL, SideC is EnemyC, !.		%Enemy on the diagonal	
pawn(PawnSpot, _, NewSpot):- move(PawnSpot, NewSpot).																										%Free path

%========================================================DIVISIBILITY BY 3========================================================%

div3(3):- !.
div3(6):- !.
div3(9):- !.

div3(N):- N >= 10, Unit is N mod 10, Dozen is N // 10, Sum is (Unit + Dozen), div3(Sum), !.

%========================================================INTERVAL NUMBERS========================================================%

%Building intervals
insert([H|T], X, Return):- append([X], H, R), Return = [R|T], !.

interval([H|T], Interval):- interval1([H|T], [Hi|Ti]), append([H], Hi, I), Interval = [I|Ti], !.

interval1([H], [[H]]):- !.
interval1([H1,H2|T], Interval):- H2 is H1 + 1, interval1([H2|T], Interval), !.
interval1([H1,H2|T], Interval):- interval1([H2|T], I), insert(I, H2, I1), append([[H1]], I1, Interval).

%check if the number is in the interval
checkInterval(X, [[H1,H2]|T]):- X >= H1, X =< H2, !;
								checkInterval(X, T). 


%========================================================NONOGRAM========================================================%

limita_valores(_, _, []).
limita_valores(Menor, Maior, [H|T]):- between(Menor, Maior, H), limita_valores(Menor, Maior, T).

nonogram([L1,L2,L3,L4], [C1,C2,C3,C4], Solucao):- Solucao = [C11, C12, C13, C14,
															 C21, C22, C23, C24,
							   								 C31, C32, C33, C34,
							   								 C41, C42, C43, C44],

limita_valores(0, 1, Solucao),

restricao(L1, [C11, C12, C13, C14]),
restricao(L2, [C21, C22, C23, C24]),
restricao(L3, [C31, C32, C33, C34]),
restricao(L4, [C41, C42, C43, C44]),

restricao(C1, [C11, C21, C31, C32]),
restricao(C2, [C12, C22, C32, C42]),
restricao(C3, [C13, C23, C33, C43]),
restricao(C4, [C14, C24, C34, C44]).

restricao(1, [C1,C2,C3,C4]):- C1 is 1, C2 is 0, C3 is 0, C4 is 0;
							  C1 is 0, C2 is 1, C3 is 0, C4 is 0;
							  C1 is 0, C2 is 0, C3 is 1, C4 is 0;
							  C1 is 0, C2 is 0, C3 is 0, C4 is 1.

restricao(2, [C1,C2,C3,C4]):- C1 is 1, C2 is 1, C3 is 0, C4 is 0;
							  C1 is 0, C2 is 1, C3 is 1, C4 is 0;
							  C1 is 0, C2 is 0, C3 is 1, C4 is 1.

restricao(3, [C1,C2,C3,C4]):- C1 is 1, C2 is 1, C3 is 1, C4 is 0;
							  C1 is 0, C2 is 1, C3 is 1, C4 is 1.

restricao(4, [C1,C2,C3,C4]):- C1 is 1, C2 is 1, C3 is 1, C4 is 1.