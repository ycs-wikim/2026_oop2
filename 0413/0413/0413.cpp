// 0413.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <windows.h>

/**
* 함수 == 기능
* C언어에서는 다양한 사용자 정의 함수를 정의하고 사용이 가능
* 사용자 정의 함수를 선언하는 방법
* 반환값 함수의이름(인수1, 매개변수2, ...)
* {
*   /// 함수가 실행해야 하는 실제 기능을 구현 => 구현 내용
* }
* 
* 반환값 : 처리가 완료된 다음 알아야 하는 정보
*       알아야 하는 정보가 없는 경우는 void 반환 값을 설정
*       void 반환 값을 갖는 함수 : 실패하지 않는다.
* 
* 함수의 이름 : 기능을 설명하는 내용으로 구성
* 
* 인수1~매개변수N : 처리를 위해 필요한 정보
* 
* 구현 내용 : 함수 이름에 맞게 실제로 동작하는 코드들
* 
* 함수 호출 3가지 방법
* 1. Call By Value : 값 복사에 의한 호출
* 2. Call By Reference : 참조에 의한 호출
* 3. Call By Address : 주소에 의한 호출
* 
* 예제는 아래 구조체를 이용해서 3가지 방법에 대해 정리
* 
* 함수 호출 방식을 규정하는 혹은 변수 정보를 전달하는 것은
* 함수의 인수가 어떤 자료형을 요구하느냐에 따라 달라진다!!!
*/

/// 구조체 선언
struct ASDF
{
    /// 구조체 멤버의 메모리 구조 : 배열과 동일하게 직선으로 생성
    int x;
    int y;
    int z;
    char c;     /// 패딩이 이루어지기 때문에 4byte 메모리 할당
    char str[1024];
    const char* cpr;
};

/// 1. Call By Value 형식으로 구조체 정보 전달
/// 인수의 복사가 발생 : 구조체 변수끼리는 대입 연산이 가능
/// ASDF a = asdf;      // 복사되어 입력
void CallByValue(ASDF a)
{
    printf("%s : %p[ %lld ]\n", __FUNCTION__, &a, sizeof(a));
    a.x = 99;       /// 복사된 변수의 값을 변경
    a.y = 999;      /// 원본에는 영향이 없다.
    a.z = 9;
}

/// 2. Call By Reference 형식으로 구조체 정보 전달
///  함수 호출 방식 : 함수의 인수/매개변수의 자료형
/// ASDF& a = asdf;     /// 복사되서 입력되는 것 같지만, 주소가 입력
void CallByReference(ASDF& a)
{
    printf("%s : %p[ %lld ]\n", __FUNCTION__, &a, sizeof(a));
    a.x = 99;       /// 복사된 변수의 값을 변경 XXXXX
    a.y = 999;      /// 참조 변수의 특징을 그대로 가져간다.
    a.z = 9;        /// 따라서 원본이 변경된다.
}


/// 3. Call By Address 형식으로 구조체 정보 전달
/// ASDF* a = &asdf;
void CallByAddress(ASDF* a)
{
    printf("%s : %p[ %lld ]\n", __FUNCTION__, &a, sizeof(a));
    a->x = 199;       /// 복사된 변수의 값을 변경 XXXXX
    a->y = 1999;      /// 참조 변수의 특징을 그대로 가져간다.
    a->z = 19;        /// 따라서 원본이 변경된다.
}


/// 4. call by mixed
void callByMixed(int a, int& b, int* c)
{
    a = 101;        /// a는 복사본만! 변경되므로 원본 영향이 없음.
    b = 102;        /// b는 또 다른 원본을 수정 -> 원본 수정이 발생
    *c = 103;       /// c는 주소를 사용 -> 원본 수정이 발생
}


/// 반환값 : void 실패하지 않는다.
void funcCallExam()
{
    /// 구현내용 : 3가지 호출 방식을 모두 구현해서 출력

    /// 구조체 변수 선언
    ASDF asdf;
    printf("%s : asdf[ %p - %lld ]\n", __FUNCTION__, &asdf, sizeof(asdf));
    /// 구조체 멤버들 초기화
    asdf.x = 10;
    asdf.y = 20;
    asdf.z = 30;

    /// 1. Call By Value 형식의 함수를 호출
    CallByValue(asdf);
    printf("1: X[ %d ] Y[ %d ] Z[ %d ]\n", asdf.x, asdf.y, asdf.z);

    /// 2. Call By Reference 형식의 함수를 호출
    CallByReference(asdf);
    printf("2: X[ %d ] Y[ %d ] Z[ %d ]\n", asdf.x, asdf.y, asdf.z);

    /// 3. Call By Address 형식의 함수를 호출
    CallByAddress(&asdf);
    printf("3: X[ %d ] Y[ %d ] Z[ %d ]\n", asdf.x, asdf.y, asdf.z);

    /// 구조체형 포인터를 사용하는 경우의 3가지 함수 호출 방법
    ASDF* ppp = &asdf;
    /// *ppp == asdf
    /// 1. Call By Value 형식의 함수를 호출
    CallByValue(*ppp);
    printf("1: X[ %d ] Y[ %d ] Z[ %d ]\n", asdf.x, asdf.y, asdf.z);
    //scanf("%d", &asdf.x);

    /// 2. Call By Reference 형식의 함수를 호출
    CallByReference(*ppp);
    printf("2: X[ %d ] Y[ %d ] Z[ %d ]\n", asdf.x, asdf.y, asdf.z);

    /// 3. Call By Address 형식의 함수를 호출
    CallByAddress(ppp);
    printf("3: X[ %d ] Y[ %d ] Z[ %d ]\n", asdf.x, asdf.y, asdf.z);

    /// 4. Call By Mixed 형식의 함수 호출
    callByMixed(asdf.x, asdf.y, &asdf.z);
    printf("4: X[ %d ] Y[ %d ] Z[ %d ]\n", asdf.x, asdf.y, asdf.z);
}


/// 함수 작성 시, 메인이든 어디든 코드가 길어진다~ 싶으면
/// 함수로 분리해서 만든다. --> 이 순서로 함수를 작성하면 편함.

void liExam(LARGE_INTEGER& lib)
{
    lib.LowPart = 35;
    lib.HighPart = 77;
    printf("Low[ %d ] Hi[ %d ]\n", lib.LowPart, lib.HighPart);
    lib.QuadPart = 9999;
    printf("Qp[ %lld ]\n", lib.QuadPart);
    printf("Low[ %d ] Hi[ %d ]\n", lib.LowPart, lib.HighPart);
}

int main()
{
    LARGE_INTEGER lib;
    liExam(lib);

    /// 구조체의 크기 출력
    printf("%d\n", sizeof(ASDF));
    /// 구조체형 변수 선언
    ASDF a, b;              /// 일반 구조체 변수 선언
    ASDF* ppp = &a;         /// 구조체형 포인터 변수
    int* pa = (int*) & a;
    /// 구조체 변수와 구조체의 첫번째 멤버 주소
    printf("%p %p\n", &a, &a.x);
    /// 구조체 멤버에 값을 할당
    a.cpr = "Hello World";
    a.x = 10;
    *(pa + 0) = 999;
    a.y = 20;
    *(pa + 1) = 9999;
    a.z = 30;
    *(pa + 2) = 99999;
    /// 멤버 값을 출력
    printf("%d %d %d\n", a.x, a.y, a.z);
    printf("%s : %s\n", a.cpr, ppp->cpr);

    /// 구조체의 연산자
    b = a;      /// 대입 연산 가능
    //a = b;    /// 구조체 자체 비교는 불가능
    //b > a;
    /// 멤버 명시 후 비교는 가능!
    if ((b.z == a.z) || ( a.z > b.x) );    
    
    funcCallExam();

    std::cout << "Hello World!\n";
}
