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
	Account(const char* n, int id, int b) : ID(id), balance(b)	   // default constructor 
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
	}
	Account(const Account& ref) : ID(ref.ID), balance(ref.balance) // copy constructor 
	{
		name = new char[strlen(ref.name) + 1];
		strcpy_s(name, strlen(ref.name) + 1, ref.name);
	}
	int GetAccID() { return ID; }
	int GetBalance() { return balance; }
	void Withdraw(int money)
	{
		if (balance < money)
			cout << "잔액부족";
		else {
			balance -= money;
			cout << "출금 완료";
		}
	}
	virtual void Deposit(int money) { balance += money; }
	virtual void ShowAccInfo() const
	{
		cout << "계좌ID: " << ID << "\n";
		cout << "이  름: " << name << "\n";
		cout << "입금액: " << balance << "\n";
	}
	virtual ~Account()
	{
		delete this->name;
		cout << "called Account destructor!" << "\n";
	}
};

class NormalAccount : public Account {
private :
	int rate;
public :
	NormalAccount(const char* n, int id, int b, int r) :
		Account(n, id, b), rate(r) {}
	virtual void Deposit(int money) {
		Account::Deposit(money);
		Account::Deposit(money * (rate / 100.0));
	}
	virtual void ShowAccInfo() const {
		Account::ShowAccInfo();
		cout << "기본이율: " << rate << "\n";
	}
	virtual ~NormalAccount() {
		cout << "called NormalAccount destructor!" << "\n";
	}
};

class HighCreditAccount : public NormalAccount {
private :
	int rank;
public :
	HighCreditAccount(const char* n, int id, int b, int rate, int rank) :
		NormalAccount(n, id, b, rate), rank(rank) {}
	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);
		switch (rank) {
		case 1: NormalAccount::Deposit(money * (0.07)); break;
		case 2: NormalAccount::Deposit(money * (0.04)); break;
		case 3: NormalAccount::Deposit(money * (0.02)); break;
		}
	}
	virtual void ShowAccInfo() const {
		NormalAccount::ShowAccInfo();
		cout << "신용등급: " << rank << "\n";;
	}
	virtual ~HighCreditAccount() {
		cout << "called HighCreditAccount destructor!" << "\n";
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
protected : 
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);
};

AccountHandler::AccountHandler() : AccNum(0) {};
AccountHandler::~AccountHandler() {
	for (int i = 0; i < AccNum; i++)  // Noted! not size(pArr)
		delete pArr[i];
}
void AccountHandler::ShowMenu(void) const
{
	cout << "\n\n-----Menu-----\n";
	cout << "1. 계좌개설 \n";
	cout << "2. 입    금 \n";
	cout << "3. 출    금 \n";
	cout << "4. 계좌정보 전체 출력 \n";
	cout << "5. 프로그램 종료 \n";
	cout << "선택: ";
}
void AccountHandler::MakeAccount(void) {
	int op;

	cout << "[계좌종류선택] \n";
	cout << "1. 보통예금계좌 2. 신용신뢰계좌 \n";
	cout << "선택: ";
	cin >> op;

	if (op == 1)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}
void AccountHandler::MakeNormalAccount(void) {
	char name[NAME_LEN];
	int ID, balance, rate;

	cout << "[보통예금계좌] \n";
	cout << "계좌ID: ";
	cin >> ID;
	cout << "이  름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	cout << "이자율: ";
	cin >> rate;

	pArr[AccNum] = new NormalAccount(name, ID, balance, rate);
	AccNum++;
}
void AccountHandler::MakeCreditAccount(void) {
	char name[NAME_LEN];
	int ID, balance, rate, rank;

	cout << "[신용신뢰계좌] \n";
	cout << "계좌ID: ";
	cin >> ID;
	cout << "이  름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	cout << "이자율: ";
	cin >> rate;
	cout << "신용등급(1toA, 2toB, 3toC): ";
	cin >> rank;

	pArr[AccNum] = new HighCreditAccount(name, ID, balance, rate, rank);
	AccNum++;
}
void AccountHandler::DepositMoney(void) {
	int keyID, keyBalance;

	cout << "[입   금] \n";
	cout << "계좌ID: ";
	cin >> keyID;
	cout << "입금액: ";
	cin >> keyBalance;

	for (int i = 0; i < AccNum; i++) {
		if (pArr[i]->GetAccID() == keyID) {
			(pArr[i]->Deposit(keyBalance));
			cout << "입금완료\n";
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다.\n";
}
void AccountHandler::WithdrawMoney(void) {
	int keyID, keyBalance;

	cout << "[출   금] \n";
	cout << "계좌ID: ";
	cin >> keyID;
	cout << "출금액: ";
	cin >> keyBalance;

	for (int i = 0; i < AccNum; i++) {
		if (pArr[i]->GetAccID() == keyID) {
			pArr[i]->Withdraw(keyBalance);
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다.";
}
void AccountHandler::ShowAllAccInfo() const {
	for (int i = 0; i < AccNum; i++) {
		pArr[i]->ShowAccInfo();
		cout << "\n";
	}
}


int main(void) {
	AccountHandler manager;
	int op;

	while (true) {
		manager.ShowMenu();
		cin >> op;
		cout << "\n\n";
		switch (op) {
		case 1: manager.MakeAccount();		break;
		case 2: manager.DepositMoney();		break;
		case 3: manager.WithdrawMoney();	break;
		case 4: manager.ShowAllAccInfo();   break;
		case 5: return 0;				    break;
		default: cout << "Illegal selection.. \n\n"; break;
		}
	}

	return 0;
}