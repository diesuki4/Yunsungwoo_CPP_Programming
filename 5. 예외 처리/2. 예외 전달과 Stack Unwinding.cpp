#include <iostream>

using namespace std;

int Divide1(float dividend, int divisor);
int Divide2(float dividend, int divisor);
int Divide3(float dividend, int divisor);

// Stack Unwinding (스택 풀기)
// 
// 예외가 발생하면 그 아래는 실행되지 않고
// 함수를 완전히 빠져나오게 된다.

// 처리되지 않은 예외는
// Caller 인 main 에게 전달된다.
int Divide1(float dividend, int divisor)
{
    cout << "Divide1()" << endl;

    int result = Divide2(dividend, divisor);

    // 예외면 이하 실행 X

    return result;
}

// 처리되지 않은 예외는
// Caller 인 Divide1 에게 전달된다.
int Divide2(float dividend, int divisor)
{
    cout << "Divide2()" << endl;

    int result = Divide3(dividend, divisor);

    // 예외면 이하 실행 X

    return result;
}

// 처리되지 않은 예외는
// Caller 인 Divide2 에게 전달된다.
int Divide3(float dividend, int divisor)
{
    cout << "Divide3()" << endl;

    if (divisor == 0)
        throw divisor;

    // 예외면 이하 실행 X

    return (dividend / divisor);
}

int main(int argc, char* argv[])
{
    int dividend, divisor;

    cin >> dividend >> divisor;

    try
    {
        // 함수 내에서 처리되지 않은
        // 예외가 전달되면
        int result = Divide1(dividend, divisor);

        // 예외면 이하 실행 X

        cout << result << endl;
    }
    // 예외가 처리될 때까지
    // Caller 에게 전달한다.
    catch (int expt)
    {
        cout << expt << "으로 나눌 수 없습니다." << endl;
    }

    return 0;
}
