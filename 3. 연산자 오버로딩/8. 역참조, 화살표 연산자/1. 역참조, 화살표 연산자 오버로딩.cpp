#include <iostream>

using namespace std;

class Number
{
    int num;

public:
    Number(int n) : num(n) { cout << "[생성자] num = " << num << endl; }

    Number& operator= (const Number& rhs) { num = rhs.num; cout << "[대입 연산자]" << endl; return *this; }

    void Show() { cout << num << endl; }

    // -> 연산자는 포인터 이외
    // 다른 자료형으로 반환하는 것은 적절치 않다.
    Number* operator-> () { return this; }
    Number& operator* ()  { return *this; }
};

int main(int argc, char* argv[])
{
    Number num(20);
    num.Show();

    // 대입 연산자가 호출된다.
    // 30이 Number(30) 임시 객체로 생성 가능하기 때문이다.
    //
    // 하지만 결과적으로,
    // private 인 Number::num 의 값을 변경하게 되므로
    // 이런 구현은 좋지 않다.
    // 
    // (Number&) *num = Number(30);
    *num = 30;

    (*num).Show();

    // -> 연산자의 반환형은 포인터이므로
    // 실제로는 다음과 같이 동작한다.
    //
    // (num->)->Show();
    num->Show();

    return 0;
}
