#include <iostream>

using namespace std;

class AAA
{
    int *pData;

public:
    AAA(int data) : pData(new int(data)) { cout << "AAA" << data << "::생성자" << endl; }

    ~AAA() { cout << "AAA" << *pData << "::소멸자" << endl; delete pData; }

    int GetData() const { return *pData; }
};

class SmartPtr
{
    AAA* ptr;

public:
    SmartPtr(AAA* ptr) : ptr(ptr) { cout << "SmartPtr" << ptr->GetData() << "::생성자" << endl; }

    // 스마트 포인터는
    // 역참조와 화살표 연산자를
    // 
    // 필수로 구현해야 한다.
    AAA& operator* ()  { return *ptr; }
    AAA* operator-> () { return ptr; }

    // 자신의 생명주기가 끝날 때
    // 갖고 있는 Raw 포인터를 해제한다.
    //
    // auto_ptr 이 이런 방식으로 동작한다.
    ~SmartPtr() { cout << "SmartPtr" << ptr->GetData() << "::소멸자" << endl; delete ptr; }
};

int main(int argc, char* argv[])
{
    // 스마트 포인터는 객체다.
    SmartPtr smPtr1(new AAA(1));
    SmartPtr smPtr2(new AAA(2));
    SmartPtr smPtr3(new AAA(3));

    cout << (*smPtr1).GetData() << " ";
    cout << smPtr2->GetData() << " ";
    cout << smPtr3->GetData() << endl;

    // SmartPtr 의 생명주기가 끝나면서
    // AAA 의 소멸자를 함께 호출한다.

    return 0;
}
