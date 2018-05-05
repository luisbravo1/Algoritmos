#include <iostream>
using namespace std;

int arreglo[12] = {2,4,3,5,6,7,8,10,12,1,9,11};
int aux[12];
int inicio = 0, fin = 11, mitad;


void Une(int inicio, int mitad, int fin) {}
	int i = inicio;
	int j = mitad+1;
	int k = inicio;

	while (i <= mitad && j <= fin) {
		if (arreglo[i] < arreglo[j]) {
			aux[k] = arreglo[i];
			i = i+1;
		} else {
			aux[k] = arreglo[j];
			j = j+1;
		}
		k = k + 1;
	}
	if (i > mitad) {
		//Mover elementos j a fin del arreglo al arreglo aux de k a fin;
		for (int x=j; x < fin; x++) {
			aux[k] = arreglo[x];
			k++;
		}

	} else {
		//Mover elementos i a mitad del arreglo al arreglo aux de k a fin;
		for (int y=i; y < mitad; y++) {
			aux[k] = arreglo[y];
			k++;
		}
	}
	//Copiar aux a arreglo;
	for(int n=inicio; n < fin; n++) {
		arreglo[n] = aux[n];
	}
}

void MergeSort(int inicio, int fin) {
	if (inicio < fin) {
		mitad = (inicio + fin) / 2;
		MergeSort(inicio, mitad);
		MergeSort(mitad+1, fin);
		Une(inicio, mitad, fin);
	}
}

int main() {

	MergeSort(inicio, fin);
	for(int i=0; i < fin; i++)
		cout << arreglo[i] << " ";
	cout << endl;

	return 0;
}
