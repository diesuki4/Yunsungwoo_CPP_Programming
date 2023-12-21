#include <iostream>

using namespace std;

// 레퍼런스도 실제로는 컴파일러에 의헤
// 포인터로 번역되므로,
//
// 역참조 비용이 발생한다.
int Add(const int& ref1, const int& ref2)
{
    return ref1 + ref2;
}

int main(int argc, char* argv[])
{
    const int num = 100;
    // 불가
    // int& ref = num;
    const int& ref = num;

    // 불가 (리터럴 상수는 레퍼런스에 할당 불가)
    // 
    // 만약 이것이 가능하려면 이름 없는 9라는 임시 값에
    // 레퍼런스를 엮어 수정할 수 있어야 하는데,
    // 
    // C++ 는 임시 값, 임시 객체의 수정을 허용하지 않는다.
    // 
    // int& ref2 = 9;

    // 따라서 일반 레퍼런스가 아닌,
    // 값 변경이 불가한 상수 레퍼런스로만 엮을 수 있다.
    const int& ref2 = 30;

    // 가능
    // Add(const int& ref1, const int& ref2)
    cout << Add(3, 4) << endl;

    int* ptr = new int;
    // 변수(l-value)가 되기 위해서는 공간과 이름이 있어야 한다.
    // new로 할당된 공간도 변수(l-value)로 간주한다.
    int& ref3 = *ptr;
    ref3 = 20;

    cout << *ptr << endl;
    delete ptr;
    ptr = nullptr;

    int a = 3, b = 6;
    // 레퍼런스는 초기화만 가능하고, 대입은 불가능하다.
    int& refA = a, & refB = b;

    // a 의 공간에 b 의 값을 복사한 것 뿐이지,
    // refB 가 참조하는 공간을 refA 도 참조하도록 대입한 것이 아니다.
    refA = refB;
    refB = 3;

    cout << refA << " " << refB << endl;

    return 0;
}
