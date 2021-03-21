import GrafoListAdj
import Grafo



import Data.List


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

arvoreEstritamenteBinaria = novoGrafo 7[(1, 2), (1, 3), (2, 4), (2, 5), (3, 6), (3, 7)]

arvoreBinaria = novoGrafo 5[(1, 2), (1, 3), (2, 4), (2, 5), (3, 6)]

arvoreGenerica = novoGrafo 4[(1, 2), (1, 3), (2, 4)]

arvoreTernaria = novoGrafo 10[(1, 2), (1, 3), (1, 4), (2, 5), (2, 6), (2, 7), (3, 8), (3, 9), (3, 10)]

testaDisjuntoVertices = 
        print( éDisjuntoVértices caminho [1, 2, 3] [4, 5]) >>
        --True

        print( éDisjuntoVértices star [2, 1, 3] [4, 1, 6]) >>
        --False

        print( éDisjuntoVértices k3 [1, 2] [3, 4])
        --False

testaEstrela = 
        print( éEstrela star) >>
        --true

        print( éEstrela bipartido) >>
        --False

        print( éEstrela k3)
        --False

testaFolha = 
        print( éFolha arvoreGenerica 4) >> 
        --True

        print( éFolha arvoreBinaria 6) >> 
        --True

        print( éFolha arvoreGenerica 1)
        --False

testaBinaria = 
        print( éBinária arvoreBinaria) >>
        --True

        print( éBinária arvoreEstritamenteBinaria) >>
        --True

        print( éBinária arvoreTernaria)
        --False

testaBinariaEstrita =
        print( éBináriaEstrita arvoreEstritamenteBinaria) >>
        --True

        print( éBináriaEstrita arvoreBinaria)>>
        --False

        print( éBináriaEstrita arvoreTernaria)
        --False

testaArvM_aria = 
        print( éÁrvM_ária arvoreBinaria 2) >>
        --True

        print( éÁrvM_ária arvoreTernaria 3) >>
        --True

        print( éÁrvM_ária arvoreEstritamenteBinaria 3)
        --False

testaSeqValida = 
        print( éSeqVálida [1, 2, 1]) >>
        --True
        
        print( éSeqVálida [1, 2, 2]) >>
        --False

        print( éSeqVálida [1, 2, 3, 1, 1]) 
        --True

testaNumArvoresRotuladas =
        print( numÁrvoresRot [1, 1, 1, 1, 2, 3, 3]) >>
        --30

        print( numÁrvoresRot [1, 1, 1, 1, 2, 4]) >>
        --4

        print( numÁrvoresRot [1, 2, 3, 4, 5])
        --0

testaCoberturaVertices = 
        print( coberturaVértices k4) >>
        --[3,2,1]

        print( coberturaVértices arvoreBinaria) >>
        --[6,5,4,2,1]

        print( coberturaVértices star)
        --[1]

