module Grafo
   (éTrivial,
    éIsolado,
    éTerminal,
    éPar,
    éImpar,
    seqGraus,
    grauMax,
    grauMin,
    éRegular,
    éKRegular,
    éVazio,
    éNulo,
    éCompleto,
    éKn,
    grafoCompleto,
    grafoComplemento,
    éSubgrafo,
    éSubgrafoProprio,
    éSubgrafoInduzidoVértices,
    éSubgrafoInduzidoArestas,
    éClique,
    éCjIndependenteVértices,
    união,
    interseção,
    soma,
    fundeVértices,
    contraiVértices,
    contraiAresta,
    éPasseio,
    éPasseioAberto,
    éPasseioFechado,
    éTrilha,
    éCaminho,
    éCiclo,
    éGrafoCíclico,
    éCn,
    éGrafoCaminho,
    éPn,
    éGrafoBipartido,
    éTrilhaEuleriana,
    éGrafoEuleriano,
    éSemiEuleriano,
    éHamiltonianoOre,
    éHamiltonianoDirac,
    fecho,
    éDisjuntoVértices,
    éEstrela,
    éFolha,
    éSeqVálida,
    numÁrvoresRot,
    coberturaVértices,
    éBinária,
    éBináriaEstrita,
    éÁrvM_ária) where

import GrafoListAdj
import Data.List

--Funçoes Grafos

éTrivial :: Grafo -> Bool
éTrivial g = if length(vértices g) == 1 then True 
  else False


éIsolado :: Grafo -> Int -> Bool
éIsolado g v = if pertence g v && grau g v == 0 then True
  else False


éTerminal :: Grafo -> Int -> Bool
éTerminal g v = if grau g v == 1 then True
  else False


éPar :: Grafo -> Int -> Bool
éPar g v = if pertence g v && mod (grau g v)  2 == 0 then True
  else False


éImpar :: Grafo -> Int -> Bool
éImpar g v = if pertence g v && mod (grau g v) 2 == 1 then True
  else False


seqGraus :: Grafo -> [Int]
seqGraus g = [grau g v | v <- vértices g]


grauMax :: Grafo -> Int
grauMax g = maximum (seqGraus g)


grauMin :: Grafo -> Int
grauMin g = minimum (seqGraus g)


éRegular :: Grafo -> Bool
éRegular g = if (grauMax g) == (grauMin g) then True
  else False


éKRegular :: Grafo -> Int -> Bool
éKRegular g k = if (grauMax g == k) && (grauMin g == k) then True
  else False


éVazio :: Grafo -> Bool
éVazio g = if length(arestas g) == 0 then True
else False


éNulo :: Grafo -> Bool
éNulo g = if ((length(arestas g) == 0) && (length(vértices g) == 0)) then True
  else False


éCompleto :: Grafo -> Bool
éCompleto g = if éKRegular g (length(vértices g) - 1) then True
  else False


éKn :: Grafo -> Int -> Bool
éKn g n = if éKRegular g (n-1) then True
  else False


grafoCompleto :: Int -> Grafo
grafoCompleto n = novoGrafo n (arestasCompleto n) 


grafoComplemento :: Grafo -> Grafo
grafoComplemento g = novoGrafo (length(vértices g)) (arestaComplemento g (length(vértices g)))


éSubgrafo :: Grafo -> Grafo -> Bool
éSubgrafo h g = if checaArestas (arestas h) (arestas g) then True
  else False


éSubgrafoProprio :: Grafo -> Grafo -> Bool
éSubgrafoProprio h g = if éSubgrafo h g && (length(arestas h) /= length(arestas g)) then True
  else False


éSubgrafoInduzidoVértices :: Grafo -> Grafo -> [Int] -> Bool
éSubgrafoInduzidoVértices h g vh = if (éSubgrafo h g && checaVertices vh (vértices h)) then True
  else False


éSubgrafoInduzidoArestas :: Grafo -> Grafo -> [(Int, Int)] -> Bool
éSubgrafoInduzidoArestas h g ah = if (éSubgrafo h g && checaArestas ah (arestas h)) then True
  else False


éClique :: Grafo -> Grafo -> Bool
éClique h g = if (éSubgrafo h g) && (grauMax h == grauMin h) && (grauMax h == 2) then True
  else False


éCjIndependenteVértices :: Grafo -> Grafo -> Bool
éCjIndependenteVértices h g = if ( checaVertices (vértices h) (vértices g)) && ( éVazio h ) then True
  else False

união :: Grafo -> Grafo -> Grafo
união g h = novoGrafo (max (maximum (vértices h)) (maximum (vértices g))) ((arestas g) `union` (arestas h))


interseção :: Grafo -> Grafo -> Grafo
interseção g h = novoGrafo ( verificaMaiorVertice ( maximum ((arestas g) `intersect` (arestas h)) ) ) ( (arestas g) `intersect` (arestas h) )


soma :: Grafo -> Grafo -> Grafo
soma g h = novoGrafo ( max (maximum (vértices g)) (maximum (vértices h)) ) ( (arestas g) `union` (arestas h) `union`  ( arestas (grafoComplemento (união g h)) ) )


--Funções Auxiliares

--Retorna um conjunto de arestas de modo que todo vertice v seja vizinho de todos os outros vertices do grafo
arestasCompleto :: Int -> [(Int, Int)]
arestasCompleto 0 = []
arestasCompleto n = [(u, v) | u <- [1..n], v <- [u..n], u /= v]

--Retorna um conjunto de arestas complementares ao Grafo g
arestaComplemento :: Grafo -> Int -> [(Int, Int)]
arestaComplemento g 0 = []
arestaComplemento g n = [(u, v) | u <- [1..n], v <- [u..n], not (adjacente g u v), u /= v]


--Verifica se todas as arestas do conjunto H estao contidas no conjunto G
checaArestas :: [(Int, Int)] -> [(Int, Int)] -> Bool
checaArestas [] _ = False
checaArestas _ [] = False
checaArestas [(u, v)] (headG: tailG) = if checa1Aresta (u, v) (headG: tailG) == True then True
  else False
checaArestas (headH: tailH) (headG: tailG) = if checa1Aresta (headH) (headG: tailG) == True then checaArestas tailH (headG: tailG)
  else False

--Verifica se uma aresta esta contida em uma lista de arestas
checa1Aresta :: (Int, Int) -> [(Int, Int)] -> Bool
checa1Aresta (u, v) [] = False 
checa1Aresta (u, v) [h] = if (u, v) == h || (v, u) == h then True
  else False
checa1Aresta (u, v) (h: t) = if (u, v) == h || (v, u) == h then True
  else checa1Aresta (u, v) t


--Verifica se todos os vertices do conjunto H estao contidos no conjunto G
checaVertices :: [Int] -> [Int] -> Bool
checaVertices _ [] = False
checaVertices [] _ = False
checaVertices [v] (headG: tailG) = if checa1Vertice v (headG: tailG) == True then True
  else False
checaVertices (headH: tailH) (headG: tailG) = if checa1Vertice (headH) (headG: tailG) == True then checaVertices tailH (headG: tailG)
  else False

--Verifica se um vertice esta contido em uma lista de vertices
checa1Vertice :: Int -> [Int] -> Bool
checa1Vertice v [] = False
checa1Vertice v [x] = if v == x then True
  else False
checa1Vertice v (h: t) = if v == h then True
  else checa1Vertice v t

--Verifica qual o maior vertice de uma aresta
verificaMaiorVertice :: (Int, Int) -> Int
verificaMaiorVertice (u, v) = if u >= v then u
  else v 


-------------------------------------- TRABALHO 2 --------------------------------------


--1)
fundeVértices :: Grafo -> Int -> Int -> Grafo
fundeVértices g v w = removeVértice (novoGrafo n ((arestas g) ++ fazfusao)) maximo          --apos lisgar as aresta do maior vertice ao menor retira o maior vertice entre v e w
  where
  n = maximum (vértices g)                                                       --numero de vertices
  x = min v w                                                                    --x é o menor vértice entre v e w
  maximo = max v w                                                               --maior vertice entre v e w
  fazfusao = [(x,  y) | y <- vizinhos g maximo]                                  --liga as arestas do maior vértice ao menor 


--2)
contraiVértices :: Grafo -> Int -> Int -> Grafo
contraiVértices g v w =  removeVértice (novoGrafo n removeRepetidos )  maximo               --apos remover os vértices repetidos remove o maior vértice entre v e w
  where 
  n = maximum (vértices g)                                                        --numero de vertices
  maximo = max v w                                                                --maior vertice entre v e w
  fusao = fundeVértices g v w                                                     --faz a fusao de vertices
  removeRepetidos = nub([(x, y) | (x, y) <- arestas fusao, x /= y])               --retira arestas repetidas


--3)
contraiAresta :: Grafo -> (Int, Int) -> Grafo
contraiAresta g (v, w) = fundeVértices(removeAresta g (v, w)) v w                 --remove a aresta (v, w) e aplica a fusao dos vertices v e w


--4)
éPasseio :: Grafo -> [Int] -> Bool
éPasseio g vs
  | verificaPasseio vs = True
  | otherwise = False

  where
    --Verifica condições necessarias para uma lista de vértices ser um passeio (todos elementos pertencem a g e se sao adjacentes 2 a 2)
    verificaPasseio :: [Int] -> Bool
    verificaPasseio [] = False
   
    verificaPasseio [v]
      | pertence g v = True
      | otherwise = False

    verificaPasseio [u, v]
      | (pertence g u && pertence g v && adjacente g u v) = True
      | otherwise =  False

    verificaPasseio ( u : v : tail)
      | (pertence g u && pertence g v && adjacente g u v) =   verificaPasseio (v: tail)
      | otherwise = False


--5)
éPasseioAberto :: Grafo -> [Int] -> Bool
éPasseioAberto g vs 
  | éPasseio g vs && aberto vs = True
  | otherwise = False

  where
    --Verifica se o primeiro elemeto de uma lista é diferente do ultimo
    aberto :: [Int] -> Bool
    aberto (x: xs)
      | x /= last xs = True
      | otherwise = False


--6)
éPasseioFechado :: Grafo -> [Int] -> Bool
éPasseioFechado g vs
  | éPasseio g vs && fechado vs = True
  | otherwise = False

  where
    --Verifica se o primeiro elemento de uma lista é igual ao ultimo
    fechado :: [Int] -> Bool
    fechado (x: xs)
      | x == last xs = True
      | otherwise = False


--7)
éTrilha :: Grafo -> [Int] -> Bool
éTrilha g vs
  | éPasseio g vs && naoRepeteAresta (criaArestas vs) = True
  | otherwise = False

  where
    --Cria arestas a partir de um conjunto de vertices sequencial [u, v] -> (u,v)
    criaArestas :: [Int] -> [(Int, Int)]
    criaArestas [] = []
    criaArestas [x] = []
    criaArestas [x1, x2] = [(x1, x2)]
    criaArestas (x1: x2: xs) = [(x1, x2)] ++ criaArestas (x2:xs)
    
    --Verifica se há alguma aresta repetida em um conjunto de arestas
    naoRepeteAresta :: [(Int, Int)] -> Bool
    naoRepeteAresta [] = True
    naoRepeteAresta [x] = True
    naoRepeteAresta (x: xs)
      | checa1Aresta x xs = False
      | otherwise = naoRepeteAresta xs


--8)
éCaminho :: Grafo -> [Int] -> Bool
éCaminho g vs
  | éTrilha g vs && naoRepeteVertice vs = True
  | otherwise = False

  where
    --Verifica se nao ha vértices repetidos em um conjunto de vertices
    naoRepeteVertice :: [Int] -> Bool
    naoRepeteVertice [] = True
    naoRepeteVertice [x] = True
    naoRepeteVertice (x: xs)
      | checa1Vertice x xs = False
      | otherwise = naoRepeteVertice xs


--9)
éCiclo :: Grafo -> [Int] -> Bool
éCiclo g vs
  | éCaminho g (take (length(vs) - 1) vs) && fechado vs = True        --Verifica se é um caminho até o penultimo vértice, depois verifica é um caminho fechado
  | otherwise = False

  where
     --Verifica se o primeiro elemento de uma lista é igual ao ultimo
    fechado :: [Int] -> Bool
    fechado (x: xs)
      | x == last xs = True
      | otherwise = False


--10)
éGrafoCíclico :: Grafo -> Bool
éGrafoCíclico c
  | éKRegular c 2 = True
  | otherwise = False


--11)
éCn :: Grafo -> Int -> Bool
éCn g n
  | éGrafoCíclico g && (length(vértices g) == n) = True
  | otherwise = False


--12)
éGrafoCaminho :: Grafo -> Bool
éGrafoCaminho g 
  | éCaminho g (retornaVertices (arestas g)) = True
  | otherwise = False

  where
    --cria um caminho de vértices a partir de um conjunto de arestas
    retornaVertices :: [(Int, Int)] -> [Int]
    retornaVertices [] = []
    retornaVertices [(x1, x2)] = [x1]
    retornaVertices ((x1, x2):xs) = retornaVertices xs ++ [x1]


--13)
éPn :: Grafo -> Int -> Bool
éPn p n
  | éGrafoCaminho p && (length(vértices p) == n) = True
  | otherwise = False 


--14)
éGrafoBipartido :: Grafo -> [Int] -> [Int] -> Bool
éGrafoBipartido g v1 v2 = verificaBiparticao (arestas g) v1 v2
  where
    --Verifica se os vertices ligados por uma aresta pertencem a conjuntos distintos
    verificaBiparticao :: [(Int, Int)] -> [Int] -> [Int] -> Bool
    verificaBiparticao [] v1 v2 = False
    verificaBiparticao [(x1, x2)] v1 v2
      | elementoDoConjunto (x1, x2) v1 v2 = True
      | otherwise = False
    verificaBiparticao ((x1, x2):xs) v1 v2
      | elementoDoConjunto (x1, x2) v1 v2 = verificaBiparticao xs v1 v2
      | otherwise = False

    --Verifica se x1 pertence a v1 e x2 pertence a v2 ou se x1 pertence a v2 e x2 pertence a v1
    elementoDoConjunto :: (Int, Int) -> [Int] -> [Int] -> Bool
    elementoDoConjunto (x1, x2) v1 v2
      | (checa1Vertice x1 v1 && checa1Vertice x2 v2) || (checa1Vertice x1 v2 && checa1Vertice x2 v1) = True
      | otherwise = False

--15)
éTrilhaEuleriana :: Grafo -> [Int] -> Bool
éTrilhaEuleriana g t
  | éTrilha g t && todasArestasContidas (arestas g) (criaArestas t)  = True
  | otherwise = False 

  where
    --Cria arestas a partir de um conjunto de vertices sequencial [u, v] -> (u,v)
    criaArestas :: [Int] -> [(Int, Int)]
    criaArestas [] = []
    criaArestas [x] = []
    criaArestas [x1, x2] = [(x1, x2)]
    criaArestas (x1: x2: xs) = [(x1, x2)] ++ criaArestas (x2:xs)

    --Verifica se todas as arestas do grafo g fazem parte da trilha t
    todasArestasContidas :: [(Int, Int)] -> [(Int, Int)] -> Bool
    todasArestasContidas [] trilha = False
    todasArestasContidas [x] trilha
      | checa1Aresta x trilha = True
      | otherwise = False
    todasArestasContidas (x:xs) trilha 
      | checa1Aresta x trilha = todasArestasContidas xs trilha
      | otherwise = False

--16)
éGrafoEuleriano :: Grafo -> Bool
éGrafoEuleriano g 
  | todosVerticesPossuemGrauPar g (vértices g) = True             --G é euleriano se possue todos os vertices com grau par
  | otherwise = False

  where
    --Verifica se todos os vertices de g possuem grau par
    todosVerticesPossuemGrauPar :: Grafo -> [Int] -> Bool
    todosVerticesPossuemGrauPar g [] = False
    todosVerticesPossuemGrauPar g [x] 
      | ehPar g x == True = True
      | otherwise = False
    todosVerticesPossuemGrauPar g (x:xs)
      | ehPar g x == True = todosVerticesPossuemGrauPar g xs
      | otherwise = False

    --Verifica se um vertice de g possui grau par
    ehPar :: Grafo -> Int -> Bool
    ehPar g x = ( mod (grau g x) 2 == 0)


--17)
éSemiEuleriano :: Grafo -> Bool
éSemiEuleriano g 
  | numeroDeGrauImpar g (vértices g) == 2 = True
  | otherwise = False

  where
    numeroDeGrauImpar :: Grafo -> [Int] -> Int
    numeroDeGrauImpar g [] = 0
    numeroDeGrauImpar g (x: xs)
      | ehImpar g x = 1 + numeroDeGrauImpar g xs 
      | otherwise = numeroDeGrauImpar g xs
    
    ehImpar :: Grafo -> Int -> Bool
    ehImpar g x = mod (grau g x) 2 == 1

--18)
éHamiltonianoOre :: Grafo -> Bool
éHamiltonianoOre g 
  | n >= 3 && somaDoisaDois g verticesNaoAdjacentes = True
  | otherwise = False

  where
    n = length(vértices g)
    --Encontra todos os pares de vertices nao adjacentes de g
    verticesNaoAdjacentes = [(v, w) | v <- vértices g, w <- vértices g, not (adjacente g v w)]

    --Soma todos os graus de pares de vertices nao adjacentes
    somaDoisaDois :: Grafo -> [(Int, Int)] -> Bool
    somaDoisaDois g [] = True            --Kn
    somaDoisaDois g [(x1, x2)]
      | somaGraus g (x1, x2) >= n = True
      | otherwise = False
    somaDoisaDois g ((x1, x2):xs)
      | somaGraus g (x1, x2) >= n = somaDoisaDois g xs
      | otherwise = False
    
    somaGraus :: Grafo -> (Int, Int) -> Int
    somaGraus g (x1, x2) = grau g x1 + grau g x2


--19)
éHamiltonianoDirac :: Grafo -> Bool
éHamiltonianoDirac g
  | n >= 3 && grauMaiorParaTodoV g (vértices g) = True
  | otherwise = False

  where
    n = length(vértices g)

    --Verifica se o grau de todo vértice v é maior do que n/2
    grauMaiorParaTodoV :: Grafo -> [Int] -> Bool
    grauMaiorParaTodoV g [] = False
    grauMaiorParaTodoV g [x]
      | grauDeV g x = True
      | otherwise = False
    grauMaiorParaTodoV g (x: xs)
      | grauDeV g x = grauMaiorParaTodoV g xs
      | otherwise = False

    --Verifica se o grau de um vértice é maior do que n/2
    grauDeV g x
      | (grau g x) >= (n `div` 2) = True
      | otherwise = False

--20)
fecho :: Grafo -> Grafo
fecho g = novoGrafo n ( (adicaoDeArestas g arestasNaoAdjacentes) ++ (arestas g) )
  where
    n = maximum (vértices g)
    arestasNaoAdjacentes = [(v, w)| v <- vértices g, w <- vértices g, v/=w, not (adjacente g v w)]
    
    adicaoDeArestas :: Grafo -> [(Int, Int)] -> [(Int, Int)]
    adicaoDeArestas g [] = []
    adicaoDeArestas g [(x1, x2)]
      | somaGraus g (x1, x2) >= n = [(x1, x2)]
      | otherwise = []
    adicaoDeArestas g ((x1, x2): xs)
      | somaGraus g (x1, x2) >= n = [(x1, x2)] ++ adicaoDeArestas g xs
      | otherwise = adicaoDeArestas g xs

    somaGraus :: Grafo -> (Int, Int) -> Int
    somaGraus g (x1, x2) = grau g x1 + grau g x2


-------------------------------------- TRABALHO 3 --------------------------------------

--1)
éDisjuntoVértices :: Grafo -> [Int] -> [Int] -> Bool
éDisjuntoVértices g c1 c2
  | naoContemNenhumElemento c1 c2 && pertenceAoGrafo g c1 && pertenceAoGrafo g c2 = True
  | otherwise = False 

  where

     --Verifica se nenhum vértice de um conjunto contido no ourto conjunto
    naoContemNenhumElemento :: [Int] -> [Int] -> Bool
    naoContemNenhumElemento [] contjunto = True
    naoContemNenhumElemento [x] conjunto
      | checa1Vertice x conjunto = False
      | otherwise = True 
     
    naoContemNenhumElemento (x:xs) conjunto
      | checa1Vertice x conjunto = False
      | otherwise = naoContemNenhumElemento xs conjunto

     --Verifica se todos os vértices de um caminho pertence ao grafo G
    pertenceAoGrafo :: Grafo -> [Int] -> Bool
    pertenceAoGrafo g [] = False
    pertenceAoGrafo g [x]
      | pertence g x = True
      | otherwise = False
    pertenceAoGrafo g (x: xs) 
      | pertence g x = pertenceAoGrafo g xs
      | otherwise = False


--2)
éEstrela :: Grafo -> Bool
éEstrela g
  | (verticesComGrauMaiorQue1 g (vértices g)) == 1 = True
  | otherwise = False

  where
    --Verifica quantos vertices de G possui grau maior do que 1
    verticesComGrauMaiorQue1 :: Grafo -> [Int] -> Int
    verticesComGrauMaiorQue1 g [] = 0
    verticesComGrauMaiorQue1 g (x:xs)
      | grau g x > 1 = verticesComGrauMaiorQue1 g xs + 1
      | otherwise = verticesComGrauMaiorQue1 g xs


--3) --Tomando t como uma arvore nao enraizada
éFolha :: Grafo -> Int -> Bool
éFolha t v
  | grau t v <= 1 = True
  | otherwise = False


    --Ola Professor, por motivos de saude eu nao tive muito tempo para fazer as funçoes de busca da lista passada
    --entao vou tentar fazer essas funçoes de arvores sem precisar utiliza-las. 

--4) --assumindo que o vértice 1 é a raiz da arvore
éBinária :: Grafo -> Bool
éBinária t
  | grau t 1 == 2 && maiorGrauDosNos <= 3 = True            --Se a raiz tem 2 ou menos vizinhos e os outros nós tem no maximo 3 vizinhos, entao é binaria
  | otherwise = False

  where
    maiorGrauDosNos = maximum(grauDosNos)
    grauDosNos = [(grau t x) | x <- vértices t, x /= 1]       --lista do grau de todos os nos, exceto da raiz


--5) --assumindo que o vértice 1 é a raiz da arvore
éBináriaEstrita :: Grafo -> Bool
éBináriaEstrita t
  | (grau t 1 == 2) && satisfazBinarioEstrito conjuntoDeGraus = True
  | otherwise = False

  where
    conjuntoDeGraus = [(grau t x) | x <- vértices t, x /= 1]

    --verifica todos os graus da lista sao 3 ou 1 (se os nós possuem 2 ou nenhum filho)
    satisfazBinarioEstrito :: [Int] -> Bool
    satisfazBinarioEstrito [] = True
    satisfazBinarioEstrito [x]
      | x == 3 || x == 1 = True
      | otherwise = False
    satisfazBinarioEstrito (x: xs)
      | x == 3 || x == 1 = satisfazBinarioEstrito xs
      | otherwise = False

--6) --assumindo que o vértice 1 é a raiz
éÁrvM_ária :: Grafo -> Int -> Bool
éÁrvM_ária t m
  | grau t 1 == m && maiorGrauDosNos <= m+1 = True
  | otherwise = False

  where
    maiorGrauDosNos = maximum(grauDosNos)
    grauDosNos = [(grau t x) | x <- vértices t, x /= 1]

--9)
éSeqVálida :: [Int] -> Bool
éSeqVálida s
  | sum s == 2 * (length s) - 2 = True
  | otherwise = False 

--10)
numÁrvoresRot :: [Int] -> Int
numÁrvoresRot s = (fatorial ((length s) - 2) ) `div` (produtorio s)

  where
    fatorial :: Int -> Int
    fatorial 0 = 1
    fatorial x = x * fatorial (x-1)
    
    produtorio :: [Int] -> Int
    produtorio [x] = fatorial (x-1)
    produtorio (x: xs) = fatorial (x-1) * produtorio xs

--11)
coberturaVértices :: Grafo -> [Int]
coberturaVértices g = nub([x | (x, y) <- arestas g])

