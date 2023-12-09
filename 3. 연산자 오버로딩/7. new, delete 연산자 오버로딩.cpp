#include <iostream>

using namespace std;

class Point
{
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) { cout << "생성자" << endl; }
    ~Point() { cout << "소멸자" << endl; }

    // new, delete 연산자를 오버로드하면
    // 자동으로 static 처리된다.
    // 
    // 객체 생성 전에 new 함수를 호출할 수 있어야 하고,
    // 소멸자 호출 이후에 delete 함수를 호출할 수 있어야 하기 때문이다.
    // 
    // static void* operator new (size_t size);
    // static void operator delete (void* adr);

    // size 는 컴파일러에 의해 전달된다.
    void* operator new (size_t size)
    {
        cout << "operator new " << size << endl;

        // 바이트 단위이므로, char 로 생성한다.
        return new char[size];
    }

    // 반환형이 void* 이므로,
    // 배열 오버로드 함수도 내용에는 변화가 없다.
    void* operator new [] (size_t size)
    {
        cout << "operator new [" << size << "]" << endl;

        return new char[size];
    }

    void operator delete (void* adr)
    {
        cout << "operator delete" << endl;

        delete [] adr;
    }

    // 마찬가지로, 내용에는 변화가 없다.
    void operator delete [] (void* adr)
    {
        cout << "operator delete []" << endl;

        delete [] adr;
    }
};

int main(int argc, char* argv[])
{
    // new 연산자
    //
    // * 1. 메모리 공간을 할당한다. (이 과정만 오버로드 가능)
    // 2. 생성자를 호출한다.
    // 3. 타입에 맞게 형변환 해 반환한다.
    Point* ptr = new Point(3, 4);

    // delete 연산자
    //
    // 1. 소멸자를 호출한다.
    // * 2. 메모리 공간을 해제한다. (이 과정만 오버로드 가능)
    delete ptr;

    Point* arr = new Point[3];

    delete [] arr;

    return 0;
}
