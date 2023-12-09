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
    Point() : Point(0, 0) { cout << "Point()" << endl; }
    Point(int x, int y) : x(x), y(y), dataPtr(new char[SIZE]) { cout << "Point(int x, int y)" << endl; }

    Point(const Point& rhs) : x(rhs.x), y(rhs.y)
    {
        dataPtr = new char[SIZE];
        copy(rhs.dataPtr, rhs.dataPtr + SIZE, dataPtr);

        cout << "Point(const Point& rhs)" << endl; 
    }

    ~Point()
    {
        delete [] dataPtr;

        cout << "~Point()" << endl;
    }
};

// 2. 객체를 Call by Value 로 전달할 때
Point GetCopy(Point p)
{
    // 3. 값 형식으로 객체를 반환할 때
    // p 객체를 통해 반환될 임시 객체를 초기화해야 하므로
    //
    // 구조체 등 큰 반환값은 Caller 가 스택에 공간을 할당한다.
    return p;
}

int main(int argc, char* argv[])
{
    Point base(10, 20);

    // 1. 기존 객체로 새로운 객체를 초기화할 때
    Point p = base;
    
    // 3. 의 상황에서 리턴 값을 받지 않아도
    // 복사 생성자는 호출된다.
    GetCopy(p);

    return 0;
}
