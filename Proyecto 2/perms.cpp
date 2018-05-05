//Luis Gerardo Bravo Ramones A01282014
//Hector de Luna Pamanes A01282272
//Super Sale Proy02B

#include <iostream>

using namespace std;

int main() {
	long P[20][210] = {0};
	P[1][0] = 1;

	for(int i=1; i < 18; i++) {
        for(int j=0; P[i][j]; j++) {
            for(int k=0; k <= i; k++) {
                P[i+1][j+k] += P[i][j];
            }
        }
	}

	int n, k;
	cin >> n >> k;
	while (n != 0 || k != 0) {
		cout << P[n][k] << endl;
		cin >> n >> k;
	}

	return 0;
}