#include <iostream>

using namespace std;

class Person
{
public:
    void Sleep()
    {
        cout << "Sleep" << endl;
    }
};

// Person 직접 상속
class Student : public Person
{
public:
    void Study()
    {
        cout << "Study" << endl;
    }
};

// Person 간접 상속
class PartTimeStudent : public Student
{
public:
    void Work()
    {
        cout << "Work" << endl;
    }
};

int main(int argc, char* argv[])
{
    // 부모의 포인터로 자식 객체를 가리킬 수 있다.
    //
    // Is-A 관계의 개념으로 인해 허용한 것이다.
    Person* person_Student = new Student();
    Person* person_PartTimeStudent = new PartTimeStudent();
    Student* student_PartTimeStudent = new PartTimeStudent();

    person_Student->Sleep();
    person_PartTimeStudent->Sleep();
    student_PartTimeStudent->Study();

    delete person_Student;
    delete person_PartTimeStudent;
    delete student_PartTimeStudent;

    return 0;
}
