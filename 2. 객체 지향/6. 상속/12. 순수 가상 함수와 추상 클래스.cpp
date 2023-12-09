#include <iostream>

using namespace std;

// <순수 가상 함수>를 사용하면,
// 
// Base 클래스의 객체 생성을 문법적으로 막을 수 있다.
// 자식에서 구현부가 작성되어야 함을 명확히 할 수 있다.

// Employee 클래스처럼 Base 의 의미만 가질 뿐,
// 객체 생성 목적이 아닌 클래스도 있다.
class Employee
{
    string name;

public:
    // 순수 가상 함수가 1개라도 포함된 클래스는 <추상 클래스>로서
    // 불완전한 클래스이기 때문에
    // 
    // 직접 객체를 생성할 수 없다.
    Employee(string name) : name(name) { }

    void ShowName() const { cout << "Name: " << name << endl; }

    // 부모 함수를 <순수 가상 함수>로 변경했다.
    // 몸체가 정의되지 않은 함수이다.
    virtual int GetPay() const = 0;
    // 부모 함수를 <순수 가상 함수>로 변경했다.
    virtual void ShowSalary() const  = 0;
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

    // 순수 가상 함수가 포함된 <추상 클래스>이므로
    // 불완전한 클래스이기 때문에
    // 
    // 직접 객체를 생성할 수 없다.
    // 
    // Employee* emp = new Employee("LEE");

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
