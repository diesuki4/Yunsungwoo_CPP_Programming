#include <iostream>

using namespace std;

// 하나의 구조체, 객체로 다른 하나를 만들 때
// 
// C 구조체에서는 값 복사로 진행되고
// C++ 클래스에서는 복사 생성자, 대입 연산자로 진행된다.

class AAA
{
    int* pData;

public:
    AAA(int data) : pData(new int(data)) { }

    AAA(const AAA& rhs)
    {
        pData = new int(*rhs.pData);
    }
/*
 *  정의하지 않으면
 *  기본 복사 생성자가 삽입되는 것과 마찬가지로,
 *   
 *  기본 대입 연산자가 삽입된다.
 *
    AAA& operator= (const AAA& rhs)
    {
        // <얕은 복사>
        pData = rhs.pData;

        return *this;
    }
*/
    virtual ~AAA() { delete pData; }
};

int main(int argc, char* argv[])
{
    AAA dest(6), src(7);

    // a2 의 pData 주소가 그대로 복사되므로
    // 소멸자에서 하나는 문제가 발생한다.
    dest = src;

    return 0;
}
