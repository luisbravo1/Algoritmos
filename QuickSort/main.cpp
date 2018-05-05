#include <iostream>
using namespace std;

int arreglo[8] = {15,22,13,27,12,10,20,25};
int inicio = 0, fin = 7, mitad;
int pivote = 0, aux, j;
int elemPivote;


void Particion(int inicio, int fin, int &pivote) {
	elemPivote = arreglo[inicio];
	j = inicio;

	for(int i=inicio+1; i <= fin; i++) {
		if (arreglo[i] < elemPivote) {
			j++;
			//Intercambia arreglo[i] con arreglo[j]
			aux = arreglo[i];
			arreglo[i] = arreglo[j];
			arreglo[j] = aux;
		}
	}
	pivote = j;
	//Intercambia arreglo[inicio] con arreglo[pivote]
	aux = arreglo[inicio];
	arreglo[inicio] = arreglo[pivote];
	arreglo[pivote] = aux;
}

void QuickSort(int inicio, int fin) {
	if (inicio < fin) {
		Particion(inicio, fin, pivote);
		QuickSort(inicio, pivote-1);
		QuickSort(pivote+1, fin);
	}
}

int main() {

	QuickSort(inicio, fin);
	for(int i=0; i <= fin; i++)
		cout << arreglo[i] << " ";
	cout << endl;

	return 0;
}