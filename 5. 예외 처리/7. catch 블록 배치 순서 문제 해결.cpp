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
    // 자식 예외일수록 위쪽으로 배치해야 한다.
    catch (CCCException& expt)
    {
        cout << "catch (CCCException& expt)" << endl;
        expt.ShowMessage();
    }
    catch (BBBException& expt)
    {
        cout << "catch (BBBException& expt)" << endl;
        expt.ShowMessage();
    }
    catch (AAAException& expt)
    {
        cout << "catch (AAAException& expt)" << endl;
        expt.ShowMessage();
    }

    return 0;
}
