// Proyecto Strassen
// Diego Martínez A01176489
// Mauricio Guadiana A01281897
// Fecha: 06/03/2018
#include <iostream>
#include <vector>

using namespace std;

int scalmult = 0;

void tradicional(int n, vector<vector<int> > A, vector<vector<int> > B, vector<vector<int> > &C){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            C[i][j] = 0;
            for (int k = 0; k < n; k++){
                C[i][j] += A[i][k]*B[k][j];
                scalmult++;
            }
        }
    }
}

void suma_matriz(int n, vector<vector<int> > A, vector<vector<int> > B, vector<vector<int> > &C){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void resta_matriz(int n, vector<vector<int> > A, vector<vector<int> > B, vector<vector<int> > &C){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, vector<vector<int> > A, vector<vector<int> > B, vector<vector<int> > &C){

    if ( n <= 2 ){
        //Calcular C = A x B de forma tradicional
        tradicional(2, A, B, C);
    } else {
        vector< vector<int> >
        a11(n/2,vector<int>(n/2)), a12(n/2,vector<int>(n/2)), a21(n/2,vector<int>(n/2)), a22(n/2,vector<int>(n/2)),
        b11(n/2,vector<int>(n/2)), b12(n/2,vector<int>(n/2)), b21(n/2,vector<int>(n/2)), b22(n/2,vector<int>(n/2)),
        m1(n/2,vector<int>(n/2)), m2(n/2,vector<int>(n/2)), m3(n/2,vector<int>(n/2)), m4(n/2,vector<int>(n/2)),
                                  m5(n/2,vector<int>(n/2)), m6(n/2,vector<int>(n/2)), m7(n/2,vector<int>(n/2)),
        R1(n/2,vector<int>(n/2)), R2(n/2,vector<int>(n/2));

        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n/2; j++) {
                a11[i][j] = A[i][j];
                b11[i][j] = B[i][j];
                a12[i][j] = A[i][j + n/2];
                b12[i][j] = B[i][j + n/2];
                a21[i][j] = A[i + n/2][j];
                b21[i][j] = B[i + n/2][j];
                a22[i][j] = A[i + n/2][j + n/2];
                b22[i][j] = B[i + n/2][j + n/2];
            }
        }

        //m1
        suma_matriz(n/2, a11, a22, R1);
        suma_matriz(n/2, b11, b22, R2);
        strassen(n/2, R1, R2, m1);
        //m2
        suma_matriz(n/2, a21, a22, R1);
        strassen(n/2, R1, b11, m2);
        //m3
        resta_matriz(n/2, b12, b22, R1);
        strassen(n/2, a11, R1, m3);
        //m4
        resta_matriz(n/2, b21, b11, R1);
        strassen(n/2, a22, R1, m4);
        //m5
        suma_matriz(n/2, a11, a12, R1);
        strassen(n/2, R1, b22, m5);
        //m6
        resta_matriz(n/2, a21, a11, R1);
        suma_matriz(n/2, b11, b12, R2);
        strassen(n/2, R1, R2, m6);
        //m7
        resta_matriz(n/2, a12, a22, R1);
        suma_matriz(n/2, b21, b22, R2);
        strassen(n/2, R1, R2, m7);

        vector< vector<int> >
        c11(n/2,vector<int>(n/2)), c12(n/2,vector<int>(n/2)), c21(n/2,vector<int>(n/2)), c22(n/2,vector<int>(n/2));
        //C11
        suma_matriz(n/2, m1, m4, R1);
        suma_matriz(n/2, R1, m7, R2);
        resta_matriz(n/2, R2, m5, c11);
        //C12
        suma_matriz(n/2, m3, m5, c12);
        //C21
        suma_matriz(n/2, m2, m4, c21);
        //C22
        suma_matriz(n/2, m1, m3, R1);
        suma_matriz(n/2, R1, m6, R2);
        resta_matriz(n/2, R2, m2, c22);

        for (int i = 0; i < n/2; i++) {
            for (int j = 0 ; j < n/2; j++) {
                C[i][j] = c11[i][j];
                C[i][j + n/2] = c12[i][j];
                C[i + n/2][j] = c21[i][j];
                C[i + n/2][j + n/2] = c22[i][j];
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int> > matA(n, vector<int>(n));
    vector<vector<int> > matB(n, vector<int>(n));
    vector<vector<int> > matC(n, vector<int>(n));

    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cin >> matA[x][y];
        }
    }

    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cin >> matB[x][y];
        }
    }

    tradicional(n, matA, matB, matC);
    cout << "Traditional:" << endl;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cout << matC[x][y] << " ";
        }
        cout << endl;
    }
    cout << "Scalar Multiplications: " << scalmult << endl;

    scalmult = 0;
    strassen(n, matA, matB, matC);
    cout << "Strassen:" << endl;
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cout << matC[x][y] << " ";
        }
        cout << endl;
    }
    cout << "Scalar Multiplications: " << scalmult << endl;
}
