// 1100
// A01282272
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int s;

int Arr[32][32];

int c;



void print() {
   for (int i = 0; i < s; i++) {
    for (int a = 0; a < s; a++) {
      cout << setw(5) << Arr[i][a] << " ";
    }
    cout << endl;
  }
  cout << endl;
}


void Trinomio(int rin, int rfin, int cin, int cfin,int iy,int ix) {


  if (rin == rfin && cin == cfin) {
    return;
  }

  int num = c++;


  int rmid = (rfin+rin)/2;
  int cmid = (cfin+cin)/2;

  // Arriba a la izquierda
  if (!(rin <= ix && rmid >= ix && cin <= iy && cmid >= iy)) {
    Arr[cmid][rmid] = num;
    Trinomio(rin,rmid,cin,cmid,cmid,rmid);
  } else {
    Trinomio(rin,rmid,cin,cmid,iy,ix);
  }
  // Arriba a la derecha
  if (!(rmid+1 <= ix && rfin >= ix && cin <= iy && cmid >= iy) ) {
    Arr[cmid][rmid+1] = num;
    Trinomio(rmid+1,rfin,cin,cmid,cmid,rmid+1);
  } else {
    Trinomio(rmid+1,rfin,cin,cmid,iy,ix);
  }
  // Abajo a la izquierda
  if (!(rin <= ix && rmid >= ix && cmid+1 <= iy && cfin >= iy)) {
    Arr[cmid+1][rmid] = num;
    Trinomio(rin,rmid,cmid+1,cfin,cmid+1,rmid);
  } else {
    Trinomio(rin,rmid,cmid+1,cfin,iy,ix);
  }
  // Abajo a la derecha
  if (!(rmid+1 <= ix && rfin >= ix && cmid+1 <= iy && cfin >= iy) ) {
    Arr[cmid+1][rmid+1] = num;
    Trinomio(rmid+1,rfin,cmid+1,cfin,cmid+1,rmid+1);
  } else {
    Trinomio(rmid+1,rfin,cmid+1,cfin,iy,ix);
  }


}


int main() {
  c = 1;
  int x,y;
  cin >> x >> y;
  cin >> s;

  Arr[y][x] = 0;

  Trinomio(0,s-1,0,s-1,y,x);

  print();

  return 0;
}