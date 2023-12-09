#include <iostream>

using namespace std;

// 개방-폐쇄 원칙
// 기능을 쉽게 확장 가능하면서, 기존 코드의 수정은 최소화해야 한다는 원칙
//
// Is-A 상속을 활용하면 개방-폐쇄 원칙을 지킬 수 있다.

class Employee
{
    string name;

public:
    Employee(string name) : name(name) { }

    void ShowName() const { cout << "Name: " << name << endl; }
};

class PermanentWorker : public Employee
{
    int salary;

public:
    // 부모의 멤버는 부모의 생성자로 초기화하는 것이 옳다.
    PermanentWorker(string name, int money) : Employee(name), salary(money) { }

    int GetPay() const { return salary; }

    void ShowSalary() const
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
    // 부모의 멤버는 부모의 생성자로 초기화하는 것이 옳다.
    TemporaryWorker(string name, int pay) : Employee(name), workTime(0), payPerHour(pay) { }

    void AddWorkTime(int time) { workTime += time; }

    int GetPay() const { return workTime * payPerHour; }

    void ShowSalary() const
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
    // 부모의 멤버는 부모의 생성자로 초기화하는 것이 옳다.
    SalesWorker(string name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) { }

    void AddSalesResult(int value) { salesResult += value; }

    // 부모인 PermanentWorker::GetPay() 오버라이드
    int GetPay() const
    {
        // 부모::함수()
        // 형태로 부모 클래스의 함수를 호출할 수도 있다.
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }

    // 부모인 PermanentWorker::ShowSalary() 오버라이드
    void ShowSalary() const
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

    // Is-A 상속을 잘 활용해
    // 정규직, 영업직, 임시직을 모두 받을 수 있다.
    //
    // 추후에 고용 형태가 추가되더라도
    // 컨트롤 클래스를 변경하지 않아도 된다.
    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }

    // 아직은 함수 오버라이드를 완벽히 적용하기 전이다.
    void ShowAllSalary() const
    {
        // for(int i=0;i<empNum;i++)
        //     empList[i]->ShowSalary();
    }

    // 아직은 함수 오버라이드를 완벽히 적용하기 전이다.
    void ShowTotalSalary() const
    {
        int total = 0;

        // for(int i = 0;i<empNum;i++)
        //     total += empList[i]->GetPay();

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
    // 컨트롤 클래스의 변경 없이
    // 모든 종류의 고용 형태를 다룰 수 있다.
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("CHOI", 2000));

    TemporaryWorker* alba = new TemporaryWorker("JUNG", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);

    SalesWorker* seller = new SalesWorker("PARK", 1500, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);

    // 클래스 외부에서도 다음과 같이 호출할 수 있기는 하다.
    // 하지만, 거의 사용하지 않는다.
    seller->PermanentWorker::ShowSalary();

    handler.ShowAllSalary();
    handler.ShowTotalSalary();

    return 0;
}
