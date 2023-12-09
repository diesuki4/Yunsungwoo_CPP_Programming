#include <iostream>

using namespace std;

// 상속은 단순히 코드 재사용 목적으로 쓰는 것이 아니다.
//
// 연관된 클래스들에 대해,
// 부모 클래스를 통해 공통적인 규약을 정할 수 있다.
//
// 그리고 오버라이딩과 가상 함수를 통해,
// 자식의 행동을 유동적으로 변경할 수 있다.

class Employee
{
    string name;

public:
    Employee(string name) : name(name) { }

    void ShowName() const { cout << "Name: " << name << endl; }

    // 부모 함수를 <가상 함수>로 변경했다.
    virtual int GetPay() const { return 0; }
    // 부모 함수를 <가상 함수>로 변경했다.
    virtual void ShowSalary() const { }
};

class PermanentWorker : public Employee
{
    int salary;

public:
    PermanentWorker(string name, int money) : Employee(name), salary(money) { }

    virtual int GetPay() const { return salary; }

    virtual void ShowSalary() const
    {
        ShowName();
        cout << "Salary: " << GetPay() << endl << endl;
    }
};

class TemporaryWorker : public Employee
{
    int workTime;
    int payPerHour;

public:
    TemporaryWorker(string name, int pay) : Employee(name), workTime(0), payPerHour(pay) { }

    void AddWorkTime(int time) { workTime += time; }

    virtual int GetPay() const { return workTime * payPerHour; }

    virtual void ShowSalary() const
    {
        ShowName();
        cout << "Salary: " << GetPay() << endl << endl;
    }
};

class SalesWorker : public PermanentWorker
{
    int salesResult;
    double bonusRatio;

public:
    SalesWorker(string name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) { }

    void AddSalesResult(int value) { salesResult += value; }

    virtual int GetPay() const
    {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }

    virtual void ShowSalary() const
    {
        ShowName();
        cout << "Salary: " << GetPay() << endl << endl;
    }
};

class EmployeeHandler
{
    Employee* empList[50];
    int empNum;

public:
    EmployeeHandler() : empNum(0) { }

    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }

    void ShowAllSalary() const
    {
        // Employee::ShowSalary() 가 가상 함수이므로,
        // 자식 객체 기준 <가장 마지막으로 오버라이드한 함수>가 호출된다.
        for (int i = 0; i < empNum; ++i)
            empList[i]->ShowSalary();
    }

    void ShowTotalSalary() const
    {
        int total = 0;

        // Employee::GetPay() 가 가상 함수이므로,
        // 자식 객체 기준 <가장 마지막으로 오버라이드한 함수>가 호출된다.
        for (int i = 0; i < empNum; ++i)
            total += empList[i]->GetPay();

        cout << "Total salary: " << total << endl;
    }

    ~EmployeeHandler()
    {
        for (int i = 0; i < empNum; ++i)
            delete empList[i];
    }
};

int main(int argc, char* argv[])
{
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("CHOI", 2000));

    TemporaryWorker* alba = new TemporaryWorker("JUNG", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    SalesWorker* seller = new SalesWorker("PARK", 1500, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    handler.ShowAllSalary();
    handler.ShowTotalSalary();

    return 0;
}
