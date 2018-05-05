#include <iostream>
#include <stack>
#include <climits>

using namespace std;

#define N 20

void initMatAdj(int mat[N][N]){
	for (int i = 0; i<N; i++){
		mat[i][i] = 0;
		for (int j = i+1; j<N; j++){
			mat[i][j] = mat[j][i] = INT_MAX;
		}
	}
}
void leeMatAdj(int mat[N][N], int e){
	char a, b;
	int c;
	for (int i=1; i<=e; i++){
		cin >> a >> b >> c;
		int ia = (int)a - 64;
		int ib = (int)b - 64;

		mat[ia-1][ib-1] = mat[ib-1][ia-1] = c;
	}
}

void Dijkstra(int W[N][N], int L[N], int T[N], int v){
	bool encontre[N];
	for (int i=0; i<v; i++){
		encontre[i] = false;
	}
	for (int i=0; i<v; i++){
		L[i] = W[0][i];
		T[i] = 0;
	}

	for (int i=1; i<v; i++){
		int min = INT_MAX;
		int imin;
		for (int j=1; j<v; j++){
			if (!encontre[j] && 0 < L[j] && L[j] < min){
				min = L[j];
				imin = j;
			}
		}

		for (int j=1; j<v; j++){
			if (W[imin][j] != INT_MAX && L[imin]+W[imin][j] < L[j]){
				L[j] =  L[imin]+W[imin][j];
				T[j] = imin;
			}
		}
		encontre[imin] = true;
	}	
}

char printMayor(int L[N], int v){
	int mayor = 0;
	int mayorIdx = 0;

	for(int i=1; i < v; i++) {
		if(L[i] > mayor) {
			mayor = L[i];
			mayorIdx = i;
		}
	}
	return mayorIdx + 65;
}

int main(){
	int mat[N][N];
	int L[N];
	int T[N];
	int cases, v, e;
	cin >> cases;
	for(int i=1; i <= cases; i++) {
		cin >> v >> e;
		initMatAdj(mat);
		leeMatAdj(mat,e);
		Dijkstra(mat, L, T, v);
		cout << "Case " << i << ": " << printMayor(L, v) << endl;
	}
	return 0;
}


/*
5 8
1 2 2
1 3 12
1 4 10
2 3 9
2 5 5
3 4 6
3 5 3
4 5 7
*/

/*
1
5 7
A B 5
A C 4
A D 7
B E 3
C D 2
C E 4
D E 1
*/

/*
1
4 6
A B 1
A C 1
A D 1
B C 1
B D 1
C D 1
*/
