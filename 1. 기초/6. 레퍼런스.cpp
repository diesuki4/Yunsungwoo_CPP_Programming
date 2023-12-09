#include <iostream>

using namespace std;

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

    // 불가 (9는 리터럴 상수이므로)
    // MOV DWORD PTR [EBP-4], 9
    // int& ref2 = 9;

    // const는 데이터 영역에 존재하므로 가능
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
    
    return 0;
}
