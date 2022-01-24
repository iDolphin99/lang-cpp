#include <iostream>
#include <cstring>
// #define LENGTH 20;

using namespace std;

int main(void)
{
	char* str1 = new char[20];
	char* str2 = new char[20];

	str1 = "I am";
	str2 = "AI";

	cout << "strlen: " << strlen(str1) << endl;
	cout << "strcat: " << strcat(str1, str2) << endl;
	cout << "strcpy: " << strcpy(str1, str2) << endl;
	cout << "strcmp: " << strcmp(str1, str2) << endl;

	return 0;
}