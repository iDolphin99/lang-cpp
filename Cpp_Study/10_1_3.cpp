#include <iostream>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :
		xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	friend bool operator==(const Point& ref1, const Point& ref2);
	friend bool operator!=(const Point& ref1, const Point& ref2);
};

bool operator==(const Point& ref1, const Point& ref2) {
	return ref1.xpos == ref2.xpos && ref1.ypos == ref2.ypos ? true : false;
}
bool operator!=(const Point& ref1, const Point& ref2) {
	return !(ref1 == ref2); // First == overloading, and then express != operator using == operator
	//return ref1.xpos != ref2.xpos && ref1.ypos != ref2.ypos ? true : false;
}

int main() {
	Point pos1(3, 4);
	Point pos2(10, 20);

	pos1.ShowPosition();
	pos2.ShowPosition();

	cout << "pos1==pos2" << endl;
	if (pos1 == pos2) cout << "[True]" << endl;
	else cout << "[False]" << endl;

	cout << "pos1!=pos2" << endl;
	if (pos1 != pos2) cout << "[True]" << endl;
	else cout << "[False]" << endl;


	return 0;
}