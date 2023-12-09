#include <iostream>

using namespace std;

// Call by Value
void Func(int val)
{
    val = -1;
}

// Call by Address
void Func(int *pVal)
{
    *pVal = 2;
}

// Call by Reference
// 값과 모호하므로 오버로드 불가
// void Func(int& refVal) { refVal = 3; }

int main(int argc, char* argv[])
{
    int val = 0;

    Func(val);
    cout << val << endl;

    Func(&val);
    cout << val << endl;

    return 0;
}
