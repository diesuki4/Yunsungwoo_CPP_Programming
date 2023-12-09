#include <iostream>

using namespace std;

// 정보 은닉성을 훼손하는 기법이므로
// 가급적 사용하지 않는 것이 좋다.
//
// 연산자 오버로딩 때만 유용

enum class EMind
{
    LOVE,
    HATE
};

// 클래스 전방 선언
class Boy;

class OtherGirl
{
public:
    // 함수가 친구로 인정 받았으므로, 함수 내에서는 private 멤버 접근 가능
    // 
    // 현 상황에서는 Boy:mind 의 존재 여부를 모르므로
    // 구현부를 여기 작성하면 안 된다.
    void CheckMind(const Boy& boy);
};

class Boy
{
    // Girl 클래스를 친구로 인정했으므로
    // Girl 클래스에서는 Boy의 속을 들여다 볼 수 있다.
    friend class Girl;
    // 함수 단위로 친구로 인정할 수도 있다.
    //
    // 여기서는 OtherGirl::CheckMind() 의 존재 여부를 알고 있다.
    friend void OtherGirl::CheckMind(const Boy& boy);

    EMind mind = EMind::LOVE;

public:
    void CheckMind(const Girl& girl)
    {
        // Girl 은 자신을 친구로 인정하지 않았으므로, private 멤버에 접근 불가
        // if (girl.mind == EMind::LOVE)
        cout << "I LOVE YOU" << endl;
    }
};

class Girl
{
    EMind mind = EMind::LOVE;

public:
    void CheckMind(const Boy& boy)
    {
        // 클래스가 친구로 인정 받았으므로, private 멤버 접근 가능
        if (boy.mind == EMind::LOVE)
            cout << "I LOVE YOU, TOO" << endl;
        else
            cout << "I HATE YOU, TOO" << endl;
    }
};

// 여기서는 Boy::mind 의 존재 여부를 알고 있다.
void OtherGirl::CheckMind(const Boy& boy)
{
    if (boy.mind == EMind::LOVE)
        cout << "I HATE YOU" << endl;
    else
        cout << "I LOVE YOU" << endl;
}

int main(int argc, char* argv[])
{
    Boy boy;
    Girl girl;
    OtherGirl otherGirl;

    boy.CheckMind(girl);
    girl.CheckMind(boy);
    otherGirl.CheckMind(boy);

    return 0;
}
