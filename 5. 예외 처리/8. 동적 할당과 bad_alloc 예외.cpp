#include <iostream>
// bad_alloc 예외 클래스가 정의되어 있다.
#include <new>

using namespace std;

int main(int argc, char* argv[])
{
    int num = 0;

    try
    {
        while (true)
        {
            cout << ++num << "번째 할당" << endl;
            new int[10000][10000];
        }
    }
    // 동적 할당이 불가능하면
    // bad_alloc 예외가 전달된다.
    catch (bad_alloc& bad)
    {
        cout << "[" << bad.what() << "] 더 이상 할당 불가!" << endl;
    }

    return 0;
}
