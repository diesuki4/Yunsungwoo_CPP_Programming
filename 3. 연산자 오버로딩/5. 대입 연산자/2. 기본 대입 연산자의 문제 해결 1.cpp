#include <iostream>

using namespace std;

class AAA
{
    int* pData;

public:
    AAA(int data) : pData(new int(data)) { }

    AAA(const AAA& rhs)
    {
        // <깊은 복사>
        pData = new int(*rhs.pData);
    }

    AAA& operator= (const AAA& rhs)
    {
        // 이미 생성된 객체에 대입하는 것이므로,
        // 기존 메모리를 해제해 주어야 한다.
        delete pData;

        // <깊은 복사>
        pData = new int(*rhs.pData);

        return *this;
    }

    // 대입 연산자는 복사 생성자처럼
    // 시그니처가 고정되어 있지 않다는 점을 참고한다.
    //
    // AAA& operator= (const AAA rhs)
    // AAA& operator= (AAA rhs)
    // AAA& operator= (int rhs)

    virtual ~AAA() { delete pData; }
};

int main(int argc, char* argv[])
{
    AAA dest(6), src(7);

    dest = src;

    return 0;
}
