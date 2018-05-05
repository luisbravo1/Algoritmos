//Luis Gerardo Bravo Ramones A01282014
//Hector de Luna Pamanes A01282272
//Super Sale Proy02A

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int P[1000];
int W[1000];
int V[1000][1000];

int m;
int n;

int backtracking() {
	for(int i=0; i <= n; i++) {
		for(int w=0; w <= m; w++) {
			if (i == 0 || w == 0) {
				V[i][w] = 0;
			} else if (W[i-1] <= w) {
				V[i][w] = max(V[i-1][w], V[i-1][w-W[i-1]] + P[i-1]);
			} else {
				V[i][w] = V[i-1][w];
			}
		}
	}
	return V[n][m];
}

int main() {
	int suma=0;
	int cases, people;

	cin >> cases;
	for(int c=0; c < cases; c++) {
		suma = 0;
		cin >> n;

		for(int x=0; x < n; x++) {
			cin >> P[x] >> W[x];
		}

		cin >> people;
		for(int p=0; p < people; p++) {
			cin >> m;
			suma += backtracking();
		}
		cout << suma << endl;
	}

	return 0;
}
