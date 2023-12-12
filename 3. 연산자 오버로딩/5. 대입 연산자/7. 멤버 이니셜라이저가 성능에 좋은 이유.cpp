#include <iostream>

using namespace std;

class AAA
{
    int data;

public:
    AAA(int data = 0) : data(data) { cout << "AAA::생성자" << endl; }

    AAA(const AAA& rhs) : data(rhs.data) { cout << "AAA::복사 생성자" << endl; }

    AAA& operator= (const AAA& rhs) { data = rhs.data; cout << "AAA::대입 연산자" << endl; return *this; }
};

class BBB
{
    AAA aaa;

public:
    // 멤버 이니셜라이저에 의한 초기화는
    // 선언과 동시에 초기화가 이뤄진다.
    BBB(const AAA& aaa) : aaa(aaa) { }
};

class CCC
{
    AAA aaa;

public:
    // 대입의 경우
    // 선언 후, 대입을 통해 초기화가 이뤄진다.
    CCC(const AAA& aaa) { this->aaa = aaa; }
};

int main(int argc, char* argv[])
{
    // AAA::생성자 호출
    AAA a;
    
    // AAA::복사 생성자 호출
    BBB b(a);

    // AAA::생성자 호출
    // AAA::대입 연산자 호출
    CCC c(a);

    return 0;
}
