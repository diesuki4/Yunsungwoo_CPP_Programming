#include <iostream>
#include <string>

using namespace std;

int Divide(float dividend, int divisor) throw (string)
{
    try
    {
        if (divisor == 0)
        {
            cout << "First throw" << endl;
            throw 0;
        }
    }
    catch (int expt)
    {
        cout << "First catch" << endl;
        // catch 블록에서 또 예외를 던질 수도 있다.
        throw string("Second throw");
    }
    // 이 catch 블록에서 Second throw 는 잡히지 않는다.
    // 
    // throw 는 Caller 에게 전달될 뿐,
    // 다음 catch 블록으로 전달되는 것은 아니다.
    catch (string expt)
    {
        cout << "Second catch" << endl;
        throw string("Third throw");
    }

    return (dividend / divisor);
}

int main(int argc, char* argv[])
{
    try
    {
        cout << Divide(9, 2) << endl;
        cout << Divide(4, 0) << endl;
    }
    // Second throw 를 잡는다.
    catch (string expt)
    {
        cout << expt << endl;
    }

    return 0;
}
