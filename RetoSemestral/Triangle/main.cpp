#include <iostream>
#include <algorithm>
using namespace std;

int sumBig(int triangle[20][20], int n){
    for ( int i = n - 2; i >= 0 ; i-- ) 
        for ( int j = 0; j <= i ; ++j ) 
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
            int num = triangle[0][0];

    return num;
}

int main() {
    int n, levels;
    int input[20][20];

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> levels;
        for(int j = 0; j < levels; j++) {
            for(int k = 0; k < j + 1; k++) {
                cin >> input[j][k];
            }
        }
        cout << sumBig(input, levels) << endl;
    }


  return 0;
}