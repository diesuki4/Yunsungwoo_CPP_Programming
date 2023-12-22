#include <iostream>
#include <vector>

using namespace std;

// ---------------------------------------------

namespace BestComImpl
{
    void SimpleFunc(void);
}

namespace BestComImpl
{
    void PrettyFunc(void);
}

// ---------------------------------------------

namespace ProgComImpl
{
    void SimpleFunc(void);
}

// ---------------------------------------------

void BestComImpl::SimpleFunc(void)
{
    cout << "BestComImpl::SimpleFunc" << endl;
    PrettyFunc();               // 동일 namespace에서는 생략 가능
    ProgComImpl::SimpleFunc();  // 다른 namespace
}

void BestComImpl::PrettyFunc(void)
{
    cout << "BestComImpl::PrettyFunc" << endl;
}

void ProgComImpl::SimpleFunc(void)
{
    cout << "ProgComImpl::SimpleFunc" << endl;
}

// -------------- 중첩 namespace ---------------

namespace AAA
{
    namespace BBB
    {
        void SimpleFunc(void);

        namespace CCC
        {
            void SimpleFunc(void);
        }
    }
}

void AAA::BBB::SimpleFunc(void)
{
    cout << "AAA::BBB::SimpleFunc" << endl;
}

void AAA::BBB::CCC::SimpleFunc(void)
{
    cout << "AAA::BBB::CCC::SimpleFunc" << endl;
}

// ---------------------------------------------

int val = 100;

int main(int argc, char* argv[])
{
    // :: 연산자로 접근
    BestComImpl::SimpleFunc();

    // 하나의 변수, 함수만 선언 가능
    using AAA::BBB::SimpleFunc;
    SimpleFunc();

    // 네임스페이스의 별칭은 namespace 키워드를 사용
    namespace ABC = AAA::BBB::CCC;
    ABC::SimpleFunc();

    // 자료형의 별칭은 using을 사용
    using myint = int;
    cout << myint(10) << endl;

    int val = 10;

    // ::변수 (전역)
    cout << "전역 ::val = " << ::val << endl;
    cout << "지역 val = " << val << endl;

    return 0;
}
