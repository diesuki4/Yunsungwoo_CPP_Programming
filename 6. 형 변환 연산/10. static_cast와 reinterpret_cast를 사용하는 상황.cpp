#include <iostream>

using namespace std;

// void* 는 어떤 포인터도 받을 수 있다.
// void* 를 반환할 수도 있다.
void* Func(void* ptr) { return ptr; }

class AAA { };

int main(int argc, char* argv[])
{
    int *iptr = nullptr;

    // static_cast 는 변환 가능성이 있지만
    // <안전하진 않을 수 있는> 상황에 사용한다.
    iptr = static_cast<int*>(Func(iptr));
    // 따라서, void* 의 변환은
    // static_cast 를 사용하는 것이 좋다.
    AAA *aptr = static_cast<AAA*>(Func(iptr));

    // reinterpret_cast 는 포인터 관련 연산에서
    // <안전하지 않은> 상황에 사용한다.
    AAA* aptr = reinterpret_cast<AAA*>(iptr);
    double* dptr = reinterpret_cast<double*>(aptr);
    // 혹은 바이트 단위로 메모리 값을 확인해야 할 때
    char* cptr = reinterpret_cast<char*>(aptr);

    return 0;
}
