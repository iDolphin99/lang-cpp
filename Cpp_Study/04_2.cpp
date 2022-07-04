#include <iostream>
using namespace std;

// Ring, Circle, Point class는 모두 자신의 정보를 출력하기 위한 함수를 
// 멤버에 포함시켜서 Encapsulation를 완성시킴 

class Point
{
private :
	int xpos, ypos;
public :
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

class Circle
{
private :
	int radius;
	Point center;
public :
	void Init(int x, int y, int r) {
		center.Init(x, y);
		radius = r;
	}
	void ShowCircleInfo() const {
		cout << "radius: " << radius  << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private :
	Circle in, out;
public :
	void Init(int x1, int y1, int r1, int x2, int y2, int r2)
	{
		in.Init(x1, y1, r1);
		out.Init(x2, y2, r2);
	}
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
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}