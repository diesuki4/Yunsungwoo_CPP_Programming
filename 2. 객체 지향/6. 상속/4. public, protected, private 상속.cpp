#include <iostream>

using namespace std;

class AAA
{
private:   int prv  = 0;
protected: int prot = 0;
public:    int pub  = 0;
};

// 다중 상속 같은 특수한 경우가 아니라면,
// 대부분 public 으로 상속한다.
class BBB : public AAA
{
/*
접근 불가:  int prv;
protected: int prot;
public:    int pub;
*/
};

class CCC : protected AAA
{
/*
접근 불가:  int prv;
protected: int prot;
protected: int pub;
*/
};

class DDD : private CCC
{
/*
접근 불가:  int prv;
private:   int prot;
private:   int pub;
*/
};

int main(int argc, char* argv[])
{
    AAA a;
    BBB b;
    CCC c;
    DDD d;

    cout << a.pub << endl;
    // cout << a.prot << endl;
    cout << b.pub << endl;
    // cout << c.pub << endl;
    // cout << d.pub << endl;

    return 0;
}
