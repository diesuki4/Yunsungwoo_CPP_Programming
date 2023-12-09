#include <iostream>

using namespace std;

template <typename T, typename U>
class MySimple
{
public:
    void WhoAreYou()
    {
        cout << "size of T: " << sizeof(T) << endl;
        cout << "size of U: " << sizeof(U) << endl;
        cout << "<typename T, typename U>" << endl << endl;
    }
};

// 클래스 템플릿 특수화
template <>
class MySimple<int, double>
{
public:
    void WhoAreYou()
    {
        cout << "size of int: " << sizeof(int) << endl;
        cout << "size of double: " << sizeof(double) << endl;
        cout << "<int, double>" << endl << endl;
    }
};

// 클래스 템플릿 <부분> 특수화
// 자료형 중 일부만 특수화한다.
template <typename T>
class MySimple<T, double>
{
public:
    void WhoAreYou()
    {
        cout << "size of T: " << sizeof(T) << endl;
        cout << "size of double: " << sizeof(double) << endl;
        cout << "<T, double>" << endl << endl;
    }
};

// 클래스 템플릿 <부분> 특수화
// 자료형 중 일부만 특수화한다.
template <typename U>
class MySimple <float, U>
{
public:
    void WhoAreYou()
    {
        cout << "size of float: " << sizeof(float) << endl;
        cout << "size of U: " << sizeof(U) << endl;
        cout << "<float, U>" << endl << endl;
    }
};

int main(int argc, char* argv[])
{
    MySimple<char, float> obj1;
    obj1.WhoAreYou();

    MySimple<int, double> obj2;
    obj2.WhoAreYou();

    MySimple<char, double> obj3;
    obj3.WhoAreYou();

    MySimple<float, int> obj4;
    obj4.WhoAreYou();

    return 0;
}
