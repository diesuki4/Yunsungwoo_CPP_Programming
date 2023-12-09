#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int num = 0;

    cin >> num;

    try
    {
        if (num == 0)
            throw 0();
        else if (num == 1)
            throw '1';
        else if (num == 2)
            throw string("2");
    }
    catch (int expt)
    {
        cout << "예외 " << expt << endl;
    }
    // 보통 모든 catch 블록의 마지막에 온다.
    // 모든 예외를 받을 수 있지만
    catch (...)
    {
        cout << "예외가 발생했으나, 어떤 예외인지는 알 수 없다." << endl;
    }

    return 0;
}
