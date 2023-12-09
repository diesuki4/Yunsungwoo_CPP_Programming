#include <iostream>

using namespace std;

class First
{
public:
    virtual void Func() { cout << "FirstFunc" << endl; }
};

class Second : public First
{
public:
    // 부모 함수가 virtual 로 선언되어 있다면
    // 자식도 자동으로 가상 함수가 되므로,
    // virtual 키워드를 생략할 수 있다.
    void Func() { cout << "SecondFunc" << endl; }
};

class Third : public Second
{
public:
    virtual void Func() { cout << "ThirdFunc" << endl; }
};

int main(int argc, char* argv[])
{
    Third* pThird = new Third();
    Second* pSecond = pThird;
    First* pFirst = pSecond;

    // 부모 함수를 가상 함수로 만들면,
    // 포인터의 타입에 관계 없이
    // 
    // 실제 객체 기준 <가장 마지막으로 오버라이드한 함수>가 호출된다.
    pFirst->Func();
    pSecond->Func();
    pThird->Func();

    delete pThird;
    pThird = nullptr;

    // ------------------
    pSecond = new Second();
    pFirst = pSecond;

    pFirst->Func();
    pSecond->Func();

    delete pSecond;

    return 0;
}
