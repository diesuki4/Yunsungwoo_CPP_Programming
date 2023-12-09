#include <iostream>

using namespace std;

// 다이아몬드 상속 문제

class Person
{
public:
    Person() { cout << "Person()" << endl; }
    void PersonFunc() { cout << "Person::PersonFunc()" << endl; }
};

class Mother : public Person
{
public:
    Mother() : Person() { cout << "Mother()" << endl; }
};

class Father : public Person
{
public:
    Father() : Person() { cout << "Father()" << endl; }
};

// Child는 Mother, Father로부터
// Person을 2번 상속 받게 된다.
class Child : public Mother, public Father
{
public:
    // 그러므로, Person 의 생성자는 2번 호출된다.
    Child() : Mother(), Father() { cout << "Child()" << endl; }

    void ChildFunc()
    {
        // 2개의 Person 상속으로 인해,
        // 모호하므로 사용할 수 없다.
        // PersonFunc();

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
