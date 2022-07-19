#include <iostream>
using namespace std;

class Rectangle {
private :
	int x, y;
public :
	Rectangle(int a, int b) : x(a), y(b) {
		cout << "Rectangle(int a, int b) Constructor called " << endl;
	}
	int getX() { return x; }
	int getY() { return y; }
	void ShowAreaInfo() {
		cout << "¸éÀû: " << getX() * getY() << endl;
	}
	~Rectangle() {}
};
class Sqaure : public Rectangle {
public :
	Sqaure(int a) : Rectangle(a, a) {
		cout << "Square(int a) Constructor called " << endl; 
	}
	~Sqaure() {}
};

int main() {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Sqaure sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}