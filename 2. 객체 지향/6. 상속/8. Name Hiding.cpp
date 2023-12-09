#include <iostream>

using namespace std;

class Base
{
public:
    // 두 함수의 이름은 같으나, 인자가 다르다.
    void Say() { cout << "I'm Base" << endl; }
};

class Derived : public Base
{
public:
    // 두 함수의 이름은 같으나, 인자가 다르다.
    void Say(string input) { cout << input << endl; }
};

int main(int argc, char* argv[])
{
    Derived d;

    // Name Hiding
    // 
    // 자식에서 부모의 함수와 <동일한 이름>의 함수를 재정의할 때
    // 부모의 함수가 가려지는 현상
    // 
    // 인자가 달라도 오버로드되지 않고
    // <이름이 같다면> 가려진다.
    // 
    // d.Say();
    d.Base::Say();

    d.Say("I'm Derived");

    return 0;
}
