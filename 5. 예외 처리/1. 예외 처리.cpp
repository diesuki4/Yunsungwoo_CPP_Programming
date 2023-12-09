#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int divisor;

    cin >> divisor;

    // 기존 방식으로는
    // 프로그램 로직과 예외 처리 코드를
    // 구분하기 쉽지 않다.
    if (divisor == 0)
        cout << "0으로 나눌 수 없습니다." << endl;
    else
        cout << 100.f / divisor << endl;

    // 가독성과 유지보수성이 높고
    // 프로그램 코드에서 예외 처리 로직을
    // 분리시킬 수 있다.
    try
    {
        // try 영역은 예외가 발생하는 상황만 묶는 것이 아니라,
        // 하나의 작업(work) 단위로 묶어야 한다.
        if (divisor == 0)
            throw divisor;

        // 예외가 발생하면 아래는 실행되지 않고
        // catch 영역으로 넘어가게 된다.
        
        cout << 100.f / divisor << endl;
    }
    catch (int expt)
    {
        cout << expt << "으로 나눌 수 없습니다." << endl;
    }

    return 0;
}
