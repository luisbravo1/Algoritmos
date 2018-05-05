
// 1100
// A01282272
#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
#include <iomanip>

using namespace std;
int MAX = INT_MAX;


int D[110][110];
int P[110][110];

void camino(int inicio,int fin) {
  cout << D[inicio][fin] << endl;
  if (P[inicio][fin] != 0) {
    camino(inicio,P[inicio][fin]-1);
    cout << D[inicio][fin] << endl;
    camino(P[inicio][fin]-1,fin);
  }
}

int main() {

  //ifstream input;
  //input.open("datos.txt");

  int x,y;
  int q;
  int ix,iy,in;


  int times;
  cin >> times;
  for (int a = 0; a < times; a++) {

    cout << "Case " << (a+1) << ":" << endl;
    cin >> x >> y >> q;

    for (int i = 0; i < x; i++) {
      for (int j = 0; j < x; j++) {
        if (i != j) {
         D[i][j] = MAX;
        }
      }
    }


    for (int i = 0; i < y; i++) {
      cin >> ix;
      cin >> iy;
      cin >> in;
      D[iy-1][ix-1] = in;
      D[ix-1][iy-1] = in;
    }

    for (int k = 0; k < x; k++) {
      for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
          if (D[i][k] != MAX && D[k][j] != MAX) {


            int max = (D[i][k] > D[k][j] ? D[i][k] : D[k][j]);
            if (D[i][j] > max) {
              P[i][j] = k + 1;
              D[i][j] = max;
            }

          }
        }
      }

    }

    int min,max;
    for (int i = 0; i < q; i++) {
      cin >> min;
      min--;
      cin >> max;
      max--;
      if (D[min][max] == MAX) {
        cout << "no path" << endl;
      } else {
        cout << D[min][max] << endl;
      }

    }


  }

  //input.close();



  return 0;
}