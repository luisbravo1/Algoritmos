#include <iostream>
#include <string>

using namespace std;

int main() {
	int letras[2][26] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
	string entrada;
	int ascii;

	cin >> entrada;

	//Suma valores de letras encontradas
	for(int i=0; i < entrada.size(); i++) {
		ascii = entrada[i];
		for(int x=0; x < 26; x++) {
			if(letras[0][x] == ascii)
				letras[1][x]++;
		}
	}

	//Muestra salida
	for(int x=0; x < 26; x++) {
		if(letras[1][x] > 0)
			cout << char(letras[0][x]) << " - " << letras[1][x] << endl;
	}
	
	return 0;
}
