#include <iostream>
#include <climits>
#include <fstream>

using namespace std;
int MAX = INT_MAX;
int D[110][110];
int d[50];

int minimo(int i, int j) {
	return (i < j) ? i:j;
}

int llenaMinimos(int y, int x) {
	int j;

	//Llena la matriz D con 0
	for(int i=0; i < x; i++) {
		D[i][i+1] = 0;
	}

	//Llena la matriz D con los minimos de cada corte
	for(int diag=2; diag <= x; diag++) {
		for(int i=0; i <= x-diag; i++) {
			j = i + diag;
			D[i][j] = MAX;
			for(int k=i+1; k < j; k++) {
				D[i][j] = minimo(D[i][j], D[i][k] + D[k][j] + (d[j] - d[i]));
			}
		}
	}

	return D[0][x];
}

int main() {
	//ifstream entrada;
	//entrada.open("datos.txt");

	int size;
	int numCuts;

	cin >> size;
	//Se va a repetir hasta que input sea 0
	while(size != 0) {
		cin >> numCuts;

		d[0] = 0;

		//Guarda los datos de los cortes y el tamaño en el 
		//arreglo datos
		for(int i=1; i <= numCuts; i++) {
			cin >> d[i];
		}
		d[numCuts+1] = size;

		cout << "The minimum cutting is " << llenaMinimos(0, numCuts+1) << "." << endl;

		cin >> size;
	}

	//entrada.close();

	return 0;
}