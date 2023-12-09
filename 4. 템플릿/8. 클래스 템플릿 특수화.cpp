#include <iostream>

using namespace std;

template <typename T>
class Point
{
    T x, y;

public:
    Point(T x, T y) : x(x), y(y) { }

    void ShowPosition() const
    {
        cout << '[' << x << ", " << y << ']' << endl;
    }
};

// 클래스 템플릿
template <typename T>
class DataWrapper
{
private:
    T data;
public:
    DataWrapper(T data) : data(data) { }

    void ShowData()
    {
        cout << "Data: " << data << endl;
    }
};

// 클래스 템플릿 특수화
template <>
class DataWrapper<string>
{
    string data;

public:
    DataWrapper(string data) : data(data) { }

    // 특정 템플릿 클래스에
    // 다른 동작을 정의할 수 있다.
    void ShowData()
    {
        cout << "String: " << data << ", Length: " << data.length() << endl;
    }
};

// 클래스 템플릿 특수화
template <>
class DataWrapper<Point<int>>
{
    Point<int> data;

public:
    DataWrapper(int x, int y) : data(x, y) { }

    // 특정 템플릿 클래스에
    // 다른 동작을 정의할 수 있다.
    void ShowData()
    {
        data.ShowPosition();
    }
};

int main(int argc, char* argv[])
{
    DataWrapper<int> iWrap(170);
    iWrap.ShowData();

    DataWrapper<string> sWrap("Class Template Specialization");
    sWrap.ShowData();

    DataWrapper<Point<int>> posWrap(3, 7);
    posWrap.ShowData();

    return 0;
}
