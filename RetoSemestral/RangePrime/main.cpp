#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

//Checks for a prime number in the left of number
int primeL(int number) {
	if(number == 2) return number;

	if(number % 2 == 0) return primeL(number-1);

	for(int i=3; (i*i)<= number; i+=2)
		if(number % i == 0) return primeL(number-1);

	return number;
}

//Checks for a prime number in the right of number
int primeR(int number) {
	if(number == 2) return number;

	if(number % 2 == 0) return primeR(number+1);

	for(int i=3; (i*i)<= number; i+=2)
		if(number % i == 0) return primeR(number+1);
	
	return number;
}

int main() {
	int num, M;
	vector <int> number;

	cin >> M;

	for(int i=0; i < M; i++) {
		cin >> num;
		number.push_back(num);
	}

	for(int i=0; i < M; i++)
		cout << primeL(number[i]) << " " << primeR(number[i]) << endl;

	return 0;
	
}