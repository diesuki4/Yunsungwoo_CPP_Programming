#include <iostream>

using namespace std;

class Car
{
    int fuelGauge;

public:
    Car(int fuel) : fuelGauge(fuel) { }

    void ShowCarState()
    {
        cout << "잔여 연료량: " << fuelGauge << endl;
    }
};

class Truck : public Car
{
    int freightWeight;

public:
    Truck(int fuel, int weight) : Car(fuel), freightWeight(weight) { }

    void ShowTruckState()
    {
        ShowCarState();
        cout << "화물의 무게: " << freightWeight << endl;
    }
};

// 업 캐스팅
// (부모 포인터)자식 포인터
//
// 다운 캐스팅
// (자식 포인터)부모 포인터

int main(int argc, char* argv[])
{
    Car* pcar1 = new Truck(80, 200);

    // 실제 객체가 자식인 Truck 이라서 동작하긴 하지만,
    // 다운 캐스팅은 적절치 못 한 방법이다.
    Truck* ptruck1 = (Truck*)pcar1;
    ptruck1->ShowTruckState();
    cout << endl;

    Car* pcar2 = new Car(120);

    // 실제 객체가 부모인 Car 이기 때문에
    // 무조건 문제가 발생한다.
    Truck* ptruck2 = (Truck*)pcar2;
    ptruck2->ShowTruckState();

    // 말도 안 되는 변환이지만, 가능하긴 하다.
    // Car 의 첫 4바이트에 위치한 Car::fuelGauge 가 출력된다.
    int* p = (int*)pcar1;
    cout << *p << endl;

    return 0;
}
