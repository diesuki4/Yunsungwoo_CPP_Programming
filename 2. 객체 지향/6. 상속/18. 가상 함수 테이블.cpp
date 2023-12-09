#include <iostream>

using namespace std;

// 가상 함수가 존재하면, 객체 생성 여부에 관계 없이
// 메모리에 클래스의 VFTable 이 생성된다.
//
// 각 객체별로 자신의 클래스에 해당하는 VFTable 포인터를 갖게 된다.
// 같은 타입의 객체는 동일한 VFTable 을 가리킨다.
//
// 함수의 호출은 VFTable 을 참조해 일어나게 된다.
//
// C 보다 성능상 단점이 있는 이유이다.

class Base
{
public:
    // 가상 함수를 1개라도 갖고 있는 클래스는
    // VFTable 을 갖게 된다.
    virtual void Func1() { cout << "Base::Func1()" << endl; }
    virtual void Func2() { cout << "Base::Func2()" << endl; }

/*
    [0]  void Base:Func1()  0x1024
    [1]  void Base:Func2()  0x2048
*/
};

class Derived : public Base
{
public:
    // 오버라이드 한 부모의 가상 함수는 VFTable 에 존재하지 않는다.
    // 이것이 가상 함수의 호출 원리이다.
    // Base::Func1()
    virtual void Func1() { cout << "Derived::Func1()" << endl; }
    // VFTable 이 존재하면,
    // 가상 함수가 아닌 함수도 VFTable 에 올라가게 된다.
    void Func3()         { cout << "Derived::Func3()" << endl; }
/*
    [0]  void Derived:Func1()  0x3072
    [1]  void Base:Func2()     0x2048
    [2]  void Derived:Func3()  0x4096
*/
};

// 부모의 가상 함수는 자동 상속되므로
// 직접 가상 함수를 정의하지 않더라도
//
// VFTable 을 갖는다.
class Descendant : public Derived
{
/*
    [0]  void Derived:Func1()  0x3072
    [1]  void Base:Func2()     0x2048
    [2]  void Derived:Func3()  0x4096
*/
};

int main(int argc, char* argv[])
{
    Base* pBase = new Derived();
    Derived* pDerived = new Derived();

    pBase->Func1();
    pDerived->Func1();
    pDerived->Func2();
    pDerived->Func3();

    delete pDerived;
    pDerived = new Descendant();

    pDerived->Func3();

    delete pBase;
    pBase = pDerived = nullptr;

    return 0;
}
