/*
Ver 0.7
- file division
*/

#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	int rank;
public:
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
	void ShowAccInfo() const {
		NormalAccount::ShowAccInfo();
		cout << "신용등급: " << rank << "\n";;
	}
	~HighCreditAccount() {
		cout << "called HighCreditAccount destructor!" << "\n";
	}
};

#endif