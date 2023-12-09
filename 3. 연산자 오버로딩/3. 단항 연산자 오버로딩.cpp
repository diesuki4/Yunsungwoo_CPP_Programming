#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) { }

    // ---- 전위 연산 ----
    // 기본적으로 전위 연산이다.
    Point& operator++ ()
    {
        ++x;
        ++y;

        return *this;
    }

    friend Point& operator-- (Point& ref);

    // ---- 후위 연산 ----
    // 인자에 int 를 추가하면 후위 연산이 된다.
    const Point operator++ (int)
    {
        const Point pivot(*this);

        ++x;
        ++y;

        return pivot;
    }

    // 후위 연산의 반환형에 const 를 붙인 이유는
    // (p++)++ 연산을 막기 위함이다.
    friend const Point operator-- (Point& ref, int);
};

Point& operator-- (Point& ref)
{
    --ref.x;
    --ref.y;

    return ref;
}

const Point operator-- (Point& ref, int)
{
    const Point pivot(ref);

    --ref.x;
    --ref.y;

    return pivot;
}

int main(int argc, char* argv[])
{
    Point p1(1, 1), p2(3, 3);

    ++p1;
    --p2;

    p1--;
    p2++;

    return 0;
}
