#include <iostream>

using namespace std;

class Car { };
class Person { };

/*
 * reinterpret_cast
 *
 * 포인터 혹은 포인터와 관련된 모든 형 변환을
 * 허용한다.
 *
 * 포인터 관련 변환만 허용한다는 점에서
 * 구식 C-Style 변환과는 차이가 있다.
 *
 * 레퍼런스에도 동일하게 사용 가능하다.
 */

int main(int argc, char* argv[])
{
    // 말도 안 되지만
    // 포인터 변환이므로 허용한다.
    Car* pCar = new Car;
    Person *pPer = reinterpret_cast<Person*>(pCar);

    // C-Style, static_cast 와 달리
    // 기본 타입 변환은 포인터가 아니므로
    // 허용하지 않는다.
    // 
    // float f = reinterpret_cast<float>(50);

    int num = 0x00010203;
    // 포인터 변환
    char* ptr = reinterpret_cast<char*>(&num);

    for (int i = 0; i < sizeof(num); ++i)
        cout << static_cast<int>(ptr[i]) << endl;

    num = 50;
    // x64 모드에서는 int* 크기는 8, int 크기는 4이므로
    // x86 모드에서 실행해야 한다.
    int* ptr2 = &num;

    // 포인터 값을 정수로 변환할 수 있다.
    int adr = reinterpret_cast<int>(ptr2);
    cout << "num 주소: 0x" << hex << adr << endl;

    // 정수를 포인터 주소로 변환할 수 있다.
    int* ptr3 = reinterpret_cast<int*>(adr);
    cout << "num 값: " << *ptr3 << endl;

    return 0;
}
