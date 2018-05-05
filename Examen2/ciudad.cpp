#include <iostream>
#include <climits>
#include <limits.h>

using namespace std;
int MAX = INT_MAX;

void Floyd(int D[20][20], int C) {
	for(int k=0; k < C; k++) {
		for(int i=0; i < C; i++) {
			for(int j=0; j < C; j++) {
				if(D[i][k] != MAX && D[k][j] != MAX) {
					if(D[i][k] + D[k][j] < D[i][j]) {
						D[i][j] = D[i][k] + D[k][j];
					}
				}
			}
		}
	}
}

void copy(int D[20][20], int P[20][20], int C) {
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < C; j++) {
			P[i][j] = D[i][j];
		}
	}
}

int main() {
	int C, S;
	int c1, c2, d;
	int moves;
	char instr;
	int D[20][20];
	int D2[20][20];  //Matriz para guardar los datos originales
	int P[20][20];

	cin >> C >> S;

	//Llena la matriz D con numeros maximos excepto
	//cuando i = j
	for(int i=0; i < C; i++) {
		for(int j=0; j < C; j++) {
			if(i != j) {
				D[i][j] = D2[i][j] = MAX;
			}
		}
	}

	//Va a ingresar a la matriz D todos los cruces 
	//con su respectivo tiempo
	for(int i=0; i < S; i++) {
		cin >> c1 >> c2 >> d;
		D[c1-1][c2-1] = D2[c1-1][c2-1] = d;
		D[c2-1][c1-1] = D2[c2-1][c1-1] = d;
	}

	cin >> moves;
	for (int i = 0; i < moves; i++) {
		cin >> instr >> c1 >> c2;

		switch (instr) {
			case 'q':
				copy(D, P, C);
				Floyd(P, C);
				cout << P[c1-1][c2-1] << endl;
				break;
			case 'b':
				D[c1-1][c2-1] = MAX;
				D[c2-1][c1-1] = MAX;
				break;
			case 'd':
			case 't':
				D[c1-1][c2-1] = D2[c1-1][c2-1];
				D[c2-1][c1-1] = D2[c2-1][c1-1];
				break;
			case 'p':
				D[c1-1][c2-1] *= 2;
				D[c2-1][c1-1] *= 2;
				break;
		}
	}
	
	return 0;
}