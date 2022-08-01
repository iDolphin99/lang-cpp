#include <iostream>
using namespace std;

class Gun {
private :
	int bullet;
public :
	Gun(int bnum) : 
		bullet(bnum) {}
	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police {
private :
	int handcuffs;
	Gun* pistol; 
public :
	Police(int bnum, int bcuff) : handcuffs(bcuff) {
		if (bnum) pistol = new Gun(bnum);
		else pistol = NULL;
	}
	Police(const Police& ref) {			  // copy constructor 
		cout << "called Copy Constructor!" << endl;

		handcuffs = ref.handcuffs;
		if (ref.pistol) pistol = new Gun(*(ref.pistol));
		else pistol = NULL;
	}
	Police& operator=(const Police &ref) { // assignment operator 
		cout << "called Assignment Operator!" << endl;

		if (pistol) delete pistol;

		if (ref.pistol) pistol = new Gun(*(ref.pistol));
		else pistol = NULL;
		
		handcuffs = ref.handcuffs;
		return *this;
	}
	void PutHandcuff() {
		cout << "SNAP!" << endl; 
		handcuffs--;
	}
	void Shot() {
		if (!pistol) cout << "HUT BBANG!" << endl;
		else pistol->Shot();
	}
	~Police() {
		if (pistol) delete pistol;
	}
};

int main() {
	Police pol1(10, 20);
	Police pol2(20, 40);

	// test for copy constructor 
	Police pol3 = pol1;
	
	// test for assignment operator 
	pol2 = pol1;

	return 0; 
}