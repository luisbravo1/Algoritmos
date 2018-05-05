#include <iostream>
using namespace std;

/*
int mayor(int matriz[4][4], int cont, int i, int j, int n) {
  return mayorCien(matriz, cont, i, j, n);
}
*/

int mayorCien(int matriz[4][4], int cont, int i, int j, int n) {
  if (i >= n && j > n) 
    return cont;
  if (j > n) {
    j = 0;
    i++;
  }
  if (matriz[i][j] >= 100) {
    return mayorCien(matriz, cont+1, i, j+1, n);
  }
  else {
    return mayorCien(matriz, cont, i, j+1, n);
  }
}

int main() {
  int matriz[4][4] = {0, 0, 0, 100, 
                      0, 100, 100, 0, 
                      100, 0, 100, 0, 
                      0, 0, 0, 100};

  cout << mayorCien(matriz, 0, 0, 0, 3) << endl;
}