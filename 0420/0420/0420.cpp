// 0420.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
/// 가변 인수를 사용하기 위해 반드시 선언해야 하는 헤더 파일
#include <stdarg.h>

using namespace std;

#include "add.h"

/// 함수의 선언부 : 앞으로 이런 함수가 나올 예정이야. 그러니 걱정말고 번역해
///     ==> 함수의 원형, 프로토타입, 시그니처
///     선언부 구성 방법 : 반환값 함수이름(인수/매개변수, ...) ;
///     선언부 구성할 때, 인수/매개변수의 변수 이름은 생략 가능하다.
///          Ex) void addFunc(int, int);
void asdf();
void asdf1();
void asdf2();
void asdf3();

/// 기본 인자 함수의 원형/선언부에는 기본 인자를 표시한다!
int defaultFunc(int a = 15, int bioSensorDefaultValue = 9);

/// 기본 인자 함수(C++ 추가 기능)
/// 인수/매개변수를 선언하면서 동시에 초기화를 수행하는 인수/매개변수
/// 호출자가 별도로 명시하지 않으면 지정된 값을 초기화해서 사용
/// 인수 값을 잘 모르거나 정확하지 않은 경우, 기본 인자 함수가 설정되어
/// 있다면 그대로 사용하라고 알려주는 용도.
/// 주의! 반드시 오른쪽부터 사용해야 한다!
///     누구를 인수로 전달하는 것인지 컴파일러는 알 수 없다!
/// 기본 인자 함수의 구현부에는 기본 인자를 표시하지 않는다!!!
int defaultFunc(int a, int bioSensorDefaultValue)
{
    printf("%d + %d = %d\n", a, bioSensorDefaultValue, a + bioSensorDefaultValue);
    return -9;
}

/// 가변 인자 함수 선언부/구현부
/// 가변 인자/매개변수(...)가 시작되는 위치부터는 일반 인수를 받을 수 없다.
/// 가변 인자(...) 앞쪽의 인수는 반드시 전달해야만 동작한다.
/// 아래 함수 코드의 문제점 : 인수 개수에 대해 정확하게 처리 불가능!
void VFFunc(int arg1, int arg2, ...)
{
    /// va_list는 char*로 선언되어 있다.
    /// char* : 메모리의 정보 접근을 위한 최소 단위로 탐색하기 위해.
    /// arg_ptr : 가변 인수가 시작되는 위치를 가리키는 포인터. 선언만!
    va_list arg_ptr;
    /// 가변 인수에 대한 접근을 시작하겠다. 주소를 획득한다.
    va_start(arg_ptr, arg2);
    /// va_arg( ) : 전달된 포인터(arg_ptr) 위치로 부터,
    ///             전달된 자료형(double) 크기 만큼 획득해서 반환해라.
    ///             동시에 arg_ptr의 위치가 double 만큼 이동
    double varg3 = va_arg(arg_ptr, double);
    char varg4 = va_arg(arg_ptr, char);
    char* varg5 = va_arg(arg_ptr, char*);
    /// 가변 인수에 대한 접근을 종료하겠다.
    va_end(arg_ptr);

    cout << arg1 << endl;
    cout << arg2 << endl;
    cout << varg3 << endl;
    cout << varg4 << endl;
    cout << varg5 << endl;
}


/// 함수의 중복 정의
/// 동일한 함수 이름을 이용해서 다수 개의 함수를 한꺼번에 정의할 수 있다.
/// 인수의 개수와 인수의 자료형이 겹치지 않아야만 중복 정의가 가능!!!
/// 함수의 반환 값은 중복으로 인식되지 않는다.
///     ==> 반환 값으로 중복을 허용하지 않는다.
/// const를 이용한 자료형은 중복으로 허용되지 않는다.
/// const 자료형*는 중복으로 허용된다.
/// 포인터는 자료형에 대해 민감하므로 아래와 같은 경우 서로 다르게 인식
/// int *ptr != const int *ptr

/// C언어에서 더하기 함수를 만들려고 한다.
/// 더하는 자료형은 int + int, double + int, int + double, double + double
void add(int a, int b)
{
    printf("%s : %d\n", __FUNCTION__, a + b);
}

/// void addCharChar(...)
void add(char c1, char c2)
{
    printf("%s : %d\n", __FUNCTION__, c1 + c2);
}

/// 아래 add함수는 자료형이 int& == int 때문에 문제 발생.
void add(int a, int& b)
{
    printf("%s : %d\n", __FUNCTION__, a + b);
}

void add(double d, int a)
{
    printf("%s : %lf\n", __FUNCTION__, a + d);
}

void add(int a, double d)
{
    printf("%s : %lf\n", __FUNCTION__, a + d);
}

void add(double d1, double d2)
{
    printf("%s : %lf\n", __FUNCTION__, d1 + d2);
}


int main()
{
    int k = 999;
    /// 함수의 중복 정의 호출부
    add(1, 3);
    //add(33, k);
    add(1, 3.5);
    add(4.8, 66);
    add(4.5, 4.3);


    /// 기본 인자 함수 호출 방식은 여러개가 될 수 있다.
    /// 호출자가 전달하는 값이 기본 인자보다 우선한다.
    defaultFunc();
    defaultFunc(3);
    defaultFunc(3, 5);

    /// 가변 인자 함수 호출
    VFFunc(33, 44, 3.0, '4', "Hello~");
    VFFunc(22, 11);

    addFunc(3, 5);
    asdf();
    asdf1();
    asdf2();
    asdf3();
    std::cout << "Hello World!\n";
}

/// 함수의 구현부 : 기능을 실제로 구현한 코드로 프로젝트 어디에 있어도 문제 없음.
void asdf()
{
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
}


void asdf1()
{
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
}


void asdf2()
{
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
}


void asdf3()
{
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
    printf("%s\n", __FUNCTION__);
}
