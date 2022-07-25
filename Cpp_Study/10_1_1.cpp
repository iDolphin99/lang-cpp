#include <iostream>
using namespace std;

class Point {
private :
	int xpos, ypos;
public :
	Point(int x = 0, int y = 0) :
		xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	friend Point operator-(const Point& ref1, const Point& ref2);
};

Point operator-(const Point& ref1, const Point& ref2) {
	Point point(ref1.xpos - ref2.xpos, ref1.ypos - ref2.ypos);
	return point;
}

int main() {
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos2 - pos1;

	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();

	return 0;
}