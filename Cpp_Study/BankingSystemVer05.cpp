/*
Banking System Ver 0.3
* add Deep Copy Constructor
* adjust object pointer array (객체 포인터 배열)
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
	int GetAccID() { return ID; }
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
	void ShowAccInfo()
	{
		cout << "계좌ID: " << ID << "\n";
		cout << "이  름: " << name << "\n";
		cout << "입금액: " << balance << "\n\n";
	}
	~Account()
	{
		delete this->name;
		cout << "called destructor!" << endl;
	}
};

class AccountHandler {
private:
	int AccNum;
	Account* pArr[MAX_ACCNUM];
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
};

AccountHandler::AccountHandler() : AccNum(0) {};
AccountHandler::~AccountHandler() {
	for (int i = 0; i < AccNum; i++)  // Noted! not size(pArr)
		delete pArr[i];
}
void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu-----\n";
	cout << "1. 계좌개설 \n";
	cout << "2. 입    금 \n";
	cout << "3. 출    금 \n";
	cout << "4. 계좌정보 전체 출력 \n";
	cout << "5. 프로그램 종료 \n";
	cout << "선택: ";
}
void AccountHandler::MakeAccount(void) {
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
void AccountHandler::DepositMoney(void) {
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
void AccountHandler::WithdrawMoney(void) {
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
void AccountHandler::ShowAllAccInfo() const {
	cout << "\n\n";

	for (int i = 0; i < AccNum; i++)
		pArr[i]->ShowAccInfo();

	cout << "\n";
}


int main(void) {
	AccountHandler manager;
	int op;

	while (true) {
		manager.ShowMenu();
		cin >> op;

		switch (op) {
		case 1: manager.MakeAccount();		break;
		case 2: manager.DepositMoney();		break;
		case 3: manager.WithdrawMoney();	break;
		case 4: manager.ShowAllAccInfo();   break;
		case 5: return 0;				    break;
		default: cout << "Illegal selection.. \n\n"; break;
		}
	}
}