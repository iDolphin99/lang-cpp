/*
Ver 0.7
- file division
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

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