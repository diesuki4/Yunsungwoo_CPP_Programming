#include <iostream>

using namespace std;

class Point
{
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) { }

    Point operator+ (const Point& other)
    {
        // 우선 순위
        // 전역 오버로드 함수 < 멤버 오버로드 함수
        cout << "멤버 함수" << endl;
        return Point(x + other.x, y + other.y);
    }

    // 연산자 오버로딩에서
    // friend 를 적절하게 활용할 수 있다.
    //
    // 다만, 객체 지향적 관점에서
    // 전역 오버로드 함수보다는
    // 멤버 오버로드가 더 선호된다.
    friend Point operator+ (const Point& A, const Point& B);
};

Point operator+ (const Point& A, const Point& B)
{
    cout << "전역 함수" << endl;
    return Point(A.x + B.x, A.y + B.y);
}

int main(int argc, char* argv[])
{
    Point p1(1, 1), p2(3, 3);

    p1 + p2;

    return 0;
}
