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

    // const 오버로드 함수는
    // const 객체가 호출한 것이므로
    //
    // 레퍼런스를 반환해서 값 변경을 허용하면 안 된다.
    // int& operator[](int idx) const

    // 반환형에 const 를 붙일 수 있다.
    // const int& operator[](int idx) const

    // 아예 r-value 로 반환할 수도 있다.
    int operator[](int idx) const
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
        cout << ref[i] << " ";

    // 이제 반환 값을 통해
    // 값을 변경할 수 없게 되었다.
    // ref[3] = 5;

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
