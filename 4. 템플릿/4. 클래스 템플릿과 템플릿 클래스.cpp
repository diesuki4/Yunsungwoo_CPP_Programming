#include <iostream>

using namespace std;

// <클래스 템플릿>
//
// 기능과 내부 동작은 결정되어 있지만,
// 자료형은 결정되어 있지 않아
//
// 자료형에 따라 클래스를 만들어 낼 수 있는 틀
template <typename T>
class Point
{
    T x, y;

public:
    Point(T x, T y) : x(x), y(y) { cout << x << ", " << y << endl; }
};

// <템플릿 클래스>
// 
// 컴파일러에 의해
// 총 3개의 <템플릿 클래스>가 만들어 진다.
// 
// Point<int>
// Point<double>
// Point<char>

// 컴파일 타임에 컴파일러가 객체 생성문을 보고
// 필요한 자료형의 클래스를 만들어 낸다.
// 
// 컴파일 시간이 증가하고,
// 텍스트 영역의 크기가 증가한다는 단점이 있다.

int main(int argc, char* argv[])
{
    // 함수 템플릿과 달리,
    // 생성자의 인자를 통해 타입을 유추할 수 없기 때문에
    //
    // 명시적으로 타입을 적어주어야만 한다.
    // Point pos1(2.4, 3.6);
    Point<int> pos1(2.4, 3.6);

    Point<double> pos2(2.4, 3.6);

    Point<char> pos3('P', 'F');

    // 불가
    // 다른 템플릿 클래스이기 때문
    // Point<int> pos4 = pos3;

    return 0;
}
