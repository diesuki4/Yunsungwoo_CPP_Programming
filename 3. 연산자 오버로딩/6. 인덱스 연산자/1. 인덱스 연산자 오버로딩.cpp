#include <iostream>

using namespace std;

class BoundCheckIntArray
{
    int* arr;
    int arrlen;

public:
    BoundCheckIntArray(int len) : arr(new int[len]), arrlen(len) { }

    int& operator[](int idx)
    {
        if (idx < 0 || arrlen <= idx)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }

        return arr[idx];
    }

    ~BoundCheckIntArray() { delete[] arr;  }
};

int main(int argc, char* argv[])
{
    BoundCheckIntArray src(5);

    for (int i = 0; i < 5; ++i)
        cout << (src[i] = i * 10) << " ";

    cout << endl;

    // src 의 arr 주소가 그대로 복사되므로
    // 소멸자에서 둘은 문제가 발생한다.
    BoundCheckIntArray dest1 = src;
    BoundCheckIntArray dest2(5);
    dest2 = dest1;

    for (int i = 0; i < 5; ++i)
        cout << (dest2[i] = i * 20) << " ";

    cout << endl;

    return 0;
}
