#include <stdio.h>
#include <iostream>
using namespace std;

class Car {
private:
	int gasolineGauge;
public:
	Car() : gasolineGauge(20)
	{}
	int GetGasGauge() { return gasolineGauge; }
	~Car() {
		cout << "~Car() " << endl;
	}
};

class HybridCar : public Car {
private :
	int electricGauge;
public :
	HybridCar() : Car(), electricGauge(30) 
	{}
	int GetElecGauge() { return electricGauge; }
	~HybridCar() {
		cout << "~HybridCar() " << endl;
	}
};

class HybridWaterCar : public HybridCar {
private:
	int waterGauge;
public:
	HybridWaterCar() : HybridCar(), waterGauge(40)
	{}
	void ShowCurrentGauge() {
		cout << "ÀÜ¿© °¡¼Ö¸°: " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·®: " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·®: " << waterGauge << endl;
	}
	~HybridWaterCar() {
		cout << "~HybridWaterCar() " << endl;
	}
};
int main() {
	HybridWaterCar hwc;
	hwc.ShowCurrentGauge();
	return 0;
}