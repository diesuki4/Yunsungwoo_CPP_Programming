#include <iostream>

using namespace std;

class Base
{
    int baseNum;

public:
    // 자식 클래스의 생성자과 호출되면,
    // 따로 정의하지 않을 경우 void 생성자가 호출된다.
    Base() : baseNum(0)
    {
        cout << "Base()" << endl;
    }

    // 자식의 멤버 이니셜라이저에서 생성자를 지정하면
    // 별도의 생성자가 호출된다.
    Base(int base) : baseNum(base)
    {
        cout << "Base(int base)" << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }
};

class Derived : public Base
{
    int derivNum;

public:
    // 부모의 Base() 호출
    Derived() : derivNum(0)
    {
        cout << "Derived()" << endl;
    }

    // 부모의 Base() 호출
    Derived(int deriv) : derivNum(deriv)
    {
        cout << "Derived(int deriv)" << endl;
    }

    // 부모의 Base(int base) 호출
    Derived(int base, int deriv) : Base(base), derivNum(deriv)
    {
        cout << "Derived(int base, int deriv)" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }
};

int main(int argc, char* argv[])
{
    // 부모의 생성자가 먼저 호출된다.
    // 
    // 재귀의 원리와 같다.
    Derived dr1;
    cout << endl;

    Derived dr2(12);
    cout << endl;

    Derived dr3(23, 24);
    cout << endl;

    // 자식의 소멸자가 먼저 호출된다.
    // 
    // 스택의 원리로 부모가 먼저 생성되었으니,
    // 자식이 먼저 소멸해야 한다.

    return 0;
}
