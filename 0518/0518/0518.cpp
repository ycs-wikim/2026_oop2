// 0518.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class CTest
{
public:
    /// 상수 멤버 변수 선언
    /// 상수는 반드시 선언과 동시에 초기화가 수행되어야 한다.
    const int m_const = 10;         /// O
    //const int m_Con;                /// X

    /// 예제 9-6의 멤버 데이터 초기화

    /// 멤버 변수. 초기화가 수행되지 않은 변수는 인스턴스 생성 후 쓰레기 값
    /// 따라서 인스턴스 생성 후에는 반드시 초기화해서 사용해야 한다.
    int m_x;
    /// 멤버 변수. 초기화를 수행했기 때문에 인스턴스화하면 지정된 값이 할당.
    int m_I = 1;
    /// 멤버 상수. 초기화를 수행했고, 인스턴스화 이후 값의 변경이 불가능.
    const int m_CI = 2;
    /// 정적 멤버 변수. 클래스의 인스턴스화와 관계 없이 메모리에 존재.
    /// 프로그램 실행 즉시 메모리에 적재가 되어 있는 상태.
    /// 인스턴스화 없이도 사용 가능한 변수.
    /// 초기화가 되어 있지 않은 정적 멤버 변수라면 인스턴스화가 될 수 없다.
    /// 정적 멤버 변수는 반드시 초기화해야 사용 및 접근이 가능해진다.
    /// 외부에서 정적 멤버 변수 값을 접근하는 방법
    ///     ==> 클래스이름::멤버변수이름
    /// 정적 멤버 변수는 클래스에서 선언과 동시에 초기화가 불가능!!!
    //static int s_I = 9;      /// XXX 오류 발생으로 안됨.
                               /// 이미 존재하는 변수를 다시 선언하는 것과 동일
    static int s_I;
    /// static보다 const가 우선하기 때문에 선언 즉시 초기화가 가능
    /// 변수의 성질을 const가 결정하여 상수가 되었기 때문에 #define과 동일.
    static const int s_CI = 4;

    double m_D = 1.1;
    const double m_CD = 2.2;
    static double s_D;
    static const double s_CD;

    int m;
    /// this 포인터 : 항상 자기 자신을 가리키는 상수 포인터
    ///     인스턴스화 되었을 때, 자기 자신의 시작 위치 주소를 갖는 포인터
    ///     클래스 내부에서만! 사용이 가능한 예약어
    ///     클래스의 멤버를 정확하게 지칭할 때 사용
    void asdf(int m)
    {
        /// this->m은 멤버 변수 m
        this->m = 90;
        /// 인수/매개 변수 m
        m = 90;
        printf("%p\n", this);
    }

    /// 정적 멤버 함수 : 인스턴스화와 관계 없이 메모리에 이미 존재하는 상태
    ///         동일한 특성을 갖는 정적 멤버 변수는 내부에서 사용/접근 가능
    ///         비정적 멤버는 내부에서 사용 불가!!!
    static void notThis(int m)
    {
        /// 인스턴스화 되지 않은 상태에서 메모리 접근을 시도 : this 사용 불가
        //this->m = 90;
        m = 90;
        /// 동일한 정적 멤버는 사용이 가능!
        s_I = 999;
        /// 비정적 멤버는 사용이 불가능!
        //m_x = 99;

        /// 현재 인스턴스에 대한 접근도 불가!
        /// 인스턴스가 있을지 없을지 알 수 없기 때문에.
        //printf("%p\n", this);
    }

    /// const 멤버 함수 : 함수 내부에서 멤버 변수의 값을 변경할 수 없다!
    ///         모든! 멤버 변수는 const 멤버 함수 내부에서 읽기 전용이 된다.
    ///         cosnt 키워드가 함수 원형 뒤에 존재해야 const 멤버 함수가 된다.
    const int test(int param) const
    {
        /// 매개변수와 내부에서 선언된 변수의 값 변경은 문제 없음!
        int kkk = 0;
        int array[100];
        kkk += param;
        param = 100;
        /// const 멤버 함수 내부에서는 멤버 변수의 값 변경이 불가!
        //m_x = 99;
    }

    void exfunc() const;
};


/// 정적 멤버의 초기화는 클래스 외부에서 진행해야 한다.
/// 정적 멤버를 초기화하지 않으면 사용 자체가 불가능하다.
/// 정적 멤버를 외부에서 초기화할 때는 static 키워드를 생략해야 한다.
int CTest::s_I = 99;

/// const 멤버 함수를 클래스 외부에서 선언할때는 뒤에 const를 붙여야 한다.
void CTest::exfunc() const
{

}

class ABCCC
{
    /// 멤버 변수들은 일반적으로 인스턴스화 했을때 모두 스택에 만들어진다.
    int x;
    int array[100];
public:
    /// 멤버 함수들은 모두 code(text) 영역에 별도로 만들어 진다.
    void asdf()
    {
        double bb;
        int array[100];
    }
};


using namespace std;

class CParent
{
public:
    int m_Value;
    void bbb(int x)
    {
        m_private = x;
    }
protected:
    int m_prot;
private:
    int m_private;
    void mmm()
    {
        m_private = 333;
        /// ... 
    }
};


/// 상속을 받으면, 인스턴스화 될때, 부모 클래스의 모든 멤버 변수를 포함하여
/// 메모리가 할당된다.
class CChild : public CParent
{
public:
    int m_Value;
};

/// 상속된 클래스의 인스턴스가 만들어질때, 반드시 부모 클래스의
/// 멤버들이 먼저 만들어지고, 자신의 멤버가 만들어진다.

int main()
{
    CChild c;
    /// Child 인스턴스에서 부모 클래스의 멤버에 접근하는 코드
    c.CParent::m_Value = 1;
    c.m_Value = 2;

    cout << c.CParent::m_Value << endl;
    cout << c.m_Value << endl;

    printf("P[ %lld ] C[ %lld ]\n", sizeof(CParent), sizeof(CChild));
    printf("c[ %p ] pmv[ %p ] mv[ %p ]\n",
        &c, &c.CParent::m_Value, &c.m_Value);

    /// 클래스의 인스턴스의 크기는 오로지 멤버 변수에 의해서만 결정된다.
    printf("%lld\n", sizeof(ABCCC));
    /// 인스턴스와 관계 없이 직접 호출 가능
    CTest::notThis(333);

    CTest c1, c2;
    c1.asdf(123);
    c2.asdf(222);
    /// 정적 함수도 일반 메서드처럼 호출 가능
    c1.notThis(777);
    printf("%p - %p\n", &c1, &c2);
    //c1.s_I = 99;
    /// static 멤버 변수는 클래스의 인스턴스화와 관계 없이 사용 가능
    CTest::s_I = 23489;
    //std::cout << "Hello World!\n" << c1.s_I << std::endl;
    std::cout << "Hello World!\n" << CTest::s_I << std::endl;;
}
