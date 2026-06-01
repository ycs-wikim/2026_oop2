// 0601.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/**
* 생성자 : 인스턴스화 될때, 외부에서 자동으로 호출되는 초기화 함수
*       ==> 일반 함수 : 반드시 호출자가 존재
*       : 단 한번만 자동으로 호출
*   생성자 함수 선언
*       1. 함수의 반환 값이 없다.
*       2. 클래스의 이름과 동일한 이름을 사용
*       3. 권한을 반드시 public으로 선언해야 한다.
*       4. 함수 중복 선언이 가능 => 함수 오버로딩 지원
*   생성자의 목적 : 클래스의 인스턴스화 시점에 필요한 초기화를 담당
* 
* 소멸자 : 인스턴스가 메모리에서 해제될 때, 자동적으로 호출되는 함수
*       : 외부에서 호출되고 단 한번만 호출된다.
*   소멸자의 함수 선언
*       1. 함수의 반환 값이 없다.
*       2. 클래스의 이름과 동일한 이름을 사용
*           => 클래스 이름 앞에 "~"를 붙인다.
*       3. 권한을 반드시 public으로 선언해야 한다.
*       4. 함수의 중복 선언이 불가능 => 오버로딩 지원 불가
*           소멸자는 반드시! 한개만 존재해야 한다.
* 
* 생성자/소멸자는 클래스의 이름과 항상 동일해야 한다.
*   => 클래스의 이름이 외부에서 확인 가능
*   => 이름이 동일하기 때문에 함수 호출이 가능해진다.
*/

class CTest
{
public:
    /// 단순하게 인스턴스를 생성만 하면 호출
    /// Ex) CTest t;
    CTest()
    {
        printf("%p - %s Called\n", this, __FUNCTION__);
    }

    /// 인스턴스 생성 시점에 함수 호출하듯이 호출
    /// CTest t(3);
    CTest(int x)
    {
        printf("%p - %s Called\n", this, __FUNCTION__);
    }

    /// 소멸자 선언
    ~CTest()
    {
        printf("%p - ~ 소멸자가 호출\n", this);
    }

protected:
    void proFunc()
    {
        printf("protected 호출\n");
    }

};

/// 생성자와 소멸자가 없는 클래스
///     ==> 컴파일러가 의미 없는 생성/소멸자를 넣어준다.
///     CTTT(){}    ==> 기본 생성자 : 인수 없는 생성자
///     ~CTTT(){}
class CTTT : public CTest
{
public:
    int m_x;
    CTTT()
    {
        printf("%p - %s Called\n", this, __FUNCTION__);
        m_x = 0;
    }
    CTTT(int x)
    {
        m_x = x;
    }
    ~CTTT()
    {
        printf("%p - %s Called\n", this, __FUNCTION__);
        /// 부모 클래스에서 상속 받은 함수를 소멸자에서 호출!!!
        /// 부모 클래스의 인스턴스가 없다면 호출 불가능!
        proFunc();
    }
};

/**
* 생성자 : 선처리 영역
*   영역 구성 : 함수 인수의 끝나는 )부터 { 시작 사이 부분
*   ==> 필요한 초기화 작업을 수행하기 위해서
*/

class CTESTS
{
public:
    /// 상수는 반드시 선언하면서 초기화를 수행해야 한다!
    const int m_ci;
    const int m_cx;
    CTESTS()
        : m_ci(9), m_cx(8)
    {}

    /// 상수 값을 실행 시간 도중에 설정할 수 있다!
    CTESTS(int cx)
        /// 선처리 영역 시작
        : m_ci(cx), m_cx(cx)    // 변수명(값)
        /// 선처리 영역 종료
    {
        /// 선언시에 상수이기 때문에 초기화 불가능!
        //m_ci = 9;
    }

    /// 복사 생성자 : 원본을 이용한 새로운 인스턴스 생성이 목적
    CTESTS(const CTESTS& obj)
        : m_ci(obj.m_ci), m_cx(obj.m_cx)
    {
        printf("복사 생성자 호출\n");
        /// 자신과 동일한 클래스의 인스턴스 이기 때문에
        /// 내용을 확인하고, 필요한 내용만 가져와서
        /// 초기화를 수행할 수 있다.
    }

    /// 소멸자
    ~CTESTS()
    {

    }
    /// 소멸자의 후처리 영역 : 프로그래머가 할 수 있는 것이 없다.
};


class CNumber
{
public:
    int m_value;
};


class OPER
{
    
public:
    int m_x = 9;
    /// 객체의 연산자 적용을 지원하는 함수 선언
    OPER operator + (int a)
    {
        OPER op;
        op.m_x = op.m_x - a;
        return op;
    }

    OPER operator + (double a)
    {

    }

    int operator - (int x) {}
    int operator * (int x) {}
    int operator / (int x) {}
    int operator % (int x) {}
    int operator ^ (int x) {}
    int operator - (int x) {}
    int operator & (int x) {}
    int operator | (int x) {}
    int operator && (int x) {}
    int operator || (int x) {}
    int operator = (int x) {}
    int operator -> (int x) {}

    int operator ? (int x) {}
    
    int operator . (int x) {}
    int operator ! (int x) {}

};



int main()
{
    OPER oop;
    OPER op = oop + 3;
    printf("OP: %d\n", op.m_x);

    int a = 123;
    int b(444);
    int c = a + b;
    /// ==> b(444)가 가능한 이유 : int가 클래스
    CNumber a1;
    CNumber b1;
    a1.m_value = 3;
    b1.m_value = 6;
    //CNumber c1 = a1 + 3;

    /// 
    /**
    * 자료형의 크기 결정 : 큰 자료형으로 무조건 변환
    *   ==> 정보 손실을 방지하기 위해
    * 
    * int + int = int
    * int + double = double
    * double + int = double
    * double + double = double
    * int + char = int
    * char + char = char
    * char + double = double
    */


    printf("a: %d - b: %d\n", a, b);

    return 0;

    CTESTS tc1, tc2;
    CTTT ct;

    /// 복사 생성자를 이용한 인스턴스 생성
    CTESTS tc3(tc1);        /// 복사 생성자 호출 방식 1
    CTESTS tc4 = tc1;       /// 복사 생성자 호출 방식 2

    /*
    CTest t1;
    CTest t2(88);
    CTest* pt = new CTest();


    {
        CTest t3;
    }

    std::cout << "Hello World!\n";

    delete pt;
    */
}
