/*
 * https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file#answer-495056
 */
#include <iostream>
#include "TemplateClass.h"
// 컴파일은 파일 단위로 실행 된다.
// 여기서는 TemplateClass.cpp 의 내용을 모르면
// 각 템플릿 클래스를 만들 수 없다.
//
// 따라서, 구현부인 cpp 파일도 포함시켜 주어야 한다.
#include "TemplateClass.cpp"

using namespace std;

int main(int argc, char* argv[])
{
    Point<int> pos1(2.4, 3.6);       // Point<int> 템플릿 클래스가 만들어지는 시점
    pos1.Func(2);

    Point<double> pos2(2.4, 3.6);    // Point<double> 템플릿 클래스가 만들어지는 시점
    pos2.Func(4.5);

    Point<char> pos3('P', 'F');      // Point<char> 템플릿 클래스가 만들어지는 시점
    pos3.Func('P');

    return 0;
}
