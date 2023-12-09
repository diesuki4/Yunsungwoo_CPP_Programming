#include <iostream>

using namespace std;

template <typename T>
class Point
{
    T x, y;

public:
    // 멤버 이니셜라이저는 외부에 작성한다.
    Point(T x, T y);

    // 클래스 외부에 멤버 함수를 정의할 때
    T Func(const T& ref);
};

// 외부에 정의할 때도 이 구문을 잊지 말아야 한다.
// 컴파일러는 T가 무엇인지 모르기 때문
template <typename T>
// Point<T> 클래스의 생성자
Point<T>::Point(T x, T y) : x(x), y(y)
{
    cout << x << ", " << y << endl;
}

template <typename T>
// Point<T> 클래스의 Func() 함수
T Point<T>::Func(const T& ref)
{
    return ref;
}

int main(int argc, char* argv[])
{
    Point<int> pos1(2.4, 3.6);

    Point<double> pos2(2.4, 3.6);

    Point<char> pos3('P', 'F');

    return 0;
}
