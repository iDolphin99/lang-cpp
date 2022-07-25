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
	Point& operator+=(const Point& ref1) {
		this->xpos += ref1.xpos;
		this->ypos += ref1.ypos;
		return *this;
	}
	Point& operator-=(const Point& ref1) {
		this->xpos -= ref1.xpos;
		this->ypos -= ref1.ypos;
		return *this;
	}
};

int main() {
	Point pos1(3, 4);
	Point pos2(10, 20);

	pos1.ShowPosition();
	pos2.ShowPosition();
	
	Point& pos3 = pos2 += pos1;
	pos3.ShowPosition();

	Point& pos4 = pos2 -= pos1;
	pos4.ShowPosition();

	return 0;
}