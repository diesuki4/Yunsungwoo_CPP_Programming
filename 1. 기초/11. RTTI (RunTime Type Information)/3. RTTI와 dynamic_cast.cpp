/*
 * https://stackoverflow.com/questions/18359780/how-is-dynamic-cast-implemented#answer-18360193
 * https://stackoverflow.com/questions/4644753/c-dynamic-cast-polymorphic-requirement-and-downcasting
 */
#include <iostream>
#include <type_traits>

using namespace std;

/*
 * RTTI와 dynamic_cast
 *
 * dynamic_cast 연산자도 RTTI 정보에 의존한다.
 *
 * 그렇기 때문에
 * 
 * 가상 함수 테이블을 통해 RTTI 정보를 얻을 수 있는
 * 다형적 클래스만 인자로 전달할 수 있는 것이다.
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

    cout << is_polymorphic_v<Mother> << endl;
    // SonM* sm = dynamic_cast<SonM*>(new Mother);
    // DaughterM* dm = dynamic_cast<DaughterM*>(new Mother);

    /*
     * 실제로는 업캐스팅인 경우에는
     * 런타임에 확인할 필요가 없으므로
     * 
     * 인자가 다형적 클래스의 객체가 아니어도 된다.
     */
    cout << is_polymorphic_v<SonM> << endl;
    ms = dynamic_cast<Mother*>(new SonM);

    cout << is_polymorphic_v<DaughterM> << endl;
    md = dynamic_cast<Mother*>(new DaughterM);

    /*
     * 다운캐스팅이거나, 아예 상속 관계가 없는 클래스끼리는
     *
     * 인자가 꼭 다형적 클래스의 객체여야 한다.
     */
    cout << is_polymorphic_v<Father> << endl;
    SonF* sf = dynamic_cast<SonF*>(new Father);
    DaughterF* df = dynamic_cast<DaughterF*>(new Father);

    cout << is_polymorphic_v<SonF> << endl;
    fs = dynamic_cast<Father*>(new SonF);

    cout << is_polymorphic_v<DaughterF> << endl;
    fd = dynamic_cast<Father*>(new DaughterF);

    return 0;
}
