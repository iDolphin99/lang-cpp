#include <iostream>

using namespace std;

void PlusOne(int &ref) {
	ref++;
}
void SwapSign(int& ref) {
	ref *= -1;
}


int main(void) {
	int a = 1; 

	cout << "original value : " << a << endl;
	PlusOne(a);
	cout << "PlusOne function : " << a << endl;
	SwapSign(a);
	cout << "SwapSign function : " << a << endl;

	return 0;
}