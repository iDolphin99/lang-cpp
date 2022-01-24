#include <iostream>

using namespace std;

char* MakeStrAdr(int len)
{
	// char *str = (char*)malloc(sizeof(char)*len)
	char* str = new char[len];

	return str;
}

int main(void)
{
	char* str = MakeStrAdr(20);
	
	strcpy(str, "I AM AI");
	cout << str << endl;

	// free(str);
	delete []str;

	return 0;
}