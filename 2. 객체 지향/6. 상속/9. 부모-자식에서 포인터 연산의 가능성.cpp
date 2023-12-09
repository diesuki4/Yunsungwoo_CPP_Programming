#include <iostream>

using namespace std;

// 컴파일러는 포인터 연산의 가능성을 판단할 때
// 실제 객체가 아닌, 포인터의 자료형으로 판단한다.

class Base
{
public:
    void BaseFunc() { cout << "BaseFunc()" << endl; }
};

class Derived : public Base
{
public:
    void DerivedFunc() { cout << "DerivedFunc" << endl; }
};

int main(int argc, char* argv[])
{
    // 부모 포인터는 자식 객체를 가리킬 수 있다.
    Base* pBase = new Derived();
    // 부모에 있는 모든 멤버는 자식에 있기 때문
    Derived* pDerived = new Derived();
    pBase = pDerived;

    // 단, 자식의 멤버에 접근할 수는 없다.
    // pBase->DerivedFunc();

    // 자식의 포인터는 부모 객체를 가리킬 수 없다.
    // 자식에 있는 것 중에 부모에는 없는 것도 있기 때문
    // pDerived = new Base();
    // pDerived = pBase;

    return 0;
}
