#include <iostream>

using namespace std;

// 가상 소멸자를 사용하면
// 메모리 릭을 해결할 수 있다.
class First
{
protected:
    string name;
    int* data1;

public:
    First(string name) : name(name), data1(new int) { }
    virtual ~First() { cout << name << " ~First()" << endl << endl; delete data1; }
};

class Second : public First
{
protected:
    int* data2;

public:
    Second(string name) : First(name), data2(new int) { }
    // 부모 함수가 virtual 로 선언되어 있다면
    // 자식도 자동으로 가상 함수가 되므로,
    // virtual 키워드를 생략할 수 있다.
    //
    // 가상 소멸자는 이름이 달라도 오버라이드 된다고 생각하면 쉽다.
    ~Second() { cout << name << " ~Second()" << endl; delete data2; }
};

class Third : public Second
{
protected:
    int* data3;

public:
    Third(string name) : Second(name), data3(new int) { }
    virtual ~Third() { cout << name << " ~Third()" << endl; delete data3; }
};

int main(int argc, char* argv[])
{
    // 부모의 포인터가 자식 객체를 가리킬 때도
    // 메모리 릭이 발생하지 않는다.
    //
    // First 의 포인터에 담긴 실제 객체 Second 이지만
    // First, Second 의 소멸자가 모두 호출된다.
    First* pFirst = new Second("pFirst");
    delete pFirst;
    //
    // Second 의 포인터에 담긴 실제 객체 Third 이지만
    // First, Second, Third 의 소멸자가 모두 호출된다.
    Second* pSecond = new Third("pSecond");
    delete pSecond;

    return 0;
}
