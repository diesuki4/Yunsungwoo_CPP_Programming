#include <iostream>

using namespace std;

// 예외의 명시는 참고용일 뿐,
// 컴파일이나 런타임 에러를 발생시키지는 않는다.
void Func1(int num) throw (int, char)
{
    if (num == 0)
        throw 0;
    else if (num == 1)
        throw '1';
    // string 예외에 대한 명시가 없지만,
    // Caller 인 main 에서 처리가 가능하므로
    //
    // 에러가 발생하지는 않는다.
    else if (num == 2)
        throw string("2");
}

// 마찬가지로
// 에러를 발생시키지는 않는다.
void Func2(int num) throw ()
{
    if (num == 3)
        throw 3;
}

int main(int argc, char* argv[])
{
    int num;

    cin >> num;

    try
    {
        Func1(num);
        Func2(num);
    }
    catch (int expt)
    {
        cout << "int " << expt << endl;
    }
    catch (char expt)
    {
        cout << "char '" << expt << "'" << endl;
    }
    // Func() 의 예외에 명시되어 있지 않지만
    // 동작한다.
    catch (string expt)
    {
        cout << "string \"" << expt << "\"" << endl;
    }

    return 0;
}
