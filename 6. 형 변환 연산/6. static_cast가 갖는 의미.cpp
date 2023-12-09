#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // 구식 C-Style 형 변환은
    // 아래 같은 말도 안 되는 형 변환도 허용한다.

    const int num = 20;

    int* ptr = (int*)&num;
    // const 변수의 값이 변경된다.
    *ptr = 30;

    cout << *ptr << endl;

    // double* 에 int 변수의 주소가 담겼다.
    double* adr = (double*)ptr;

    cout << *adr << endl;

    // static_cast 는 다른 캐스팅과 달리
    // 부모-자식 관계에서의 유연한 형 변환과 함께
    // 기본 타입간의 형 변환도 제공하지만,
    //
    // 위와 같은 말도 안 되는 형 변환을 허용하지는 않는다.

    // const 변수의 주소를 일반 포인터로 변환할 수 없다.
    // ptr = static_cast<int*>(&num);
    const int* ptr2 = static_cast<const int*>(&num);

    // int* 를 double* 로 변환할 수 없다.
    // double* adr = static_cast<double*>(ptr);

    // C-Style 형 변환에 비해
    // static_cast 를 통해서는
    //
    // 상속 관계 혹은 기본 타입에 대한
    // 변환이라는 것을 유추할 수 있다.

    // 이런 의미가 있기 때문에,
    // 기본 자료형에서도 다음과 같은 구식 형 변환보다는
    double result = double(20) / 3;
    // static_cast 를 사용하는 것이 추천된다.
    result = static_cast<double>(20) / 3;

    return 0;
}
