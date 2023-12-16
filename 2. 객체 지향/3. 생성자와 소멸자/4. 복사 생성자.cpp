#include <iostream>
#include <algorithm>

using namespace std;

class Point
{
    int x;
    int y;

    char* dataPtr;
    const int SIZE = 3;

public:
    // 생성자 체이닝
    Point() : Point(0, 0) { cout << "Point()" << endl; }
    Point(int x, int y) : x(x), y(y), dataPtr(new char[SIZE]) { cout << "Point(int x, int y)" << endl; }

    // 복사 생성자가 없으면, 기본 복사 생성자가 삽입된다.
    // Point(const Point& rhs) : x(rhs.x), y(rhs.y) { }
    //
    // 복사 생성자의 인자는 항상 & 레퍼런스여야 한다.
    // 값 형식이면, 무한 루프에 빠지게 된다.
    Point(const Point& rhs) : x(rhs.x), y(rhs.y)
    {
        // 깊은 복사
        dataPtr = new char[SIZE];
        copy(rhs.dataPtr, rhs.dataPtr + SIZE, dataPtr);

        cout << "Point(const Point& rhs)" << endl; 
    }

    // explicit Point(const Point& rhs) : x(rhs.x), y(rhs.y) { }
    // 
    // explicit 키워드를 사용하면, base 는 Non-const 이기 때문에
    // Point p2 = base 는 묵시적 변환이 되지 않아, 사용할 수 없게 된다.

    // = 연산자 오버로딩이 없으면, 기본 값 복사가 삽입된다.
    // Point& = (const Point& rhs) { x = rhs.x; y = rhs.y; return *this; }
    Point& operator= (const Point& rhs)
    {
        x = rhs.x;
        y = rhs.y;

        cout << "Point& operator= (const Point& rhs)" << endl;

        return *this;
    }
    
    ~Point()
    {
        delete [] dataPtr;

        cout << "~Point()" << endl;
    }
};

int main(int argc, char* argv[])
{
    Point base(10, 20);

    // 아래 두 구문은 동작이 같다.
    // 
    // 자동으로 다음과 같이 묵시적 변환이 일어난다.
    // Point p1(base);
    //
    // 복사 생성자는 생성자 대신 호출된다.
    Point p1 = base;
    Point p2(base);

    // 위와는 다른 동작이다.
    // 
    // 생성자가 호출되고
    Point p3;
    // 값 복사가 일어난다.
    p3 = base;

    return 0;
}
