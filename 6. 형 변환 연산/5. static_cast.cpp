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

class Other
{
public:
    void ShowOtherState()
    {
        cout << "상속 관계가 아닌 클래스" << endl;
    }
};

/*
 * static_cast
 *
 * 실제 객체가 자식일 수 있다는 사실을 인정하고,
 * (자식 포인터)부모 포인터
 *
 * 변환인 다운 캐스팅도 허용한다.
 * 따라서, dynamic_cast 에 비해
 * 유연하지만 안전성은 낮다.
 *
 * 가능하면 제한적으로 사용해야 한다.
 *
 * 레퍼런스에도 동일하게 사용 가능하다.
 */

int main(int argc, char* argv[])
{
    Car* pCar;
    Truck* pTruck;

    Car* pCar_oTruck = new Truck(80, 200);
    // 다운 캐스팅을 허용한다.
    pCar = static_cast<Truck*>(pCar_oTruck);
    pTruck = static_cast<Truck*>(pCar_oTruck);
    pCar = static_cast<Car*>  (pCar_oTruck);
    // 자식 포인터 = 부모 포인터, 안 된다.
    // pTruck = static_cast<Car*>  (pCar_oTruck);

    Car* pCar_oCar = new Car(120);
    // 다운 캐스팅을 허용한다.
    pCar = static_cast<Truck*>(pCar_oCar);
    pTruck = static_cast<Truck*>(pCar_oCar);
    pCar = static_cast<Car*>  (pCar_oCar);
    // 자식 포인터 = 부모 포인터, 안 된다.
    // pTruck = static_cast<Car*>  (pCar_oCar);

    Truck* pTruck_oTruck = new Truck(70, 150);
    pCar = static_cast<Truck*>(pTruck_oTruck);
    pTruck = static_cast<Truck*>(pTruck_oTruck);
    pCar = static_cast<Car*>  (pTruck_oTruck);
    // 자식 포인터 = 부모 포인터, 안 된다.
    // pTruck = static_cast<Car*>  (pTruck_oTruck);

    // 불가
    // Truck* pTruck_oCar = new Car(150);


    // -------------------------


    Car& rCar = *new Car(10);
    Truck& rTruck = *new Truck(60, 150);

    Car rCar_oTruck = Truck(80, 200);
    // 다운 캐스팅을 허용한다.
    rCar = static_cast<Truck&>(rCar_oTruck);
    rTruck = static_cast<Truck&>(rCar_oTruck);
    rCar = static_cast<Car&>  (rCar_oTruck);
    // 자식 참조자 = 부모 참조자, 안 된다.
    // rTruck = static_cast<Car&>  (rCar_oTruck);

    Car& rCar_oCar = *new Car(120);
    // 다운 캐스팅을 허용한다.
    rCar = static_cast<Truck&>(rCar_oCar);
    rTruck = static_cast<Truck&>(rCar_oCar);
    rCar = static_cast<Car&>  (rCar_oCar);
    // 자식 참조자 = 부모 참조자, 안 된다.
    // rTruck = static_cast<Car&>  (rCar_oCar);

    Truck& rTruck_oTruck = *new Truck(70, 150);
    rCar = static_cast<Truck&>(rTruck_oTruck);
    rTruck = static_cast<Truck&>(rTruck_oTruck);
    rCar = static_cast<Car&>  (rTruck_oTruck);
    // 자식 포인터 = 부모 포인터, 안 된다.
    // rTruck = static_cast<Car&>  (rTruck_oTruck);

    // 불가
    // Truck& rTruck_oCar = *new Car(150);


    // -------------------------


    // 상속 관계가 아니므로, 사용 불가
    // Other* pOther = static_cast<Other*>(pTruck_oTruck);

    return 0;
}
