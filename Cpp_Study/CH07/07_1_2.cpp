#include <cstring>
#include <iostream>
using namespace std;

class MyFriendInfo {
private :
	char* name;
	int age;
public :
	MyFriendInfo(const char *myName, int myAge) : age(myAge){
		name = new char[strlen(myName) + 1];
		strcpy_s(name, strlen(myName) + 1, myName);
	}
	void ShowMyFriendInfo() {
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
	~MyFriendInfo() {
		delete[] name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private :
	char* addr;
	char* phone;
public :
	MyFriendDetailInfo(const char* myName, int myAge, const char* myAddr, const char* myPhone) 
		: MyFriendInfo(myName, myAge)
	{
		addr = new char[strlen(myAddr) + 1];
		phone = new char[strlen(myPhone) + 1]; 
		strcpy_s(addr, strlen(myAddr) + 1, myAddr);
		strcpy_s(phone, strlen(myPhone) + 1, myPhone);
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl;
	}
	~MyFriendDetailInfo() {
		delete[] addr, phone;
	}
};
int main() {
	MyFriendDetailInfo friend1("이르미", 22, "서울시서울구", "010-1234-5678");
	friend1.ShowMyFriendDetailInfo();
	return 0;
}