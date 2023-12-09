#include <iostream>

using namespace std;

// Is-A 와 Has-A 관계 이외에
// 상속을 사용하는 경우는 없다.

class Gun
{
    int bullet;

public:
    Gun(int bullet) : bullet(bullet) { }
};

// Has-A 관계
//
// <경찰> => <총>을 소유하고 있다.
//
// 상속을 통해 Has-A 관계를 표현하는 것은
// 좋은 방법이 아니다.
//
// <강한 연관성>을 띄기에
// 총을 소유하지 않은 경찰을 표현할 수 없다.
class Police : public Gun
{
    string name;

public:
    Police(int bullet, string name) : Gun(bullet), name(name) { }
};

int main(int argc, char* argv[])
{
    Police police(6, "Jane");

    return 0;
}
