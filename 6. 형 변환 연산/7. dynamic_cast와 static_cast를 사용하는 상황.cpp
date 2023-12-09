#include <iostream>

using namespace std;

/*
 * 다운 캐스팅에서 인자가
 * 
 * 다형적 클래스가 아니라면,
 * static_cast 만
 * 
 * 다형적 클래스라면,
 * static_cast, dynamic_cast 모두 사용할 수 있다.
 */

/*
 * static_cast 는 기본 타입과
 * 부모-자식 상속 관계에서만
 * 사용 가능한 반면,
 * 
 * dynamic_cast 는
 * 부모-자식 상속 관계가 아니어도
 * 다형적 클래스라면 사용 가능하다.
 */

class BasePoly
{
public:
    virtual void ShowBase() { cout << "BasePoly" << endl; }
};

class DerivedPoly : public BasePoly
{
    int data = 0;

public:
    void ShowDerived() { cout << "DerivedPoly " << data << endl; }
};

bool CheckPtr(void* ptr, string message)
{
    bool bResult = (ptr != nullptr);

    cout << (bResult ? "[변환 성공] " : "[변환 실패] ") << message << endl;

    return bResult;
}

int main(int argc, char* argv[])
{
    // 업 캐스팅 후
    BasePoly* basePolyPtr = new DerivedPoly;

    // 다운 캐스팅
    // 다형적 클래스이므로, 가능
    DerivedPoly* derivedPolyPtr = dynamic_cast<DerivedPoly*>(basePolyPtr);
    // <dynamic_cast 는 반환 값을 통해>
    // <올바른 다운 캐스팅이었는지 확인이 가능하다.>
    if (CheckPtr(derivedPolyPtr, "dynamic_cast<DerivedPoly*>(BasePoly* DerivedPoly)"))
    {
        derivedPolyPtr->ShowBase();
        derivedPolyPtr->ShowDerived();
    }

    // 다운 캐스팅
    derivedPolyPtr = static_cast<DerivedPoly*>(basePolyPtr);
    // <static_cast 는>
    // <올바른 다운 캐스팅이었는지 확인이 불가능하다.>
    derivedPolyPtr->ShowBase();
    derivedPolyPtr->ShowDerived();

    delete basePolyPtr;
    basePolyPtr = new BasePoly;

    // 다운 캐스팅
    derivedPolyPtr = dynamic_cast<DerivedPoly*>(basePolyPtr);
    // 대신, dynamic_cast 는 런 타임에 안전성을 검사하므로
    // 속도가 느린 대신 안전하다.
    if (CheckPtr(derivedPolyPtr, "dynamic_cast<DerivedPoly*>(BasePoly* BasePoly)"))
    {
        derivedPolyPtr->ShowBase();
        derivedPolyPtr->ShowDerived();
    }

    // 다운 캐스팅
    derivedPolyPtr = static_cast<DerivedPoly*>(basePolyPtr);
    // static_cast 는 안전성 검사 없이
    // 무조건 변환이 가능하도록 컴파일 타임에 작성하므로
    // 속도가 빠른 대신 안전하지는 않다.
    derivedPolyPtr->ShowBase();

    // BasePoly 객체로 생성했기 때문에
    // DerivedPoly::data 변수가 메모리에 존재하지 않는다.
    // 
    // 함수는 객체가 아닌, 텍스트 영역에 존재하므로
    // 런 타임 에러가 발생하지는 않지만,
    //
    // 쓰레기 값이 출력된다.
    derivedPolyPtr->ShowDerived();

    return 0;
}
