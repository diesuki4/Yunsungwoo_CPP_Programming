#include <iostream>

using namespace std;

class Number
{
    int num;

public:
    Number(int num = 0) : num(num) { cout << "생성자(" << num << ")" << endl; }

    Number& operator= (const Number& ref)
    {
        cout << "대입 연산자" << endl;

        num = ref.num;

        return *this;
    }

    // 형 변환 연산자는 상황에 따라
    // 알아서 호출되기 때문에
    //
    // 반환 형을 명시하지 않는다.
    //
    // int 로 변환되야 하는 상황에
    // float 을 반환하는 건 말이 안 되기 때문
    operator int ()
    {
        return num;
    }

    void Show() { cout << num << endl; }

    ~Number() { cout << "~소멸자(" << num << ")" << endl; }
};

int main(int argc, char* argv[])
{
    Number num1;

    // int -> Number 객체로의 자동 형 변환
    // 
    // num = Number(10);
    num1 = 10;

    // + 연산자가 오버로드 되어 있지 않으므로
    // 다음이 가능하기 위해선
    //
    // num1 이 int 로 변환되어야 한다.

    // Number 객체 -> int 로의 형 변환
    //
    // Number num2 = (int)num1 + 20;
    Number num2 = num1 + 20;

    num2.Show();

    return 0;
}
