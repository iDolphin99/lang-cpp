/*
Banking System Ver 0.4
* add const keyword 
* declare all member functions that can be editted as const
*/

#include <iostream>
#include <cstring>

using namespace std;
const int MAX_ACCNUM = 100;
const int NAME_LEN = 20;

class Account {
private:
	char* name;
	int ID;
	int balance = 0;
public:
	Account(const char* n, int id, int b) : ID(id), balance(b)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	Account(const Account& ref) : ID(ref.ID), balance(ref.balance)
	{
		name = new char[strlen(ref.name) + 1];
		strcpy_s(name, strlen(ref.name) + 1, ref.name);
	}
	int GetAccID() const { return ID; }
	void Deposit(int b)
	{
		balance += b;
	}
	void Withdraw(int b)
	{
		if (balance < b)
			cout << "잔액부족 \n\n\n";
		else {
			balance -= b;
			cout << "출금 완료 \n\n";
		}
	}
	void ShowAccInfo() const
	{
		cout << "계좌ID: " << ID << "\n";
		cout << "이  름: " << name << "\n";
		cout << "입금액: " << balance << "\n\n";
	}
	~Account()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
};

void MakeAccount();
void Deposit();
void Withdraw();
void ShowAllAccInfo();

int AccNum = 0;
Account* pArr[MAX_ACCNUM];

int main(void) {
	int op;

	while (true) {
		cout << "-----Menu-----\n";
		cout << "1. 계좌개설 \n";
		cout << "2. 입    금 \n";
		cout << "3. 출    금 \n";
		cout << "4. 계좌정보 전체 출력 \n";
		cout << "5. 프로그램 종료 \n";
		cout << "선택: ";
		cin >> op;

		switch (op) {
		case 1: MakeAccount();			break;
		case 2: Deposit();				break;
		case 3: Withdraw();				break;
		case 4: ShowAllAccInfo();		break;
		case 5: return 0;				break;
		default: cout << "Illegal selection.. \n\n"; break;
		}
	}

	free(pArr);

	return 0;
}

void MakeAccount() {
	char name[NAME_LEN];
	int ID, balance;

	cout << "\n\n[계좌개설] \n";
	cout << "계좌ID: ";
	cin >> ID;
	cout << "이  름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	cout << "\n\n";

	pArr[AccNum] = new Account(name, ID, balance);
	AccNum += 1;
}
void Deposit() {
	int keyID, keyBalance;

	cout << "\n\n[입   금] \n";
	cout << "계좌ID: ";
	cin >> keyID;
	cout << "입금액: ";
	cin >> keyBalance;

	for (int i = 0; i < AccNum; i++) {
		if (pArr[i]->GetAccID() == keyID) {
			(pArr[i]->Deposit(keyBalance));
			cout << "입금완료 \n\n\n";
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다. \n\n\n";
}
void Withdraw() {
	int keyID, keyBalance;

	cout << "\n\n[출   금] \n";
	cout << "계좌ID: ";
	cin >> keyID;
	cout << "입금액: ";
	cin >> keyBalance;

	for (int i = 0; i < AccNum; i++) {
		if (pArr[i]->GetAccID() == keyID) {
			pArr[i]->Withdraw(keyBalance);
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다. \n\n\n";
}
void ShowAllAccInfo() {
	cout << "\n\n";

	for (int i = 0; i < AccNum; i++)
		pArr[i]->ShowAccInfo();

	cout << "\n";
}