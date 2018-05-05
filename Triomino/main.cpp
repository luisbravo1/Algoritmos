#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int RI, RM, RF, CI, CM, CF;
int matriz[32][32];
int numero = 2;
int posR, posC;

void divide(int RI, int RF, int CI, int CF, int posR, int posC) {
	if(RI == RF && CI == CF) {
		return;
	}

	RM = (RI+RF)/2;
	CM = (CI+CF)/2;

	
	if (posR < RM && posC < CM) {
		matriz[RM][CM+1] = numero;
		matriz[RM+1][CM] = numero;
		matriz[RM+1][CM+1] = numero;
		numero++;
		divide(RI, RM, CI, CM, posR, posC);
		divide(RI, RM, CM+1, CF, RM, CM+1);
		divide(RM+1, RF, CI, CM, RM+1, CM);
		divide(RM+1, RF, CM+1, CF, RM+1, CM+1);
	}
	
	if (posR < RM && posC > CM) {
		matriz[RM][CM] = numero;
		matriz[RM+1][CM] = numero;
		matriz[RM+1][CM+1] = numero;
		numero++;
		divide(RI, RM, CI, CM, RM, CI);
		divide(RI, RM, CM+1, CF, posR, posC);
		divide(RM+1, RF, CI, CM, RM+1, CM);
		divide(RM+1, RF, CM+1, CF, RM+1, CM+1);
	}
	
	if (posR > RM && posC < CM) {
		matriz[RM][CM] = numero;
		matriz[RM][CM+1] = numero;
		matriz[RM+1][CM+1] = numero;
		numero++;
		divide(RI, RM, CI, CM, RM, CM);
		divide(RI, RM, CM+1, CF, RM, CM+1);
		divide(RM+1, RF, CI, CM, posR, posC);
		divide(RM+1, RF, CM+1, CF, RM+1, CM+1);
	}
	
	if (posR > RM && posC > CM) {
		matriz[RM][CM] = numero;
		matriz[RM+1][CM] = numero;
		matriz[RM][CM+1] = numero;
		numero++;
		divide(RI, RM, CI, CM, RM, CM);
		divide(RI, RM, CM+1, CF, RM, CM+1);
		divide(RM+1, RF, CI, CM, RM+1, CM);
		divide(RM+1, RF, CM+1, CF, posR, posC);
	}
}

int main() {
	int tam;

	cout << "De que tamaño es la matriz? ";
	cin >> tam;
	cout << "En donde se encuentra la X? ";
	cin >> posR >> posC;
	matriz[posR][posC] = 1;

	divide(0,tam-1,0,tam-1,posR,posC);

	for(int i=0; i < tam; i++) {
		for(int j=0; j < tam; j++) {
			cout << setw(5) << matriz[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}