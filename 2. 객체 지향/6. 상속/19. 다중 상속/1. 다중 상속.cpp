#include <iostream>

using namespace std;

class Base1
{
public:
    void Func() { cout << "Base1" << endl; }
};

class Base2
{
public:
    void Func() { cout << "Base2" << endl; }
};

// 다중 상속은 가능하면
// 사용하지 않는 것이 좋다.
class MultiDerived : public Base1, protected Base2
{
public:
    void ComplexFunc()
    {
        // 모호하므로 사용 불가
        // Func();
        Base1::Func();
        Base2::Func();
    }
};

int main(int argc, char* argv[])
{
    MultiDerived mtDerived;

    // 모호하므로 사용 불가
    // mtDerived.Func();
    mtDerived.Base1::Func();

    return 0;
}
