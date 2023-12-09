#include <iostream>

using namespace std;

class Number
{
    int num;

public:
    // 생성자가 int 를 받을 수 있기 때문에
    // 다음이 가능하다.
    // 
    // Number n = 10;
    // Number n = Number(10);
    Number(int num = 0) : num(num) { cout << "생성자(" << num << ")" << endl; }

    Number& operator= (const Number& ref)
    {
        cout << "대입 연산자" << endl;

        num = ref.num;

        return *this;
    }

    void Show() { cout << num << endl; }

    ~Number() { cout << "~소멸자(" << num << ")" << endl; }
};

int main(int argc, char* argv[])
{
    Number num;

    // Number 의 생성자는
    // int 를 인자로 받을 수 있으므로
    // 
    // <임시 객체로의 자동 형 변환>이 진행되고,
    // 대입 연산자가 호출된다.
    // 
    // num = Number(10);
    num = 10;

    // 임시 객체는 다음 라인에
    // 바로 소멸한다.

    num.Show();

    return 0;
}
