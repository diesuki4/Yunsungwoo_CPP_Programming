#include <iostream>

using namespace std;

/*
 * const_cast
 *
 * 포인터의 const 속성을 제거한다.
 *
 * const 속성이 사라짐으로 인해
 * 값이 변경될 수 있으므로
 * 제한적으로 사용해야 한다.
 *
 * 레퍼런스에도 동일하게 사용 가능하다.
 */

// 인자 전달 시 const 선언으로 인해
// 타입 불일치가 발생할 때 유용하다.
void ShowString(char* str)
{
    cout << str << endl;
}

void ShowAddResult(int& a, int& b)
{
    cout << (a + b) << endl;

    a = 10;
    b = 20;
}

int main(int argc, char* argv[])
{
    const char* str = "const char*";

    // ShowString(str);
    ShowString(const_cast<char*>(str));

    const int& num1 = 100;
    const int& num2 = 200;

    // ShowAddResult(num1, num2);
    ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));
    ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));

    return 0;
}
