/*
 * https://en.cppreference.com/w/cpp/language/ebo
 */
#include <iostream>
#include <vector>

using namespace std;

/*
 * EBO (Empty Base Optimization)
 *
 * 빈 구조체/클래스의 크기는 0 이 아닌, 1 이다.
 *
 * 이것을 상속 받은 클래스에서
 * 빈 부모 부분의 크기를 1 이 아닌 0 으로 최적화하는 기법이다.
 *
 * STL 에서는 대개 typedef 를 가진 빈 클래스들에 EBO 가 많이 사용된다.
 *
 * 단, 자식 클래스의 첫 번째 멤버가 그 타입(혹은 그의 자손) 이면
 * EBO 는 동작하지 않는다.
 *
 * 객체의 부모 부분과, 멤버에서의 부모 부분을 구별할 수 있어야 하기 때문.
 *
 * 또한, 다중 상속에서도 동작하지 않는다.
 */

// TOTAL : 1 Byte
struct CompletelyEmpty  // 1 Byte
{
};

// TOTAL : 1 Byte
struct DerivedCompletelyEmpty : CompletelyEmpty  // 1 Byte
{
};

// TOTAL : 1 Byte
struct EmptyWithClassVar  // 1 Byte
{
    static int num;  // Not in Object Memory
};

// TOTAL : 1 Byte
struct EmptyWithMemberFunc  // 1 Byte
{
    // Not in Object Memory
    typedef vector<int> vecInt;
    using byte = char;
    enum Color { Red, Blue, Green };
    void Func() {}

    /* 가상 함수는 첫 번째 멤버로 vptr 이 추가되므로, 빈 객체가 될 수 없다.
    virtual void vFunc() {} */
};

// TOTAL : 1 Byte
struct EmptyAsMember
{
    CompletelyEmpty c;  // 1 Byte
};

// TOTAL : 4 Bytes
struct Derived1 : CompletelyEmpty  // EBO
{
    int i;  // 4 Bytes
};

// TOTAL : 8 Bytes
struct Derived2 : CompletelyEmpty  // 1 Byte
{
    CompletelyEmpty c;  // 1 Byte (CompletelyEmpty is 1st member)
                        // 2 Paddings
    int i;              // 4 Bytes
};

// TOTAL : 12 Bytes
struct Derived3 : CompletelyEmpty  // 1 Byte
{
                 // 3 Paddings
    Derived1 c;  // 4 Bytes (Descendant of CompletelyEmpty is 1st member)
    int i;       // 4 Bytes
};

// TOTAL : 8 Bytes
struct Derived4 : CompletelyEmpty  // EBO
{
    int i;       // 4 Bytes
    Derived1 c;  // 4 Bytes (Descendant of CompletelyEmpty, but not 1st member)
};

int main(int argc, char* argv[])
{
    CompletelyEmpty arr[100];
    CompletelyEmpty* p = arr;

    // 만약 CompletelyEmpty 의 크기가 0이라면,
    // p 는 항상 1번째 원소만 가리키게 된다.
    for (int i = 0; i < 10; ++i, ++p);

    cout << sizeof(CompletelyEmpty) << endl;         // 1 Byte
    cout << sizeof(DerivedCompletelyEmpty) << endl;  // 1 Byte
    cout << sizeof(EmptyWithClassVar) << endl;       // 1 Byte
    cout << sizeof(EmptyWithMemberFunc) << endl;     // 1 Byte
    cout << sizeof(EmptyAsMember) << endl;  // 1 Byte
    cout << sizeof(Derived1) << endl;       // 4 Bytes
    cout << sizeof(Derived2) << endl;       // 8 Bytes
    cout << sizeof(Derived3) << endl;       // 12 Bytes
    cout << sizeof(Derived4) << endl;       // 8 Bytes

    return 0;
}
