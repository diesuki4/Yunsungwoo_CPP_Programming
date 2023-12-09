#include <iostream>

using namespace std;

class Base
{
public:
    virtual void Show() { cout << "Base" << endl; }
};

class Derived : public Base
{
public:
    virtual void Show() override { cout << "Derived" << endl; }
};

/*
 * dynamic_cast 를 레퍼런스에 사용할 때는
 * 꼭 bad_cast 예외를 처리해 주어야 한다.
 */

int main(int argc, char* argv[])
{
    Base baseObj;
    Base& baseRef = baseObj;

    try
    {
        // 레퍼런스에는 nullptr 을 저장할 수 없다.
        Derived& derivedRef = dynamic_cast<Derived&>(baseRef);
    }
    // 따라서, bad_cast 예외가 발생한다.
    catch (bad_cast expt)
    {
        cout << expt.what() << endl;
    }

    return 0;
}
