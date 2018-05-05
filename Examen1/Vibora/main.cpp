#include <iostream>

using namespace std;

int n, m;

void vibora(int **plano, int **copia, int row, int col, int tam, int &mayorTam) {
	if(plano[row][col] == 0) {
		copia[row][col] = 1;
		return ;
	}
	if(plano[row][col] == 1) {
		tam++;
		copia[row][col] = 1;
	}
	//Checa derecha
	if(col+1 < m) {
		if(copia[row][col+1] != 1) {
			if(plano[row][col+1] == 1) {
				vibora(plano, copia, row, col+1, tam, mayorTam);
			} else {
				copia[row][col+1] = 1;
			}
		}
	}
	//Checa abajo
	if(row+1 < n) {
		if(copia[row+1][col] != 1) {
			if(plano[row+1][col] == 1) {
				vibora(plano, copia, row+1, col, tam, mayorTam);
			} else {
				copia[row+1][col] = 1;
			}
		}
	}
	//Checa izquierda
	if(col-1 >= 0) {
		if(copia[row][col-1] != 1) {
			if(plano[row][col-1] == 1) {
				vibora(plano, copia, row, col-1, tam, mayorTam);
			} else {
				copia[row][col-1] = 1;
			}
		}
	}

	if (tam > mayorTam) {
		mayorTam = tam;
	}
}

int main() {

	int mayorTam=0;
	cin >> n >> m;
	//Crea matriz
	int** plano = new int*[n];
	for(int i=0; i < n; ++i)
		plano[i] = new int[m];

	//Crea matrizCopia
	int** copia = new int*[n];
	for(int i=0; i < n; ++i)
		copia[i] = new int[m];

	//Asigna los valores a la matriz;
	for(int rows=0; rows < n; rows++) {
		for(int col=0; col < m; col++)
			cin >> plano[rows][col];
	}

	//Checa si no se ha visitado esa casilla
	for(int rows=0; rows < n; rows++) {
		for(int cols=0; cols < m; cols++) {
			if(copia[rows][cols] != 1) {
				vibora(plano, copia, rows, cols, 0, mayorTam);
			}
		}	
	}

	cout << mayorTam << endl;

	//Liberar memoria
	for(int i=0; i < n; ++i)
		delete [] plano[i];
	delete [] plano;

	for(int i=0; i < n; ++i)
		delete [] copia[i];
	delete [] copia;
	
	return 0;
}