// 0608.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

class CTest
{
    /// +, -, *, /, % : 이항 연산자
    /// ++, -- : 단항 연산자 => 객체++ or ++객체
public:
    int m_Value = 0;

    /// 단항 연산자 ++, --를 구현하기 위해서는 2개의 멤버 함수 필요
    CTest& operator ++ ()
    {
        cout << "Prefix: ";     /// ++객체

        m_Value++;          /// 멤버 변수 값의 증가
        return *this;       /// 자기 자신을 반환
    }

    const CTest& operator ++(int)
    {
        cout << "Postfix: ";    /// 객체++

        CTest t = *this;    /// 현재 자신의 값 입력
        m_Value++;          /// t에 대한 연산이 없음.
        return t;           /// 이전 상태의 t를 반환
    }
};


class CTT
{
public:
    int m_Value = 9;
    /// 선언과 동시에 초기화되어야 하는 멤버가 존재하는 경우
    /// 대입 연산을 수행하려면 반드시 복사 대입 연산자를 선언해야 한다.
    const int m_Const = 1;
    int& m_Ref = m_Value;
    CTT& operator = (const CTT& obj)
    {
        return *this;
    }
};

class CTEST
{
protected:
    int m_Value;
};

class CChild : public CTEST
{
public:
    void Set(int arg)
    {
        m_Value = arg;
    }
};

class ppp
{
private:
    int m_private;
protected:
    int m_protected;
public:
    int m_public;
    void func()
    {
        /// 자기 자신의 멤버이기 때문에 모두 접근 가능!!!
        m_private = 0;
        m_protected = 1;
        m_public = 2;
    }
};

/// 상속 권한은 자식(파생)클래스가 인스턴스화 되었을 때 영향.
/// 상속된 클래스 내부에서는 원래 권한대로 접근이 가능
class child1 : public ppp
{
public:
    void aaa()
    {
        /// 상속 권한과 관계 없이 부모 멤버들에 접근이 가능!!!
        m_public = 10;
        m_protected = 120;
        func();
        //m_private = 0;
        printf("%d - %d\n", m_public, m_protected);
    }
};


int main()
{
    child1 c1;
    c1.aaa();

    CTEST ctt;
    //ctt.m_Value = 1;
    CChild& c = (CChild&)ctt;
    c.Set(3);


    CTT ct;
    CTT ct1;
    ct1 = ct;

    int a = 9;
    a++;        /// a = 10;
    ++a;        /// a = 11;

    /// 특이한 연산자 중복
    CTest t1, t2;
    
    cout << (++t1).m_Value << endl;
    cout << (t2++).m_Value << endl;     /// t2는 0이 출력
    cout << t2.m_Value << endl;

    std::cout << "Hello World!\n";
}
