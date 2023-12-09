#include <iostream>

using namespace std;

class Exception abstract
{
public:
    virtual void ShowMessage() = 0;
    virtual ~Exception() { }
};

class AAAException : Exception
{
public:
    virtual void ShowMessage() override { cout << "AAAException" << endl; }
};

class BBBException : public AAAException
{
public:
    virtual void ShowMessage() override { cout << "BBBException" << endl; }
};

class CCCException : public BBBException
{
public:
    virtual void ShowMessage() override { cout << "CCCException" << endl; }
};

int main(int argc, char* argv[])
{
    int num;

    cin >> num;

    try
    {
        if (num == 0)
            throw AAAException();
        else if (num == 1)
            throw BBBException();
        else if (num == 2)
            throw CCCException();
    }
    // catch 문을 위에서부터 순서대로
    // 처리 가능한지를 확인한다.
    //
    // AAAException <- BBBException <- CCCException
    // 로 상속 관계가 있으므로
    //
    // 모든 예외가 여기에 걸려 버리게 된다.
    catch (AAAException& expt)
    {
        cout << "catch (AAAException& expt)" << endl;
        expt.ShowMessage();
    }
    catch (BBBException& expt)
    {
        cout << "catch (BBBException& expt)" << endl;
        expt.ShowMessage();
    }
    catch (CCCException& expt)
    {
        cout << "catch (CCCException& expt)" << endl;
        expt.ShowMessage();
    }

    return 0;
}
