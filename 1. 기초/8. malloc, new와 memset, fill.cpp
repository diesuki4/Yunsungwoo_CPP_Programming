#include <iostream>
#include <cstdlib>

using namespace std;

// 둘 다 쓰레기 값이 저장된다.
//
// memset()
// value가 내부적으로는 int -> unsigned char로 동작
// 그래서 0으로만 초기화 가능
// 2 Byte가 넘어가는 int, long long 등에서 오버플로우가 발생
// Low-level에서 동작하므로 빠르다.
// 
// fill()
// 특정 값으로 초기화할 수 있다.
// 오버플로우가 없어 안전하다.
// for문과 비슷한 방식이므로 느리다.

int main(int argc, char* argv[])
{
    const int SIZE = 3;

    // ------- malloc -------
    // 
    // 인자로 Byte 크기를 받는다.
    // 반환형이 void 라서 캐스팅이 필요하다.
    // 생성자를 호출해주지 않는다.
    //
    // realloc을 통해 크기 변경이 가능하다.

    int* mallocPtr = (int*)malloc(sizeof(int) * SIZE);
    memset(mallocPtr, 0, sizeof(int) * SIZE);

    for (int i = 0; i < SIZE; ++i)
        cout << mallocPtr[i] << " ";
    cout << endl;

    // 소멸자를 호출하지 않는다.
    free(mallocPtr);
    mallocPtr = nullptr;

    // ------- new --------
    //
    // 인자로 자료형의 개수를 받는다.
    // 캐스팅이 필요 없다.
    // 할당과 동시에 초기화가 가능하다.
    // 생성자를 호출해준다.
    // 
    // 크기 변경이 불가능하다.

    // 0으로 초기화
    // int* newPtr = new int[SIZE]();

    int* newPtr = new int[SIZE]{1, 2, 3};

    for (int i = 0; i < SIZE; ++i)
        cout << newPtr[i] << " ";
    cout << endl;

    // 다음과 같이 크기를 생략할 수도 있다.
    char* pStr = new char[]{"char* pStr"};

    cout << pStr << endl;

    // 소멸자를 호출한다.
    delete [] newPtr;
    delete [] pStr;
    // 이미 해제된 메모리를 가리키는
    // <댕글링 포인터>를 방지한다.
    newPtr = nullptr;
    pStr = nullptr;

    return 0;
}
