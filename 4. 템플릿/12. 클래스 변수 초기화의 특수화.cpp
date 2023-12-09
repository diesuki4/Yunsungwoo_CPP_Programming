#include <iostream>

using namespace std;

template <typename T>
class SimpleStaticMem
{
    static T mem;

public:
    void AddMem(int num) { mem += num; }
    void ShowMem()       { cout << mem << endl; }
};

// 템플릿 클래스의 mem 클래스 변수
// 기본값은 0이다.
template <typename T>
T SimpleStaticMem<T>::mem = 0;

// 특수화는 함수 템플릿이나 클래스 템플릿에서만
// 적용 가능한 것이 아니다.
//
// SimpleStaticMem<float> 템플릿 클래스에 대해서는
// mem 클래스 변수의 기본값을 100으로 한다.
template <>
float SimpleStaticMem<float>::mem = 100;

int main(int argc, char* argv[])
{
    SimpleStaticMem<int> intClass1;
    SimpleStaticMem<int> intClass2;
    SimpleStaticMem<int> intClass3;
    intClass1.AddMem(2);
    intClass2.AddMem(3);
    intClass3.ShowMem();

    SimpleStaticMem<long> longClass1;
    SimpleStaticMem<long> longClass2;
    longClass1.AddMem(50);
    longClass2.ShowMem();

    SimpleStaticMem<float> floatClass;
    floatClass.ShowMem();

    return 0;
}
