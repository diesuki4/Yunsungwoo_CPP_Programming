#include <iostream>

using namespace std;

class BoundCheckIntArray
{
    int* arr;
    int arrlen;

    BoundCheckIntArray(const BoundCheckIntArray& rhs) { }
    BoundCheckIntArray& operator= (const BoundCheckIntArray& rhs) { }

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

    int GetArrLen() const { return arrlen; }

    ~BoundCheckIntArray() { delete[] arr; }
};

// const 객체로 선언되어서
// 내부 값을 변경할 수 없다.
void ShowAll(const BoundCheckIntArray& ref)
{
    for (int i = 0; i < ref.GetArrLen(); ++i)
        // operator[]() 는 const 함수가 아니기 때문에
        // 호출할 수 없다.
        // cout << ref[i] << " ";

    cout << endl;
}

int main(int argc, char* argv[])
{
    BoundCheckIntArray bcia(5);

    for (int i = 0; i < bcia.GetArrLen(); ++i)
        bcia[i] = i * 10;

    ShowAll(bcia);

    return 0;
}
