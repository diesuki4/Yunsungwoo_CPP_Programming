#include <iostream>

using namespace std;

// 멤버 이니셜라이저
//
// 선언과 동시에 초기화되므로,
// 성능상에 이점이 있다.
//
// X
// int num;
// num = n1;
//
// O
// int num = n1;

class Point
{
    // const 변수는
    // 선언과 동시에 초기화하거나
    const int x = 0;
    // 멤버 이니셜라이저를 통해 초기화한다.
    const int y;

public:
    Point(int x, int y)
    // 값 초기화에도 사용된다.
    : x(x), y(y) { }
};

class Rectangle
{
    // 선언과 동시에 초기화되므로
    // 레퍼런스를 멤버 변수로 사용할 수도 있다.
    Point& leftTop;
    Point RightBottom;

public:
    Rectangle(Point& leftTop, int x2, int y2)
    // 멤버 객체의 생성자 호출에도 사용된다.
    : leftTop(leftTop), RightBottom(x2, y2) { }
};

int main(int argc, char* argv[])
{
    Rectangle rect(0, 0, 3, 4);

    return 0;
}
