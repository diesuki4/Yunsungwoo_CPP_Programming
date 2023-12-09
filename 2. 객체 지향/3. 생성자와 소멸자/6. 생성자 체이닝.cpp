#include <iostream>

using namespace std;

class Vector3A
{
    int x;
    int y;
    int z;

public:
    // 생성자 체이닝
    Vector3A()                    : Vector3A(0)       { cout << "Vector3A()" << endl; }
    Vector3A(int x)               : Vector3A(x, 0)    { cout << "Vector3A(int x)" << endl; }
    Vector3A(int x, int y)        : Vector3A(x, y, 0) { cout << "Vector3A(int x, int y)" << endl; }
    // 모든 생성자는 가장 마지막 체인을 시작으로
    // 재귀적으로 호출된다.
    Vector3A(int x, int y, int z) : x(x), y(y), z(z)  { cout << "Vector3A(int x, int y, int z)" << endl; }
};

class Vector3B
{
    int x;
    int y;
    int z;

public:
    // 디폴트 파라미터
    Vector3B(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z)
    {
        cout << "Vector3B(int x = 0, int y = 0, int z = 0)" << endl;
    }
};

int main(int argc, char* argv[])
{
    Vector3A v3a1;          cout << endl;
    Vector3A v3a2(1);       cout << endl;
    Vector3A v3a3(1, 2);    cout << endl;
    Vector3A v3a4(1, 2, 3); cout << endl;

    Vector3B v3b1;          cout << endl;
    Vector3B v3b2(1);       cout << endl;
    Vector3B v3b3(1, 2);    cout << endl;
    Vector3B v3b4(1, 2, 3); cout << endl;

    return 0;
}
