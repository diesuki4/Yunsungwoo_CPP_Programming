#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) { }

    // 피연산자에 다른 자료형이 있을 때
    // 교환법칙을 성립하기 위해서는
    Point operator* (int times)
    {
        return Point(x * times, y * times);
    }

    // 필연적으로 전역 오버로드 함수를 정의해야 한다.
    friend Point operator* (int times, const Point& ref);
};

Point operator* (int times, Point& ref)
{
    // 기존 멤버 오버로드를 이용하면
    // 쉽게 구현할 수 있다.
    return ref * times;
}

int main(int argc, char* argv[])
{
    Point p(1, 1);

    p * 3;
    3 * p;

    return 0;
}
