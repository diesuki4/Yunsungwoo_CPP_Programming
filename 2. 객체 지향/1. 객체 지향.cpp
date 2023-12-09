#include <iostream>

using namespace std;

// 객체 지향 프로그래밍
//
// 현실에 존재하는 대상과 행동을 실체화 시키는 형태의 프로그래밍
// 객체는 멤버 변수인 <상태>, 멤버 함수인 <행동>으로 구성된다.
//
// (나)가 (과일장수)에게 (사과)를 [샀다]
class Seller
{
    int numApple = 10;
    int money = 0;
    const int PRICE = 100;

public:
    int SellApples(int money)
    {
        int num = money / PRICE;
        numApple -= num;
        this->money += money;

        return num;
    }
};

class Buyer
{
    int numApple = 0;
    int money = 300;

public:
    void BuyApples(Seller& seller, int money)
    {
        // 메시지 패싱 (Message Passing)
        // 판매자님 사과 money원어치 주세요.
        numApple += seller.SellApples(money);
        this->money -= money;
    }
};

int main(int argc, char* argv[])
{
    Seller seller;
    Buyer buyer;

    buyer.BuyApples(seller, 200);
    
    return 0;
}
