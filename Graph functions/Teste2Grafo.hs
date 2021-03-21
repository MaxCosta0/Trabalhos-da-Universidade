import GrafoListAdj
import Grafo


petersen = novoGrafo 9[(0, 1), (0, 7), (0, 4), (1, 2), (1, 5), (2, 3), (2, 9), (3, 4), (3, 6), (4, 8), (5, 6), (5, 8), (6, 7), (7, 9), (8, 9)]

k3 = novoGrafo 3[(1, 2), (1, 3), (2, 3)]

k4 = novoGrafo 4[(1, 2), (1, 3), (1, 4), (2, 3), (2, 4), (3, 4)]

star = novoGrafo 6[(2, 1), (3, 1), (4, 1), (5, 1), (6, 1)]

generico = novoGrafo 5[(1, 2), (1, 5), (2, 3)]

generico2 = novoGrafo 4[(1, 2), (1, 3), (1, 4), (3, 4)]

ciclico = novoGrafo 5[(1, 2), (1, 5), (2, 3), (3, 4), (4, 5)]

caminho = novoGrafo 5[(1, 2), (2, 3), (3, 4), (4, 5)]

bipartido = novoGrafo 5[(1, 3), (1, 4), (1, 5), (2, 3), (2, 4), (2, 5)]

euleriano = novoGrafo 7[(1, 2), (1, 3), (2, 4), (2, 5), (2, 3), (3, 4), (3, 6), (4, 5), (4, 6), (5, 6), (5, 7), (6, 7)]

semiEuleriano = novoGrafo 6[(2, 4), (2, 5), (2, 3), (3, 4), (3, 6), (4, 5), (4, 6), (5, 6), (5, 7), (6, 7)]

hamiltoniano = novoGrafo 6[(1, 2), (1, 3), (1,6), (2, 3), (2, 4), (3, 5), (4, 5), (4, 6), (5, 6)]

testaFundeVertices = 
        print( fundeVértices k4 2 3) >>
        --LsAdj (fromList [(1,[2,4,2]),(2,[4,2,2,1,1,4]),(4,[2,1,2])])

        print( fundeVértices star 1 2) >>
        --LsAdj (fromList [(1,[1,1,6,5,4,3]),(3,[1]),(4,[1]),(5,[1]),(6,[1])])

        print( fundeVértices generico 1 5)
        --LsAdj (fromList [(1,[1,1,2]),(2,[1,3]),(3,[2]),(4,[])])


testaContraiVertices = 
        print( contraiVértices k4 2 3) >>
        --LsAdj (fromList [(1,[2,4]),(2,[1,4]),(4,[1,2])])

        print( contraiVértices star 1 2) >>
        --LsAdj (fromList [(1,[6,5,4,3]),(3,[1]),(4,[1]),(5,[1]),(6,[1])])

        print( contraiVértices generico 1 5)
        --LsAdj (fromList [(1,[2]),(2,[1,3]),(3,[2]),(4,[])])

testaContraiAresta = 
        print( contraiAresta k4 (2, 3)) >>
        --LsAdj (fromList [(1,[2,4]),(2,[1,4]),(4,[1,2])])

        print( contraiAresta generico2 (3, 4)) >>
        --LsAdj (fromList [(1,[6,5,4,3]),(3,[1]),(4,[1]),(5,[1]),(6,[1])])

        print( contraiAresta generico (1, 5))
        --LsAdj (fromList [(1,[2]),(2,[1,3]),(3,[2]),(4,[])])

testaPasseio = 

        print( éPasseio petersen [0, 1, 2, 9, 7, 0, 4]) >>
        --True

        print( éPasseio k4 [5]) >>
        --True

        print( éPasseio generico [1])
        --True

testaPasseioAberto =
        print( éPasseioAberto petersen [0, 1, 2, 9, 7, 0, 4]) >>
        -- True

        print( éPasseioAberto k4 [1, 2, 3, 4, 1]) >>
        --False

        print( éPasseioAberto generico [1, 2, 4]) 
        --False

testaPasseioFechado = 

        print( éPasseioFechado petersen [0, 1, 2, 9, 7, 0, 4]) >>
        -- False

        print( éPasseioFechado k4 [1, 2, 3, 4, 1]) >>
        --True

        print( éPasseioFechado generico [1, 2, 4]) 
        --False

testaTrilha = 
        print( éTrilha petersen [0, 1, 2, 9, 7]) >>
        --True

        print( éTrilha k4 [1, 2, 3, 4, 1, 2]) >>
        --False

        print( éTrilha generico [1])
        --True

testaCaminho = 
        print( éCaminho petersen [0, 1, 2 ,9, 7]) >>
        --True

        print( éCaminho k4 [1, 2, 3, 4, 1, 2]) >>
        --False

        print( éCaminho generico [1])
        --True

testaCiclo = 
        print( éCiclo petersen [0, 1, 2, 9, 7, 0]) >>
        --True

        print( éCiclo k4 [1, 2, 3, 4]) >>
        --False

        print( éCiclo generico [1]) 
        --False

testaGrafoCiclico =
        print( éGrafoCíclico petersen) >>
        --False

        print( éGrafoCíclico k3) >>
        --True

        print( éGrafoCíclico ciclico)
        --True

testaCn =
        print( éCn petersen 3) >>
        --False

        print( éCn k3 2) >>
        --False

        print( éCn ciclico 5)
        --True

testaGrafoCaminho = 
        print( éGrafoCaminho caminho) >>
        --True

        print( éGrafoCaminho petersen) >>
        --False

        print( éGrafoCaminho generico)
        --False

testaPn = 
        print( éPn caminho 5) >>
        --True

        print( éPn petersen 10) >>
        --False

        print( éPn generico 5)
        --False

testaGrafoBipartido = 
        print( éGrafoBipartido k4 [1, 2] [3, 4]) >>
        --False

        print( éGrafoBipartido bipartido [1, 2] [3, 4, 5]) >>
        --True

        print( éGrafoBipartido star [1] [2, 3, 4, 5, 6])
        --True

testaTrilhaEuleriana = 
        print( éTrilhaEuleriana euleriano [1, 2, 5, 7, 6, 3, 2, 4, 5, 6, 4, 3, 1]) >>
        --True

        print( éTrilhaEuleriana k4 [1, 2, 3, 4]) >>
        --False

        print( éTrilhaEuleriana generico [1, 2, 3, 4, 5])
        --False

testaGrafoEuleriano = 
        print( éGrafoEuleriano euleriano) >>
        --True

        print( éGrafoEuleriano k4) >>
        --False

        print( éGrafoEuleriano k3 )
        --True

testaSemiEuleriano = 
        print( éSemiEuleriano euleriano) >>
        --False

        print( éSemiEuleriano semiEuleriano) >>
        --True

        print( éSemiEuleriano k3 )
        --False

testaHamiltonianoOre = 
        print( éHamiltonianoOre euleriano) >>
        --False

        print( éHamiltonianoOre hamiltoniano) >>
        --True

        print( éHamiltonianoOre k4 )
        --True

testaHamiltonianoDirac = 
        print( éHamiltonianoDirac euleriano) >>
        --False

        print( éHamiltonianoDirac hamiltoniano) >>
        --True

        print( éHamiltonianoDirac k4 )
        --True

testaFecho = 
        print( fecho euleriano) >>
        --LsAdj (fromList [(1,[3,2]),(2,[1,3,5,4,6,6]),(3,[1,2,6,4,5,5]),(4,[2,3,6,5]),(5,[2,4,7,6,3,3]),(6,[3,4,5,7,2,2]),(7,[5,6])])

        print( fecho generico) >>
        --LsAdj (fromList [(1,[5,2]),(2,[1,3]),(3,[2]),(4,[]),(5,[1])])

        print( fecho k4 )
        --LsAdj (fromList [(1,[4,3,2]),(2,[1,4,3]),(3,[1,2,4]),(4,[1,2,3])])