#include <iostream>

using namespace std;

template <typename T>
class SimpleArray1
{
    int len;
    T* arr;

public:
    // 생성자에서 길이를 받은 경우
    SimpleArray1(int len) : len(len), arr(new int[len]) { }

    T& operator[] (int i) { return arr[i]; }

    SimpleArray1<T>& operator= (const SimpleArray1<T>& rhs)
    {
        for (int i = 0; i < rhs.len; ++i)
            arr[i] = rhs.arr[i];

        return *this;
    }

    int GetLen() const { return len; }

    ~SimpleArray1() { delete [] arr; }
};

// 템플릿 매개변수에는
// 변수 선언이 올 수 있다.
//
// 예) std::array<int, 5>
//
// 사실은 기본값도 정할 수 있다.
template <typename T = int, int len = 7>
class SimpleArray2
{
    // 클래스 템플릿으로 길이를 받은 경우
    T arr[len];

public:
    T& operator[] (int i) { return arr[i]; }

    SimpleArray2<T, len>& operator= (const SimpleArray2<T, len>& rhs)
    {
        for (int i = 0; i < len; ++i)
            arr[i] = rhs.arr[i];

        return *this;
    }

    // 클래스 내에서 변수처럼 사용할 수도 있다.
    int GetLen() const { return len; }
};

template <typename T>
void Fill(T& arr)
{
    for (int i = 0; i < arr.GetLen(); ++i)
        arr[i] = i * 10;
}

template <typename T>
void Show(T& arr)
{
    for (int i = 0; i < arr.GetLen(); ++i)
        cout << arr[i] << " ";

    cout << endl;
}

int main(int argc, char* argv[])
{
    // iarr5와 iarr7은 길이가 다르지만,
    // 같은 SimpleArray1<int> 자료형이다.
    SimpleArray1<int> iarr5(5), iarr7(7);
    Fill(iarr5); Fill(iarr7);
    
    // 7 공간에 5 개를 채운다.
    iarr7 = iarr5;

    // 5 공간에 7개를 채운다.
    // 컴파일은 되지만, 런타임 오류가 발생한다.
    // iarr5 = iarr7;

    // 둘은 같은 자료형이다.
    SimpleArray2<int, 5> i5arr1, i5arr2;
    Fill(i5arr1);

    i5arr2 = i5arr1;
    Show(i5arr2);

    // 템플릿 매개변수에 기본값이 지정되어도
    // <>는 꼭 추가해줘야 한다.
    // SimpleArray2 i7arr1, i7arr2;
    SimpleArray2<> i7arr1, i7arr2;
    Fill(i7arr1);

    i7arr2 = i7arr1;
    Show(i7arr2);

    // 둘은 길이도 다르고, 다른 자료형이므로
    // <대입을 원천적으로 방지할 수 있다.>
    // i5arr1 = i7arr1;

    return 0;
}
