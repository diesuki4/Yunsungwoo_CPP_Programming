#include <iostream>

using namespace std;

template <typename T>
class Point
{
    T x, y;

public:
    Point(T x, T y) : x(x), y(y) { }

    // 특정 템플릿 클래스(Point<int>) 를 인자로 받는
    // 일반 함수에 friend 선언을 할 수 있다.
    friend Point<int> operator+ (const Point<int>&, const Point<int>&);

    // 클래스 템플릿을 인자로 받는
    // 외부의 함수 템플릿에도 friend 선언을 할 수 있다.
    //
    // T 와는 다르게 선언해야 한다.
    template <typename U>
    friend ostream& operator<< (ostream& os, const Point<U>& pos);
};

Point<int> operator+ (const Point<int>& pos1, const Point<int>& pos2)
{
    return Point<int>(pos1.x + pos2.x, pos1.y + pos2.y);
}

template <typename U>
ostream& operator<< (ostream& os, const Point<U>& pos)
{
    os << '[' << pos.x << ", " << pos.y << ']' << endl;

    return os;
}

int main(int argc, char* argv[])
{
    Point<int> pos1(2, 4);
    Point<int> pos2(4, 8);
    Point<int> pos3 = pos1 + pos2;

    cout << pos1 << pos2 << pos3;

    return 0;
}
