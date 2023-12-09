#include <iostream>

using namespace std;

class AAA
{
public:
    void Show()       { cout << "AAA::Show()" << endl; }
    void Show() const { cout << "AAA::Show() const" << endl; }
};

AAA RetAAA()
{
    // 함수 내에서만 const 로 사용된다.
    const AAA ret;

    // 반환 시에는 임시 객체로 복사가 일어나므로,
    // ret 이 const 인 것과는 상관이 없어진다.
    return ret;
}

// 반환되는 임시 객체를 const 로 지정하겠다는 뜻
const AAA RetAAAConst()
{
    const AAA ret;

    return ret;
}

int main(int argc, char* argv[])
{
    // num 값 변경 불가
    const int num = 10;

    int val = 0;

    // const int 이므로 val 값 변경 불가
    const int* ptr1 = &val;
    // *ptr1 = 3;
    ptr1 = nullptr;

    // const ptr2 이므로 ptr2 값 변경 불가
    int* const ptr2 = &val;
    *ptr2 = 3;
    // ptr2 = nullptr;

    // 둘 다 변경 불가
    const int* const ptr3 = &val;
    // *ptr3 = 3;
    // ptr3 = nullptr;

    const int t = 0;
    // const 변수는 값 변경을 막기 위해서
    // const 레퍼런스만 받을 수 있다.
    // int& ref = t;
    const int& ref = t;

    RetAAA().Show();
    // const 임시 객체이므로
    // const 함수만 호출할 수 있다.
    RetAAAConst().Show();

    return 0;
}
