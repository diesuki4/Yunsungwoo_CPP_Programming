#include <iostream>

using namespace std;

// C++에서 구조체와 클래스의 유일한 차이는 기본 접근 지정자다.
//
// 이것은 멤버 뿐만 아니라, 상속에서도 적용된다.
//
// 구조체 (public 기본)
// 클래스 (private 기본) (은닉화 때문)
//
// 구조체도 상속이 가능하다.

struct Car
{
    int fuelGauge;
    int curSpeed;

    // 구조체, 클래스 내부에 정의된 함수는
    // 자동으로 inline 처리된다.
    void ShowCarState()
    {
        cout << "fuelGauge: " << fuelGauge << endl;
        cout << "curSpeed: " << curSpeed << endl;
    }

    void Accel();
};

// 자동으로 inline 처리되지 않는다.
void Car::Accel()
{
    curSpeed += 10;
}

int main(int argc, char* argv[])
{
    // 구조체, 클래스 둘 다 new를 사용하지 않으면 Stack에 할당된다.
    Car stackCar;

    // malloc이나 new를 사용하면 Heap에 할당된다.
    Car *heapCar = new Car;

    delete heapCar;
    heapCar = nullptr;

    return 0;
}
