/*
Ver 0.7
- file division
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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