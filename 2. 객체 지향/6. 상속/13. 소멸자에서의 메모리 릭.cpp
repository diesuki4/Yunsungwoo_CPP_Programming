#include <iostream>

using namespace std;

// 가상 소멸자를 사용하지 않으면
// 메모리 릭이 발생할 수 있다.

// 아래는 가상 소멸자를 사용하지 않은 예이다.
class First
{
protected:
    string name;
    int* data1;

public:
    First(string name) : name(name), data1(new int) { }
    ~First() { cout << name << " ~First()" << endl << endl; delete data1; }
};

class Second : public First
{
protected:
    int* data2;

public:
    Second(string name) : First(name), data2(new int) { }
    ~Second() { cout << name << " ~Second()" << endl; delete data2; }
};

class Third : public Second
{
protected:
    int* data3;

public:
    Third(string name) : Second(name), data3(new int) { }
    ~Third() { cout << name << " ~Third()" << endl; delete data3; }
};

int main(int argc, char* argv[])
{
    // 값 타입에서는 정상적으로
    // 모든 소멸자가 호출된다.
    Second sec("sec");

    // 포인터 타입과 실제 객체가 일치할 때도
    // 메모리 릭이 발생하지 않는다.
    Third* pThird = new Third("pThird");
    delete pThird;

    // 부모의 포인터가 자식 객체를 가리킬 때
    // 메모리 릭이 발생한다.
    //
    // 실제 객체는 Second 이지만
    // First 의 소멸자만 호출된다.
    First* pFirst = new Second("pFirst");
    delete pFirst;
    //
    // 실제 객체는 Third 이지만
    // First, Second 의 소멸자만 호출된다.
    Second* pSecond = new Third("pSecond");
    delete pSecond;

    return 0;
}
