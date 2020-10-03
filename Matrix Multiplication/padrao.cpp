/* 
	Algoritmo Padrao para multiplicação de Matrizes

	Grupo: Maxley Soares da Costa			11911BCC038
		   Joao Vitor Afonso Pereira		11911BCC037
		   Bruno Oliveira Sinhoroto			11821BCC044
*/


#include<bits/stdc++.h>
#include<chrono>

using namespace std::chrono;
using namespace std;

#define MAXN 1000
#define int long long

int n;

// Multiplica duas matrizes
void matrixmult(vector< vector<int> > &A, vector< vector<int> > &B, vector< vector<int> > &C){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			C[i][j] = 0;
			for(int k = 0; k < n; k++){
				C[i][j] += A[i][k] * B[k][j]; 
			}
		}
	}
	return;
}

// Printa a matriz resultante
void mostra(vector< vector<int> > C){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << C[i][j] << " ";
		}

		cout << "\n";
	}

}

// Funcao que cria as matrizes aleatorias
void cria_matrizes(vector< vector<int> > &A, vector< vector<int> > &B){
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

// Funçao para encontrar o desvio padrao e auxiliar no relatorio
double desvio_padrao(vector<int> v, int qte){
	int somatorio = 0;

	for(int i = 0; i < qte; i++){
		somatorio += v[i];
	}

	double media = 1.0 * somatorio / qte;

	double x = 0;

	for(int i = 0; i < qte; i++){
		double temp = v[i] - media;
		x += temp * temp;
	}

	double sigma = sqrt(x / qte);

	return sigma;
}

int32_t main(){

	cout << "Digite o tamanho da Matriz NxN: \n";
    cin >> n;


    //Auxiliar para definiir o tamanho das matrizes
    vector<int> interno(n);

    vector< vector<int> > A(n, interno);
    vector< vector<int> > B(n, interno);
    vector< vector<int> > C(n, interno);

	//vetor que guarda os tempos decorridos de cada vez que o codigo roda
	vector<int> tempo;

	int temp = 0;
	int qte = 30;

	//Roda o algoritmo qte vezes
	for(int i = 0; i < qte; i++){

		cria_matrizes(A, B);
		
		//Contagem de tempo em que o algoritmo roda
		auto start = high_resolution_clock::now();
		matrixmult(A, B, C);
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

	//Printa a matriz resultado
	//mostra(C);

	return 0;
}