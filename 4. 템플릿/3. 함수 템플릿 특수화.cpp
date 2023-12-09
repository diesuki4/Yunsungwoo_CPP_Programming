#include <iostream>

using namespace std;

template <typename T>
T Max(T a, T b)
{
    return a < b ? b : a;
}

// <템플릿 특수화>

// const char* 타입에 대해서는
// 템플릿 함수를 만들지 않고
//
// 이 함수를 사용한다.
template <>
const char* Max<const char*>(const char* a, const char* b)
{
    cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;

    string sA(a), sB(b);

    return sA.length() < sB.length() ? b : a;
}

// string 타입에 대해서는
// 템플릿 함수를 만들지 않고
//
// 이 함수를 사용한다.
template <>
string Max<string>(string a, string b)
{
    cout << "string Max<string>(string a, string b)" << endl;

    return a < b ? b : a;
}

// 꺽쇠의 자료형은 생략할 수 있다.
// 
// const char* Max(const char* a, const char* b);
// string Max(string a, string b);

int main(int argc, char* argv[])
{
    cout << Max(11, 15) << endl;
    cout << Max('T', 'Q') << endl;
    cout << Max(3.5, 7.5) << endl;

    cout << Max("Simple", "Best") << endl;

    string s1 = "Simple", s2 = "Best";
    cout << Max(s1, s2) << endl;

    return 0;
}
