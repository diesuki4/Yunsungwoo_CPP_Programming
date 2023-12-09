#include <iostream>

using namespace std;

class AAA
{
    int* pData;

    // 복사 생성자와 대입 연산자를
    // 강제로 private 설정하면
    //
    // 복사, 대입을 원천적으로 차단할 수도 있다.
    AAA(const AAA& rhs) { }
    AAA& operator= (const AAA& rhs) { }

public:
    AAA(int data) : pData(new int(data)) { }

    AAA(const AAA& rhs)
    {
        pData = new int(*rhs.pData);
    }

    virtual ~AAA() { delete pData; }
};

int main(int argc, char* argv[])
{
    AAA src(6);

    // 복사 생성자는 private 이므로 차단되었다.
    // AAA dest(src);
    // AAA dest = src;

    AAA dest(5);

    // 대입 연산자는 private 이므로 차단되었다.
    // dest = src;

    return 0;
}
