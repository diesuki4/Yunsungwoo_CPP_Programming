#include <iostream>

using namespace std;

class Base
{
protected:
    int* pBaseData;

public:
    Base(int baseData) : pBaseData(new int(baseData)) { }

    Base& operator= (const Base& rhs)
    {
        cout << "Base& operator= ()" << endl;

        delete pBaseData;

        pBaseData = new int(*rhs.pBaseData);

        return *this;
    }

    void Show() { cout << "Base: " << *pBaseData << endl; }

    virtual ~Base() { delete pBaseData; }
};

class Derived : public Base
{
protected:
    int* pDerivedData;

public:
    Derived(int baseData, int derivedData) : Base(baseData), pDerivedData(new int(derivedData)) { }

    // 자식의 대입 연산자에서는
    Derived& operator= (const Derived& rhs)
    {
        cout << "Derived& operator= ()" << endl;

        // 부모의 대입 연산자를
        // 명시적으로 호출해 주어야 한다.
        Base::operator=(rhs);

        delete pDerivedData;

        pDerivedData = new int(*rhs.pDerivedData);

        return *this;
    }

    void Show() { cout << "Base: " << *pBaseData << ", Derived: " << *pDerivedData << endl; }

    virtual ~Derived() { delete pDerivedData; }
};

int main(int argc, char* argv[])
{
    Derived dest(0, 0), src(1, 2);

    dest = src;
    dest.Show();

    return 0;
}
