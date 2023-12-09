#include <iostream>

using namespace std;

// 추상 클래스
// 
// <순수 가상 함수> 를 1개 이상 갖고 있어
// 객체화할 수 없는 클래스다.
class AbstractBase
{
    int data;

public:
    // 순수 가상 함수
    // 자식에서 <무조건> 오버라이드 해야 한다.
    virtual void PureVirtualFunc() = 0;
    // 가상 함수
    virtual void VirtualFunc() { cout << "AbstractBase::VirtualFunc()" << endl; }

    void Func() { cout << "AbstractBase::Func()" << endl; }
};

// 인터페이스
//
// 추상 클래스의 일종이라고 할 수도 있다.
//
// 모든 함수가 순수 가상 함수인 클래스다.
// <멤버 변수와 구현부>를 일체 포함하지 않는다.
class ISomething
{
// 멤버 변수(상태) 를 포함하지 않는다.

// 모든 함수는 public 으로 선언한다.
public:
    // 가상 소멸자를 정의해주지 않으면
    // 상속받은 클래스의 소멸자가 호출되지 않는다.
    virtual ~ISomething() { }
    // 순수 가상 함수이므로, 모두 자식에서 오버라이드 해야 한다.
    virtual void MoveX(int x) = 0;
    virtual void MoveY(int y) = 0;
    virtual void Reset() = 0;
};

int main(int argc, char* argv[])
{

    return 0;
}
