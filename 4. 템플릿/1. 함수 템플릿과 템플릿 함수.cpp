#include <iostream>

using namespace std;

// <함수 템플릿>
//
// 기능을 결정되어 있지만,
// 자료형은 결정되어 있지 않아
//
// 자료형에 따라 함수를 만들어 낼 수 있는 틀
template <typename T>
T Add(T num1, T num2)
{
    return num1 + num2;
}

// <템플릿 함수>
// 
// 컴파일러에 의해
// 총 3개의 <템플릿 함수>가 만들어 진다.
// 
// int Add<int>(int num1, int num2);
// float Add<float>(float num1, float num2);
// double Add<double>(double num1, double num2);

// 컴파일 타임에 컴파일러가 호출문을 보고
// 필요한 자료형의 함수를 만들어 낸다.
// 
// 컴파일 시간이 증가하고,
// 텍스트 영역의 크기가 증가한다는 단점이 있다.

// 템플릿 자료형이 인자에 사용되지 않은
// 함수 템플릿
template <typename T, typename U>
void Show(double num)
{
    cout << (T)num << ", " << (U)num << endl;
}

int main(int argc, char* argv[])
{
    // 타입을 명시하지 않으면,
    // 컴파일러가 인자를 통해 타입을 유추한다.
    cout << Add<int>(1, 2) << endl;            // int
    cout << Add(3, 4) << endl;                // int
    cout << Add(3.1, 4.2) << endl;            // double
    cout << Add<float>(3.4, 4.3) << endl;    // float

    // 인자를 통해 타입을 유추할 수 없는 경우
    // 타입을 명시적으로 적어주어야 한다.
    // Show(3.5);
    Show<int, double>(3.5);
    Show<double, int>(3.5);

    return 0;
}
