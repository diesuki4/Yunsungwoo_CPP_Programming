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

/*
 * dynamic_cast
 * 
 * 실제 객체가 자식일 수 있다는 사실을 인정하지 않고,
 * (자식 포인터)부모 포인터
 * 
 * 변환인 다운 캐스팅은 무조건 막는다.
 * 따라서, 안전성이 높다.
 * 
 * 레퍼런스에도 동일하게 사용 가능하다.
 */

int main(int argc, char* argv[])
{
    Car* pCar;
    Truck* pTruck;

    Car* pCar_oTruck = new Truck(80, 200);
    // 다운 캐스팅은 무조건 안 된다.
    // pCar   = dynamic_cast<Truck*>(pCar_oTruck);
    // pTruck = dynamic_cast<Truck*>(pCar_oTruck);
       pCar   = dynamic_cast<Car*>  (pCar_oTruck);
    // 자식 포인터 = 부모 포인터, 안 된다.
    // pTruck = dynamic_cast<Car*>  (pCar_oTruck);

    Car* pCar_oCar = new Car(120);
    // 다운 캐스팅은 무조건 안 된다.
    // pCar   = dynamic_cast<Truck*>(pCar_oCar);
    // pTruck = dynamic_cast<Truck*>(pCar_oCar);
       pCar   = dynamic_cast<Car*>  (pCar_oCar);
    // 자식 포인터 = 부모 포인터, 안 된다.
    // pTruck = dynamic_cast<Car*>  (pCar_oCar);

    Truck* pTruck_oTruck = new Truck(70, 150);
       pCar   = dynamic_cast<Truck*>(pTruck_oTruck);
       pTruck = dynamic_cast<Truck*>(pTruck_oTruck);
       pCar   = dynamic_cast<Car*>  (pTruck_oTruck);
    // 자식 포인터 = 부모 포인터, 안 된다.
    // pTruck = dynamic_cast<Car*>  (pTruck_oTruck);

    // 불가
    // Truck* pTruck_oCar = new Car(150);


    // -------------------------


    Car& rCar = *new Car(10);
    Truck& rTruck = *new Truck(60, 150);

    Car rCar_oTruck = Truck(80, 200);
    // 다운 캐스팅은 무조건 안 된다.
    // rCar   = dynamic_cast<Truck&>(rCar_oTruck);
    // rTruck = dynamic_cast<Truck&>(rCar_oTruck);
       rCar   = dynamic_cast<Car&>  (rCar_oTruck);
    // 자식 참조자 = 부모 참조자, 안 된다.
    // rTruck = dynamic_cast<Car&>  (rCar_oTruck);

    Car& rCar_oCar = *new Car(120);
    // 다운 캐스팅은 무조건 안 된다.
    // rCar   = dynamic_cast<Truck&>(rCar_oCar);
    // rTruck = dynamic_cast<Truck&>(rCar_oCar);
       rCar   = dynamic_cast<Car&>  (rCar_oCar);
    // 자식 참조자 = 부모 참조자, 안 된다.
    // rTruck = dynamic_cast<Car&>  (rCar_oCar);

    Truck& rTruck_oTruck = *new Truck(70, 150);
       rCar   = dynamic_cast<Truck&>(rTruck_oTruck);
       rTruck = dynamic_cast<Truck&>(rTruck_oTruck);
       rCar   = dynamic_cast<Car&>  (rTruck_oTruck);
    // 자식 포인터 = 부모 포인터, 안 된다.
    // rTruck = dynamic_cast<Car&>  (rTruck_oTruck);

    // 불가
    // Truck& rTruck_oCar = *new Car(150);

    return 0;
}
