#include <iostream>
#include <climits>
//#include <fstream>

using namespace std;
int MAX = INT_MAX;

int main() {
	//ifstream entrada;
	//entrada.open("datos.txt");

	int cases;
	int C, S, Q;
	int c1, c2, d;
	int D[110][110];
	int P[110][110];

	//Numero de veces que se va a repetir
	cin >> cases;
	for(int n=0; n < cases; n++) {
		cout << "Case " << n+1 << ":" << endl;
		cin >> C >> S >> Q;

		//Llena la matriz D con numeros maximos excepto
		//cuando i = j
		for(int i=0; i < C; i++) {
			for(int j=0; j < C; j++) {
				if(i != j) {
					D[i][j] = MAX;
				}
			}
		}

		//Va a ingresar a la matriz D todos los cruces 
		//con su respectivo decibel
		for(int i=0; i < S; i++) {
			cin >> c1 >> c2 >> d;
			D[c1-1][c2-1] = d;
			D[c2-1][c1-1] = d;
		}

		//Floyd
		for(int k=0; k < C; k++) {
			for(int i=0; i < C; i++) {
				for(int j=0; j < C; j++) {
					if(D[i][k] != MAX && D[k][j] != MAX) {
						int valMax = (D[i][k] > D[k][j] ? D[i][k] : D[k][j]);
						if(D[i][j] > valMax) {
							P[i][j] = k + 1;
							D[i][j] = valMax;
						}
					}
				}
			}
		}

		//Muestra el sonido minimo entre c1 y c2
		int c1, c2;
		for(int i=0; i < Q; i++) {
			cin >> c1 >> c2;
			if(D[c1-1][c2-1] != MAX)
				cout << D[c1-1][c2-1] << endl;
			else
				cout << "no path" << endl;
		}

		for(int i=0; i < C; i++) {
			for(int j=0; j < C; j++) {
				cout << D[i][j] << " ";
			}
			cout << endl;
		}
	}

	//entrada.close();

	return 0;
}