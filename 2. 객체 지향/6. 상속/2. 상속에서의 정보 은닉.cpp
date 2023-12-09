#include <iostream>

using namespace std;

class Person
{
    string name;
    int age;

public:
    // 원칙: 클래스의 멤버는 해당 클래스의 생성자를 통해 초기화해야 한다.
    Person(string name, int age) : name(name), age(age) { }

    void ShowInfo() { cout << name << " " << age << endl; }
};

class UniversityStudent : public Person
{
    string major;

public:
    UniversityStudent(string name, int age, string major)
    // 생성자의 구현부에서 직접 부모의 멤버를 초기화하지 말고,
    // 멤버 이니셜라이저를 통해 부모의 생성자를 호출하는 것이 좋다.
    //
    // 멤버 이니셜라이저에서도 부모의 private 멤버를 직접 초기화할 수는 없다.
    // : name(name), age(age)
    : Person(name, age)
    , major(major) { }

    void ShowStudentInfo()
    {
        // 접근 제한자는 클래스 단위로 적용된다.
        //
        // private 이라고 상속이 안 되는 것이 아니다.
        // 멤버 이니셜라이저를 통해 초기화가 됐으니 상속이 되긴 했지만,
        // 자식에서는 접근이 불가능할 뿐이다.
        //
        // 정보 은닉은 부모-자식 관계에서도 적용된다.

        // cout << name << " " << age << endl;
        ShowInfo();
    }
};

int main(int argc, char* argv[])
{
    UniversityStudent student1("KIM", 22, "Computer eng.");
    UniversityStudent student2("LEE", 23, "Electronic eng.");

    student1.ShowInfo();
    student2.ShowStudentInfo();

    return 0;
}
