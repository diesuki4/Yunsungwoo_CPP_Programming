#include <iostream>

using namespace std;

class AAA
{
    // 멤버 변수는 객체마다 존재한다.
    // 값 타입이면 <스택>
    // 동적 할당이면 <힙>
    int data;

public:
    // 멤버 함수는 모든 객체가 공유해 사용한다.
    // 객체마다 생성되는 것이 아니다.
    // <텍스트 영역>
    AAA(int data) : data(data) { }
    void Show() { cout << data << endl; }
};

int main(int argc, char* argv[])
{
    AAA a1(3), a2(5);

    a1.Show();
    a2.Show();

    return 0;
}
