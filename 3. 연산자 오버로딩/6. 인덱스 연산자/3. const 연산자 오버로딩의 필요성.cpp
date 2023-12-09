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

    // 반환형이 레퍼런스임을 유심히 보자.
    int& operator[](int idx) const
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
        // operator[]() const 함수가 오버로드 되었기 때문에
        // 호출할 수 있다.
        cout << ref[i] << " ";

    // 하지만, const 객체임에도
    // 내부 값 변경이 가능하게 돼버렸다.
    ref[3] = 5;

    cout << endl;
}

int main(int argc, char* argv[])
{
    BoundCheckIntArray bcia(5);

    for (int i = 0; i < bcia.GetArrLen(); ++i)
        bcia[i] = i * 10;

    ShowAll(bcia);
    ShowAll(bcia);

    return 0;
}
