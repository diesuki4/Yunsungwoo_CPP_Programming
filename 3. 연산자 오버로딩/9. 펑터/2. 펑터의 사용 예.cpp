#include <iostream>
#include <algorithm>

using namespace std;

// 펑터는 함수나 객체의 동작 방식에
// 유연함을 제공할 때 사용된다.

// 추상 클래스
class SortRule
{
public:
    // 순수 가상 함수
    virtual bool operator() (int A, int B) const = 0;
};

class AscendingRule : public SortRule
{
public:
    // 실제로 호출되는 오버로드 함수
    bool operator() (int A, int B) const { return A > B; }
};

class DescendingRule : public SortRule
{
public:
    // 실제로 호출되는 오버로드 함수
    bool operator() (int A, int B) const { return A < B; }
};

// 정렬 방식을 함수 객체로 정의해
// 어떤 방식을 전달하느냐에 따라
//
// 동작이 달라지도록 했다.
void BubbleSort(int arr[], const SortRule& functor)
{
    const size_t size = 5;

    for (int i = 0; i < (size - 1); ++i)
        for (int j = 0; j < (size - 1) - i; ++j)
            // 객체를 함수처럼 사용될 수 있게 했다.
            if (functor(arr[j], arr[j + 1]))
                swap(arr[j], arr[j + 1]);
}

void Show(int arr[])
{
    const size_t size = 5;

    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

int main(int argc, char* argv[])
{
    int arr[] = {5, 1, 4, 2, 3};

    BubbleSort(arr, AscendingRule());
    Show(arr);

    BubbleSort(arr, DescendingRule());
    Show(arr);

    return 0;
}
