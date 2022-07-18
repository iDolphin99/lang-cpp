#include <iostream>

using namespace std;

int main(void)
{
	const int num = 12;
	const int *ptrNum = &num;
	const int* (&ptrPtr) = ptrNum;
	//const int &ptrPtr = *ptrNum;

	cout << &num << endl;
	cout << ptrNum << endl;
	cout << &ptrPtr << endl;

	return 0; 
}

// num(12, &num)
// ptrNum(num林家, &ptrNum)
// ptrPtr(num林家, &ptrPtr)