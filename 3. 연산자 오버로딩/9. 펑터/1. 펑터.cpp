#include <iostream>

using namespace std;

// 펑터 (Funtion Object)
//
// () 연산자 오버로딩을 통해
// 객체를 함수처럼 사용할 수 있다.

class Adder
{
public:
    int operator()    (const int& n1, const int& n2)       { return n1 + n2; }
    double operator() (const double& e1, const double& e2) { return e1 + e2; }
};

int main(int argc, char* argv[])
{
    Adder adder;

    cout << adder(1, 3) << endl;
    cout << adder(1.5, 3.7) << endl;

    return 0;
}
