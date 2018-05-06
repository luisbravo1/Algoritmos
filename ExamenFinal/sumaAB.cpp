// Examen Final Problema 2
// Luis Gerardo Bravo Ramones A01282014
#include <iostream>

using namespace std;

int sumaAB(int a, int b) {
  if (a <= b) return (b-a+1)*(a+b)/2;
  return 0;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << sumaAB(a,b);

  return 0;
}
