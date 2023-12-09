#include <iostream>

using namespace std;

class AAA
{
public:
    // 클래스 변수
    //
    // 클래스의 객체들이 공유하는 변수가 된다.
    // 객체를 생성하지 않아도 메모리에 존재한다.
    static int objCnt;

    // const 클래스 변수는 선언과 동시에 초기화가 가능하다.
    const static int SIZE = 5;

    // mutable 키워드를 붙이면
    // const 함수 내에서 예외적으로
    // 값을 변경할 수 있게 된다.
    //
    // const 개념을 무시하기 때문에
    // 가능한 사용하지 않는 것이 좋다.
    mutable int mtNum;

    int data;

    AAA()
    {
        cout << ++objCnt << "번째 객체 생성" << endl;
    }

    void IncreaseCnt()
    {
        data = 0;
        ++objCnt;
    }

    // 클래스 함수는 객체 생성 유무와 관계 없이 존재한다.
    static void DecreaseCnt()
    {
        // 클래스 함수 내에서는 클래스 변수만 사용할 수 있다.
        // 
        // 객체의 값에 접근할 수 없다.
        // data = 0;
        --objCnt;

        // 클래스 함수만 사용할 수 있다.
        // 
        // 함수를 통해 객체의 값에 접근해서는 안 된다.
        // IncreaseCnt();
    }

    void ChangeNum(int data) const
    {
        // const 함수 내에서도
        // 값을 변경할 수 있다.
        mtNum = data;
    }
};

// 매 생성자 호출마다 값을 초기화할 이유가 없기 때문에
// 별도의 초기화 문법을 제공한다.
int AAA::objCnt = 0;

int main(int argc, char* argv[])
{
    AAA a1;
    AAA a2;
    AAA a3;

    // 객체가 아닌, 클래스의 변수이다.
    cout << "총 객체 수: " << AAA::objCnt << endl;
    // 객체로 접근하는 것도 가능하긴 하다.
    cout << "총 객체 수: " << a1.objCnt << endl;

    // 객체가 아닌, 클래스의 함수이다.
    AAA::DecreaseCnt();
    // 객체로 접근하는 것도 가능하긴 하다.
    a1.DecreaseCnt();

    return 0;
}
