#include <iostream>

using namespace std;

class AAA
{
    int data;

public:
    // 생성자가 없으면, 기본 생성자
    // AAA() { }

    // 기본 소멸자
    // ~AAA() { }
};

class BBB
{
    int* pData;

public:
    // 생성자가 있으면, 기본 생성자는 삽입 X
    BBB(int data) : pData(new int(data)) { }

    // 소멸자는 오버로딩 불가
    ~BBB()
    {
        delete pData;
        pData = nullptr;
    }
};

class CCC
{
    int data;

public:
    // 생성자가 있으면, 기본 생성자는 삽입 X
    // 
    // 단, 디폴트 파라미터를 사용하면
    // BBB 와 달리
    //
    // CCC ccc;
    // CCC ccc(4);
    //
    // 둘 모두 사용할 수 있다.
    CCC(int data = 0) : data(data) { }
};

class DDD
{
    int data;

public:
    DDD() : DDD(0) { }

    // 변수(l-value)가 되기 위해서는 공간과 이름이 있어야 한다.
    // new로 할당된 공간도 변수(l-value)로 간주한다.
    DDD& CreateInstance(int data) const
    {
        return *new DDD(data);
    }

private:
    // private 생성자
    // 내부적으로 호출된다.
    // 객체의 생성 방법을 제한하고 싶을 때 유용하다.
    DDD(int data) : data(data) { }
};

int main(int argc, char* argv[])
{
    AAA aaa;

    // 기본 생성자가 없으므로 불가
    // BBB bbb;

    // 기본 생성자 or BBB() 생성자가 있어야 가능
    // BBB arrBBB[3];

    BBB bbb(10);

    CCC ccc;

    DDD base;
    DDD& ddd = base.CreateInstance(3);

    // new로 할당된 공간에서 가져온 레퍼런스는
    // 직접 해제해 주어야 한다.
    delete& ddd;

    return 0;
}
