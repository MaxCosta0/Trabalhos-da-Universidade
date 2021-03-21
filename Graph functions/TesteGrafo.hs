import GrafoListAdj
import Grafo



nulo = novoGrafo 0[]

trivial = novoGrafo 1[]

desconexo = novoGrafo 4[]

petersen = novoGrafo 9[(0, 1), (0, 7), (0, 4), (1, 2), (1, 5), (2, 3), (2, 9), (3, 4), (3, 6), (4, 8), (5, 6), (5, 8), (6, 7), (7, 9), (8, 9)]

k3 = novoGrafo 3[(1, 2), (1, 3), (2, 3)]

k4 = novoGrafo 4[(1, 2), (1, 3), (1, 4), (2, 3), (2, 4), (3, 4)]

star = novoGrafo 6[(2, 1), (3, 1), (4, 1), (5, 1), (6, 1)]

generico = novoGrafo 5[(1, 2), (1, 5), (2, 3)]

generico2 = novoGrafo 4[(1, 2), (1, 3), (1, 4), (3, 4)]

generico3 = novoGrafo 5[(1, 2), (1, 4), (2, 4)] 

g1 = novoGrafo 1 []

g2 = novoGrafo 2 []

g3 = novoGrafo 3 [(1,2), (1,3), (2,3)]

g4 = novoGrafo 2 [(1,2)]

g5 = novoGrafo 6 [(1,4), (2,3), (2,4), (3,4), (4,5), (4,6), (5,6)]

testaTrivial = 
        print( éTrivial trivial ) >>
        --True

        print( éTrivial desconexo ) >>
        --False

        print( éTrivial nulo )
        --False

testaIsolado = 
        print( éIsolado nulo 1 ) >>
        --False

        print( éIsolado trivial 1 ) >>
        --True

        print( éIsolado desconexo 2 )
        --True


testaTerminal = 
        print( éTerminal trivial 1 ) >> 
        --False

        print( éTerminal star 2 ) >>
        --True

        print(  éTerminal k3 1 )
        --False

testaPar = 
        print( éPar k3 2 ) >>
        --True

        print( éPar k4 2 ) >>
        --False

        print( éPar star 1 )
        --False

testaImpar = 
        print( éImpar k3 2 ) >>
        --False

        print( éImpar k4 2 ) >>
        --True

        print( éImpar star 2 )
        --False

testaSeqGraus = 
        print( seqGraus petersen) >> 
        --[3,3,3,3,3,3,3,3,3,3]

        print( seqGraus star ) >>
        --[5,1,1,1,1,1]

        print( seqGraus desconexo )
        --[0,0,0,0]

testaGrauMax = 
        print( grauMax petersen) >>
        --3

        print( grauMax star )>>
        --5

        print( grauMax k3 )
        --2

testaGrauMin =
        print( grauMin petersen ) >>
        --3

        print( grauMin star ) >>
        --1

        print( grauMin k3)
        --2

testaRegular = 
        print( éRegular k3 ) >>
        --True

        print( éRegular petersen ) >>
        --True

        print( éRegular generico)
        --False

testaKRegular = 
        print( éKRegular k3 2) >>
        --True

        print( éKRegular petersen 4) >>
        --False

        print( éKRegular petersen 3)
        --True

testaVazio =
        print( éVazio desconexo) >>
        --True

        print( éVazio nulo ) >>
        --True

        print( éVazio petersen)
        --False

testaNulo = 
        print( éNulo nulo) >>
        --True

        print( éNulo desconexo) >>
        --False

        print( éNulo trivial)
        --False

testaCompleto = 
        print( éCompleto k4) >>
        --True

        print( éCompleto petersen) >>
        --False

        print( éCompleto star)
        --False

testaKn = 
        print( éKn k3 3) >>
        --True

        print( éKn k4 4) >>
        --True

        print( éKn petersen 3)
        --False

testaGrafoCompleto = 
        print( grafoCompleto 4) >>
        --LsAdj (fromList [(1,[4,3,2]),(2,[4,3,1]),(3,[4,2,1]),(4,[3,2,1])])

        print( grafoCompleto 3) >>
        --LsAdj (fromList [(1,[3,2]),(2,[3,1]),(3,[2,1])]

        print( grafoCompleto 2)
        --LsAdj (fromList [(1,[2]),(2,[1])])

testaGrafoComplemento = 
        print( grafoComplemento k3) >>
        --LsAdj (fromList [(1,[]),(2,[]),(3,[])])

        print( grafoComplemento generico) >>
        --LsAdj (fromList [(1,[4,3]),(2,[5,4]),(3,[5,4,1]),(4,[5,3,2,1]),(5,[4,3,2])])

        print( grafoComplemento star)
        --LsAdj (fromList [(1,[7,6,5,4,3,2]),(2,[7,6,5,4,3,1]),(3,[7,6,5,4,2,1]),(4,[7,6,5,3,2,1]),(5,[7,6,4,3,2,1]),(6,[7,5,4,3,2,1]),(7,[6,5,4,3,2,1])])

testaSubgrafo = 
        print( éSubgrafo k3 k4) >>
        --True

        print( éSubgrafo k4 k3) >>
        --False

        print( éSubgrafo generico petersen)
        --True

testaSubgrafoProprio = 
        print( éSubgrafoProprio k3 k4) >>
        --True

        print( éSubgrafoProprio k3 k3) >>
        --False

        print( éSubgrafoProprio generico petersen)
        --True

testaSubgrafoInduzidoVertices =
        print( éSubgrafoInduzidoVértices k3 k4 [1, 2, 3]) >>
        --True

        print( éSubgrafoInduzidoVértices k3 k4 [1, 2, 4]) >>
        --False

        print( éSubgrafoInduzidoVértices k3 k4 [1, 2])
        --True

testaSubgrafoInduzidoArestas = 
        print( éSubgrafoInduzidoArestas k3 k4 [(1, 2), (2, 3), (1, 3)]) >>
        --True

        print( éSubgrafoInduzidoArestas k3 k4 [(1, 2), (2, 4)]) >>
        --False

        print( éSubgrafoInduzidoArestas k3 k4 [(1, 2), (2, 3)])
        --True

testaClique = 
        print( éClique k3 k4) >>
        --True

        print( éClique generico petersen) >>
        --False

        print( éClique generico2 generico3)
        --False

testaCjIndependenteVertices = 
        print( éCjIndependenteVértices desconexo petersen) >>
        --True

        print( éCjIndependenteVértices k3 k4) >>
        --False

        print( éCjIndependenteVértices trivial generico)
        --True

testaUniao =
        print( união generico2 generico3) >>
        --LsAdj (fromList [(1,[4,3,2]),(2,[4,1]),(3,[1,4]),(4,[2,1,3]),(5,[])])

        print( união star desconexo) >>
        --LsAdj (fromList [(1,[6,5,4,3,2]),(2,[1]),(3,[1]),(4,[1]),(5,[1]),(6,[1])])

        print( união k4 k3)
        --LsAdj (fromList [(1,[4,3,2]),(2,[1,4,3]),(3,[1,2,4]),(4,[1,2,3])])

testaIntersecao = 
        print( interseção generico petersen) >>
        --LsAdj (fromList [(1,[5,2]),(2,[1,3]),(3,[2]),(5,[1])])

        print( interseção k3 k4) >>
        --LsAdj (fromList [(1,[3,2]),(2,[1,3]),(3,[1,2])])

        print( interseção star generico2)
        --LsAdj (fromList [(1,[4,3,2]),(2,[1]),(3,[1]),(4,[1])])

testaSoma = 
        print( soma generico2 generico3) >>
        --LsAdj (fromList [(1,[5,4,3,2]),(2,[5,3,4,1]),(3,[2,5,1,4]),(4,[5,2,1,3]),(5,[1,2,3,4])])

        print( soma star generico) >>
        --LsAdj (fromList [(1,[6,5,4,3,2]),(2,[6,5,4,3,1]),(3,[6,5,4,2,1]),(4,[2,3,6,5,1]),(5,[2,3,4,6,1]),(6,[2,3,4,5,1])])

        print( soma k3 k4)
        --LsAdj (fromList [(1,[4,3,2]),(2,[4,1,3]),(3,[4,1,2]),(4,[1,2,3])])