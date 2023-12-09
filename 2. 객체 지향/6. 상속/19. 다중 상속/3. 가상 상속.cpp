#include <iostream>

using namespace std;

// 다이아몬드 상속 문제는
// 가상 상속으로 해결할 수 있다.

class Person
{
public:
    Person() { cout << "Person()" << endl; }
    void PersonFunc() { cout << "Person::PersonFunc()" << endl; }
};

// 가상 상속
class Mother : virtual public Person
{
public:
    Mother() : Person() { cout << "Mother()" << endl; }
};

// 가상 상속
class Father : virtual public Person
{
public:
    Father() : Person() { cout << "Father()" << endl; }
};

// Mother와 Father가 Person을 가상 상속 했으므로
// Child는 Person을 1번만 상속 받는다.
//
// 둘 모두 가상 상속이 아닌 경우에는
// 2번 상속 된다.
class Child : public Mother, public Father
{
public:
    // 그러므로, Person 의 생성자는 1번 호출된다.
    Child() : Mother(), Father() { cout << "Child()" << endl; }

    void ChildFunc()
    {
        // 1개의 Person 상속으로 인해,
        // 모호하지 않으므로 사용할 수 있다.
        PersonFunc();

        Person::PersonFunc();
        Mother::PersonFunc();
        Father::PersonFunc();
    }
};

int main(int argc, char* argv[])
{
    Child c;

    c.ChildFunc();

    return 0;
}
