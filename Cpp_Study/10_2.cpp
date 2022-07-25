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
	Point operator-() {
		Point pos(-xpos, -ypos);
		return pos;
	}
	friend Point operator~(const Point &ref);
};

Point operator~(const Point &ref) {
	Point pos(ref.ypos, ref.xpos);
	return pos;
}

int main() {

	Point pos1(3, 4);
	pos1.ShowPosition();

	Point pos2 = -pos1;
	pos2.ShowPosition();

	(~pos2).ShowPosition();

	return 0;
}