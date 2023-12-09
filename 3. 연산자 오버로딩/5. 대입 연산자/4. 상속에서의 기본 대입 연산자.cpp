#include <iostream>

using namespace std;

class Base
{
protected:
    int baseData;

public:
    Base(int baseData) : baseData(baseData) { }

    Base& operator= (const Base& rhs)
    {
        cout << "Base& operator= ()" << endl;

        baseData = rhs.baseData;

        return *this;
    }

    void Show() { cout << "Base: " << baseData << endl; }
};

class Derived : public Base
{
protected:
    int derivedData;

public:
    Derived(int baseData, int derivedData) : Base(baseData), derivedData(derivedData) { }
/*
 *  자식의 기본 대입 연산자는
 *  부모의 대입 연산자까지 자동으로 호출한다.
 * 
    Derived& operator= (const Derived& rhs)
    {
        Base::operator=(rhs);

        derivedData = rhs.derivedData;

        return *this;
    }
*/
    void Show() { cout << "Base: " << baseData << ", Derived: " << derivedData << endl; }
};

int main(int argc, char* argv[])
{
    Derived dest(0, 0), src(1, 2);

    dest = src;
    dest.Show();

    return 0;
}
