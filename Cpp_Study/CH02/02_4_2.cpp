#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
		cout << rand() % 100 << " ";

	return 0;
}