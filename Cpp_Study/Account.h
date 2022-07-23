/*
Ver 0.7
- file division 
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	char* name;
	int ID;
	int balance;
public:
	Account(const char* n, int id, int b);
	Account(const Account& ref);

	int GetAccID();
	int GetBalance();
	void Withdraw(int money);
	virtual void Deposit(int money);
	void ShowAccInfo() const;
	~Account();
};

#endif