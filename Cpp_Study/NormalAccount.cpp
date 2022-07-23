/*
Ver 0.7
- file division
*/

#include "BankingCommonDecl.h"
#include "NormalAccount.h"

class NormalAccount : public Account {
private:
	int rate;
public:
	NormalAccount(const char* n, int id, int b, int r) :
		Account(n, id, b), rate(r) {}
	virtual void Deposit(int money) {
		Account::Deposit(money);
		Account::Deposit(money * (rate / 100.0));
	}
	void ShowAccInfo() const {
		Account::ShowAccInfo();
		cout << "기본이율: " << rate << "\n";
	}
	~NormalAccount() {
		cout << "called NormalAccount destructor!" << "\n";
	}
};