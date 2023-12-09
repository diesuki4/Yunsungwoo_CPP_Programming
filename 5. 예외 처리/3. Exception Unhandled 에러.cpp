#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int i;
    char c;
    string s;

    cin >> i >> c >> s;

    // 하나의 try 블록에
    try
    {
        if (i == 0)
            throw i;
        else if (c == '0')
            throw c;
        else if (s == "0")
            throw s;

        cout << i << " " << c << " " << s << endl;
    }
    // 다른 자료형을 받는
    // 다수의 catch 블록을 구성할 수 있다.
    catch (int expt)
    {
        cout << "i == " << expt << endl;
    }
    catch (char expt)
    {
        cout << "c == " << expt << endl;
    }
/*
 * 자료형에 맞는 catch 문이 없더라도
 * 예외는 전달된다.
 * 
 * 단, 이때
 * Exception Unhandled 에러가 발생한다.
 * 
    catch (string expt)
    {
        cout << "s == " << expt << endl;
    }
 */

    return 0;
}
