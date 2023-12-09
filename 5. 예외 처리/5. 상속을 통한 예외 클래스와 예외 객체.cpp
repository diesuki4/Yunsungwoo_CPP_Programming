#include <iostream>
#include <cstring>

using namespace std;

// 예외 클래스를 정의해
// 예외를 객체로 전달하면
//
// 발생 원인에 대한
// 더 다양한 정보들을 담을 수 있다.

// 여러 예외들을 묶기 위한
// 추상 클래스
class Exception abstract
{
public:
    virtual void ShowMessage() = 0;
    virtual ~Exception() { }
};

class DepositException : public Exception
{
    int reqDep;

public:
    DepositException(int money) : reqDep(money) { }

    virtual void ShowMessage() override
    {
        cout << "[예외] " << reqDep << "원 입금 불가" << endl;
    }
};

class WithdrawException : public Exception
{
    int    balance;

public:
    WithdrawException(int money) : balance(money) { }

    virtual void ShowMessage() override
    {
        cout << "[예외] 잔액 " << balance << "원, 출금 불가" << endl;
    }
};

class Account
{
    string accNum;
    int    balance;

public:
    Account(string acc, int money) : accNum(acc), balance(money) { }

    // DepositException 이 Exception 을 상속하므로
    // 다음과 같이 예외 명시가 가능하다.
    void Deposit(int money) throw (Exception)
    {
        cout << money << "원 입금 요청" << endl;

        if (money <= 0)
            // 예외를 객체로 전달한다.
            throw DepositException(money);

        balance += money;
    }

    // WithdrawException 이 Exception 을 상속하므로
    // 다음과 같이 예외 명시가 가능하다.
    void Withdraw(int money) throw (Exception)
    {
        cout << money << "원 출금 요청" << endl;

        if (balance < money)
            // 예외를 객체로 전달한다.
            throw WithdrawException(balance);

        balance -= money;
    }

    void ShowMoney()
    {
        cout << "잔액: " << balance << "원" << endl;
    }
};

int main(int argc, char* argv[])
{
    Account myAcc("56789-827120", 5000);

    myAcc.ShowMoney();

    try
    {
        myAcc.Deposit(2000); myAcc.ShowMoney();
        myAcc.Deposit(-300); myAcc.ShowMoney();
    }
    // DepositException 이 Exception 을 상속하므로
    // Exception 객체의 레퍼런스로 전달 받을 수 있다.
    catch (Exception& expt)
    {
        // 더 자세한 원인 파악이 가능하다.
        expt.ShowMessage();
    }

    try
    {
        myAcc.Withdraw(3000); myAcc.ShowMoney();
        myAcc.Withdraw(4500); myAcc.ShowMoney();
    }
    // WithdrawException 이 Exception 을 상속하므로
    // Exception 객체의 레퍼런스로 전달 받을 수 있다.
    catch (Exception& expt)
    {
        // 더 자세한 원인 파악이 가능하다.
        expt.ShowMessage();
    }

    return 0;
}
