#include <iostream>

// 매크로 함수 (전처리기)
// 
// 속도가 빠르다.
//
// 정의가 어렵다.
#define SQUARE_MACRO(x) ((x) * (x))

using namespace std;

// 인라인 함수 (컴파일러)
// 
// 속도가 빠르다.
// 정의가 간편하다.
//
// 데이터 손실이 발생할 수 있다.
// 컴파일러가 거부할 수도 있다.
//
// 함수의 정의가 선언과 같은 파일에 존재해야 한다.
// 컴파일러가 선언이 있는 파일에서 정의를 보고,
// 호출문을 정의의 몸체로 교체해야 하기 때문이다.
// (컴파일러는 파일 단위로 컴파일한다.)
inline int SQUARE_INLINE(int x)
{
    return x * x;
}

// 데이터 손실을 방지하기 위해선, 템플릿을 사용해야 한다.
template <typename T>
inline T SQUARE_INLINE_TEMPLATE(T x)
{
    return x * x;
}

int main(int argc, char* argv[])
{
    cout << SQUARE_MACRO(1.5) << endl;
    cout << SQUARE_INLINE(1.5) << endl;
    cout << SQUARE_INLINE_TEMPLATE(1.5) << endl;

    return 0;
}
