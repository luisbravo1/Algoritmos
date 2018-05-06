// Examen Final Problema 3
// Luis Gerardo Bravo Ramones A01282014
#include <iostream>

using namespace std;

int caminos = 0;
int n, m;

void countCaminos(int renglon, int columna) {
  if (renglon == n && columna == m) {
    caminos++;
    return;
  }
  if (renglon > n || columna > m) return;

  countCaminos(renglon + 2, columna + 1);
  countCaminos(renglon + 1, columna + 2);
}

int main() {
  cin >> n >> m;
  countCaminos(1, 1);
  cout << caminos << endl;

  return 0;
}
