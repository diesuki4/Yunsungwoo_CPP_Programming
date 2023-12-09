#include <iostream>

using namespace std;

class Clamper
{
    // 정보 은닉
    // 
    // 멤버 변수를 private으로 선언하고
    // 접근 함수를 별도로 정의해서
    // 안전하게 변수의 접근을 유도하는 것
    // 
    // 은닉이 제대로 되지 않으면
    // 무결성이 훼손된다.
public:
    int min;    // 500
    int max;    // 100

    int clamp(int val)
    {
        if (val < min)
            return min;
        else if (max < val)
            return max;
        else
            return val;
    }

    int GetMin() { return min; }
    int GetMax() { return max; }

    void ShowMinMax() const
    {
        // 클래스의 const 함수 내에서는
        // const가 아닌 클래스 함수는 호출할 수 없다.
        // 멤버 변수 값이 변경되면 안 되기 때문
        // cout << GetMin() << " " << GetMax() << endl;
        cout << min << " " << max << endl;
    }

    void SetMin(const Clamper& clamper)
    {
        // const 레퍼런스를 이용하면
        // 클래스의 const 함수만 호출이 가능하다.
        // 내부에서 값이 변경되면 안 되기 때문
        // min = clamper.GetMin();
    }
};

int main(int argc, char* argv[])
{
    Clamper clamper1{500, 100};

    // const 객체는 const 멤버 함수만 호출할 수 있다.
    const Clamper clamper2;

    // 내부에서 값이 변경되면 안 되기 때문
    // clamper2.GetMin();

    return 0;
}
