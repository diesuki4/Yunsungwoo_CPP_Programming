#include <iostream>

using namespace std;

// 연산자 오버로딩은
// 본래 의도를 벗어나지 않도록 작성해야 한다.
//
// O
// Vector3 + Vector3 = 덧셈
// 
// X
// Vector3 + Vector3 = 내적

class Point
{
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) { }

    // 연산자 오버로딩은
    // 디폴트 파라미터가 불가능하다.
    // Point operator+ (int X = 0)
    Point operator+ (const Point& other)
    {
        return Point(x + other.x, y + other.y);
    }
};

int main(int argc, char* argv[])
{
    Point p1(1, 1), p2(3, 3);

    p1 + p2;

    return 0;
}
