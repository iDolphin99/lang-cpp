#include <iostream>

using namespace std;

void SwapPointer(int* (&ptr1), int* (&ptr2)) 
{
	int *temp = ptr1; 
	ptr1 = ptr2;
	ptr2 = temp;
}
// temp(&林家, ptr1=num1林家)
// ptr1(&林家, num1林家) 
// ptr2(&林家, num2林家) 
int main(void) 
{
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2; 

	cout << "original value of ptr1 : " << *ptr1 << ", ptr2 : " << *ptr2 << endl;
	SwapPointer(ptr1, ptr2);
	cout << "After SwapPointer function, value of ptr1 : " << *ptr1 << ", ptr2 : " << *ptr2 << endl;

	return 0;
}