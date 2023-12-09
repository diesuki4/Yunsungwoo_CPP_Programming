#include <iostream>

using namespace std;

// 디폴트 파라미터
//
// 오른쪽부터 채워야 한다.
// 선언부에만 작성한다.
int Func(int n1, int n2 = 0, int n3 = 0);

int Func(int n1, int n2, int n3)
{
    return n1 + n2 + n3;
}

int main(int argc, char* argv[])
{
    cout << Func(40) << endl;

    return 0;
}
