#include <iostream>

using namespace std;

// 함수 템플릿을 정의한 상태에서
// 일반 함수까지 정의하는 것은
// 
// 바람직한 구현은 아니다.

template <typename T>
T Add(T num1, T num2)
{
    cout << "T Add(T num1, T num2)" << endl;

    return num1 + num2;
}

// 우선순위
// 템플릿 함수 < 일반 함수
int Add(int num1, int num2)
{
    cout << "int Add(int num1, int num2)" << endl;

    return num1 + num2;
}

// 우선순위
// 템플릿 함수 < 일반 함수
double Add(double num1, double num2)
{
    cout << "double Add(double num1, double num2)" << endl;

    return num1 + num2;
}

int main(int argc, char* argv[])
{
    cout << Add<int>(1, 2) << endl;            // Add<int>()
    cout << Add(3, 4) << endl;                // Add()
    cout << Add(3.1, 4.2) << endl;            // Add()
    cout << Add<double>(3.4, 4.3) << endl;    // Add<double>()

    return 0;
}
