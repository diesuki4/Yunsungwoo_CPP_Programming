#include <iostream>

using namespace std;

int Func(char n1)
{
    return n1;
}
/* 반환형의 const 는 오버로드 조건이 아니다.
const int Func(char n1)
{
    return n1;
}
*/
int Func(int n1)
{
    return n1;
}

int Func(int n1, int n2)
{
    return n1 + n2;
}

// 반환형이 다르면 오버로드 할 수 없다.
// float Func(int n1) { return n1; }

class AAA
{
    int val = 0;

public:
    // const 도 오버로드 조건에 해당한다.
    void Show()       { cout << "AAA::Show()" << endl; }
    void Show() const { cout << "AAA::Show() const" << endl; }
};

int main(int argc, char* argv[])
{
    cout << Func('A') << endl;
    cout << Func(65) << endl;
    cout << Func(70, 80) << endl;

    // 일반 Show() 함수가 호출된다.
    AAA aaa;
    aaa.Show();

    // const 객체는 const 멤버 함수만 호출 가능하므로
    // const 함수가 오버로드 된다.
    const AAA constAAA;
    constAAA.Show();

    return 0;
}
