// Strassen
// Luis Gerardo Bravo Ramones A01282014
// Hector de Luna Pamanes A01282272

#include <iostream>
#include <vector>

using namespace std;

int totalMult = 0;

void traditional (vector <vector<int> > A, vector <vector<int> > B, vector <vector<int> > &C, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			C[i][j] = 0;
			for (int k = 0; k < N; k++) {
				C[i][j] += A[i][k]*B[k][j];
				totalMult++;
			}
		}
	}
}

void sumaM(vector <vector<int> > A, vector <vector<int> > B, vector <vector<int> > &C, int N) {
	 for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void restaM(vector <vector<int> > A, vector <vector<int> > B, vector <vector<int> > &C, int N) {
	 for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(vector <vector<int> > A, vector <vector<int> > B, vector <vector<int> > &C, int N) {
	// Si la matriz es de 2x2 o menor se aplica el metodo tradicional
	if (N <= 2) {
		traditional(A, B, C, N);
	} else {
		// Divide las matrices en 4 elementos
		int mid = N/2;
		vector<vector<int> > A11(mid, vector<int>(mid)), A12(mid, vector<int>(mid)), A21(mid, vector<int>(mid)), A22(mid, vector<int>(mid));
		vector<vector<int> > B11(mid, vector<int>(mid)), B12(mid, vector<int>(mid)), B21(mid, vector<int>(mid)), B22(mid, vector<int>(mid));
		vector<vector<int> > C11(mid, vector<int>(mid)), C12(mid, vector<int>(mid)), C21(mid, vector<int>(mid)), C22(mid, vector<int>(mid));
		vector<vector<int> > M1(mid, vector<int>(mid)), M2(mid, vector<int>(mid)), M3(mid, vector<int>(mid)), M4(mid, vector<int>(mid)),
			M5(mid, vector<int>(mid)), M6(mid, vector<int>(mid)), M7(mid, vector<int>(mid));
		vector<vector<int> > AA(mid, vector<int>(mid)), BB(mid, vector<int>(mid));
		
		// Asigna valores a las matrices
		for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + mid];
                A21[i][j] = A[i + mid][j];
                A22[i][j] = A[i + mid][j + mid];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + mid];
                B21[i][j] = B[i + mid][j];
                B22[i][j] = B[i + mid][j + mid];
            }
        }

        // M1
        sumaM(A11, A22, AA, mid);
        sumaM(B11, B22, BB, mid);
        strassen(AA, BB, M1, mid);

        // M2
        sumaM(A21, A22, AA, mid);
        strassen(AA, B11, M2, mid);

        // M3
        restaM(B12, B22, AA, mid);
        strassen(A11, AA, M3, mid);

        // M4
        restaM(B21, B11, AA, mid);
        strassen(A22, AA, M4, mid);

        // M5 
        sumaM(A11, A12, AA, mid);
        strassen(AA, B22, M5, mid);

        // M6
        restaM(A21, A11, AA, mid);
        sumaM(B11, B12, BB, mid);
        strassen(AA, BB, M6, mid);

        // M7
        restaM(A12, A22, AA, mid);
        sumaM(B21, B22, BB, mid);
        strassen(AA, BB, M7, mid);

        // C0
        sumaM(M1, M4, AA, mid);
        restaM(M7, M5, BB, mid);
        sumaM(AA, BB, C11, mid);
        
        // C1
        sumaM(M3, M5, C12, mid);
        
        // C2
        sumaM(M2, M4, C21, mid);
        
        // C3
        restaM(M1, M2, AA, mid);
        sumaM(M3, M6, BB, mid);
        sumaM(AA, BB, C22, mid);

        for(int i = 0; i < mid; i++) {
            for(int j = 0; j < mid; j++) {
				C[i][j] = C11[i][j];
				C[i][j + mid] = C12[i][j];
				C[i + mid][j] = C21[i][j];
				C[i + mid][j + mid] = C22[i][j];        
            }        
        }
	}
}

int main() {
	int N;
	cin >> N;

	vector<vector<int> > matrixA(N, vector<int>(N));
	vector<vector<int> > matrixB(N, vector<int>(N));
	vector<vector<int> > matrixC(N, vector<int>(N));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrixA[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrixB[i][j];
		}
	}

	totalMult = 0;
	traditional(matrixA, matrixB, matrixC, N);
	cout << "Traditional:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrixC[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Scalar Multiplications: " << totalMult << endl;
	cout << endl;

	totalMult = 0;
	strassen(matrixA, matrixB, matrixC, N);
    cout << "Strassen:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrixC[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Scalar Multiplications: " << totalMult << endl;

	return 0;
}