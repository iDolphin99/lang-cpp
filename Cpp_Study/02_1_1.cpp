#include <iostream>

using namespace std;

void IncreaseOne(int &ref) {
	ref++;
}
void InverseSign(int& ref) {
	ref *= -1;
}


int main(void) {
	int a = 1; 

	cout << "original value : " << a << endl;
	IncreaseOne(a);
	cout << "PlusOne function : " << a << endl;
	InverseSign(a);
	cout << "SwapSign function : " << a << endl;

	return 0;
}