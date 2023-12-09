#include <iostream>

using namespace std;

class KotMulYak   { public: void Take() { cout << "콧물 약 복용" << endl; } };
class MokgamkiYak { public: void Take() { cout << "목감기 약 복용" << endl; } };
class KichimYak   { public: void Take() { cout << "기침 약 복용" << endl; } };

// 캡슐화
//
// 관련 있는 둘 이상의 기능이 모여, 하나의 목적을 달성하도록 하는 방식
class TheraFlu
{
    // 캡슐화할 때는 <안전하게> 감싸야 하므로,
    // 기본적으로 정보 은닉을 내포한다.
    KotMulYak kot;
    MokgamkiYak mok;
    KichimYak kichim;

public:
    void Take()
    {
        kot.Take();
        mok.Take();
        kichim.Take();
    }
};

int main(int argc, char* argv[])
{
/*
    KotMulYak kot;
    MokgamkiYak mok;
    KichimYak kichim;

    kot.Take();
    mok.Take();
    kichim.Take();
*/
    TheraFlu theraflu;

    theraflu.Take();

    return 0;
}
