#include <iostream>

using namespace std;

// 엔티티 클래스
//
// 데이터적 성격이 강한 클래스
class PermanentWorker
{
    string name;
    int salary;

public:
    PermanentWorker(string name, int salary) : name(name), salary(salary) { }

    int GetPay() const { return salary; }
    void ShowSalaryInfo() const { cout << "Name: " << name << ", Salary: " << salary << endl; }
};

// 컨트롤(핸들러) 클래스
//
// 기능의 처리를 실제로 담당하는 클래스
// 객체 지향의 핵심이 된다.
class EmployeeHandler
{
    PermanentWorker* empList[50];
    int numWorker;

public:
    EmployeeHandler() : numWorker(0) { }

    void AddEmployee(PermanentWorker* emp)
    {
        empList[numWorker++] = emp;
    }

    void ShowAllSalaryInfo() const
    {
        for (int i = 0; i < numWorker; ++i)
            empList[i]->ShowSalaryInfo();
    }

    void ShowTotalSalary() const
    {
        int sum = 0;

        for (int i = 0; i < numWorker; ++i)
            sum += empList[i]->GetPay();

        cout << "Total salary: " << sum << endl;
    }

    ~EmployeeHandler()
    {
        for (int i = 0; i < numWorker; ++i)
            delete empList[i];
    }
};

int main(int argc, char* argv[])
{
    EmployeeHandler handler;

    // 좋은 객체지향이란,
    // 
    // 요구사항의 변경에 유연하게 대응할 수 있어야 한다.
    // 코드 수정을 최소화하면서, 기능을 쉽게 확장할 수 있어야 한다.

    // 이는 좋은 설계가 아니다.
    // 
    // 고용 형태가 다양해지면,
    // Worker 클래스를 추가로 만들어야 한다.
    // EmployeeHandler에 각 Worker 마다 추가로 배열과 함수를 만들어야 한다.
    handler.AddEmployee(new PermanentWorker("KIM", 1000));
    handler.AddEmployee(new PermanentWorker("LEE", 1500));
    handler.AddEmployee(new PermanentWorker("PARK", 2000));

    handler.ShowAllSalaryInfo();
    handler.ShowTotalSalary();

    return 0;
}
