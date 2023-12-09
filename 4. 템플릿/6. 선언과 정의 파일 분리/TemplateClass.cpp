#include <iostream>
#include "TemplateClass.h"

using namespace std;

template <typename T>
Point<T>::Point(T x, T y) : x(x), y(y)
{
    cout << x << ", " << y << endl;
}

template <typename T>
T Point<T>::Func(const T& ref)
{
    return ref;
}
