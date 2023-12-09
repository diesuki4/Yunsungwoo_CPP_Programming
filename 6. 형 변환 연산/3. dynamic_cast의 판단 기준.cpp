#include <iostream>

using namespace std;

/*
 * 사실
 * dynamic_cast 가 변환을 막는 기준은
 * 다운 캐스팅이 아니라,
 *
 * 다형적(Polymorphic) 클래스인지 여부다.
 * 
 * 가상 함수를 1개라도 포함하면 다형적 클래스가 되고,
 * 상속 받은 자식도 당연히 다형적 클래스가 된다.
 * 
 * 다형적 클래스라면, dynamic_cast 에서도
 * 다운 캐스팅이 허용된다.
 * 
 * 정리하면, dynamic_cast 에서는
 * 다형적 클래스가 아니면 다운 캐스팅이 막히고,
 * 다형적 클래스면 다운 캐스팅이 허용된다.
 */

class Base
{
public:
    void Show() { cout << "Base" << endl; }
};

class Derived : public Base
{
public:
    void Show() { cout << "Derived" << endl; }
};

class BasePoly
{
public:
    virtual void Show() { cout << "BasePoly" << endl; }
};

class DerivedPoly : public BasePoly
{
public:
    virtual void Show() override { cout << "DerivedPoly" << endl; }
};

class OtherPoly
{
public:
    virtual void Show() { cout << "OtherPoly" << endl; }
};

bool CheckPtr(void* ptr, string message)
{
    bool bResult = (ptr != nullptr);

    cout << (bResult ? "[변환 성공] " : "[변환 실패] ") << message << endl;

    return bResult;
}

int main(int argc, char* argv[])
{
    Base* basePtr;
    Derived* derivedPtr;

    BasePoly* basePolyPtr;
    DerivedPoly* derivedPolyPtr;

    // 업 캐스팅 후
    basePtr = new Derived;

    // 다운 캐스팅
    // 다형적 클래스가 아니므로, 불가능
    // derivedPtr = dynamic_cast<Derived*>(basePtr);

    delete basePtr;
    basePtr = new Base;

    // 다운 캐스팅
    // 다형적 클래스가 아니므로, 불가능
    // derivedPtr = dynamic_cast<Derived*>(basePtr);

    // 업 캐스팅 후
    basePolyPtr = new DerivedPoly;

    // 다운 캐스팅
    // 다형적 클래스이므로, 가능
    derivedPolyPtr = dynamic_cast<DerivedPoly*>(basePolyPtr);
    // 실제 객체가 DerivedPoly 였으므로, 가능
    if (CheckPtr(derivedPolyPtr, "dynamic_cast<DerivedPoly*>(BasePoly* DerivedPoly)")) derivedPolyPtr->Show();

    delete basePolyPtr;
    basePolyPtr = new BasePoly;

    // 다운 캐스팅
    // 실제 객체가 BasePoly 였으므로, 불가능
    derivedPolyPtr = dynamic_cast<DerivedPoly*>(basePolyPtr);
    // nullptr 반환
    if (CheckPtr(derivedPolyPtr, "dynamic_cast<DerivedPoly*>(BasePoly* BasePoly)")) derivedPolyPtr->Show();

    // 신기하게도, 부모-자식 상속 관계가 아니어도
    // 다형적 클래스이기만 하면 동작하긴 한다.
    OtherPoly* otherPolyPtr = new OtherPoly;
    derivedPolyPtr = dynamic_cast<DerivedPoly*>(otherPolyPtr);
    // 그러나, nullptr 이 반환된다.
    if (CheckPtr(derivedPolyPtr, "dynamic_cast<DerivedPoly*>(OtherPoly* OtherPoly)")) derivedPolyPtr->Show();

    // 인자가 다형적 클래스여야 하고
    // 받는 쪽은 아니어도 무관하다.
    derivedPtr = dynamic_cast<Derived*>(otherPolyPtr);
    // nullptr 이 반환된다.
    if (CheckPtr(derivedPtr, "dynamic_cast<Derived*>(OtherPoly* OtherPoly)")) derivedPtr->Show();

    return 0;
}
