#include <iostream>
#include <cstring>
using namespace std;

namespace RISK_LEVEL {
	enum {RISK_A=30, RISK_B=20, RISK_C=10};
}

class Employee {
private : 
	char name[100];
public :
	Employee(const char* eName) {
		strcpy_s(name, strlen(eName)+1, eName);
	}
	void ShowYourName() const {
		cout << "Name: " << name << endl;
	}
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class TemporaryWorker : public Employee {
private :
	int workTime;
	int payPerHour;
public :
	TemporaryWorker(const char* tName, int tTime, int tPay) :
		Employee(tName), workTime(tTime), payPerHour(tPay) {};
	void AddWorkTime(int time) { workTime += time; }
	int GetPay() const { return workTime * payPerHour; }
	virtual void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << GetPay() << endl;
	}
};

class PermanentWorker : public Employee {
private : 
	int salary;
public :
	PermanentWorker(const char* pName, int pSalary) : 
		Employee(pName), salary(pSalary) {};
	int GetPay() const { return salary; }
	virtual void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << GetPay() << endl;
	}
};

class SalesWorker : public PermanentWorker {
private :
	int salesResult;
	double bonusRatio;
public :
	SalesWorker(const char* sName, int salary, int ratio) :
		PermanentWorker(sName, salary), salesResult(0), bonusRatio(ratio) {};
	void AddSalesResult(int value) { salesResult += value; }
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	virtual void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << GetPay() << endl;
	}
};

class ForeignSalesWorker : public SalesWorker {
private :
	const int riskRank;
public :
	ForeignSalesWorker(const char* fName, int salary, int ratio, int rank) :
		SalesWorker(fName, salary, ratio), riskRank(rank) {}
	int GetPay() const { return SalesWorker::GetPay() + GetRiskPay(); }
	int GetRiskPay() const { return SalesWorker::GetPay() * (riskRank / 100.0); }
	virtual void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << SalesWorker::GetPay() << endl;
		cout << "Risk Pay: " << GetRiskPay() << endl;
		cout << "Total Salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler {
private : 
	Employee* empList[50];
	int empNum;
public :
	EmployeeHandler() : empNum(0) {};
	void addEmployee(Employee *emp) {
		empList[empNum] = emp;
		empNum++;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary() const {

	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main() {
	EmployeeHandler handler;

	// Add Foreign Sales Worker 
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.addEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.addEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.addEmployee(fseller3);

	// Information on salaries due this month 
	handler.ShowAllSalaryInfo();
	return 0;
}