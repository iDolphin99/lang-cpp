#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

typedef struct _account {
	char name[NAME_LEN];
	int ID, balance = 0;
}ACCOUNT;

int MakeAccount(int count, ACCOUNT* pArr);
void Deposit(int count, ACCOUNT* pArr);
void Withdraw(int count, ACCOUNT* pArr);
void ShowAllAccInfo(int count, ACCOUNT* pArr);

int main(void) {
	int op, count = 0;
	ACCOUNT account[20];
	ACCOUNT* pArr = account;

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
		case 1: count = MakeAccount(count, pArr);	break;
		case 2: Deposit(count, pArr);				break;
		case 3: Withdraw(count, pArr);				break;
		case 4: ShowAllAccInfo(count, pArr);		break;
		case 5: return 0; break;
		default: cout << "Illegal selection.. \n\n"; break;
		}
	}

	free(pArr);

	return 0;
}

int MakeAccount(int count, ACCOUNT* pArr) {
	cout << "\n\n[계좌개설] \n";
	cout << "계좌ID: ";
	cin >> (pArr + count)->ID;
	cout << "이  름: ";
	cin >> (pArr + count)->name;
	cout << "입금액: ";
	cin >> (pArr + count)->balance;
	cout << "\n\n";

	return count + 1;
}
void Deposit(int count, ACCOUNT* pArr) {
	int keyID, keyBalance;

	cout << "\n\n[입   금] \n";
	cout << "계좌ID: ";
	cin >> keyID;
	cout << "입금액: ";
	cin >> keyBalance;

	for (int i = 0; i < count; i++) {
		if (((pArr + i)->ID) == keyID) {
			((pArr + i)->balance) += keyBalance;
			cout << "입금완료 \n\n\n";
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다. \n\n\n";
}
void Withdraw(int count, ACCOUNT* pArr) {
	int keyID, keyBalance;

	cout << "\n\n[출   금] \n";
	cout << "계좌ID: ";
	cin >> keyID;
	cout << "입금액: ";
	cin >> keyBalance;

	for (int i = 0; i < count; i++) {
		if (((pArr + i)->ID) == keyID) {
			if (((pArr + i)->balance) < 0) {
				cout << "잔액부족 \n\n\n";
				return;}
			((pArr + i)->balance) -= keyBalance;
			cout << "출금완료 \n\n\n";
			return;
		}
	}

	cout << "유효하지 않은 ID 입니다. \n\n\n";
}
void ShowAllAccInfo(int count, ACCOUNT* pArr) {
	cout << "\n\n";
	
	for (int i = 0; i < count; i++) {
		cout << "계좌ID: " << (pArr + i) -> ID << "\n";
		cout << "이  름: " << (pArr + i)->name << "\n";
		cout << "입금액: " << (pArr + i)->balance<< "\n\n";
	}
	
	cout << "\n";
}