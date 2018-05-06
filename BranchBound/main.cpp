#include <iostream>
#include <limits.h>

using namespace std;

/*
void nivelXnivel(int r) {
	int *n, *h;

	while(f.size() != NULL) {

	}

}*/

int costoPosible(int matriz[5][5], int size) {
	int suma = 0;
	int menor = INT_MAX;
	for(int i=0; i < size; i++) {
		for(int j=0; j < size; j++) {
			if(matriz[i][j] < menor && matriz[i][j] != 0)
				menor = matriz[i][j];
		}
		suma += menor;
		menor = INT_MAX;
	}
	return suma;
}

int main() {
	int matriz[5][5] = {0,14,4,10,20,
						14,0,7,8,7,
						4,5,0,7,16,
						11,7,9,0,2,
						18,7,17,4,0};

	cout << costoPosible(matriz, 5);
	return 0;
}
