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

class Stick
{
    int damage;

public:
    Stick(int damage) : damage(damage) { }
};

class Shield
{
    int durability;

public:
    Shield(int durability) : durability(durability) { }
};

// Has-A 관계
//
// <경찰> => <총>, <경광봉>, <방패>를 소유하고 있다.
//
// 컴포짓을 통해 Has-A 관계를 표현하면
// 좀 더 좋은 모델이다.
class Police
{
    // <연관성이 낮기에>
    // 권총을 소유하지 않은 경찰도 표현할 수 있다.
    // <확장성이 좋기에>
    // 경광봉, 방패를 소유하기 위해 다중 상속을 하지 않아도 된다.
    Gun* gun;
    Stick* stick;
    Shield* shield;

    string name;

public:
    Police(int bullet, bool bStick, bool bShield, string name)
    : gun(nullptr), stick(nullptr), shield(nullptr), name(name)
    {
        if (0 < bullet) gun = new Gun(bullet);
        if (bStick)     stick = new Stick(10);
        if (bShield)    shield = new Shield(100);
    }
};

int main(int argc, char* argv[])
{
    Police police(6, false, true, "Jane");

    return 0;
}
