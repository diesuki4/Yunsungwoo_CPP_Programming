#include <iostream>

using namespace std;

class First
{
protected:
    string name;
    int* data1;

public:
    First(string name) : name(name), data1(new int) { }
    virtual void Func() const { cout << name << " First::Func()" << endl; }
    virtual ~First() { cout << name << " ~First()" << endl << endl; delete data1; }
};

class Second : public First
{
protected:
    int* data2;

public:
    Second(string name) : First(name), data2(new int) { }
    virtual void Func() const { cout << name << " Second::Func()" << endl; }
    virtual ~Second() { cout << name << " ~Second()" << endl; delete data2; }
};

class Third : public Second
{
protected:
    int* data3;

public:
    Third(string name) : Second(name), data3(new int) { }
    virtual void Func() const { cout << name << " Third::Func()" << endl; }
    virtual ~Third() { cout << name << " ~Third()" << endl; delete data3; }
};

// 이 함수는 First 클래스의
// 자식 레퍼런스까지 받을 수 있다.
void GoodFunction(const First& ref)
{
    cout << "-- GoodFunction() --" << endl;
    ref.Func();
}

int main(int argc, char* argv[])
{
    // 상속에서 적용되는 모든 특징은
    // 레퍼런스 사용 시에도 동일하게 적용된다.

    // 부모의 레퍼런스로 자식 객체를 담을 수 있다.
    First& refFirst = *new Second("refFirst");
    Second& refSecond = *new Third("refSecond");

    // 가상 함수의 특성도 그대로 적용된다.
    refFirst.Func();
    refSecond.Func();
    cout << endl;

    GoodFunction(refFirst);
    GoodFunction(refSecond);
    cout << endl;

    delete &refFirst;
    delete &refSecond;

    return 0;
}
