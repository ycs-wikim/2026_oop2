// 0511.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


/// C++ 클래스 선언
///  [, ]로 묶여있는 부분은 있을 수도/없을 수도 있다.
/// 예약어 클래스이름 [ : 클래스이름, 클래스이름, ... ]
/// {
/// 접근 지정자(권한):     /// 3P(private, protected, public)
///     멤버 변수;          /// 정보 (자료 구조)
///     멤버 함수;          /// 기능 (알고리즘)
/// 접근 지정자:         /// 접근 지정자는 N개 사용 가능
/// } ;

class aaa{};
class bbb{};

/// C++에서 class는 구조체와 동일
class Person : public aaa, private bbb
/// : 클래스이름 ==> 상속을 의미
/// 상속의 차이점
/// JAVA는 무조건! 단일 상속!
/// C++은 다중 상속을 지원
{
    int xxx;        /// C++에서 xxx의 권한: private
    int java;       /// JAVA에서 java의 권한 : public

/// 권한 정리
/// public : 누구나 접근하고, 사용 가능하다
/// protected : 관계가 있는 경우, 접근 및 사용 가능
/// private : 나만 사용 및 접근 가능
///
/// JAVA style
/*
    public int x;       
    private int x1;
    public int x2;
    */
/// C++ style
public:         /// 권한 + : 형태로 구성
                /// 해당 권한 아래로는 모두 동일한 권한
                /// 다른 권한이 나타날때까지
    int x;
    int y;
    int z;
    void asdf()
    {
        printf("asdf\n");
    }

private:        /// 다른 권한
    int a;
    int b;
    int c;
public:
    int z1;
};

/// CFamily 클래스 선언부
class CFamily
{
    /// 권한에서 이야기하는 범위가 어디냐??
    /// private, protected, public은 클래스 내부에서 허용
    /// private은 클래스 외부에서 접근 불가!
    ///     ==> 인스턴스화 했을 때, 보이지 않는다.
    /// protected는 클래스 외부에서 접근 불가!
    ///     ==> 상속된 클래스에서는 접근 가능!
/// 관계가 있는 클래스에서만 접근 가능한 멤버
///  관계 ==> 상속
/// protected 권한
///     상속된 클래스에서는 접근 가능
///     상속되지 않은 클래스에서는 접근 불가능! (private)
protected:
    const char* m_FamilyName;

public:
    /// 어디서나 접근 및 사용 가능한 메서드(멤버 함수)
    void SetFamilyName(const char* arg)
    {
        m_FamilyName = arg;
    }
};

/// CName 클래스 선언부
/// : pubilc CFamily ==> 상속을 의미 한다.
class CName : public CFamily
{
private:
    const char *m_Name;     /// 외부에서 접근 불가능!
public:
    /// static 멤버 선언
    static int m_value;
public:
    /// C++에서는 함수 선언부와 구현부를 분리해서 사용
    /// 메서드(멤버 함수)의 선언부!만 있는 상태
    void SetName(const char* arg);

    void ShowName()
    {
        /// m_famliyName 멤버는 상위 클래스에 선언되어
        /// 있으나, 상속을 받았기 때문에 즉시 사용 가능!
        std::cout << m_FamilyName << " " << m_Name << std::endl;
    }
};

/// 멤버 함수의 구현부
/// 1. 함수 원형을 그대로 가져온다.
/// 2. ; 삭제 후 { } 작성
/// 3. 클래스이름:: 형태로 함수 이름 앞에 작성
///     ==> 이 함수는 클래스의 멤버이다. 라는 것을 알림.
/// 4. 내용을 작성한다.
void CName::SetName(const char* arg)
{
    m_Name = arg;
}


/**
* static 예약어
* C언어
*   변수 선언 : static int x = 0;
*       => 한번만 초기화되는 전역 변수
*   함수 선언 : static void asdf( ) { ... }
*       => 해당 파일 외부에서는 호출 불가능한 함수
* C++언어
*   클래스 멤버 변수 선언 : static int m_x = 0;
*   클래스 멤버 함수 선언 : static void asdf( ){ ... }
*       => 공유할 수 있다. 반정도 근처만 맞는 이야기
*       => 클래스의 인스턴스화와 관계 없이 메모리에 존재
*           할 수 있는 멤버를 나타낸다.
*       => 포함된 클래스가 인스턴스화가 되지 않더라도...
*       => 프로그램이 시작되면 즉시 메모리에 할당된다.
*/



int main()
{
    CFamily cf;
    CName name, n1, n2, n3;
    //name.m_value = 10;      /// 정적 멤버 특징으로 이렇게 접근 불가!
    CName::m_value = 10;
    std::cout << "Value : " << CName::m_value << std::endl;
    name.SetFamilyName("Kim");
    name.SetName("Do Hyung");
    name.ShowName();
    /// 구조체와 동일하게 메모리 획득이 가능!
    /// 클래스에서는 이런 메모리를 인스턴스라 부름
    /// 클래스를 메모리에 적재한다라는 의미
    Person p1;  /// 인스턴스화
    p1.asdf();  /// 구조체 접근과 동일하게 사용 가능
    std::cout << "Hello World!\n";
}
