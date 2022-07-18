#include <iostream>

using namespace std;

class Calculator {
private :
	int addCnt, minCnt, subCnt, divCnt;

public :
	void Init() {
		addCnt = 0;
		minCnt = 0;
		subCnt = 0;
		divCnt = 0;
	}
	double Add(double a, double b) {
		addCnt++;
		return a + b;
	}
	double Min(double a, double b) {
		minCnt++;
		return a - b;
	}
	double Sub(double a, double b) {
		subCnt++;
		return a * b;
	}
	double Div(double a, double b) {
		divCnt++;
		return a / b;
	}
	void ShowOpCount() {
		cout << "µ¡¼À: " << addCnt << " »¬¼À: " << minCnt << " °õ¼À: " << subCnt << " ³ª´°¼À: " << divCnt; 
	}
};

int main(void) 
{
	Calculator cal; 
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 - 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 / 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 - 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();

	return 0;
}