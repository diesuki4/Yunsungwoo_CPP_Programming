#include <iostream>

using namespace std;

// Is-A 와 Has-A 관계 이외에
// 상속을 사용하는 경우는 없다.

class Person
{
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) { }
};

// Is-A 관계
// 
// <학생> => <사람>이다.
class Student : public Person
{
    string studentNo;

public:
    Student(string name, int age, string studentNo) : Person(name, age), studentNo(studentNo) { }
};

int main(int argc, char* argv[])
{
    Student student("KIM", 22, "Computer eng.");

    return 0;
}
