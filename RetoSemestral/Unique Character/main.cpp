#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	int size;
	string mid;
	int posMid;
	string left, right;
	int contL=1;
	int contR=1;

	cin >> input;

	do {

		contL = contR = 1;
		size = input.size();
		if(size == 1){
			cout << input << endl;
			break;
		}
		mid = input.substr(size/2, 1);
		posMid = size/2;

		//cout << "mid: " << mid << endl;

		do {
			left = input.substr(posMid-contL, 1);	
			if(left == mid)
				contL++;
			else
				contL--;	
		} while(left == mid);

		do {
			right = input.substr(posMid+contR, 1);
			if(right == mid)
				contR++;		
		} while(right == mid);

		if(contL == 0 && contR == 1)
			cout << mid << endl;
		else
			input.erase(posMid-contL, contL+contR);

		//cout << input << endl;
	} while (contL != 0 || contR != 1);

	return 0;
	
}