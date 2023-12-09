#include <iostream>

using namespace std;

/*
 * static 변수도 3개가 만들어진다.
 * 
 * ShowStaticValue<int>()    의 num
 * ShowStaticValue<long>()   의 num
 * ShowStaticValue<double>() 의 num
 */
template <typename T>
void ShowStaticValue()
{
    static T num = 0;

    cout << ++num << " ";
}

/*
 * static 클래스 변수도 2개가 만들어진다.
 *
 * SimpleStaticMem<int>::mem
 * SimpleStaticMem<long>::mem
 */
template <typename T>
class SimpleStaticMem
{
    static T mem;

public:
    void AddMem(int num) { mem += num; }
    void ShowMem()       { cout << mem << endl; }
};

/*
 * 초기화 구문은 다음과 같다.
 *
 * int  SimpleStaticMem<int>::mem  = 0
 * long SimpleStaticMem<long>::mem = 0
 */
template <typename T>
T SimpleStaticMem<T>::mem = 0;

int main(int argc, char* argv[])
{
    ShowStaticValue<int>();
    ShowStaticValue<int>();
    ShowStaticValue<int>();
    cout << endl;

    ShowStaticValue<long>();
    ShowStaticValue<long>();
    ShowStaticValue<long>();
    cout << endl;

    ShowStaticValue<double>();
    ShowStaticValue<double>();
    ShowStaticValue<double>();
    cout << endl;

    SimpleStaticMem<int> intClass1;
    SimpleStaticMem<int> intClass2;
    SimpleStaticMem<int> intClass3;
    intClass1.AddMem(2);
    intClass2.AddMem(3);
    intClass3.ShowMem();

    SimpleStaticMem<long> longClass1;
    SimpleStaticMem<long> longClass2;
    longClass1.AddMem(100);
    longClass2.ShowMem();

    return 0;
}
