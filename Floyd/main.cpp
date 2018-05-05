#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int MAX = INT_MAX;

int D[100][100];
int P[100][100];

void camino(int inicio, int fin) {
	cout << D[inicio][fin] << endl;
	if(P[inicio][fin] != 0) {
		camino(inicio, P[inicio][fin]-1);
		cout << P[inicio][fin];
		camino(P[inicio][fin]-1, fin);
	}
}


int main() {

	ifstream entrada;
	entrada.open("datosFloyd.txt");

	int n, m, q;
	int col;
	int row;
	int val;

	entrada >> n >> m >> q;


	for(int i=0; i < n; i++) {
		for(int j=0; j < n; j++) {
			if(i != j) {
				D[i][j] = MAX;
			}
		}
	}

	for(int x=1; x <= m; x++) {
		entrada >> col >> row >> val;
		D[col-1][row-1] = val;
		D[row-1][col-1] = val;
	}

	/*
	for(int x=0; x < 10; x++) {
		for(int y=0; y < 10; y++)
			cout << setw(6) << D[x][y] << " ";
		cout << endl;
	}
	cout << endl;
	*/

	for(int k=0; k < n; k++) {
		for(int i=0; i < n; i++) {
			for(int j=0; j < n; j++) {
				if(D[k][j] != MAX && D[i][j] != MAX) {
					if(D[i][k] + D[k][j] < D[i][j]) {
						P[i][j] = k + 1;
						D[i][j] = D[i][k] + D[k][j];
					}
				}
			}
		}
	}

	//camino(10,1);

	/*
	for(int x=0; x < 10; x++) {
		for(int y=0; y < 10; y++)
			cout << setw(3) << P[x][y] << " ";
		cout << endl;
	}*/

	for(int x=1; x <= q; x++) {
		entrada >> row >> col;
		cout << D[row-1][col-1] << endl;
	}

 
	entrada.close();


	return 0;
}