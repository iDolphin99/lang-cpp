#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y)
		: xpos(x), ypos(y) {};
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	int radius;
	Point center;
public:
	Circle(int x, int y, int r)
		: center(x, y), radius(r) {};
	void ShowCircleInfo() const {
		cout << "radius: " << radius << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle in, out;
public:
	Ring(int x1, int y1, int r1, int x2, int y2, int r2)
		: in(x1, y1, r1), out(x2, y2, r2) {};
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		in.ShowCircleInfo();
		cout << "Outer Circle Info..." << endl;
		out.ShowCircleInfo();
	}
};

int main(void)
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}