#include <iostream>

using namespace std;

/*
 * 상속에서의 가상 함수 포인터
 * 
 * 가상 함수 테이블 포인터(vptr) 는 private 멤버 변수처럼 추가된다고 보면 된다.
 * Base 클래스로부터 상속된다.
 * 
 * 객체 생성 시에 어떤 가상 함수 테이블을 가리킬지 정해진다.
 *
 * vptr 은 객체의 1번째 멤버로 추가된다.
 */

/*
 * 이 Base 클래스는 다형적 클래스가 아니므로, vptr 이 존재하지 않는다.
 */
class Mother
{ public: void BaseFunc() { } };
// 따라서, 여기도 vptr 이 없다.
class SonM : public Mother
{ public: void DerivedFunc() { } };
// 여기 있는 vptr 은 Mother 가 아닌, 자신의 것이다.
class DaughterM : public Mother
{ public: virtual void DerivedFunc() { } };

/*
 * 이 Base 클래스는 다형적 클래스이므로, vptr 이 존재한다.
 */
class Father
{ public: virtual void BaseFunc() { } };
// 따라서, 여기도 vptr 이 존재한다.
class SonF : public Father
{ public: void DerivedFunc() { } };
// 여기 있는 vptr 도 Father 의 것이다.
class DaughterF : public Father
{ public: virtual void DerivedFunc() { } };

int main(int argc, char* argv[])
{
    cout << sizeof(Mother) << endl;     // 1 Byte
    cout << sizeof(SonM) << endl;       // 1 Byte
    cout << sizeof(DaughterM) << endl;  // 4 Bytes
    cout << sizeof(Father) << endl;     // 4 Bytes
    cout << sizeof(SonF) << endl;       // 4 Bytes
    cout << sizeof(DaughterF) << endl;  // 4 Bytes

    return 0;
}
