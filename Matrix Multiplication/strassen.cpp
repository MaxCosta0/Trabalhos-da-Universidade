/* 
	Algoritmo de Strassen para multiplicação de Matrizes

	Grupo: Maxley Soares da Costa			11911BCC038
		   Joao Vitor Afonso Pereira		11911BCC037
		   Bruno Oliveira Sinhoroto			11821BCC044
*/

#include<bits/stdc++.h>
#include <chrono>

using namespace std::chrono;
using namespace std;

int n;
int parada;

//Multiplica duas matrizes
void multiplica (vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int d){
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            for (int k = 0; k < d; k++)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}


// separa a matriz
void separa (vector< vector<int> > &A, vector< vector<int> > &B, int linha, int coluna, int d){
    for (int i1 = 0, i2 = linha; i1 < d; i1++, i2++){
        for (int j1 = 0, j2 = coluna; j1 < d; j1++, j2++){
            B[i1][j1] = A[i2][j2];
        }
    }
}

// junta 4 matrizes em 1 resultante
void junta (	vector< vector<int> > &A, vector< vector<int> > &B, int linha, int coluna, int d){
    for (int i1 = 0, i2 = linha; i1 < d; i1++, i2++){
        for (int j1 = 0, j2 = coluna; j1 < d; j1++, j2++){
        	B[i2][j2] = A[i1][j1];
        }
    }
}

// Soma duas matrizes 
void soma (	vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int d){
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// subtrai duas matrizes
void subtrai (	vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int d){
    for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// printa a matriz
void mostra (vector< vector<int> > C, int d){
	for (int i = 0; i < d; i++){
        for (int j = 0; j < d; j++){
             cout << C[i][j] << " ";
        }
        cout << "\n";
    }
}

// Cria duas matrizes iniciais
void cria_matrizes(vector< vector<int> > &A, vector< vector<int> > &B, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			A[i][j] = rand()%10;
		}
	}	

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			B[i][j] = rand()%10;
		}
	}
}


// Dado duas matrizes iniciais, aplica o metodo de Strassen para multiplica-las
void strassen (vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C, int d)
{
	//verifica se a matriz possui tamaho multiplo de 2, caso nao tenha aplica o preenchimento
	if (d&1)
	{
		d++;
		A.resize (d);
		B.resize (d);
		C.resize (d);
		
		// redimensiona o tamanho interno das matrizes
		for (int i = 0; i < d; i++)
		{
			A[i].resize (d);
			B[i].resize (d);
			C[i].resize (d);
		}
	}
	
	// Ponto onde aplica a multiplicação de matrizes (para otimizar o tempo parada = 86)
	if (d <= parada)
	{
		multiplica (A, B, C, d);
		return;
	}
	else
	{
		
		int m = d/2;
        
        vector<int> interno (m);

        // Submatrizes		
		vector< vector<int> > A11 (m, interno);
		vector< vector<int> > A12 (m, interno);
		vector< vector<int> > A21 (m, interno);
		vector< vector<int> > A22 (m, interno);
		vector< vector<int> > B11 (m, interno);
		vector< vector<int> > B12 (m, interno);
		vector< vector<int> > B21 (m, interno);
		vector< vector<int> > B22 (m, interno);
		vector< vector<int> > C11 (m, interno);
		vector< vector<int> > C12 (m, interno);
		vector< vector<int> > C21 (m, interno);
		vector< vector<int> > C22 (m, interno);

		// Separa matrizes A e B
		separa(A, A11, 0 , 0, m);
        separa(A, A12, 0 , m, m);
        separa(A, A21, m, 0, m);
        separa(A, A22, m, m, m);
        separa(B, B11, 0 , 0, m);
        separa(B, B12, 0 , m, m);
        separa(B, B21, m, 0, m);
        separa(B, B22, m, m, m);

     	// Matrizes para guardar o resultado 
		vector< vector<int> > result1 (m, interno);
		vector< vector<int> > result2 (m, interno);


        /************************************************
        *** 	M1 = (A11 + A22)(B11 + B22)
        *** 	M2 = (A21 + A22) B11
        *** 	M3 = A11 (B12 - B22)
        *** 	M4 = A22 (B21 - B11)
        *** 	M5 = (A11 + A12) B22
        *** 	M6 = (A21 - A11) (B11 + B12)
        *** 	M7 = (A12 - A22) (B21 + B22)
        ************************************************/

		// calcula M1
		soma(A11, A22, result1, m);
		soma(B11, B22, result2, m);
		vector< vector<int> > M1 (m, interno);
		strassen(result1, result2, M1, m);

		// calcula M2
		soma(A21, A22, result1, m);
		vector< vector<int> > M2 (m, interno);
		strassen(result1, B11, M2, m);

		// calcula M3
		subtrai(B12, B22, result2, m);
		vector< vector<int> > M3 (m, interno);
		strassen(A11, result2, M3, m);

		// calcula M4
		subtrai(B21, B11, result2, m);
		vector< vector<int> > M4 (m, interno);
		strassen(A22, result2, M4, m);

		// calcula M5
		soma(A11, A12, result1, m);
		vector< vector<int> > M5 (m, interno);
		strassen(result1, B22, M5, m);

		// calcula M6
		subtrai(A21, A11, result1, m);
		soma(B11, B12, result2, m);
		vector< vector<int> > M6 (m, interno);
		strassen(result1, result2, M6, m);

		// calcula M7
		subtrai(A12, A22, result1, m);
		soma(B21, B22, result2, m);
		vector< vector<int> > M7 (m, interno);
		strassen(result1, result2, M7, m);

		/**********************************************
        ***      C11 = M1 + M4 - M5 + M7
        ***      C12 = M3 + M5
        ***      C21 = M2 + M4
        ***      C22 = M1 - M2 + M3 + M6
        **********************************************/

		// calcula C11
       	soma(M1, M4, result1, m);
       	soma(result1, M7, result2, m);
       	subtrai(result2, M5, C11, m);

       	// calcula C12
       	soma(M3, M5, C12, m);

       	// calcula C21
       	soma(M2, M4, C21, m);

       	// calcula C22
       	subtrai(M1, M2, result1, m);
       	soma(M3, M6, result2, m);
       	soma(result1, result2, C22, m);

       	// junta os resultados em uma unica matriz
       	junta(C11, C, 0 , 0, m);
        junta(C12, C, 0 , m, m);
        junta(C21, C, m, 0, m);
        junta(C22, C, m, m, m);
	}
}

// Funçao para encontrar o desvio padrao e auxiliar no relatorio
double desvio_padrao(vector<int> tempo, int qte){
	int somatorio = 0;

	for(int i = 0; i < qte; i++){
		somatorio += tempo[i];
	}

	double media = 1.0 * somatorio / qte;

	double x = 0;

	for(int i = 0; i < qte; i++){
		double temp = tempo[i] - media;
		x += temp * temp;
	}

	double sigma = sqrt(x / qte);

	return sigma;
}

int main(){
	
	cout << "Digite o tamanho da Matriz NxN: \n";
    cin >> n;

	// ponto onde deve parar de dividir as matrizes
	parada = 64;

	//auxiliar para definir tamanho da matriz
	vector<int> interno (n);

	//matrizes
	vector< vector<int> > A (n, interno);
	vector< vector<int> > B (n, interno);
	vector< vector<int> > C (n, interno);

	//vetor que guarda os tempos decorridos de cada vez que o codigo roda
	vector<int> tempo;

	int temp = 0;
	int qte = 10;

	//Roda o algoritmo qte vezes
	for(int i = 0; i < qte; i++){

		cria_matrizes(A, B, n);
		
		//Contagem de tempo em que o algoritmo roda
		auto start = high_resolution_clock::now();
		strassen(A, B, C, n);
		auto stop = high_resolution_clock::now();

		auto t = duration_cast<microseconds>(stop-start);

		//atribui o tempo decorrido ao vetor para calcular o desvio padrao posteriormente
		tempo.push_back(t.count());

		//atribui o tempo decorrido à variavel para fazer a media posteriormente
		temp += t.count();
	}

	cout << "Media: " << temp/qte << " ms\n";


	double desvio = desvio_padrao(tempo, qte);
	cout << "Desvio Padrao: " << desvio << "\n";

	
	//Printa Matriz
	//mostra(C, n);	

   	return 0;
}
