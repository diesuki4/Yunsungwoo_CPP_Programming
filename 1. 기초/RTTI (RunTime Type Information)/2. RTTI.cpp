/*
 * https://chogyujin-study.tistory.com/25
 * https://dataonair.or.kr/db-tech-reference/d-lounge/technical-data/?mod=document&uid=235810
 * https://www.gamejob.co.kr/Community/Talk/Detail?talk_Stat=14&idx=54112
 */
#include <iostream>
#include <typeinfo>

using namespace std;

/*
 * RTTI (RunTime Type Information)
 *
 * 런타임 중 객체의 실제 타입을 알 수 있는 방법
 * 
 * RTTI 정보는 가상 함수 테이블에 담긴다.
 * 
 * 따라서 가상 함수 테이블과 마찬가지로,
 * RTTI 정보도 클래스별로 싱글톤이라고 할 수 있다.
 * 
 * 다형적 클래스가 아니면, RTTI 정보를 얻을 수 없다.
 */

class Mother
{ public: void BaseFunc() { } };
class SonM : public Mother
{ public: void DerivedFunc() { } };
class DaughterM : public Mother
{ public: virtual void DerivedFunc() { } };

class Father
{ public: virtual void BaseFunc() { } };
class SonF : public Father
{ public: void DerivedFunc() { } };
class DaughterF : public Father
{ public: virtual void DerivedFunc() { } };

int main(int argc, char* argv[])
{
    Mother* ms = new SonM;
    Mother* md = new DaughterM;
    Father* fs = new SonF;
    Father* fd = new DaughterF;

    /* 다형적 클래스가 아니므로, RTTI 정보를 갖지 않는다. */
    cout << typeid(*ms).name() << endl;      // Mother

    /* 다형적 클래스여도 Mother 부분에는 vptr 이 존재하지 않으므로, RTTI 정보를 갖지 않는다. */
    cout << typeid(*md).name() << endl;      // Mother

    /* 다형적 클래스이고 Father 부분에 vptr 이 존재하므로, RTTI 정보를 갖는다. */
    cout << typeid(*fs).name() << endl;      // SonF
    cout << typeid(*fd).name() << endl;      // DqughterF

    return 0;
}
