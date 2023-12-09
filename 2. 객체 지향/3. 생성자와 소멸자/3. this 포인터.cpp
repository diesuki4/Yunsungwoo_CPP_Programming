#include <iostream>

using namespace std;

class AAA
{
    int data;

public:
    // this 포인터 = 객체 자신의 주소
    // 멤버 변수와 같은 이름의 인자가 오더라도
    // 멤버 변수에 접근할 수 있다.
    void SetData(int data) { this->data = data; }

    // Self-reference를 반환할 수도 있다.
    AAA& GetRef() { return *this; }
};

int main(int argc, char* argv[])
{
    AAA aaa;

    return 0;
}
